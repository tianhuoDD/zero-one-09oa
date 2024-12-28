package com.zeroone.star.project.dto.j2.message.service;

import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class MessageNotifyServiceDTO {
    /**
     * 客户端编号
     */
    private String clientId;

    /**
     * 通知消息内容
     */
    private String message;
}