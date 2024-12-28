package com.zeroone.star.systemhome.entity.file;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

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
@TableName("pp_c_read")
public class PpCRead implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xactivity;

    private String xactivityAlias;

    private String xactivityDescription;

    private String xactivityName;

    private String xactivityToken;

    private String xactivityType;

    private String xapplication;

    private String xapplicationAlias;

    private String xapplicationName;

    private Boolean xbooleanValue01;

    private Boolean xbooleanValue02;

    private Boolean xcompleted;

    private String xcreatorIdentity;

    private String xcreatorPerson;

    private String xcreatorUnit;

    private String xcurrentActivityName;

    private LocalDateTime xdateTimeValue01;

    private LocalDateTime xdateTimeValue02;

    private LocalDateTime xdateTimeValue03;

    private LocalDateTime xdateTimeValue04;

    private LocalDateTime xdateTimeValue05;

    private LocalDate xdateValue01;

    private LocalDate xdateValue02;

    private Double xdoubleValue01;

    private Double xdoubleValue02;

    private Double xdoubleValue03;

    private Double xdoubleValue04;

    private Double xdoubleValue05;

    private String xidentity;

    private String xjob;

    private Long xlongValue01;

    private Long xlongValue02;

    private Long xlongValue03;

    private Long xlongValue04;

    private Long xlongValue05;

    private String xopinion;

    private String xopinionLob;

    private String xperson;

    private String xprocess;

    private String xprocessAlias;

    private String xprocessName;

    private String xproperties;

    private String xserial;

    private LocalDateTime xstartTime;

    private String xstartTimeMonth;

    private String xstringValue01;

    private String xstringValue02;

    private String xstringValue03;

    private String xstringValue04;

    private String xstringValue05;

    private String xstringValue06;

    private String xstringValue07;

    private String xstringValue08;

    private String xstringValue09;

    private String xstringValue10;

    private LocalTime xtimeValue01;

    private LocalTime xtimeValue02;

    private String xtitle;

    private String xunit;

    private LocalDateTime xviewTime;

    private String xwork;

    private String xworkCompleted;


}
