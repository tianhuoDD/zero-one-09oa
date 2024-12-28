package com.zeroone.star.project.vo.j2.message.service;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.Email;
import java.time.LocalDateTime;

/**
 * 消息发送VO
 * 用于返回给前端的消息状态或消息详细信息
 * @author qingjiu
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel(description = "邮件消息发送VO，用于返回消息的详细信息")
public class MessageSendMailVO {

    @ApiModelProperty(value = "请求状态码，返回OK代表请求成功", example = "OK")
    private String code;

    @ApiModelProperty(value = "状态码的描述", example = "邮件发送成功")
    private String message;

    @ApiModelProperty(value = "邮件发送时间", example = "2024-10-02T10:00:00")
    private LocalDateTime sendTime;

    @ApiModelProperty(value = "接收者邮箱", example = "example@example.com")
    @Email(message = "邮箱格式不正确")
    private String recipientEmail;

    @ApiModelProperty(value = "错误码（如果有）", example = "EMAIL_SEND_ERROR")
    private String errorCode;

    @ApiModelProperty(value = "错误描述（如果有）", example = "邮箱地址无效")
    private String errorDescription;
}