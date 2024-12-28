package com.zeroone.star.bizcenter.entity;

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
 * @author xiongjian
 * @since 2024-10-29
 */
@Getter
@Setter
@TableName("pp_c_attachment")
public class PpCAttachment implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xencryptKey;

    private String xactivity;

    private String xactivityName;

    private String xactivityToken;

    private String xactivityType;

    private String xapplication;

    private Boolean xcompleted;

    private Boolean xdeepPath;

    private String xextension;

    private String xfromId;

    private String xfromJob;

    private String xfromPath;

    private String xjob;

    private String xlastUpdatePerson;

    private LocalDateTime xlastUpdateTime;

    private Long xlength;

    private String xname;

    private Integer xobjectSecurityClearance;

    private Integer xorderNumber;

    private String xperson;

    private String xprocess;

    private String xproperties;

    private String xsite;

    private String xstorage;

    private String xstringValue01;

    private String xstringValue02;

    private String xstringValue03;

    private String xtext;

    private String xtype;

    private String xwork;

    private String xworkCompleted;

    private LocalDateTime xworkCreateTime;


}
