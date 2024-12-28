package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 活动快照实体类
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-28
 */
@Getter
@Setter
@TableName("pp_c_snap")
public class PpCSnap implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 快照ID
     */
    private String xid;

    /**
     * 创建时间
     */
    private LocalDateTime xcreateTime;

    /**
     * 序列号
     */
    private String xsequence;

    /**
     * 更新时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 分配因子
     */
    private Integer xdistributeFactor;

    /**
     * 活动代码
     */
    private String xactivity;

    /**
     * 活动别名
     */
    private String xactivityAlias;

    /**
     * 活动描述
     */
    private String xactivityDescription;

    /**
     * 活动名称
     */
    private String xactivityName;

    /**
     * 活动Token
     */
    private String xactivityToken;

    /**
     * 活动类型
     */
    private String xactivityType;

    /**
     * 应用代码
     */
    private String xapplication;

    /**
     * 应用别名
     */
    private String xapplicationAlias;

    /**
     * 应用名称
     */
    private String xapplicationName;

    /**
     * 创建者身份
     */
    private String xcreatorIdentity;

    /**
     * 创建者个人代码
     */
    private String xcreatorPerson;

    /**
     * 创建者单位代码
     */
    private String xcreatorUnit;

    /**
     * 职位代码
     */
    private String xjob;

    /**
     * 个人代码
     */
    private String xperson;

    /**
     * 流程代码
     */
    private String xprocess;

    /**
     * 流程别名
     */
    private String xprocessAlias;

    /**
     * 流程名称
     */
    private String xprocessName;

    /**
     * 属性
     */
    private String xproperties;

    /**
     * 开始时间
     */
    private LocalDateTime xstartTime;

    /**
     * 标题
     */
    private String xtitle;

    /**
     * 类型
     */
    private String xtype;

}
