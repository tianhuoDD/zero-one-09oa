package com.zeroone.star.project.dto.j2.message.service;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;
import java.time.LocalDateTime;
import java.util.List;

/**
 * 消息发送DTO
 * 用于传输发送消息（短信或邮件）的相关信息
 * @author qingjiu
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("消息发送DTO,用于传输发送消息的相关信息")
public class MessageSendDTO {

    @ApiModelProperty(value = "消息唯一标识符", required = true, example = "123e4567-e89b-12d3-a456-426614174000")
    @NotBlank(message = "消息唯一标识符不能为空")
    private String xid;

    @ApiModelProperty(value = "消息序列号", example = "seq-001", notes = "用于处理消息的顺序，特别是在同一个接收者的多个消息场景下使用")
    private String xsequence;

    @ApiModelProperty(value = "创建时间", example = "2023-04-01T10:00:00", notes = "表示消息创建的时间")
    @NotNull(message = "创建时间不能为空")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "最后更新时间", example = "2023-04-01T12:00:00", notes = "表示消息最后一次更新的时间")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "分布因子，用于负载均衡或分片", example = "3", notes = "可以帮助对消息的分布处理")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "消息内容", required = true, example = "这是一条测试消息内容", notes = "短信和邮件的实际消息内容")
    @NotBlank(message = "消息内容不能为空")
    @Size(max = 5000, message = "消息内容长度不能超过5000个字符")
    private String xbody;

    @ApiModelProperty(value = "接收者标识符列表（手机号或邮箱）", required = true, example = "[\"+1234567890\", \"example@example.com\"]", notes = "发送的目标接收者列表，支持多个接收者。短信是手机号，邮件是邮箱地址")
    @NotNull(message = "接收者标识符列表不能为空")
    @Size(min = 1, message = "接收者标识符列表中至少包含一个接收者")
    private List<@NotBlank(message = "接收者标识符不能为空") String> xpersons;

    @ApiModelProperty(value = "消息标题（主要用于邮件）", example = "这是消息的标题", notes = "对于短信类型的消息标题可为空，但邮件类型必须提供标题")
    private String xtitle;

    @ApiModelProperty(value = "消息类型（SMS 或 EMAIL）", required = true, example = "SMS", notes = "用于区分消息的类型，是短信还是邮件")
    @NotBlank(message = "消息类型不能为空")
    private String xtype;

    @ApiModelProperty(value = "扩展属性，用于自定义一些参数，可能为JSON格式", example = "{\"priority\": \"high\"}", notes = "可以包含一些额外的配置或说明")
    private String xproperties;
}
