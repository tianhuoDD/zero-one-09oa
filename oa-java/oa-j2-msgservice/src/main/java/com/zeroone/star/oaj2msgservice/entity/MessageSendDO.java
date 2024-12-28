package com.zeroone.star.oaj2msgservice.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * 消息发送数据对象（DO）
 * 该类用于映射消息发送相关的属性。
 *
 * @author qingjiu
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@TableName("msg_message")
public class MessageSendDO {

    /**
     * 消息唯一标识符
     */
    private String xid;

    /**
     * 消息创建时间
     */
    private LocalDateTime xcreateTime;

    /**
     * 消息序列号
     */
    private String xsequence;

    /**
     * 消息最后更新时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 消息的分发因子
     */
    private Integer xdistributeFactor;

    /**
     * 消息内容文本
     */
    private String xbody;

    /**
     * 消息是否已被消费（处理）
     */
    private Boolean xconsumed;

    /**
     * 处理该消息的消费者标识
     */
    private String xconsumer;

    /**
     * 消息是否为即时发送标识
     */
    private String xinstant;

    /**
     * 消息的发送者标识
     */
    private String xperson;

    /**
     * 附加属性，存储其他相关信息
     */
    private String xproperties;

    /**
     * 消息标题
     */
    private String xtitle;

    /**
     * 消息类型（例如：短信、邮件等）
     */
    private String xtype;
}
