package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author yuanzijie
 * @since 2024-10-28
 */
@Getter
@Setter
@TableName("org_person")
public class OrgPerson implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "xid", type = IdType.ASSIGN_ID)
    private String xid;

    private LocalDateTime xcreateTime;

    private String xsequence;

    private LocalDateTime xupdateTime;

    private Integer xdistributeFactor;

    private Integer xage;

    private String xandFxHash;

    private String xandFxId;

    private LocalDate xbirthday;

    private LocalDate xboardDate;

    private LocalDate xchangePasswordTime;

    private String xdescription;

    private String xdingdingHash;

    private String xdingdingId;

    private String xdistinguishedName;

    private String xemployee;

    private Integer xfailureCount;

    private LocalDateTime xfailureTime;

    private String xgenderType;

    private Boolean xhiddenMobile;

    private String xicon;

    private String xiconLdpi;

    private String xiconMdpi;

    private String xipAddress;

    private String xlanguage;

    private String xlastLoginAddress;

    private String xlastLoginClient;

    private LocalDateTime xlastLoginTime;

    private LocalDateTime xlockTime;

    private String xmail;

    private String xmobile;

    private String xmpwxopenId;

    private String xname;

    private String xnickName;

    private String xofficePhone;

    private String xopen1Id;

    private String xopen2Id;

    private String xopen3Id;

    private String xopen4Id;

    private String xopen5Id;

    private Integer xorderNumber;

    private String xpassword;

    private LocalDate xpasswordExpiredTime;

    private String xpinyin;

    private String xpinyinInitial;

    private String xqiyeweixinHash;

    private String xqiyeweixinId;

    private String xqq;

    private String xsignature;

    private String xstatus;

    private String xstatusDes;

    private Integer xsubjectSecurityClearance;

    private String xsuperior;

    private String xunique;

    private String xweLinkHash;

    private String xweLinkId;

    private String xweixin;

    private String xzhengwuDingdingHash;

    private String xzhengwuDingdingId;


}
