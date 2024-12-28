package com.zeroone.star.project.dto.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("新建情况下的编辑页面上传对象")
public class NewEditDTO {

    /*
     * 新建消息id
     */
    @ApiModelProperty(value = "新建消息时的编辑模板id", example = "1")
    private String xid;

    /*
     * 创建人
     */
    @ApiModelProperty(value = "创建人姓名", example = "张三")
    private String xcreatorName;

    /*
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2023-04-01 00:00:00")
    private String xcreateTime;

    /*
     * 标题
     */
    @ApiModelProperty(value = "标题",example = "通知公告1：你们要加班")
    private String xfieldTitle;

    /*
     * 发布范围
     */
    @ApiModelProperty(value = "发布范围", example = "张三、李四、王五")
    private List<String> publishRange;

    /*
     * 审批人
     */
    @ApiModelProperty(value = "审批人", example = "审批员赵六")
    private String approver;

    /*
     * 简要说明
     */
    @ApiModelProperty(value = "简要说明", example = "这是一个XXX")
    private String sampleDescription;

    /*
     * 正文内容
     */
    @ApiModelProperty(value = "正文内容", example = "正文内容")
    private String content;

    /**
     * 附件
     */
    @ApiModelProperty(value = "附件", example = "附件")
    private List<String> attachment;
}
