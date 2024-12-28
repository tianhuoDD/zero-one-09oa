package com.zeroone.star.project.dto.j6.calendar;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.io.Serializable;
import java.time.LocalDateTime;

@Data
@ApiModel("修改日程详情DTO")
@AllArgsConstructor
@NoArgsConstructor
public class EventDetailDTO {
    /*
   日程id（主键）
    */
    @ApiModelProperty(value = "日程主键id", example = "00916be8-6232-4614-93e1-9ec0d0745576")
    private String xid;
    /*
    对应的日历id
     */
    @ApiModelProperty(value = "对应的日历id", example = "9d62965b-4482-429e-ad03-c278c80f2ea5")
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
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(shape = JsonFormat.Shape.STRING, pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xstartTime;
    /*
    日程结束时间
     */
    @ApiModelProperty(value = "日程结束时间", example = "2024-10-22 23:59:59")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(shape = JsonFormat.Shape.STRING, pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xendTime;
    /*
    是否全天
     */
    @ApiModelProperty(value = "日程是否全天 是：1 否：0 ", example = "1")
    private Boolean xisAllDayEvent;
    /*
    地点
     */
    @ApiModelProperty(value = "日程地点", example = "01星球")
    private String xlocationName;

    /*
    是否提醒
     */
    @ApiModelProperty(value = "是否设置提醒 是：1 否：0", example = "1")
    private Boolean xalarm;

    /*
    如果提醒的话提醒时间是什么时候
     */
    @ApiModelProperty(value = "提醒时间", example = "2024-10-22 23:59:59")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(shape = JsonFormat.Shape.STRING, pattern = "yyyy-MM-dd HH:mm:ss")
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
