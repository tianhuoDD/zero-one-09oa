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
@ApiModel(description = "消息发送VO，用于返回消息的详细信息")
public class MessageSendVO {

    @ApiModelProperty(value = "消息唯一标识符", required = true, example = "123e4567-e89b-12d3-a456-426614174000", notes = "每条消息的唯一标识符，用于追踪和定位消息")
    @NotBlank(message = "消息唯一标识符不能为空")
    private String xid;

    @ApiModelProperty(value = "创建时间", required = true, example = "2023-04-01T10:00:00", notes = "记录消息的创建时间")
    @NotNull(message = "创建时间不能为空")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "最后更新时间", example = "2023-04-01T12:00:00", notes = "记录消息的最后一次更新的时间")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "消息内容", required = true, example = "这是消息的具体内容", notes = "包含短信或邮件的主体内容，便于前端显示")
    @NotBlank(message = "消息内容不能为空")
    private String xbody;

    @ApiModelProperty(value = "接收者标识符（手机号或邮箱）", required = true, example = "+1234567890 或 example@example.com", notes = "标识消息的接收人，短信是手机号，邮件是邮箱地址")
    @NotBlank(message = "接收者标识符不能为空")
    private String xperson;

    @ApiModelProperty(value = "消息标题", example = "这是消息的标题", notes = "用于邮件的标题，对于短信来说可能为空")
    private String xtitle;

    @ApiModelProperty(value = "消息类型（SMS 或 EMAIL）", required = true, example = "EMAIL", allowableValues = "SMS, EMAIL", notes = "消息的类型，用于区分是短信还是邮件")
    @NotBlank(message = "消息类型不能为空")
    private String xtype;

    @ApiModelProperty(value = "是否已被消费", required = true, example = "true", notes = "标识这条消息是否已经被消费过。true 表示已消费，false 表示未消费")
    @NotNull(message = "消费状态不能为空")
    private Boolean xconsumed;
}