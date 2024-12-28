package com.zeroone.star.project.dto.j5.bizcenter;

import lombok.Data;

import java.time.LocalDateTime;

/**
 * @program: oa-java
 * @description: 流程列表-待阅实体类
 * @author: hamhuo
 * @create: 2024-10-29 15:50
 **/

@Data
public class PpCReadDTO {
    private String xid;
    private String xjob;
    private String xwork;
    private Boolean xcompleted;
    private String xtitle;
    private LocalDateTime xstartTime;
    private String xstartTimeMonth;
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
    private String xactivity;
    private String xactivityName;
    private String xactivityAlias;
    private String xactivityDescription;
    private String xactivityType;
    private String xactivityToken;
    private String xcreatorPerson;
    private String xcreatorIdentity;
    private String xcreatorUnit;
    private String xcurrentActivityName;
    private LocalDateTime xcreateTime;
    private LocalDateTime xupdateTime;
}
