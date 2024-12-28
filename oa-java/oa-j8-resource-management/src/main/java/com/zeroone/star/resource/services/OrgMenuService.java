
package com.zeroone.star.resource.services;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.resource.menu.MenuDTO;
import com.zeroone.star.project.dto.j8.resource.menu_permission.MenuPermissionsDTO;
import com.zeroone.star.project.query.j8.resource.menu_permission.MenuPermissionsQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.resource.resource_tree.ResourceTreeVO;
import com.zeroone.star.resource.entity.OrgMenu;
import java.util.List;
/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_menu(菜单权限表)】的数据库操作Service实现
 * @createDate 2024-10-24 20:49:30
 * @modifier liang
 * @modification date 2024-10-27 15:27:00
 */
public interface OrgMenuService extends IService<OrgMenu> {
    /**
     * 创建新的菜单项
     * @param menuDTO 菜单数据传输对象
     * @return 创建后的菜单 ID
     */
    JsonVO<String> addMenu(MenuDTO menuDTO);

    /**
     * 根据 ID 获取菜单
     * @param menuID 菜单 ID
     * @return 查询结果
     */
    JsonVO<MenuDTO> queryMenuByID(String menuID);

    /**
     * 更新菜单
     * @param menuDTO 更新的菜单数据传输对象
     * @return 成功更新，返回菜单 ID
     */
    JsonVO<String> modifyMenu(MenuDTO menuDTO);

    /**
     * 逻辑删除菜单项
     * @param menuDTO 需要删除的菜单
     * @return 成功删除, 返回菜单 ID
     */
    JsonVO<String> removeMenu(MenuDTO menuDTO);

    /**
     * 分页查询菜单权限
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<MenuPermissionsDTO>> queryMenuPermissions(MenuPermissionsQuery condition);

    /**
     * 批量添加菜单权限
     * @param MenuPermissionsDTOList 菜单权限 DTO 列表
     * @return 添加结果
     */
    JsonVO<Void> addMenuPermissions(List<MenuPermissionsDTO> MenuPermissionsDTOList);

    /**
     * 批量删除菜单权限
     * @param MenuPermissionsIds 菜单权限 ID 列表
     * @return 删除结果
     */
    JsonVO<Void> deleteMenuPermissions(List<Integer> MenuPermissionsIds);

    /**
     * 更新菜单权限
     * @param MenuPermissionsDTO 菜单权限 DTO
     * @return 更新结果
     */
    JsonVO<Void> modifyMenuPermissions(MenuPermissionsDTO MenuPermissionsDTO);

    /**
     * 获取资源名称树
     * @return
     */
    List<ResourceTreeVO> getResourceTree();

    /**
     * 获取菜单树
     * @param condition
     * @return
     */
    List<MenuDTO> getMenuTree(MenuPermissionsQuery condition);
}