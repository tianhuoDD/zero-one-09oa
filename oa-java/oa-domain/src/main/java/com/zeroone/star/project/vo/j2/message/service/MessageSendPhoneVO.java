package com.zeroone.star.project.vo.j2.message.service;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.time.LocalDateTime;

/**
 * 消息发送VO
 * 用于返回给前端的消息状态或消息详细信息
 * @author qingjiu
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel(description = "短信消息发送VO，用于返回消息的详细信息")
public class MessageSendPhoneVO {

    @ApiModelProperty(value = "请求状态码，返回OK代表请求成功", example = "OK")
    private String code;

    @ApiModelProperty(value = "状态码的描述", example = "短信发送成功")
    private String message;

    @ApiModelProperty(value = "短信发送时间", example = "2024-10-02T10:00:00")
    private LocalDateTime sendTime;

    @ApiModelProperty(value = "接收者手机号", example = "+1234567890")
    private String recipientPhone;

    @ApiModelProperty(value = "错误码（如果有）", example = "SMS_CODE_ERROR")
    private String errorCode;

    @ApiModelProperty(value = "错误描述（如果有）", example = "验证码错误")
    private String errorDescription;
}