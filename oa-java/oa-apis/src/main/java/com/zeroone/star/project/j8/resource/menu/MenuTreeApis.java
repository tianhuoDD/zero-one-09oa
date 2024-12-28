package com.zeroone.star.project.j8.resource.menu;

import com.zeroone.star.project.dto.j8.resource.menu.MenuDTO;
import com.zeroone.star.project.query.j8.resource.menu_permission.MenuPermissionsQuery;
import com.zeroone.star.project.vo.JsonVO;
import java.util.List;

/**
 * <p>
 * 描述：菜单树业务接口定义
 * </p>
 * @author 门门
 * @version 1.0.0
 */
public interface MenuTreeApis {

    /**
     * 获取菜单树
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<List<MenuDTO>> getMenuTree(MenuPermissionsQuery condition);


}
