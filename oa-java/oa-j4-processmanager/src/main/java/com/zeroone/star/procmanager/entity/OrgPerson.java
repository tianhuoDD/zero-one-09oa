package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * <p>
 *  成员do
 * </p>
 *
 * @author nefertari
 * @since 2024-10-22
 */
@Getter
@Setter
@TableName("org_person")
public class OrgPerson implements Serializable {

    private static final long serialVersionUID = 1L;
    /**
     * 唯一标识
     */
    @TableId(value = "xid",type = IdType.ASSIGN_ID)
    private String xid;
    /**
     * 创建时间
     */
    private LocalDateTime xcreateTime;
    /**
     *序列号
     */
    private String xsequence;
    /**
     * 更新时间
     */
    private LocalDateTime xupdateTime;
    /**
     * 分配因素
     */
    private Integer xdistributeFactor;
    /**
     *年龄
     */
    private Integer xage;
    /**
     *Fx哈希值
     */
    private String xandFxHash;
    /**
     *Fx的id
     */
    private String xandFxId;
    /**
     *生日
     */
    private LocalDate xbirthday;
    /**
     *董事会的日期
     */
    private LocalDate xboardDate;
    /**
     *上次更改密码的时间
     */
    private LocalDate xchangePasswordTime;
    /**
     *对某项功能的描述描述
     */
    private String xdescription;
    /**
     *钉钉的哈希值
     */
    private String xdingdingHash;
    /**
     *钉钉的id
     */
    private String xdingdingId;
    /**
     *区别名
     */
    private String xdistinguishedName;
    /**
     *员工
     */
    private String xemployee;
    /**
     *失败次数
     */
    private Integer xfailureCount;
    /**
     *上次失败的时间
     */
    private LocalDateTime xfailureTime;
    /**
     *性别类型
     */
    private String xgenderType;
    /**
     *隐藏的设备
     */
    private Boolean xhiddenMobile;
    /**
     *头像
     */
    private String xicon;
    /**
     *头像的高分辨率
     */
    private String xiconLdpi;
    /**
     *头像的中分辨率
     */
    private String xiconMdpi;
    /**
     *id地址
     */
    private String xipAddress;
    /**
     *语言
     */
    private String xlanguage;
    /**
     *上次登录的地址
     */
    private String xlastLoginAddress;
    /**
     *上传登录的客户端
     */
    private String xlastLoginClient;
    /**
     *上次登录的时间
     */
    private LocalDateTime xlastLoginTime;
    /**
     *上锁的时间
     */
    private LocalDateTime xlockTime;
    /**
     *邮箱
     */
    private String xmail;
    /**
     *移动设备
     */
    private String xmobile;
    /**
     *mpwx标识符
     */
    private String xmpwxopenId;
    /**
     *姓名
     */
    private String xname;
    /**
     *昵称
     */
    private String xnickName;
    /**
     *办公室电话
     */
    private String xofficePhone;
    /**
     *标识符1
     */
    private String xopen1Id;
    /**
     *标识符2
     */
    private String xopen2Id;
    /**
     *标识符3
     */
    private String xopen3Id;
    /**
     *标识符4
     */
    private String xopen4Id;
    /**
     *标识符5
     */
    private String xopen5Id;
    /**
     *订单号
     */
    private Integer xorderNumber;
    /**
     *密码
     */
    private String xpassword;
    /**
     *上次校验密码的时间
     */
    private LocalDate xpasswordExpiredTime;
    /**
     *拼音
     */
    private String xpinyin;
    /**
     *初始化拼音
     */
    private String xpinyinInitial;
    /**
     *企业微信哈希值
     */
    private String xqiyeweixinHash;
    /**
     *企业微信id
     */
    private String xqiyeweixinId;
    /**
     *QQ号
     */
    private String xqq;
    /**
     *标识
     */
    private String xsignature;
    /**
     *状态
     */
    private String xstatus;
    /**
     *状态说明
     */
    private String xstatusDes;
    /**
     *主题安全许可
     */
    private Integer xsubjectSecurityClearance;
    /**
     *上级标识
     */
    private String xsuperior;
    /**
     *唯一标识
     */
    private String xunique;
    /**
     *weLink的哈希值
     */
    private String xweLinkHash;
    /**
     *weLink的id值
     */
    private String xweLinkId;
    /**
     *微信号
     */
    private String xweixin;
    /**
     *政务钉钉的哈希值
     */
    private String xzhengwuDingdingHash;
    /**
     *政务钉钉的id
     */
    private String xzhengwuDingdingId;

    @Override
    public String toString() {
        return "OrgPerson{" +
                "xid='" + xid + '\'' +
                ", xcreateTime=" + xcreateTime +
                ", xsequence='" + xsequence + '\'' +
                ", xupdateTime=" + xupdateTime +
                ", xdistributeFactor=" + xdistributeFactor +
                ", xage=" + xage +
                ", xandFxHash='" + xandFxHash + '\'' +
                ", xandFxId='" + xandFxId + '\'' +
                ", xbirthday=" + xbirthday +
                ", xboardDate=" + xboardDate +
                ", xchangePasswordTime=" + xchangePasswordTime +
                ", xdescription='" + xdescription + '\'' +
                ", xdingdingHash='" + xdingdingHash + '\'' +
                ", xdingdingId='" + xdingdingId + '\'' +
                ", xdistinguishedName='" + xdistinguishedName + '\'' +
                ", xemployee='" + xemployee + '\'' +
                ", xfailureCount=" + xfailureCount +
                ", xfailureTime=" + xfailureTime +
                ", xgenderType='" + xgenderType + '\'' +
                ", xhiddenMobile=" + xhiddenMobile +
                ", xicon='" + xicon + '\'' +
                ", xiconLdpi='" + xiconLdpi + '\'' +
                ", xiconMdpi='" + xiconMdpi + '\'' +
                ", xipAddress='" + xipAddress + '\'' +
                ", xlanguage='" + xlanguage + '\'' +
                ", xlastLoginAddress='" + xlastLoginAddress + '\'' +
                ", xlastLoginClient='" + xlastLoginClient + '\'' +
                ", xlastLoginTime=" + xlastLoginTime +
                ", xlockTime=" + xlockTime +
                ", xmail='" + xmail + '\'' +
                ", xmobile='" + xmobile + '\'' +
                ", xmpwxopenId='" + xmpwxopenId + '\'' +
                ", xname='" + xname + '\'' +
                ", xnickName='" + xnickName + '\'' +
                ", xofficePhone='" + xofficePhone + '\'' +
                ", xopen1Id='" + xopen1Id + '\'' +
                ", xopen2Id='" + xopen2Id + '\'' +
                ", xopen3Id='" + xopen3Id + '\'' +
                ", xopen4Id='" + xopen4Id + '\'' +
                ", xopen5Id='" + xopen5Id + '\'' +
                ", xorderNumber=" + xorderNumber +
                ", xpassword='" + xpassword + '\'' +
                ", xpasswordExpiredTime=" + xpasswordExpiredTime +
                ", xpinyin='" + xpinyin + '\'' +
                ", xpinyinInitial='" + xpinyinInitial + '\'' +
                ", xqiyeweixinHash='" + xqiyeweixinHash + '\'' +
                ", xqiyeweixinId='" + xqiyeweixinId + '\'' +
                ", xqq='" + xqq + '\'' +
                ", xsignature='" + xsignature + '\'' +
                ", xstatus='" + xstatus + '\'' +
                ", xstatusDes='" + xstatusDes + '\'' +
                ", xsubjectSecurityClearance=" + xsubjectSecurityClearance +
                ", xsuperior='" + xsuperior + '\'' +
                ", xunique='" + xunique + '\'' +
                ", xweLinkHash='" + xweLinkHash + '\'' +
                ", xweLinkId='" + xweLinkId + '\'' +
                ", xweixin='" + xweixin + '\'' +
                ", xzhengwuDingdingHash='" + xzhengwuDingdingHash + '\'' +
                ", xzhengwuDingdingId='" + xzhengwuDingdingId + '\'' +
                '}';
    }
}
