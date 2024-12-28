package com.zeroone.star.calmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author lee
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("cal_event")
@ApiModel("日程DO")
public class CalEvent implements Serializable {

    private static final long serialVersionUID = 1L;
    /*
   日程id（主键）
    */
    @ApiModelProperty(value = "日程主键id", example = "1")
    @TableId(value = "xid",type = IdType.AUTO)
    private String xid;
    /*
    日程创建时间
     */
    @ApiModelProperty(value = "日程创建时间", example = "2024-10-21 23:59:59")
    @TableField(value = "xcreateTime")
    private LocalDateTime xcreateTime;
    @TableField(value = "xsequence")
    private String xsequence;
    /*
    日程更新时间
     */
    @ApiModelProperty(value = "日程更新时间", example = "2024-10-21 23:59:59")
    @TableField(value = "xupdateTime")
    private LocalDateTime xupdateTime;
    @TableField(value = "xdistributeFactor")
    private Integer xdistributeFactor;
    /*
    是否提醒
     */
    @ApiModelProperty(value = "是否设置提醒 是：true 否：false", example = "true")
    @TableField(value = "xalarm")
    private Boolean xalarm;

    @TableField(value = "xalarmAlready")
    private Boolean xalarmAlready;
    /*
    如果提醒的话提醒时间是什么时候
     */
    @ApiModelProperty(value = "提醒时间", example = "2024-10-22 23:59:59")
    @TableField(value = "xalarmTime")
    private LocalDateTime xalarmTime;
    @TableField(value = "xbundle")
    private String xbundle;
    /*
    对应的日历id
     */
    @ApiModelProperty(value = "对应的日历id", example = "1")
    @TableField(value = "xcalendarId")
    private String xcalendarId;
    /*
    颜色
     */
    @ApiModelProperty(value = "日程颜色", example = "#1462be")
    @TableField(value = "xcolor")
    private String xcolor;
    /*
    日程内容
     */
    @ApiModelProperty(value = "日程内容", example = "java测试oa项目")
    @TableField(value = "xcomment")
    private String xcomment;

    @TableField(value = "xcommentId")
    private String xcommentId;
    /*
    创建日程人的id
     */
    @ApiModelProperty(value = "创建日程人的id", example = "admin")
    @TableField(value = "xcreatePerson")
    private String xcreatePerson;
    /*
    日程持续时间（开始时间和结束时间一样为0，24小时内为1天）
     */
    @ApiModelProperty(value = "日程持续时间", example = "1")
    @TableField(value = "xdaysOfDuration")
    private Integer xdaysOfDuration;
    /*
    日程结束时间
     */
    @ApiModelProperty(value = "日程结束时间", example = "2024-10-22 23:59:59")
    @TableField(value = "xendTime")
    private LocalDateTime xendTime;
    /*
   日程结束时间字符串形式
    */
    @ApiModelProperty(value = "日程结束时间", example = "2024-10-22 23:59:59")
    @TableField(value = "xendTimeStr")
    private String xendTimeStr;
    /*
   日程类型
    */
    @ApiModelProperty(value = "日程类型", example = "CAL_EVENT")
    @TableField(value = "xeventType")
    private String xeventType;
    /*
   是否全天
    */
    @ApiModelProperty(value = "日程是否全天 是：true 否：false ", example = "true")
    @TableField(value = "xisAllDayEvent")
    private Boolean xisAllDayEvent;
    /*
    是否全天
    */
    @ApiModelProperty(value = "日程是否公开 是：true 否：false ", example = "true")
    @TableField(value = "xisPublic")
    private Boolean xisPublic;
    @TableField(value = "xlatitude")
    private String xlatitude;
    /*
    地点
     */

    @ApiModelProperty(value = "日程地点", example = "01星球")
    @TableField(value = "xlocationName")
    private String xlocationName;
    @TableField(value = "xlongitude")
    private String xlongitude;
    @TableField(value = "xrecurrenceExc")
    private String xrecurrenceExc;

    /*
    日程是否重复 重复规则是什么
    案例表示每天重复，20241001T160000Z是指结束日期
     */
    @ApiModelProperty(value = "日程是否重复 如果重复 规则是什么", example = "FREQ=DAILY;UNTIL=20241001T160000Z")
    @TableField(value = "xrecurrenceRule")
    private String xrecurrenceRule;
    @TableField(value = "xrepeatMasterId")
    private String xrepeatMasterId;
    @TableField(value = "xsource")
    private String xsource;
    /*
    日程开始时间
     */
    @ApiModelProperty(value = "日程开始时间", example = "2024-10-21 23:59:59")
    @TableField(value = "xstartTime")
    private LocalDateTime xstartTime;
    /*
    日程开始时间字符串
     */
    @ApiModelProperty(value = "日程开始时间字符串", example = "2024-10-21 23:59:59")
    @TableField(value = "xstartTimeStr")
    private String xstartTimeStr;
    @TableField(value = "xtargetType")
    private String xtargetType;
    /*
    日程标题
     */
    @ApiModelProperty(value = "日程标题", example = "测试案例")
    @TableField(value = "xtitle")
    private String xtitle;
    /*
    更新日程的人
     */

    @ApiModelProperty(value = "日程更新人", example = "admin")
    @TableField(value = "xupdatePerson")
    private String xupdatePerson;

    @TableField(value = "xvalarmTime_config")
    private String xvalarmtimeConfig;
    @TableField(value = "xvalarm_Summary")
    private String xvalarmSummary;
    @TableField(value = "xvalarm_description")
    private String xvalarmDescription;
    @TableField(value = "xvalarm_mailto")
    private String xvalarmMailto;


}
