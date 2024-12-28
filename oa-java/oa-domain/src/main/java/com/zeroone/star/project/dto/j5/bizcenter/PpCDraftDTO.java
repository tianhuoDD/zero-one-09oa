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
public class PpCDraftDTO {

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xapplication;

    private String xapplicationAlias;

    private String xapplicationName;

    private String xidentity;

    private String xperson;

    private String xprocess;

    private String xprocessAlias;

    private String xprocessName;

    private String xproperties;

    private String xtitle;

    private String xunit;
}
