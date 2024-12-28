package com.zeroone.star.project.dto.j8.resource.menu;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.util.ArrayList;
import java.util.List;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：菜单传输对象
 * </p>
 * @author DOT
 * @version 1.0.0
 */
@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("菜单数据对象")
public class MenuDTO {
    @ApiModelProperty(value = "菜单ID", example = "1")
    private String menuId;

    @ApiModelProperty(value = "菜单名称", example = "信息管理")
    @NotBlank(message = "菜单名称不能为空")
    private String menuName;

    @ApiModelProperty(value = "菜单类型 (1: 普通菜单, 2: 目录, 3: 内嵌iFrame, 4: 外链跳转)", example = "1")
    @NotNull(message = "菜单类型不能为空")
    private Integer menuType;

    @ApiModelProperty(value = "是否为按钮", example = "0")
    private Boolean isButton;

    @ApiModelProperty(value = "父菜单ID", example = "13")
    private String parentId;

    @ApiModelProperty(value = "权限标识", example = "123456")
    private String permission;

    @ApiModelProperty(value = "菜单状态 (1: 启用, 0: 停用)", example = "1")
    private Integer status;

    @ApiModelProperty(value = "所在层数，用于快速查询同层结点", example = "2")
    @NotNull(message = "所在层数不能为空")
    private Integer level;

    @ApiModelProperty(value = "外链跳转页面对应URL", example = "/menu-add")
    private String linkUrl;

    @ApiModelProperty(value = "备注", example = "操作菜单")
    private String remark;

    @ApiModelProperty(value = "图标", example = "")
    private String icon;

    private List<MenuDTO> children = new ArrayList<>();
}
