package com.zeroone.star.project.dto.j2.message.notification;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@ApiModel("消息通知对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class MsgInstantDTO {

    /**
     * 消息Id
     */
    @ApiModelProperty(value = "消息ID", example = "99e3e999-29cd-408a-9b57-4634134b88ee",required = true)
    String xid;

    /**
     * 消息状态
     */
    @ApiModelProperty(value = "消息通知是否被消费", example = "0",required = true)
    Boolean xconsumed;
}
