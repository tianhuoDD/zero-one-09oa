package com.zeroone.star.project.query.j2.message.service;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

@Data
@ApiModel("消息发送查询对象")
public class MessageSendQuery extends PageQuery {

    @ApiModelProperty(value = "接收者标识符（手机号或邮箱）", example = "+1234567890 或 example@example.com", required = true)
    @NotBlank(message = "接收者标识符不能为空")
    private String xperson;

    @ApiModelProperty(value = "消息类型（SMS 或 EMAIL）", example = "EMAIL", allowableValues = "SMS, EMAIL", required = true)
    @NotBlank(message = "消息类型不能为空")
    private String xtype;

    @ApiModelProperty(value = "消息内容", example = "这是一条消息的内容", required = true)
    @NotBlank(message = "消息内容不能为空")
    private String xbody;

    @ApiModelProperty(value = "消息标题（仅用于邮件）", example = "消息的标题", notes = "发送邮件时的标题")
    private String xtitle;
}
