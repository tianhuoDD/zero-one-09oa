package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

@Data
@ApiModel("工作流VO")
public class WorkVO {

    @ApiModelProperty(value = "唯一标识符")
    @Alias("xid")
    private String id;

    @ApiModelProperty(value = "创建时间")
    @Alias("xcreateTime")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "序列号")
    @Alias("xsequence")
    private String sequence;

    @ApiModelProperty(value = "更新时间")
    @Alias("xupdateTime")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "分配因子")
    @Alias("xdistributeFactor")
    private Integer distributeFactor;

    @ApiModelProperty(value = "活动标识")
    @Alias("xactivity")
    private String activity;

    @ApiModelProperty(value = "活动别名")
    @Alias("xactivityAlias")
    private String activityAlias;

    @ApiModelProperty(value = "活动到达时间")
    @Alias("xactivityArrivedTime")
    private LocalDateTime activityArrivedTime;

    @ApiModelProperty(value = "活动描述")
    @Alias("xactivityDescription")
    private String activityDescription;

    @ApiModelProperty(value = "活动名称")
    @Alias("xactivityName")
    private String activityName;

    @ApiModelProperty(value = "活动令牌")
    @Alias("xactivityToken")
    private String activityToken;

    @ApiModelProperty(value = "活动类型")
    @Alias("xactivityType")
    private String activityType;

    @ApiModelProperty(value = "应用标识")
    @Alias("xapplication")
    private String application;

    @ApiModelProperty(value = "应用别名")
    @Alias("xapplicationAlias")
    private String applicationAlias;

    @ApiModelProperty(value = "应用名称")
    @Alias("xapplicationName")
    private String applicationName;

    @ApiModelProperty(value = "执行前是否已执行")
    @Alias("xbeforeExecuted")
    private Boolean beforeExecuted;

    @ApiModelProperty(value = "布尔值01")
    @Alias("xbooleanValue01")
    private Boolean booleanValue01;

    @ApiModelProperty(value = "布尔值02")
    @Alias("xbooleanValue02")
    private Boolean booleanValue02;

    @ApiModelProperty(value = "创建者身份")
    @Alias("xcreatorIdentity")
    private String creatorIdentity;

    @ApiModelProperty(value = "创建者个人标识")
    @Alias("xcreatorPerson")
    private String creatorPerson;

    @ApiModelProperty(value = "创建者单位标识")
    @Alias("xcreatorUnit")
    private String creatorUnit;

    @ApiModelProperty(value = "创建者单位级别名称")
    @Alias("xcreatorUnitLevelName")
    private String creatorUnitLevelName;

    @ApiModelProperty(value = "数据是否已更改")
    @Alias("xdataChanged")
    private Boolean dataChanged;

    @ApiModelProperty(value = "日期时间值01")
    @Alias("xdateTimeValue01")
    private LocalDateTime dateTimeValue01;

    @ApiModelProperty(value = "日期时间值02")
    @Alias("xdateTimeValue02")
    private LocalDateTime dateTimeValue02;

    @ApiModelProperty(value = "日期时间值03")
    @Alias("xdateTimeValue03")
    private LocalDateTime dateTimeValue03;

    @ApiModelProperty(value = "日期时间值04")
    @Alias("xdateTimeValue04")
    private LocalDateTime dateTimeValue04;

    @ApiModelProperty(value = "日期时间值05")
    @Alias("xdateTimeValue05")
    private LocalDateTime dateTimeValue05;

    @ApiModelProperty(value = "日期值01")
    @Alias("xdateValue01")
    private LocalDate dateValue01;

    @ApiModelProperty(value = "日期值02")
    @Alias("xdateValue02")
    private LocalDate dateValue02;

    @ApiModelProperty(value = "目标活动")
    @Alias("xdestinationActivity")
    private String destinationActivity;

    @ApiModelProperty(value = "目标活动类型")
    @Alias("xdestinationActivityType")
    private String destinationActivityType;

    @ApiModelProperty(value = "目标路径")
    @Alias("xdestinationRoute")
    private String destinationRoute;

    @ApiModelProperty(value = "目标路径名称")
    @Alias("xdestinationRouteName")
    private String destinationRouteName;

    @ApiModelProperty(value = "双精度浮点值01")
    @Alias("xdoubleValue01")
    private Double doubleValue01;

    @ApiModelProperty(value = "双精度浮点值02")
    @Alias("xdoubleValue02")
    private Double doubleValue02;

    @ApiModelProperty(value = "双精度浮点值03")
    @Alias("xdoubleValue03")
    private Double doubleValue03;

    @ApiModelProperty(value = "双精度浮点值04")
    @Alias("xdoubleValue04")
    private Double doubleValue04;

    @ApiModelProperty(value = "双精度浮点值05")
    @Alias("xdoubleValue05")
    private Double doubleValue05;

    @ApiModelProperty(value = "嵌入目标工作")
    @Alias("xembedTargetWork")
    private String embedTargetWork;

    @ApiModelProperty(value = "过期时间")
    @Alias("xexpireTime")
    private LocalDateTime expireTime;

    @ApiModelProperty(value = "表单标识")
    @Alias("xform")
    private String form;

    @ApiModelProperty(value = "工作标识")
    @Alias("xjob")
    private String job;

    @ApiModelProperty(value = "长整型值01")
    @Alias("xlongValue01")
    private Long longValue01;

    @ApiModelProperty(value = "长整型值02")
    @Alias("xlongValue02")
    private Long longValue02;

    @ApiModelProperty(value = "长整型值03")
    @Alias("xlongValue03")
    private Long longValue03;

    @ApiModelProperty(value = "长整型值04")
    @Alias("xlongValue04")
    private Long longValue04;

    @ApiModelProperty(value = "长整型值05")
    @Alias("xlongValue05")
    private Long longValue05;

    @ApiModelProperty(value = "对象安全等级")
    @Alias("xobjectSecurityClearance")
    private Integer objectSecurityClearance;

    @ApiModelProperty(value = "流程标识")
    @Alias("xprocess")
    private String process;

    @ApiModelProperty(value = "流程别名")
    @Alias("xprocessAlias")
    private String processAlias;

    @ApiModelProperty(value = "流程名称")
    @Alias("xprocessName")
    private String processName;

    @ApiModelProperty(value = "属性信息")
    @Alias("xproperties")
    private String properties;

    @ApiModelProperty(value = "序列号")
    @Alias("xserial")
    private String serial;

    @ApiModelProperty(value = "分裂令牌")
    @Alias("xsplitToken")
    private String splitToken;

    @ApiModelProperty(value = "分裂值")
    @Alias("xsplitValue")
    private String splitValue;

    @ApiModelProperty(value = "是否进行分裂")
    @Alias("xsplitting")
    private Boolean splitting;

    @ApiModelProperty(value = "开始时间")
    @Alias("xstartTime")
    private LocalDateTime startTime;

    @ApiModelProperty(value = "开始时间月份")
    @Alias("xstartTimeMonth")
    private String startTimeMonth;

    @ApiModelProperty(value = "字符串值01")
    @Alias("xstringValue01")
    private String stringValue01;

    @ApiModelProperty(value = "字符串值02")
    @Alias("xstringValue02")
    private String stringValue02;

    @ApiModelProperty(value = "字符串值03")
    @Alias("xstringValue03")
    private String stringValue03;

    @ApiModelProperty(value = "字符串值04")
    @Alias("xstringValue04")
    private String stringValue04;

    @ApiModelProperty(value = "字符串值05")
    @Alias("xstringValue05")
    private String stringValue05;

    @ApiModelProperty(value = "字符串值06")
    @Alias("xstringValue06")
    private String stringValue06;

    @ApiModelProperty(value = "字符串值07")
    @Alias("xstringValue07")
    private String stringValue07;

    @ApiModelProperty(value = "字符串值08")
    @Alias("xstringValue08")
    private String stringValue08;

    @ApiModelProperty(value = "字符串值09")
    @Alias("xstringValue09")
    private String stringValue09;

    @ApiModelProperty(value = "字符串值10")
    @Alias("xstringValue10")
    private String stringValue10;

    @ApiModelProperty(value = "时间值01")
    @Alias("xtimeValue01")
    private LocalTime timeValue01;

    @ApiModelProperty(value = "时间值02")
    @Alias("xtimeValue02")
    private LocalTime timeValue02;

    @ApiModelProperty(value = "标题")
    @Alias("xtitle")
    private String title;

    @ApiModelProperty(value = "工作创建类型")
    @Alias("xworkCreateType")
    private String workCreateType;

    @ApiModelProperty(value = "工作状态")
    @Alias("xworkStatus")
    private String workStatus;

    @ApiModelProperty(value = "工作是否通过手动完成")
    @Alias("xworkThroughManual")
    private Boolean workThroughManual;


}
