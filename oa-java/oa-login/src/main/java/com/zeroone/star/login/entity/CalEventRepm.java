package com.zeroone.star.login.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 
 * </p>
 *
 * @author han
 * @since 2024-10-23
 */
@Getter
@Setter
@TableName("cal_event_repm")
public class CalEventRepm implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private Boolean xalarm;

    private LocalDateTime xalarmTime;

    private String xcalendarId;

    private String xcolor;

    private String xcomment;

    private String xcommentId;

    private String xcreatePerson;

    private Integer xdaysOfDuration;

    private LocalDateTime xendTime;

    private String xeventType;

    private Boolean xisAllDayEvent;

    private Boolean xisPublic;

    private String xlatitude;

    private String xlocationName;

    private String xlongitude;

    private String xrecurrenceExc;

    private String xrecurrenceRule;

    private LocalDateTime xrecurrenceStartTime;

    private String xrepeatStatus;

    private String xsource;

    private LocalDateTime xstartTime;

    private String xtargetType;

    private String xtitle;

    private String xupdatePerson;

    private String xvalarmtimeConfig;

    private String xvalarmSummary;

    private String xvalarmDescription;

    private String xvalarmMailto;


}
