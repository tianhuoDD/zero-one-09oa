package com.zeroone.star.calmanager.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
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
@TableName("cal_event_repm")
public class CalEventRepm implements Serializable {

    private static final long serialVersionUID = 1L;
    @TableId
    private String xid;
    @TableField("xcreateTime")
    private LocalDateTime xcreateTime;

    private String xsequence;
    @TableField("xupdateTime")
    private LocalDateTime xupdateTime;
    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    private Boolean xalarm;
    @TableField("xalarmTime")
    private LocalDateTime xalarmTime;
    @TableField("xcalendarId")
    private String xcalendarId;

    private String xcolor;

    private String xcomment;
    @TableField("xcommentId")
    private String xcommentId;
    @TableField("xcreatePerson")
    private String xcreatePerson;
    @TableField("xdaysOfDuration")
    private Integer xdaysOfDuration;
    @TableField("xendTime")
    private LocalDateTime xendTime;
    @TableField("xeventType")
    private String xeventType;
    @TableField("xisAllDayEvent")
    private Boolean xisAllDayEvent;

    private Boolean xisPublic;

    private String xlatitude;
    @TableField("xlocationName")
    private String xlocationName;

    private String xlongitude;
    @TableField("xrecurrenceExc")
    private String xrecurrenceExc;
    @TableField("xrecurrenceRule")
    private String xrecurrenceRule;
    @TableField("xrecurrenceStartTime")
    private LocalDateTime xrecurrenceStartTime;
    @TableField("xrepeatStatus")
    private String xrepeatStatus;

    private String xsource;
    @TableField("xstartTime")
    private LocalDateTime xstartTime;
    @TableField("xtargetType")
    private String xtargetType;

    private String xtitle;
    @TableField("xupdatePerson")
    private String xupdatePerson;
    @TableField("xvalarmtimeConfig")
    private String xvalarmtimeConfig;
    @TableField("xvalarmSummary")
    private String xvalarmSummary;
    @TableField("xvalarmDescription")
    private String xvalarmDescription;
    @TableField("xvalarmMailto")
    private String xvalarmMailto;


}
