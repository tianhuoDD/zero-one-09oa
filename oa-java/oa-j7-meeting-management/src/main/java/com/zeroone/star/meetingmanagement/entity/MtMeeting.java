package com.zeroone.star.meetingmanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.LocalTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author ydp
 * @since 2024-10-21
 */
@Getter
@Setter
@TableName("mt_meeting")
public class MtMeeting implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private LocalTime xactualCompletedTime;

    private LocalTime xactualStartTime;

    private String xapplicant;

    private String xauditor;

    private LocalDateTime xcompletedTime;

    private String xconfirmStatus;

    private String xdescription;

    private String xhostPerson;

    private String xhostUnit;

    private Boolean xmanualCompleted;

    private String xmemo;

    private String xmode;

    private String xpinyin;

    private String xpinyinInitial;

    private String xroom;

    private String xroomId;

    private String xroomLink;

    private LocalDateTime xstartTime;

    private String xsubject;

    private String xsummary;

    private String xtype;


}
