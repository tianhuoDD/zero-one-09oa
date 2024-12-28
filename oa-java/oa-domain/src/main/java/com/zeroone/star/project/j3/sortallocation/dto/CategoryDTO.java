package com.zeroone.star.project.j3.sortallocation.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotNull;


@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("分类传输数据对象")
public class CategoryDTO<T> {
    @NotNull
    @ApiModelProperty(value = "分类名称")
    private String categoryName;
    @ApiModelProperty(value = "分类标识")
    private String id;
    @ApiModelProperty(value = "表单类型")
    private Integer distributeFactor;
    @ApiModelProperty(value = "分类别名")
    private String categoryAlias;
    @ApiModelProperty(value = "文档类型")
    private String documentType;
    @ApiModelProperty(value = "发布时是否发送消息")
    private Boolean sendNotify;
    @ApiModelProperty(value = "工作流程应用名称")
    private String workflowAppName;
    @ApiModelProperty(value = "工作流程名称")
    private String workflowName;
    @NotNull
    @ApiModelProperty(value = "栏目ID")
    private String appId;
/*    @TableField(value = "栏目名称")
    private String appName;*/

    @ApiModelProperty(value = "管理者群组列表")
    private String xmanageableGroupList;
    @ApiModelProperty(value = "管理者个人列表")
    private String xmanageablePersonList;
    @ApiModelProperty(value = "管理者组织列表")
    private String xmanageableUnitList;
    @ApiModelProperty(value = "发布者群组列表")
    private String xpublishableGroupList;
    @ApiModelProperty(value = "发布者个人列表")
    private String xpublishablePersonList;
    @ApiModelProperty(value = "发布者组织列表")
    private String xpublishableUnitList;
    @ApiModelProperty(value = "查看者群组列表")
    private String xviewableGroupList;
    @ApiModelProperty(value = "查看者个人列表")
    private String xviewablePersonList;
    @ApiModelProperty(value = "查看者组织列表")
    private String xviewableUnitList;







}
