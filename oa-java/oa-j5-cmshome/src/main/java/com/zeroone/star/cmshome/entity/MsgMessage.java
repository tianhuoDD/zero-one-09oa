package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@TableName("msg_message")
public class MsgMessage implements Serializable {

    /**
     * 消息唯一标识
     * 示例: "76c920fd-eade-4afd-b1b4-c4b2c9515b6f"
     */
    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    /**
     * 消息创建时间
     * 示例: "2024-10-27T15:56:41"
     */
    @TableField("xcreateTime")
    private LocalDateTime xcreateTime;

    /**
     * 序列号
     * 示例: "20241027155641abc123"
     */
    @TableField("xsequence")
    private String xsequence;

    /**
     * 消息更新时间
     * 示例: "2024-10-27T16:00:00"
     */
    @TableField("xupdateTime")
    private LocalDateTime xupdateTime;

    /**
     * 分发因子，通常用于分配和调度消息
     * 示例: 10
     */
    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    /**
     * 消息内容
     * 示例: "消息的具体内容"
     */
    @TableField("xbody")
    private String xbody;

    /**
     * 消息是否已被消费，1表示已消费，0表示未消费
     * 示例: true
     */
    @TableField("xconsumed")
    private Boolean xconsumed;

    /**
     * 消费者标识
     * 示例: "abc123-consumer"
     */
    @TableField("xconsumer")
    private String xconsumer;

    /**
     * 关联的即时消息标识
     * 示例: "123e4567-e89b-12d3-a456-426614174000"
     */
    @TableField("xinstant")
    private String xinstant;

    /**
     * 关联的人员标识
     * 示例: "3783390a-d443-4e06-9fe8-c55ddb3c7282"
     */
    @TableField("xperson")
    private String xperson;

    /**
     * 消息的属性（通常为JSON格式的键值对）
     * 示例: "{ \"priority\": \"high\", \"status\": \"active\" }"
     */
    @TableField("xproperties")
    private String xproperties;

    /**
     * 消息标题
     * 示例: "horse"
     */
    @TableField("xtitle")
    private String xtitle;

    /**
     * 消息类型
     * 示例: "通知"
     */
    @TableField("xtype")
    private String xtype;
}
