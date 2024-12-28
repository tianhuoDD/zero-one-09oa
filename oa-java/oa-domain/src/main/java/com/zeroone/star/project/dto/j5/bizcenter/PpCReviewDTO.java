package com.zeroone.star.project.dto.j5.bizcenter;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;


/**
 * @program: oa-java
 * @description: 精简后的参阅实体类
 * @author: hamhuo
 * @create: 2024-10-28 18:18
 **/


@Getter
@Setter
public class PpCReviewDTO implements Serializable {


    private String xid;
    private String xjob;
    private String xwork;
    private String xworkCompleted;
    private Boolean xcompleted;
    private String xtitle;
    private String xserial;
    private LocalDateTime xstartTime;
    private String xstartTimeMonth;
    private String xcompletedTimeMonth;
    private String xapplication;
    private String xapplicationName;
    private String xapplicationAlias;
    private String xprocess;
    private String xprocessName;
    private String xprocessAlias;
    private String xperson;
    private String xcreatorPerson;
    private String xcreatorIdentity;
    private String xcreatorUnit;
    private Boolean xpermissionWrite;
    private String xproperties;
    private LocalDateTime xcreateTime;
    private LocalDateTime xupdateTime;

}

