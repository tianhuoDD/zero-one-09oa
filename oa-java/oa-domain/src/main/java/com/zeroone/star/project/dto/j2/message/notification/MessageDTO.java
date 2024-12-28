package com.zeroone.star.project.dto.j2.message.notification;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @Author: hjm
 * @Date: 2024/10/20/16:22
 * @Description: 消息操作对象
 */
@ApiModel("消息操作对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class MessageDTO {
    /**
     * 消息ID
     */
    @ApiModelProperty(value = "消息ID", example = "1")
    private String xid;

    /**
     * 用户ID
     */
    @ApiModelProperty(value = "用户ID", example = "1")
    private String xperson;

    /**
     * 消息内容
     */
    @ApiModelProperty(value = "消息内容", example = "您有一条新消息")
    private String xbody;

    /**
     * 是否已读
     */
    @ApiModelProperty(value = "是否已读", example = "false")
    private Boolean xconsumed;
}
