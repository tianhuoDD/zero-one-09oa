package com.zeroone.star.project.vo.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/*
获取日程详情返回的VO
 */
@ApiModel("获取日程详情显示对象")
@Data
public class EventDetailVO {
    /*
    日程id（主键）
     */
    @ApiModelProperty(value = "日程主键id", example = "1")
    private String xid;
    /*
    对应的日历id
     */
    @ApiModelProperty(value = "对应的日历id", example = "1")
    private String xcalendarId;
    /*
    日程标题
     */
    @ApiModelProperty(value = "日程标题", example = "测试案例")
    private String xtitle;
    /*
    日程开始时间
     */
    @ApiModelProperty(value = "日程开始时间", example = "2024-10-21 23:59:59")
    private LocalDateTime xstartTime;
    /*
    日程结束时间
     */
    @ApiModelProperty(value = "日程结束时间", example = "2024-10-22 23:59:59")
    private LocalDateTime xendTime;
    /*
    是否全天
     */
    @ApiModelProperty(value = "日程是否全天 是：1 否：0 ", example = "1")
    private Byte xisAllDayEvent;
    /*
    地点
     */
    @ApiModelProperty(value = "日程地点", example = "01星球")
    private String xlocationName;

    /*
    是否提醒
     */
    @ApiModelProperty(value = "是否设置提醒 是：1 否：0", example = "1")
    private Byte xalarm;

    /*
    如果提醒的话提醒时间是什么时候
     */
    @ApiModelProperty(value = "提醒时间", example = "2024-10-22 23:59:59")
    private LocalDateTime xalarmTime;

    /*
    日程是否重复 重复规则是什么
    案例表示每天重复，20241001T160000Z是指结束日期
     */
    @ApiModelProperty(value = "日程是否重复 如果重复 规则是什么", example = "FREQ=DAILY;UNTIL=20241001T160000Z")
    private String xrecurrenceRule;
    /*
    颜色
     */
    @ApiModelProperty(value = "日程颜色", example = "#1462be")
    private String xcolor;

    /*
    日程内容
     */
    @ApiModelProperty(value = "日程内容", example = "java测试oa项目")
    private String xcomment;
}
