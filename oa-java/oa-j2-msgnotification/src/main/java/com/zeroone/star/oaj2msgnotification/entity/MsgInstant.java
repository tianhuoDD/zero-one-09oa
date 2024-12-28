package com.zeroone.star.oaj2msgnotification.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import java.time.LocalDateTime;

/**
 * 消息DO对象
 */
@Data
@TableName("msg_instant")
public class MsgInstant {
    /**
     * 唯一标识
     */
    @TableId
    private String xid;

    /**
     * 创建时间
     */
    private LocalDateTime xcreateTime;

    /**
     * 序列号,可能用于标识消息的顺序
     */
    private String xsequence;

    /**
     * 更新时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 可能表示分发因子,具体含义取决于业务需求
     */
    private Integer xdistributeFactor; // 使用 Integer 类型，便于处理 NULL

    /**
     * 消息体
     */
    private String xpody;

    /**
     * 是否被消费
     */
    private Boolean xconsumed; // 使用 Boolean 类型  只能为0/1

    /**
     * 消息接收用户
     */
    private String xperson;

    /**
     * 消息标题
     */
    private String xtitle;

    /**
     * 消息类型
     */
    private String xtype;
}
