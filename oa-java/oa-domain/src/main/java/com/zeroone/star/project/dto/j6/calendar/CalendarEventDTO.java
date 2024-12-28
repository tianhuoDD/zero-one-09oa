package com.zeroone.star.project.dto.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;
import java.util.Date;

/**
 * 日历日程操作对象
 */
@ApiModel("添加日程DTO")
@Data
public class CalendarEventDTO {
    /**
     *日程Id唯一标识
     */
    @ApiModelProperty(value = "唯一标识",example ="" )
    private String xid;
    /**
     *是否提醒
     */
    @ApiModelProperty(value = "是否提醒",example ="1" )
    private boolean xalarm;

    /**
     *当前日程提醒时间
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "当前日程提醒时间",example ="2024-12-19 23:55:00" )
    private Date xalarmTime;

    /**
     *当前日程对应的日历唯一标识id
     */
    @ApiModelProperty(value = "当前日程对应的日历唯一标识id",example ="eb5e2b97-5601-4c37-b890-4d8ffa7849d4" )
    private String xcalendarId;
    /**
     * 日程显示在日历上的颜色
     */
    @ApiModelProperty(value = "日程显示在日历上的颜色",example ="#1462be" )
    private String xcolor;
    /**
     * 日程中备注信息，（文本框的内容 <p></p>）
     */
    @ApiModelProperty(value = "日程中备注信息",example =" <p>21312312</p>" )
    private String xcomment;


    /**
     *日程持续天数
     */
    @ApiModelProperty(value = "日程持续天数",example ="1" )
    private int xdaysOfDuration;
    /**
     * 日程结束时间
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "日程结束时间",example ="2024-10-30 07:00:00" )
    private Date xendTime;

    /**
     *是否为全天日程
     */
    @ApiModelProperty(value = "是否为全天日程",example ="0" )
    private boolean xisAllDayEvent;
    /**
     *是否公开
     */
    @ApiModelProperty(value = "是否公开",example ="0" )
    private boolean xisPublic;

    /**
     *地点说明
     */
    @ApiModelProperty(value = "地点说明",example ="实验室" )
    private String xlocationName;

//    /**
//     *排除日期表达式RecurrenceExc (暂时不理解)
//     */
//    private String xrecurrenceExc;
    /**
     *重复日期表达式RecurrenceRule FREQ=MONTHLY 每月该日，都有此日程
     */
    @ApiModelProperty(value = "重复日期表达式RecurrenceRule ",example ="FREQ=MONTHLY" )
    private String xrecurrenceRule;

    /**
     *信息来源: PERSONAL| LEADER | UNIT | MEETING | BUSINESS_TRIP | HOLIDAY"
     */
    @ApiModelProperty(value = "信息来源: PERSONAL| LEADER | UNIT | MEETING | BUSINESS_TRIP | HOLIDAY ",example ="PERSONAL" )
    private String xsource;
    /**
     *日程开始时间
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "日程开始时间 ",example ="2024-10-30 08:00:00" )
    private Date xstartTime;

    /**
     *参与者类型：PERSON | UNIT | GROUP
     */
    @ApiModelProperty(value = "参与者类型：PERSON | UNIT | GROUP ",example ="PERSON" )
    private String xtargetType;
    /**
     *日程标题
     */
    @ApiModelProperty(value = "日程标题 ",example ="testadd1" )
    private String xtitle;

    /**
     提醒提配置：天, 时, 分, 秒  提醒提配置：天, 时, 分, 秒 例如 0 0 -5 0  开始前五分钟提醒
     */
    @ApiModelProperty(value = "提醒提配置 天, 时, 分, 秒  提醒提配置：天, 时, 分, 秒 例如 0 0 -5 0  开始前五分钟提醒",example ="0,0,-5,0" )
    private String xvalarmTime_config;
    /**
     *提醒显示标题
     */
    @ApiModelProperty(value = "提醒显示标题(暂时不用) ",example ="日程提醒" )
    private String xvalarm_Summary;
    /**
     *提醒备注信息
     */
    @ApiModelProperty(value = "提醒备注信息（暂时不用） ",example =" " )
    private String xvalarm_description;

}
