package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@TableName("msg_instant")
public class MsgInstant implements Serializable {

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
    private String xbody;

    /**
     * 消息是否已被消费，1表示已消费，0表示未消费
     * 示例: 1
     */
    private Boolean xconsumed;

    /**
     * 关联的人员标识
     * 示例: "3783390a-d443-4e06-9fe8-c55ddb3c7282"
     */
    private String xperson;

    /**
     * 消息标题
     * 示例: "horse"
     */
    private String xtitle;

    /**
     * 消息类型
     * 示例: "通知"
     */
    private String xtype;
}
