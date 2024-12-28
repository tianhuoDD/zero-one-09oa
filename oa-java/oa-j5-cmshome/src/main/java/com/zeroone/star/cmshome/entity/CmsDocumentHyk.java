package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.TableField;
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
 * @author hyk
 * @since 2024-10-29
 */
@Getter
@Setter
@TableName("cms_document")
public class CmsDocumentHyk implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private String xappAlias;

    private String xappId;

    private String xappName;

    private String xcategoryAlias;

    private String xcategoryId;

    private String xcategoryName;

    private Long xcommendCount;

    private Long xcommentCount;

    private String xcreatorIdentity;

    private String xcreatorPerson;

    private String xcreatorTopUnitName;

    private String xcreatorUnitName;

    private LocalDateTime xdateTimeValue01;

    private LocalDateTime xdateTimeValue02;

    private LocalDateTime xdateTimeValue03;



    private String xdocStatus;

    private String xdocumentType;

    private Double xdoubleValue01;

    private Double xdoubleValue02;

    private String xform;

    private String xformName;

    private Boolean xhasIndexPic;

    private String ximportBatchName;

    private String xindexPics;

    private Boolean xisAllRead;

    private Boolean xisTop;

    private Long xlongValue01;

    private Long xlongValue02;

    private LocalDateTime xmodifyTime;

    private Integer xobjectSecurityClearance;

    private String xppFormId;

    private String xproperties;

    private LocalDateTime xpublishTime;

    private String xreadFormId;

    private String xreadFormName;

    private Boolean xreviewed;

    private String xsequenceAppAlias;

    private String xsequenceCategoryAlias;

    private String xsequenceCreatorPerson;

    private String xsequenceCreatorUnitName;

    private String xsequenceTitle;

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

    private String xsummary;

    private String xtitle;

    private Long xviewCount;


    // 描述,表cms_appinfo
    @TableField(value = "xdescription")
    private String xdescription;

    // 创建部门org_unti
    @TableField(value = "xlevelName")
    private String xlevelName;

    // 创建人org_identity
    @TableField(value = "xname")
    private String xname;

    // 操作类型cms_log
    @TableField(value = "xoperationType")
    private String xoperationType;

}
