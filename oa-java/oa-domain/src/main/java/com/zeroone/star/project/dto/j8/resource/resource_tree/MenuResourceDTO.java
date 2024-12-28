package com.zeroone.star.project.dto.j8.resource.resource_tree;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

@Data
public class MenuResourceDTO {

    @ApiModelProperty(value = "菜单ID", required = true)
    private String menuId; // 菜单ID

    @ApiModelProperty(value = "菜单名称", required = true)
    private String menuName; // 菜单名称

    @ApiModelProperty(value = "菜单类型", required = true)
    private Integer menuType; // 菜单类型 (1: 普通菜单, 2: 目录, 3: 内嵌iFrame, 4: 外链跳转)

    @ApiModelProperty(value = "父菜单ID", required = true)
    private String parentId; // 父菜单ID

    @ApiModelProperty(value = "是否按钮")
    private Boolean isButton; // 是否按钮

    @ApiModelProperty(value = "权限标识")
    private String permission; // 权限标识

    @ApiModelProperty(value = "菜单状态", required = true)
    private Integer status; // 菜单状态（1启用 0停用）

    @ApiModelProperty(value = "备注信息")
    private String remark; // 备注

    @ApiModelProperty(value = "创建者ID")
    private String creatorId; // 创建者ID

    @ApiModelProperty(value = "创建时间")
    private Date createTime; // 创建时间

    @ApiModelProperty(value = "更新者ID")
    private String updaterId; // 更新者ID

    @ApiModelProperty(value = "更新时间")
    private Date updateTime; // 更新时间

    @ApiModelProperty(value = "逻辑删除", required = true)
    private Boolean deleted; // 逻辑删除标志
}
