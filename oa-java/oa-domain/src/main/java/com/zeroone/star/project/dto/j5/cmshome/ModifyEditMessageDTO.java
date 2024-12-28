package com.zeroone.star.project.dto.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("修改消息保存对象")
public class ModifyEditMessageDTO {

    /*
     * 文档ID
     */
    @ApiModelProperty(value = "文档ID", example = "d7a5521d-4ab9-413a-8e5a-cb1d669c19be")
    private String documentXid;

    /*
     * 创建人
     *//*
    @ApiModelProperty(value = "创建人姓名", example = "张三")
    private String xcreatorName;

    *//*
     * 创建时间
     *//*
    @ApiModelProperty(value = "创建时间", example = "2023-04-01 00:00:00")
    private LocalDateTime xcreateTime;
*/
    /*
     * 标题
     */
    @ApiModelProperty(value = "标题",example = "通知公告1：你们要加班")
    private String xfieldTitle;

    /*
     * 模板内容
     */
    @ApiModelProperty(value = "模板内容",example = "根据app类型不同模板内容也不同")
    private String xdata;
}
