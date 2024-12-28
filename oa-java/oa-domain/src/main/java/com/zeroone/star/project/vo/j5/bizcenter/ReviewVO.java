package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

@Data
@ApiModel("审核信息")
public class ReviewVO {


    @Alias("xid")
    @ApiModelProperty("ID")
    private String id;

    @Alias("xcreateTime")
    @ApiModelProperty("创建时间")
    private LocalDateTime createTime;

    @Alias("xsequence")
    @ApiModelProperty("序列")
    private String sequence;

    @Alias("xupdateTime")
    @ApiModelProperty("更新时间")
    private LocalDateTime updateTime;

    @Alias("xdistributeFactor")
    @ApiModelProperty("分配因子")
    private Integer distributeFactor;

    @Alias("xapplication")
    @ApiModelProperty("应用程序")
    private String application;

    @Alias("xapplicationAlias")
    @ApiModelProperty("应用程序别名")
    private String applicationAlias;

    @Alias("xapplicationName")
    @ApiModelProperty("应用程序名称")
    private String applicationName;

    @Alias("xbooleanValue01")
    @ApiModelProperty("布尔值01")
    private Boolean booleanValue01;

    @Alias("xbooleanValue02")
    @ApiModelProperty("布尔值02")
    private Boolean booleanValue02;

    @Alias("xcompleted")
    @ApiModelProperty("是否完成")
    private Boolean completed;

    @Alias("xcompletedTime")
    @ApiModelProperty("完成时间")
    private LocalDateTime completedTime;

    @Alias("xcompletedTimeMonth")
    @ApiModelProperty("完成时间月份")
    private String completedTimeMonth;

    @Alias("xcreatorIdentity")
    @ApiModelProperty("创建者身份")
    private String creatorIdentity;

    @Alias("xcreatorPerson")
    @ApiModelProperty("创建者")
    private String creatorPerson;

    @Alias("xcreatorUnit")
    @ApiModelProperty("创建者单位")
    private String creatorUnit;

    @Alias("xcurrentActivityName")
    @ApiModelProperty("当前活动名称")
    private String currentActivityName;

    @Alias("xdateTimeValue01")
    @ApiModelProperty("日期时间值01")
    private LocalDateTime dateTimeValue01;

    @Alias("xdateTimeValue02")
    @ApiModelProperty("日期时间值02")
    private LocalDateTime dateTimeValue02;

    @Alias("xdateTimeValue03")
    @ApiModelProperty("日期时间值03")
    private LocalDateTime dateTimeValue03;

    @Alias("xdateTimeValue04")
    @ApiModelProperty("日期时间值04")
    private LocalDateTime dateTimeValue04;

    @Alias("xdateTimeValue05")
    @ApiModelProperty("日期时间值05")
    private LocalDateTime dateTimeValue05;

    @Alias("xdateValue01")
    @ApiModelProperty("日期值01")
    private LocalDate dateValue01;

    @Alias("xdateValue02")
    @ApiModelProperty("日期值02")
    private LocalDate dateValue02;

    @Alias("xdoubleValue01")
    @ApiModelProperty("双精度值01")
    private Double doubleValue01;

    @Alias("xdoubleValue02")
    @ApiModelProperty("双精度值02")
    private Double doubleValue02;

    @Alias("xdoubleValue03")
    @ApiModelProperty("双精度值03")
    private Double doubleValue03;

    @Alias("xdoubleValue04")
    @ApiModelProperty("双精度值04")
    private Double doubleValue04;

    @Alias("xdoubleValue05")
    @ApiModelProperty("双精度值05")
    private Double doubleValue05;

    @Alias("xjob")
    @ApiModelProperty("工作")
    private String job;

    @Alias("xlongValue01")
    @ApiModelProperty("长整数值01")
    private Long longValue01;

    @Alias("xlongValue02")
    @ApiModelProperty("长整数值02")
    private Long longValue02;

    @Alias("xlongValue03")
    @ApiModelProperty("长整数值03")
    private Long longValue03;

    @Alias("xlongValue04")
    @ApiModelProperty("长整数值04")
    private Long longValue04;

    @Alias("xlongValue05")
    @ApiModelProperty("长整数值05")
    private Long longValue05;

    @Alias("xpermissionWrite")
    @ApiModelProperty("写权限")
    private Boolean permissionWrite;

    @Alias("xperson")
    @ApiModelProperty("人员")
    private String person;

    @Alias("xprocess")
    @ApiModelProperty("流程")
    private String process;

    @Alias("xprocessAlias")
    @ApiModelProperty("流程别名")
    private String processAlias;

    @Alias("xprocessName")
    @ApiModelProperty("流程名称")
    private String processName;

    @Alias("xproperties")
    @ApiModelProperty("属性")
    private String properties;

    @Alias("xserial")
    @ApiModelProperty("序列号")
    private String serial;

    @Alias("xstartTime")
    @ApiModelProperty("开始时间")
    private LocalDateTime startTime;

    @Alias("xstartTimeMonth")
    @ApiModelProperty("开始时间月份")
    private String startTimeMonth;

    @Alias("xstringValue01")
    @ApiModelProperty("字符串值01")
    private String stringValue01;

    @Alias("xstringValue02")
    @ApiModelProperty("字符串值02")
    private String stringValue02;

    @Alias("xstringValue03")
    @ApiModelProperty("字符串值03")
    private String stringValue03;

    @Alias("xstringValue04")
    @ApiModelProperty("字符串值04")
    private String stringValue04;

    @Alias("xstringValue05")
    @ApiModelProperty("字符串值05")
    private String stringValue05;

    @Alias("xstringValue06")
    @ApiModelProperty("字符串值06")
    private String stringValue06;

    @Alias("xstringValue07")
    @ApiModelProperty("字符串值07")
    private String stringValue07;

    @Alias("xstringValue08")
    @ApiModelProperty("字符串值08")
    private String stringValue08;

    @Alias("xstringValue09")
    @ApiModelProperty("字符串值09")
    private String stringValue09;

    @Alias("xstringValue10")
    @ApiModelProperty("字符串值10")
    private String stringValue10;

    @Alias("xtimeValue01")
    @ApiModelProperty("时间值01")
    private LocalTime timeValue01;

    @Alias("xtimeValue02")
    @ApiModelProperty("时间值02")
    private LocalTime timeValue02;

    @Alias("xtitle")
    @ApiModelProperty("标题")
    private String title;

    @Alias("xwork")
    @ApiModelProperty("工作")
    private String work;

    @Alias("xworkCompleted")
    @ApiModelProperty("工作完成")
    private String workCompleted;

}