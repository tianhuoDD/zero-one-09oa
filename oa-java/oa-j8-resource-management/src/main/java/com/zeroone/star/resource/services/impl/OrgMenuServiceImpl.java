package com.zeroone.star.resource.services.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.resource.menu.MenuDTO;
import com.zeroone.star.project.dto.j8.resource.menu_permission.MenuPermissionsDTO;
import com.zeroone.star.project.dto.j8.resource.resource_tree.MenuResourceDTO;
import com.zeroone.star.project.query.j8.resource.menu_permission.MenuPermissionsQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.resource.resource_tree.ResourceTreeVO;
import com.zeroone.star.resource.entity.OrgMenu;
import com.zeroone.star.resource.mapper.OrgMenuMapper;
import com.zeroone.star.resource.services.OrgMenuService;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import javax.annotation.Resource;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.util.CollectionUtils;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_menu(菜单权限表)】的数据库操作Service实现
 * @createDate 2024-10-24 20:49:30
 * @modifier liang
 * @modification date 2024-10-27 15:27:00
 */
@Service
@Slf4j
public class OrgMenuServiceImpl extends ServiceImpl<OrgMenuMapper, OrgMenu>
    implements OrgMenuService {

    @Resource
    private OrgMenuMapper orgMenuMapper; // 确保注入Mapper

    @Override
    public JsonVO<String> addMenu(MenuDTO menuDTO) {
        OrgMenu orgMenu = new OrgMenu();
        BeanUtils.copyProperties(menuDTO, orgMenu);
        orgMenuMapper.insert(orgMenu);
        log.info("新增菜单项数据库ID：{}", orgMenu.getMenuId());
        return JsonVO.success(orgMenu.getMenuId());
    }

    @Override
    public JsonVO<MenuDTO> queryMenuByID(String menuID) {
        OrgMenu orgMenu = orgMenuMapper.selectById(menuID);
        if (orgMenu == null) {
            log.warn("未找到ID为{}的菜单", menuID);
            return JsonVO.fail(null);
        }
        MenuDTO menuDTO = new MenuDTO();
        BeanUtils.copyProperties(orgMenu, menuDTO);
        log.info("查询到的菜单：{}", menuDTO);
        return JsonVO.success(menuDTO);
    }

    @Override
    public JsonVO<String> modifyMenu(MenuDTO menuDTO) {
        OrgMenu orgMenu = new OrgMenu();
        BeanUtils.copyProperties(menuDTO, orgMenu);
        orgMenuMapper.updateById(orgMenu);
        return JsonVO.success(orgMenu.getMenuId());
    }

    @Override
    public JsonVO<String> removeMenu(MenuDTO menuDTO) {
        orgMenuMapper.deleteById(menuDTO.getMenuId());
        return JsonVO.success(menuDTO.getMenuId());
    }

    @Override
    public JsonVO<PageDTO<MenuPermissionsDTO>> queryMenuPermissions(MenuPermissionsQuery condition) {
        // 根据条件查询实际的总记录数
        long totalRecords = orgMenuMapper.countByCondition(condition);

        // 获取分页参数
        long pageIndex = condition.getPageIndex();
        long pageSize = condition.getPageSize();

        // 计算总页数
        long totalPages = (totalRecords + pageSize - 1) / pageSize;

        // 查询当前页的数据
        List<OrgMenu> orgMenuList = orgMenuMapper.queryByCondition(condition, pageIndex, pageSize);

        // 将OrgMenu转换为MenuPermissionsDTO
        List<MenuPermissionsDTO> records = orgMenuList.stream().map(orgMenu -> {
            MenuPermissionsDTO dto = new MenuPermissionsDTO();
            BeanUtils.copyProperties(orgMenu, dto);
            return dto;
        }).collect(Collectors.toList());

        // 构建分页结果
        PageDTO<MenuPermissionsDTO> resultPage = new PageDTO<>();
        resultPage.setPageIndex(pageIndex);
        resultPage.setPageSize(pageSize);
        resultPage.setTotal(totalRecords);
        resultPage.setPages(totalPages);
        resultPage.setRows(records); // 设置实际查询到的数据

        // 返回包含分页信息的 JsonVO
        return JsonVO.success(resultPage);
    }

    @Override
    public JsonVO<Void> addMenuPermissions(List<MenuPermissionsDTO> MenuPermissionsDTOList) {
        List<OrgMenu> orgMenuList = MenuPermissionsDTOList.stream().map(dto -> {
            OrgMenu orgMenu = new OrgMenu();
            BeanUtils.copyProperties(dto, orgMenu);
            return orgMenu;
        }).collect(Collectors.toList());
        // 执行批量插入
        saveBatch(orgMenuList);
        return JsonVO.success(null);
    }

    @Override
    public JsonVO<Void> deleteMenuPermissions(List<Integer> MenuPermissionsIds) {
        // 根据ID批量删除菜单权限
        removeByIds(MenuPermissionsIds);
        return JsonVO.success(null);
    }

    @Override
    public JsonVO<Void> modifyMenuPermissions(MenuPermissionsDTO MenuPermissionsDTO) {
        OrgMenu orgMenu = new OrgMenu();
        BeanUtils.copyProperties(MenuPermissionsDTO, orgMenu);
        // 执行更新
        updateById(orgMenu);
        return JsonVO.success(null);
    }

    /**
     * 获取资源名称树
     */
    @Override
    public List<ResourceTreeVO> getResourceTree() {
        List<MenuResourceDTO> menus = orgMenuMapper.getMenuResources();
        return buildResourceTree(menus);
    }

    private List<ResourceTreeVO> buildResourceTree(List<MenuResourceDTO> menus) {
        return menus.stream()
            .filter(menu -> menu.getParentId() == null || menu.getParentId().isEmpty())
            .map(menu -> {
                ResourceTreeVO treeVO = new ResourceTreeVO();
                BeanUtils.copyProperties(menu, treeVO);
                treeVO.setChildren(buildChildren(menu.getMenuId(), menus));
                return treeVO;
            })
            .collect(Collectors.toList());
    }

    private List<ResourceTreeVO> buildChildren(String parentId, List<MenuResourceDTO> menus) {
        return menus.stream()
            .filter(menu -> menu.getParentId() != null && menu.getParentId().equals(parentId))
            .map(menu -> {
                ResourceTreeVO treeVO = new ResourceTreeVO();
                BeanUtils.copyProperties(menu, treeVO);
                treeVO.setChildren(buildChildren(menu.getMenuId(), menus));
                return treeVO;
            })
            .collect(Collectors.toList());
    }

    /**
     * 获取菜单树
     */
    @Override
    public List<MenuDTO> getMenuTree(MenuPermissionsQuery condition) {
        // 获取菜单列表
        List<OrgMenu> orgMenuList = orgMenuMapper.getMenuList();

        // 判断是否为空
        if (CollectionUtils.isEmpty(orgMenuList)) {
            return new ArrayList<>();
        } else {
            // 构建树形菜单
            return buildMenuTree(orgMenuList, "0");  // "0" 表示根菜单的parent_id
        }
    }

    /**
     * 递归构建MenuDTO树
     */
    private List<MenuDTO> buildMenuTree(List<OrgMenu> orgMenuList, String parentId) {
        List<MenuDTO> menuTree = new ArrayList<>();

        for (OrgMenu menu : orgMenuList) {
            // 若当前菜单为一级菜单，递归查找子菜单
            if (menu.getParentId().equals(parentId)) {
                // 创建 MenuDTO 节点并复制 OrgMenu 信息
                MenuDTO node = new MenuDTO();
                node.setMenuId(menu.getMenuId());
                node.setMenuName(menu.getMenuName());
                node.setParentId(menu.getParentId());

                // 递归构建子菜单
                List<MenuDTO> children = buildMenuTree(orgMenuList, menu.getMenuId());
                node.setChildren(children);

                // 添加到菜单树中
                menuTree.add(node);
            }
        }
        return menuTree;
    }

}
