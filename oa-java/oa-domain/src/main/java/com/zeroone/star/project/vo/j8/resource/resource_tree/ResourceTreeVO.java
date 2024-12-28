package com.zeroone.star.project.vo.j8.resource.resource_tree;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.util.List;
import lombok.Data;

@Data
@ApiModel("菜单资源信息")
public class ResourceTreeVO{

    @ApiModelProperty(value="菜单ID")
    private String menuId;

    @ApiModelProperty(value="菜单名称")
    private String menuName;

    @ApiModelProperty(value = "子菜单")
    private List<ResourceTreeVO> children;
}
