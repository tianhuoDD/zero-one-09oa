package com.zeroone.star.project.query.j8.resource.menu_permission;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@ApiModel("菜单权限查询对象")
public class MenuPermissionsQuery extends PageQuery {

    @ApiModelProperty(value = "菜单ID", example = "menu123")
    private String menuId; // 菜单ID

    @ApiModelProperty(value = "菜单名称", example = "用户管理")
    private String menuName; // 菜单名称
}
