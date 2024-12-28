package com.zeroone.star.project.dto.j5.bizcenter;

import lombok.Data;
import java.time.LocalDateTime;

/**
 * @program: oa-java
 * @description: 待办实体类DTO
 * @author: hamhuo
 * @create: 2024-10-27
 **/
@Data
public class PpCTaskDTO {
    private static final long serialVersionUID = 1L;

    private String xid;
    private String xjob;
    private String xtitle;
    private LocalDateTime xstartTime;
    private String xstartTimeMonth;
    private String xwork;
    private String xapplication;
    private String xapplicationName;
    private String xapplicationAlias;
    private String xprocess;
    private String xprocessName;
    private String xprocessAlias;
    private String xserial;
    private String xperson;
    private String xidentity;
    private String xunit;
    private String xempowerFromIdentity;
    private String xactivity;
    private String xactivityName;
    private String xactivityAlias;
    private String xactivityDescription;
    private String xactivityType;
    private String xactivityToken;
    private String xcreatorPerson;
    private String xcreatorIdentity;
    private String xcreatorUnit;
    private Boolean xexpired;
    private Boolean xurged;
    private String xrouteName;
    private String xrouteAlias;
    private String xopinion;
    private Boolean xmodified;
    private LocalDateTime xviewTime;
    private Boolean xfirst;
    private String xproperties;
    private String xseries;
    private String xworkCreateType;
    private String xlabel;
    private String xdistinguishedName;
    private LocalDateTime xcreateTime;
    private LocalDateTime xupdateTime;
}
