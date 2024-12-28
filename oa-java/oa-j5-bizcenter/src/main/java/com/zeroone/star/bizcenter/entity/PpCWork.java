package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示一个工作单元或任务的相关信息，用于业务中心的内部数据处理。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-28
 */
@Getter
@Setter
@TableName("pp_c_work")
public class PpCWork implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识符
     */
    @TableId
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
     * 活动标识
     */
    private String xactivity;

    /**
     * 活动别名
     */
    private String xactivityAlias;

    /**
     * 活动到达时间
     */
    private LocalDateTime xactivityArrivedTime;

    /**
     * 活动描述
     */
    private String xactivityDescription;

    /**
     * 活动名称
     */
    private String xactivityName;

    /**
     * 活动令牌
     */
    private String xactivityToken;

    /**
     * 活动类型
     */
    private String xactivityType;

    /**
     * 应用标识
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
     * 执行前是否已执行
     */
    private Boolean xbeforeExecuted;

    /**
     * 布尔值01
     */
    private Boolean xbooleanValue01;

    /**
     * 布尔值02
     */
    private Boolean xbooleanValue02;

    /**
     * 创建者身份
     */
    private String xcreatorIdentity;

    /**
     * 创建者个人标识
     */
    private String xcreatorPerson;

    /**
     * 创建者单位标识
     */
    private String xcreatorUnit;

    /**
     * 创建者单位级别名称
     */
    private String xcreatorUnitLevelName;

    /**
     * 数据是否已更改
     */
    private Boolean xdataChanged;

    /**
     * 日期时间值01
     */
    private LocalDateTime xdateTimeValue01;

    /**
     * 日期时间值02
     */
    private LocalDateTime xdateTimeValue02;

    /**
     * 日期时间值03
     */
    private LocalDateTime xdateTimeValue03;

    /**
     * 日期时间值04
     */
    private LocalDateTime xdateTimeValue04;

    /**
     * 日期时间值05
     */
    private LocalDateTime xdateTimeValue05;

    /**
     * 日期值01
     */
    private LocalDate xdateValue01;

    /**
     * 日期值02
     */
    private LocalDate xdateValue02;

    /**
     * 目标活动
     */
    private String xdestinationActivity;

    /**
     * 目标活动类型
     */
    private String xdestinationActivityType;

    /**
     * 目标路径
     */
    private String xdestinationRoute;

    /**
     * 目标路径名称
     */
    private String xdestinationRouteName;

    /**
     * 双精度浮点值01
     */
    private Double xdoubleValue01;

    /**
     * 双精度浮点值02
     */
    private Double xdoubleValue02;

    /**
     * 双精度浮点值03
     */
    private Double xdoubleValue03;

    /**
     * 双精度浮点值04
     */
    private Double xdoubleValue04;

    /**
     * 双精度浮点值05
     */
    private Double xdoubleValue05;

    /**
     * 嵌入目标工作
     */
    private String xembedTargetWork;

    /**
     * 过期时间
     */
    private LocalDateTime xexpireTime;

    /**
     * 表单标识
     */
    private String xform;

    /**
     * 工作标识
     */
    private String xjob;

    /**
     * 长整型值01
     */
    private Long xlongValue01;

    /**
     * 长整型值02
     */
    private Long xlongValue02;

    /**
     * 长整型值03
     */
    private Long xlongValue03;

    /**
     * 长整型值04
     */
    private Long xlongValue04;

    /**
     * 长整型值05
     */
    private Long xlongValue05;

    /**
     * 对象安全等级
     */
    private Integer xobjectSecurityClearance;

    /**
     * 流程标识
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
     * 属性信息
     */
    private String xproperties;

    /**
     * 序列号
     */
    private String xserial;

    /**
     * 分裂令牌
     */
    private String xsplitToken;

    /**
     * 分裂值
     */
    private String xsplitValue;

    /**
     * 是否进行分裂
     */
    private Boolean xsplitting;

    /**
     * 开始时间
     */
    private LocalDateTime xstartTime;

    /**
     * 开始时间月份
     */
    private String xstartTimeMonth;

    /**
     * 字符串值01
     */
    private String xstringValue01;

    /**
     * 字符串值02
     */
    private String xstringValue02;

    /**
     * 字符串值03
     */
    private String xstringValue03;

    /**
     * 字符串值04
     */
    private String xstringValue04;

    /**
     * 字符串值05
     */
    private String xstringValue05;

    /**
     * 字符串值06
     */
    private String xstringValue06;

    /**
     * 字符串值07
     */
    private String xstringValue07;

    /**
     * 字符串值08
     */
    private String xstringValue08;

    /**
     * 字符串值09
     */
    private String xstringValue09;

    /**
     * 字符串值10
     */
    private String xstringValue10;

    /**
     * 时间值01
     */
    private LocalTime xtimeValue01;

    /**
     * 时间值02
     */
    private LocalTime xtimeValue02;

    /**
     * 标题
     */
    private String xtitle;

    /**
     * 工作创建类型
     */
    private String xworkCreateType;

    /**
     * 工作状态
     */
    private String xworkStatus;

    /**
     * 工作是否通过手动完成
     */
    private Boolean xworkThroughManual;
}
