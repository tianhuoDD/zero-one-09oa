package com.zeroone.star.orgmanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author zlw
 * @since 2024-10-18
 */
@Getter
@Setter
@TableName("org_person")

public class OrgPerson implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty("组织人员id")
    private String xid;

    @ApiModelProperty("组织人员id")
    private LocalDateTime xcreateTime;

    @ApiModelProperty("组织人员id")
    private String xsequence;

    @ApiModelProperty("组织人员id")
    private LocalDateTime xupdateTime;

    @ApiModelProperty("组织人员id")
    private Integer xdistributeFactor;

    @ApiModelProperty("组织人员id")
    private Integer xage;

    @ApiModelProperty("组织人员id")
    private String xandFxHash;

    @ApiModelProperty("组织人员id")
    private String xandFxId;

    @ApiModelProperty("组织人员id")
    private LocalDate xbirthday;

    @ApiModelProperty("组织人员id")
    private LocalDate xboardDate;

    @ApiModelProperty("组织人员id")
    private LocalDate xchangePasswordTime;

    @ApiModelProperty("组织人员id")
    private String xdescription;

    @ApiModelProperty("组织人员id")
    private String xdingdingHash;

    @ApiModelProperty("组织人员id")
    private String xdingdingId;

    @ApiModelProperty("组织人员id")
    private String xdistinguishedName;

    @ApiModelProperty("组织人员id")
    private String xemployee;

    @ApiModelProperty("组织人员id")
    private Integer xfailureCount;

    @ApiModelProperty("组织人员id")
    private LocalDateTime xfailureTime;

    @ApiModelProperty("组织人员id")
    private String xgenderType;

    @ApiModelProperty("组织人员id")
    private Boolean xhiddenMobile;

    @ApiModelProperty("组织人员id")
    private String xicon;

    @ApiModelProperty("组织人员id")
    private String xiconLdpi;

    @ApiModelProperty("组织人员id")
    private String xiconMdpi;

    @ApiModelProperty("组织人员id")
    private String xipAddress;

    @ApiModelProperty("组织人员id")
    private String xlanguage;

    @ApiModelProperty("组织人员id")
    private String xlastLoginAddress;

    @ApiModelProperty("组织人员id")
    private String xlastLoginClient;

    @ApiModelProperty("组织人员id")
    private LocalDateTime xlastLoginTime;

    @ApiModelProperty("组织人员id")
    private LocalDateTime xlockTime;

    @ApiModelProperty("组织人员id")
    private String xmail;

    @ApiModelProperty("组织人员id")
    private String xmobile;

    @ApiModelProperty("组织人员id")
    private String xmpwxopenId;

    @ApiModelProperty("组织人员id")
    private String xname;

    @ApiModelProperty("组织人员id")
    private String xnickName;

    @ApiModelProperty("组织人员id")
    private String xofficePhone;

    @ApiModelProperty("组织人员id")
    private String xopen1Id;

    @ApiModelProperty("组织人员id")
    private String xopen2Id;

    @ApiModelProperty("组织人员id")
    private String xopen3Id;

    @ApiModelProperty("组织人员id")
    private String xopen4Id;

    @ApiModelProperty("组织人员id")
    private String xopen5Id;

    @ApiModelProperty("组织人员id")
    private Integer xorderNumber;

    @ApiModelProperty("组织人员id")
    private String xpassword;

    @ApiModelProperty("组织人员id")
    private LocalDate xpasswordExpiredTime;

    @ApiModelProperty("组织人员id")
    private String xpinyin;

    @ApiModelProperty("组织人员id")
    private String xpinyinInitial;

    @ApiModelProperty("组织人员id")
    private String xqiyeweixinHash;

    @ApiModelProperty("组织人员id")
    private String xqiyeweixinId;

    @ApiModelProperty("组织人员id")
    private String xqq;

    @ApiModelProperty("组织人员id")
    private String xsignature;

    @ApiModelProperty("组织人员id")
    private String xstatus;

    @ApiModelProperty("组织人员id")
    private String xstatusDes;

    @ApiModelProperty("组织人员id")
    private Integer xsubjectSecurityClearance;

    @ApiModelProperty("组织人员id")
    private String xsuperior;

    @ApiModelProperty("组织人员id")
    private String xunique;

    @ApiModelProperty("组织人员id")
    private String xweLinkHash;

    @ApiModelProperty("组织人员id")
    private String xweLinkId;

    @ApiModelProperty("组织人员id")
    private String xweixin;

    @ApiModelProperty("组织人员id")
    private String xzhengwuDingdingHash;

    @ApiModelProperty("组织人员id")
    private String xzhengwuDingdingId;


}
