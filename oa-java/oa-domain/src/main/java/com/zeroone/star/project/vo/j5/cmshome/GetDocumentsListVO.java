package com.zeroone.star.project.vo.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("获取文档列表")
public class GetDocumentsListVO {

    @ApiModelProperty(value = "ID", example = "12345")
    private String id; // 对应于 d2.xid

    @ApiModelProperty(value = "标题", example = "通知公告")
    private String xtitle; // 对应于 d2.xtitle

    @ApiModelProperty(value = "创建人姓名", example = "张三")
    private String xcreatorName; // 这个字段应该对应于 u2.xname

    @ApiModelProperty(value = "创建部门", example = "技术部")
    private String xcreatorUnit; // 这个字段应该对应于 u1.xlevelName

    @ApiModelProperty(value = "分类", example = "通知")
    private String xcategoryName; // 这个字段应该对应于 d2.xcategoryName

    @ApiModelProperty(value = "发布时间", example = "2023-04-01 12:00:00")
    private String xpublishTime; // 这个字段可以对应于 d2.xcreateTime
}
