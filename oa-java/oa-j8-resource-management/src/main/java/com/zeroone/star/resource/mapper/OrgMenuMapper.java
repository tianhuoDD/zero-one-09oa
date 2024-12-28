package com.zeroone.star.resource.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j8.resource.resource_tree.MenuResourceDTO;
import com.zeroone.star.project.query.j8.resource.menu_permission.MenuPermissionsQuery;
import com.zeroone.star.resource.entity.OrgMenu;
import java.util.List;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

/**
 * @author Sleepyhead-Desktop
 * @description 针对表【org_menu(菜单权限表)】的数据库操作Mapper
 * @createDate 2024-10-24 20:49:30
 * @Entity com.zeroone.star.resource.entity.OrgMenu
 */
@Mapper
public interface OrgMenuMapper extends BaseMapper<OrgMenu> {

    /**
     * 根据条件查询符合条件的记录总数
     * @param condition 查询条件
     * @return 符合条件的记录总数
     */
    long countByCondition(@Param("condition") MenuPermissionsQuery condition);

    /**
     * 根据条件进行分页查询
     * @param condition 查询条件
     * @param pageIndex 当前页码
     * @param pageSize 每页条数
     * @return 当前页数据列表
     */
    List<OrgMenu> queryByCondition(@Param("condition") MenuPermissionsQuery condition,
                                   @Param("pageIndex") long pageIndex,
                                   @Param("pageSize") long pageSize);

    /**
     * 获取资源名称树
     * @return
     */
    @Select("SELECT " +
            "menu_id AS menuId, " +
            "menu_name AS menuName, " +
            "menu_type AS menuType, " +
            "parent_id AS parentId, " +
            "is_button AS isButton, " +
            "permission, " +
            "status " +
            "FROM res_menu " +
        "WHERE deleted = 0 AND isButton == 1")
    List<MenuResourceDTO> getMenuResources();


    /**
     * 获取所有菜单
     * @return
     */
    @Select("SELECT " +
        "menu_id AS menuId, " +
        "menu_name AS menuName, " +
        "menu_type AS menuType, " +
        "parent_id AS parentId, " +
        "is_button AS isButton, " +
        "permission, " +
        "status " +
        "FROM res_menu " +
        "WHERE deleted = 0 AND isButton != 0")
    List<OrgMenu> getMenuList();

}




