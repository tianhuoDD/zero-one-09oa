package com.zeroone.star.login.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.Menu;
import com.zeroone.star.login.mapper.MenuMapper;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：定义一个Menu数据到MenuTreeNode的属性映射配器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
class MenuTreeNodMapper implements TreeNodeMapper<Menu> {
	@Override
	public TreeNode objectMapper(Menu menu) {
		MenuTreeVO treeNode = new MenuTreeVO();
		// 首先设置TreeNode计算层数使用属性
		treeNode.setTnId(menu.getMenuId().toString());
		if (menu.getParentId() == null) {
			treeNode.setTnPid(null);
		} else {
			treeNode.setTnPid(menu.getParentId().toString());
		}
		// 设置扩展属性
		treeNode.setId(menu.getMenuId());
		treeNode.setIcon(menu.getIcon());
		treeNode.setText(menu.getMenuName());
		treeNode.setHref(menu.getLinkUrl());
		treeNode.setPid(Integer.parseInt(menu.getParentId()));
		return treeNode;
	}
}

/**
 * <p>
 * 菜单 服务实现类
 * </p>
 *
 * @author 阿伟
 */
@Service
public class MenuServiceImpl extends ServiceImpl<MenuMapper, Menu> implements IMenuService {

	@Override
	public List<MenuTreeVO> listMenuByRoleName(List<String> roleNames) {
		// 1 定义一个存储数据库查询菜单数据的容器
		List<Menu> menus = new ArrayList<>();

		// 2 遍历获取角色获取所有的菜单列表
		roleNames.forEach(roleName -> {
			// 通过角色名获取菜单列表
			List<Menu> tMenus = baseMapper.selectByRoleName(roleName);
            Set<Menu> tMenusSet = new HashSet<>(tMenus);
			Set<Menu> childMenus = selectChild(tMenusSet);
			tMenus.addAll(childMenus);
			if (tMenus != null && !tMenus.isEmpty()) {
				menus.addAll(tMenus);
			}
		});
		// 3 转换树形结构并返回
		return TreeUtils.listToTree(menus, new MenuTreeNodMapper());
	}

	@Autowired
	private MenuMapper menuMapper;

	private Set<Menu> selectChild(Set<Menu> tMenus) {
		Set<Integer> parentIds = tMenus.stream().map(Menu::getMenuId).collect(Collectors.toSet());
		Set<Menu> chileMenu = menuMapper.getChild(parentIds);
		if (chileMenu == null || chileMenu.isEmpty()) {
			return new HashSet<>();
		} else {
			chileMenu.addAll(selectChild(chileMenu));
		}
		return chileMenu;
	}


}
