package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

@Data
@ApiModel("任务信息")
public class TaskVO {


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

    @ApiModelProperty(value = "是否允许快速")
    @Alias("xallowRapid")
    private Boolean allowRapid;

    @ApiModelProperty(value = "应用标识")
    @Alias("xapplication")
    private String application;

    @ApiModelProperty(value = "应用别名")
    @Alias("xapplicationAlias")
    private String applicationAlias;

    @ApiModelProperty(value = "应用名称")
    @Alias("xapplicationName")
    private String applicationName;

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

    @ApiModelProperty(value = "区分名称")
    @Alias("xdistinguishedName")
    private String distinguishedName;

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

    @ApiModelProperty(value = "授权来源身份")
    @Alias("xempowerFromIdentity")
    private String empowerFromIdentity;

    @ApiModelProperty(value = "过期时间")
    @Alias("xexpireTime")
    private LocalDateTime expireTime;

    @ApiModelProperty(value = "是否已过期")
    @Alias("xexpired")
    private Boolean expired;

    @ApiModelProperty(value = "是否首次")
    @Alias("xfirst")
    private Boolean first;

    @ApiModelProperty(value = "来源区分名称")
    @Alias("xfromDistinguishedName")
    private String fromDistinguishedName;

    @ApiModelProperty(value = "身份")
    @Alias("xidentity")
    private String identity;

    @ApiModelProperty(value = "工作标识")
    @Alias("xjob")
    private String job;

    @ApiModelProperty(value = "标签")
    @Alias("xlabel")
    private String label;

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

    @ApiModelProperty(value = "媒体意见")
    @Alias("xmediaOpinion")
    private String mediaOpinion;

    @ApiModelProperty(value = "是否已修改")
    @Alias("xmodified")
    private Boolean modified;

    @ApiModelProperty(value = "意见")
    @Alias("xopinion")
    private String opinion;

    @ApiModelProperty(value = "意见详细")
    @Alias("xopinionLob")
    private String opinionLob;

    @ApiModelProperty(value = "是否暂停")
    @Alias("xpause")
    private Boolean pause;

    @ApiModelProperty(value = "个人标识")
    @Alias("xperson")
    private String person;

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

    @ApiModelProperty(value = "路由别名")
    @Alias("xrouteAlias")
    private String routeAlias;

    @ApiModelProperty(value = "路由名称")
    @Alias("xrouteName")
    private String routeName;

    @ApiModelProperty(value = "序列号")
    @Alias("xserial")
    private String serial;

    @ApiModelProperty(value = "系列")
    @Alias("xseries")
    private String series;

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

    @ApiModelProperty(value = "单位")
    @Alias("xunit")
    private String unit;

    @ApiModelProperty(value = "催办时间")
    @Alias("xurgeTime")
    private LocalDateTime urgeTime;

    @ApiModelProperty(value = "是否已催办")
    @Alias("xurged")
    private Boolean urged;

    @ApiModelProperty(value = "查看时间")
    @Alias("xviewTime")
    private LocalDateTime viewTime;

    @ApiModelProperty(value = "工作")
    @Alias("xwork")
    private String work;

    @ApiModelProperty(value = "工作创建类型")
    @Alias("xworkCreateType")
    private String workCreateType;


}
