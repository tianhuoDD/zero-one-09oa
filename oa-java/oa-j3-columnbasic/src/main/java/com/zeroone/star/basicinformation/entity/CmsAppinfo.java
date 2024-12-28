package com.zeroone.star.basicinformation.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.*;

/**
 * <p>
 * 
 * </p>
 *
 */
@Builder
@Getter
@Setter
@TableName("cms_appinfo")
@NoArgsConstructor
@AllArgsConstructor
public class CmsAppinfo implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid",type = IdType.ASSIGN_ID)
    private String xid;

    @TableField(value = "xcreateTime")
    private LocalDateTime xcreateTime;

    @TableField(value = "xsequence")
    private String xsequence;

    @TableField(value = "xupdateTime")
    private LocalDateTime xupdateTime;

    @TableField(value = "xdistributeFactor")
    private Integer xdistributeFactor;

    @TableField(value = "xallPeoplePublish")
    private Boolean xallPeoplePublish;

    @TableField(value = "xallPeopleView")
    private Boolean xallPeopleView;

    @TableField(value = "xshowAllDocuments")
    private Boolean xshowAllDocuments;

    @TableField(value = "xanonymousAble")
    private Boolean xanonymousAble;

    @TableField(value = "xappAlias")
    private String xappAlias;

    @TableField(value = "xappIcon")
    private String xappIcon;

    @TableField(value = "xappInfoSeq")
    private String xappInfoSeq;

    @TableField(value = "xappMemo")
    private String xappMemo;

    @TableField(value = "xappName")
    private String xappName;

    @TableField(value = "xappType")
    private String xappType;

    @TableField(value = "xcreatorIdentity")
    private String xcreatorIdentity;

    @TableField(value = "xcreatorPerson")
    private String xcreatorPerson;

    @TableField(value = "xcreatorTopUnitName")
    private String xcreatorTopUnitName;

    @TableField(value = "xcreatorUnitName")
    private String xcreatorUnitName;

    @TableField(value = "xdefaultEditForm")
    private String xdefaultEditForm;

    @TableField(value = "xdefaultReadForm")
    private String xdefaultReadForm;

    @TableField(value = "xdescription")
    private String xdescription;

    @TableField(value = "xdocumentType")
    private String xdocumentType;

    @TableField(value = "xiconColor")
    private String xiconColor;

    @TableField(value = "xsendNotify")
    private Boolean xsendNotify;

    @TableField(exist = false)
    private CmsForm cmsForm;

    @TableField(exist = false)
    private String xeditName;

    @TableField(exist = false)
    private String xpublishName;


}
