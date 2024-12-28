package com.zeroone.star.project.dto.j8.resource.menu_permission;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.time.LocalDateTime;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("菜单权限数据传输对象")
public class MenuPermissionsDTO {

    @ApiModelProperty(value = "菜单ID", example = "menu123")
    private String menuId; // 菜单ID

    @ApiModelProperty(value = "菜单名称", example = "用户管理")
    private String menuName; // 菜单名称

    @ApiModelProperty(value = "菜单类型", example = "1")
    private Integer menuType; // 菜单的类型 (1为普通菜单，2为目录，3为内嵌iFrame，4为外链跳转)

    @ApiModelProperty(value = "父菜单ID", example = "parent123")
    private String parentId; // 父菜单ID

    @ApiModelProperty(value = "是否按钮", example = "true")
    private Boolean isButton; // 是否按钮

    @ApiModelProperty(value = "权限标识", example = "USER_MANAGE")
    private String permission; // 权限标识

    @ApiModelProperty(value = "菜单状态", example = "1")
    private Integer status; // 菜单状态（1启用，0停用）

    @ApiModelProperty(value = "备注", example = "该菜单用于管理用户")
    private String remark; // 备注

    @ApiModelProperty(value = "图标", example = "creator123")
    private String icon; // 图标

    @ApiModelProperty(value = "创建者ID", example = "creator123")
    private String creatorId; // 创建者ID

    @ApiModelProperty(value = "创建时间", example = "2023-01-01T12:00:00")
    private LocalDateTime createTime; // 创建时间

    @ApiModelProperty(value = "更新者ID", example = "updater123")
    private String updaterId; // 更新者ID

    @ApiModelProperty(value = "更新时间", example = "2023-02-01T15:00:00")
    private LocalDateTime updateTime; // 更新时间

    @ApiModelProperty(value = "逻辑删除", example = "false")
    private Boolean deleted; // 逻辑删除
}
