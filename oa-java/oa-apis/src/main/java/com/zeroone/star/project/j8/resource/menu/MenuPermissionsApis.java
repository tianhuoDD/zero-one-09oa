package com.zeroone.star.project.j8.resource.menu;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.resource.menu_permission.MenuPermissionsDTO;
import com.zeroone.star.project.query.j8.resource.menu_permission.MenuPermissionsQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface MenuPermissionsApis {
    /**
     * 获取菜单功能的分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageDTO<MenuPermissionsDTO>> queryMenuPermissions(MenuPermissionsQuery condition);

    /**
     * 多项添加菜单功能权限
     * @param MenuPermissionsDTOList 要添加的菜单功能权限list表
     * @return 添加多项菜单功能权限
     */
    JsonVO<Void> addMenuPermissions(List<MenuPermissionsDTO> MenuPermissionsDTOList);
    /**
     * 批量删除菜单功能权限
     * @param MenuPermissionsIds 菜单权限功能ID列表
     * @return 删除结果
     */
    JsonVO<Void> deleteMenuPermissions(List<Integer> MenuPermissionsIds);
    /**
     * 修改菜单功能权限
     * @param MenuPermissionsDTO 更新数据
     * @return  修改结果
     */
    JsonVO<Void> modifyMenuPermissions(MenuPermissionsDTO MenuPermissionsDTO);
}
