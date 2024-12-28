package com.zeroone.star.project.j3.appinfo.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("栏目对象")
public class AppDTO {
    @ApiModelProperty(value = "栏目唯一编号",example = "ba6e682d-3a7c-421e-a2e0-37555a07d79a")
    private String xid;

    @ApiModelProperty(value = "栏目类型",example = "新闻")
    private String xappType;

    @ApiModelProperty(value = "栏目名称",example = "栏目1")
    private String xappName;

    @ApiModelProperty(value = "栏目别名",example = "别名1")
    private String xappAlias;

    @ApiModelProperty(value = "栏目描述",example = "这是一个很好的栏目")
    private String xdescription;

    @ApiModelProperty(value = "栏目图片二进制资源",example = "+HxW8AAAAASUVORK5CYII=")
    private String xappIcon;

    @ApiModelProperty(value = "编辑表单类型名称",example = "发布类编辑表单")
    private String xeditName;

    @ApiModelProperty(value = "阅读表单类型名称",example = "发布类阅读表单")
    private String xpublishName;

}
