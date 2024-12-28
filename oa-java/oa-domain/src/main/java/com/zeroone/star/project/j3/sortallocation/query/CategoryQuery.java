package com.zeroone.star.project.j3.sortallocation.query;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


@Data
public class CategoryQuery {
    @ApiModelProperty(value = "分类名称",example = "通知公告")
    private String xCategoryName;
    @ApiModelProperty(value = "分类标识",example = "fjisionwv123")
    private String xId;
    @ApiModelProperty(value = "表单类型",example ="阅读表单")
    private Integer xDistributeFactor;
    @ApiModelProperty(value = "分类别名",example = "信息发布-通知公告")
    private String xCategoryAlias;
    @ApiModelProperty(value = "文档类型",example = "信息")
    private String xDocumentType;
    @ApiModelProperty(value = "发布时是否发送消息",example ="是")
    private boolean xSendNotify;
    @ApiModelProperty(value = "工作流程")
    private String workFlow;
    @ApiModelProperty(value = "可见范围")
    private String viewableRange;
    @ApiModelProperty(value = "发布者")
    private String publisher;
    @ApiModelProperty(value = "管理者")
    private  String manager;
    @ApiModelProperty(value = "父分类ID",example = "fjisionwv123")
    private String xparentId;


}
