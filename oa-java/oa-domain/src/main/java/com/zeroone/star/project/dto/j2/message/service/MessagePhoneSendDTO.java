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
 * 手机消息发送DTO
 * 用于传输发送消息（短信）的相关信息
 * @author qingjiu
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("手机消息发送DTO,用于传输发送消息的相关信息")
public class MessagePhoneSendDTO {
    @ApiModelProperty(value = "消息内容", required = true, example = "这是一条测试消息内容", notes = "短信的实际消息内容")
    @NotBlank(message = "消息内容不能为空")
    @Size(max = 5000, message = "消息内容长度不能超过5000个字符")
    private String xbody;

    @ApiModelProperty(value = "接收者标识符列表手机号", required = true, example = "[\"+1234567890\"", notes = "发送的目标接收者列表，支持多个接收者。短信是手机号")
    @NotNull(message = "接收者标识符列表不能为空")
    @Size(min = 1, message = "接收者标识符列表中至少包含一个接收者")
    private List<@NotBlank(message = "接收者标识符不能为空") String> xpersons;

}
