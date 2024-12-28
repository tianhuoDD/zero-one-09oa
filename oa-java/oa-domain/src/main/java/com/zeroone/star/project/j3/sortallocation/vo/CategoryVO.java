package com.zeroone.star.project.j3.sortallocation.vo;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class CategoryVO {
    @ApiModelProperty(value = "分类名称")
    private String categoryName;

    @ApiModelProperty(value = "栏目id")
    private String appId;

/*    @TableField(value = "栏目名称")
    private String xappName;*/

    @ApiModelProperty(value = "分类唯一标识")
    private String id;

    @ApiModelProperty(value = "表单类型")
    private int distributeFactor;

    @ApiModelProperty(value = "分类别名")
    private String categoryAlias;

    @ApiModelProperty(value = "文档类型")
    private String documentType;

    @ApiModelProperty(value = "发布时是否发送消息")
    private boolean sendNotify;

    @ApiModelProperty(value = "可见范围")
    private String viewableRange;

    @ApiModelProperty(value = "发布者")
    private String publisher;

    @ApiModelProperty(value = "管理者")
    private String manager;

    @ApiModelProperty(value = "工作流应用名称")
    private String workflowAppName;

    @ApiModelProperty(value = "工作流名称")
    private String workflowName;






}
