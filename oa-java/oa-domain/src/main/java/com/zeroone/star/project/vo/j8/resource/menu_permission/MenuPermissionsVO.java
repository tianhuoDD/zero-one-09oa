package com.zeroone.star.project.vo.j8.resource.menu_permission;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;

import java.time.LocalDateTime;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("菜单权限视图对象")
public class MenuPermissionsVO {

    @ApiModelProperty(value = "菜单ID", example = "menu123")
    private String menuId; // 菜单ID

    @ApiModelProperty(value = "菜单名称", example = "用户管理")
    private String menuName; // 菜单名称

    @ApiModelProperty(value = "权限标识", example = "USER_MANAGE")
    private String permission; // 权限标识


}
