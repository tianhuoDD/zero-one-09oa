package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.KeySequence;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 *   与app信息相关的表的实体类
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-24
 */
@Getter
@Setter
@TableName("cms_appinfo")
public class CmsAppinfo implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private Boolean xallPeoplePublish;

    private Boolean xallPeopleView;

    private Boolean xshowAllDocuments;

    private Boolean xanonymousAble;

    private String xappAlias;

    private String xappIcon;

    private String xappInfoSeq;

    private String xappMemo;

    private String xappName;

    private String xappType;

    private String xcreatorIdentity;

    private String xcreatorPerson;

    private String xcreatorTopUnitName;

    private String xcreatorUnitName;

    private String xdefaultEditForm;

    private String xdefaultReadForm;

    private String xdescription;

    private String xdocumentType;

    private String xiconColor;

    private Boolean xsendNotify;


}
