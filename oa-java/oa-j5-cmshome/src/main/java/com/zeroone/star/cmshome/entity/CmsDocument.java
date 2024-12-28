package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
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
 * @author yuanzijie
 * @since 2024-10-24
 */
@Getter
@Setter
@TableName("cms_document")
public class CmsDocument implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    @TableField("xcreateTime")
    private LocalDateTime xcreateTime;

    @TableField("xsequence")
    private String xsequence;

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime;

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor;

    @TableField("xappAlias")
    private String xappAlias;

    @TableField("xappId")
    private String xappId;

    @TableField("xappName")
    private String xappName;

    @TableField("xcategoryAlias")
    private String xcategoryAlias;

    @TableField("xcategoryId")
    private String xcategoryId;

    @TableField("xcategoryName")
    private String xcategoryName;

    @TableField("xcommendCount")
    private Long xcommendCount;

    @TableField("xcommentCount")
    private Long xcommentCount;

    @TableField("xcreatorIdentity")
    private String xcreatorIdentity;

    @TableField("xcreatorPerson")
    private String xcreatorPerson;

    @TableField("xcreatorTopUnitName")
    private String xcreatorTopUnitName;

    @TableField("xcreatorUnitName")
    private String xcreatorUnitName;

    @TableField("xdateTimeValue01")
    private LocalDateTime xdateTimeValue01;

    @TableField("xdateTimeValue02")
    private LocalDateTime xdateTimeValue02;

    @TableField("xdateTimeValue03")
    private LocalDateTime xdateTimeValue03;

    @TableField("xdescription")
    private String xdescription;

    @TableField("xdocStatus")
    private String xdocStatus;

    @TableField("xdocumentType")
    private String xdocumentType;

    @TableField("xdoubleValue01")
    private Double xdoubleValue01;

    @TableField("xdoubleValue02")
    private Double xdoubleValue02;

    @TableField("xform")
    private String xform;

    @TableField("xformName")
    private String xformName;

    @TableField("xhasIndexPic")
    private Boolean xhasIndexPic;

    @TableField("ximportBatchName")
    private String ximportBatchName;

    @TableField("xindexPics")
    private String xindexPics;

    @TableField("xisAllRead")
    private Boolean xisAllRead;

    @TableField("xisTop")
    private Boolean xisTop;

    @TableField("xlongValue01")
    private Long xlongValue01;

    @TableField("xlongValue02")
    private Long xlongValue02;

    @TableField("xmodifyTime")
    private LocalDateTime xmodifyTime;

    @TableField("xobjectSecurityClearance")
    private Integer xobjectSecurityClearance;

    @TableField("xppFormId")
    private String xppFormId;

    @TableField("xproperties")
    private String xproperties;

    @TableField("xpublishTime")
    private LocalDateTime xpublishTime;

    @TableField("xreadFormId")
    private String xreadFormId;

    @TableField("xreadFormName")
    private String xreadFormName;

    @TableField("xreviewed")
    private Boolean xreviewed;

    @TableField("xsequenceAppAlias")
    private String xsequenceAppAlias;

    @TableField("xsequenceCategoryAlias")
    private String xsequenceCategoryAlias;

    @TableField("xsequenceCreatorPerson")
    private String xsequenceCreatorPerson;

    @TableField("xsequenceCreatorUnitName")
    private String xsequenceCreatorUnitName;

    @TableField("xsequenceTitle")
    private String xsequenceTitle;

    @TableField("xstringValue01")
    private String xstringValue01;

    @TableField("xstringValue02")
    private String xstringValue02;

    @TableField("xstringValue03")
    private String xstringValue03;

    @TableField("xstringValue04")
    private String xstringValue04;

    @TableField("xstringValue05")
    private String xstringValue05;

    @TableField("xstringValue06")
    private String xstringValue06;

    @TableField("xstringValue07")
    private String xstringValue07;

    @TableField("xstringValue08")
    private String xstringValue08;

    @TableField("xstringValue09")
    private String xstringValue09;

    @TableField("xstringValue10")
    private String xstringValue10;

    @TableField("xsummary")
    private String xsummary;

    @TableField("xtitle")
    private String xtitle;

    @TableField("xviewCount")
    private Long xviewCount;
}
