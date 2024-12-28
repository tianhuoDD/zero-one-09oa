package com.zeroone.star.project.dto.j5.bizcenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("流程分类 数据对象")
public class ProcessCategoryDTO {
    @ApiModelProperty("ID")
    private String id;

    @ApiModelProperty("分类名称")
    private String categoryName;

    @ApiModelProperty("应用ID")
    private String appId;

    @ApiModelProperty("应用名称")
    private String appName;

    @ApiModelProperty("文档类型")
    private String documentType;

    @ApiModelProperty("分类别名")
    private String categoryAlias;

    @ApiModelProperty("工作流类型")
    private String workflowType;

    @ApiModelProperty("工作流应用ID")
    private String workflowAppId;

    @ApiModelProperty("工作流应用名称")
    private String workflowAppName;

    @ApiModelProperty("工作流名称")
    private String workflowName;

    @ApiModelProperty("工作流标志")
    private String workflowFlag;

    @ApiModelProperty("表单ID")
    private String formId;

    @ApiModelProperty("表单名称")
    private String formName;

    @ApiModelProperty("阅读表单ID")
    private String readFormId;

    @ApiModelProperty("阅读表单名称")
    private String readFormName;

    @ApiModelProperty("分类序列")
    private String categorySeq;

    @ApiModelProperty("创建人")
    private String creatorPerson;

    @ApiModelProperty("创建人身份")
    private String creatorIdentity;

    @ApiModelProperty("创建人单位名称")
    private String creatorUnitName;

    @ApiModelProperty("创建人顶级单位名称")
    private String creatorTopUnitName;

    @ApiModelProperty("是否允许匿名")
    private boolean anonymousAble;

    @ApiModelProperty("是否所有人可查看")
    private boolean allPeopleView;

    @ApiModelProperty("是否所有人可发布")
    private boolean allPeoplePublish;

    @ApiModelProperty("是否发送通知")
    private boolean sendNotify;

    @ApiModelProperty("是否发送空白通知")
    private boolean blankToAllNotify;

    @ApiModelProperty("创建时间")
    private LocalDateTime createTime;

    @ApiModelProperty("更新时间")
    private LocalDateTime updateTime;
}
