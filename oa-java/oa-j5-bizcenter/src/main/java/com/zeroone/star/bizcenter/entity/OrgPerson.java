package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 组织人员实体类
 */
@Data
@TableName("org_person")
public class OrgPerson {

    @TableId(value = "xid",type =IdType.ASSIGN_ID )//雪花算法生成ID
    private String xid; // 主键ID；

    @TableField("xcreateTime")
    private LocalDateTime xcreateTime; // 创建时间；

    @TableField("xsequence")
    private String xsequence; // 序列；

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime; // 更新时间；

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor; // 分发因子；

    @TableField("xage")
    private Integer xage; // 年龄；

    @TableField("xandFxHash")
    private String xandFxHash; // AndFx系统的哈希值；

    @TableField("xandFxId")
    private String xandFxId; // AndFx系统的ID；

    @TableField("xbirthday")
    private LocalDateTime xbirthday; // 出生日期；

    @TableField("xboardDate")
    private LocalDateTime xboardDate; // 入职日期；

    @TableField("xchangePasswordTime")
    private LocalDateTime xchangePasswordTime; // 最后修改密码时间；

    @TableField("xdescription")
    private String xdescription; // 描述；

    @TableField("xdingdingHash")
    private String xdingdingHash; // 钉钉系统的哈希值；

    @TableField("xdingdingId")
    private String xdingdingId; // 钉钉系统的ID；

    @TableField("xdistinguishedName")
    private String xdistinguishedName; // LDAP中的唯一名称；

    @TableField("xemployee")
    private String xemployee; // 员工编号；

    @TableField("xfailureCount")
    private Integer xfailureCount; // 登录失败次数；

    @TableField("xfailureTime")
    private LocalDateTime xfailureTime; // 登录失败时间；

    @TableField("xgenderType")
    private String xgenderType; // 性别类型；

    @TableField("xhiddenMobile")
    private Boolean xhiddenMobile; // 是否隐藏手机号码；

    @TableField("xicon")
    private String xicon; // 头像；

    @TableField("xiconLdpi")
    private String xiconLdpi; // 低分辨率头像；

    @TableField("xiconMdpi")
    private String xiconMdpi; // 中分辨率头像；

    @TableField("xipAddress")
    private String xipAddress; // IP地址；

    @TableField("xlanguage")
    private String xlanguage; // 语言；

    @TableField("xlastLoginAddress")
    private String xlastLoginAddress; // 最后登录地址；

    @TableField("xlastLoginClient")
    private String xlastLoginClient; // 最后登录客户端；

    @TableField("xlastLoginTime")
    private LocalDateTime xlastLoginTime; // 最后登录时间；

    @TableField("xlockTime")
    private LocalDateTime xlockTime; // 账户锁定时间；

    @TableField("xmail")
    private String xmail; // 邮件地址；

    @TableField("xmobile")
    private String xmobile; // 手机号码；

    @TableField("xmpwxopenId")
    private String xmpwxopenId; // 微信公众平台开放ID；

    @TableField("xname")
    private String xname; // 姓名；

    @TableField("xnickName")
    private String xnickName; // 昵称；

    @TableField("xofficePhone")
    private String xofficePhone; // 办公电话；

    @TableField("xopen1Id")
    private String xopen1Id; // 第三方开放ID 1；

    @TableField("xopen2Id")
    private String xopen2Id; // 第三方开放ID 2；

    @TableField("xopen3Id")
    private String xopen3Id; // 第三方开放ID 3；

    @TableField("xopen4Id")
    private String xopen4Id; // 第三方开放ID 4；

    @TableField("xopen5Id")
    private String xopen5Id; // 第三方开放ID 5；

    @TableField("xorderNumber")
    private Integer xorderNumber; // 排序编号；

    @TableField("xpassword")
    private String xpassword; // 密码；

    @TableField("xpasswordExpiredTime")
    private LocalDateTime xpasswordExpiredTime; // 密码过期时间；

    @TableField("xpinyin")
    private String xpinyin; // 拼音；

    @TableField("xpinyinInitial")
    private String xpinyinInitial; // 拼音首字母；

    @TableField("xqiyeweixinHash")
    private String xqiyeweixinHash; // 企业微信的哈希值；

    @TableField("xqiyeweixinId")
    private String xqiyeweixinId; // 企业微信的ID；

    @TableField("xqq")
    private String xqq; // QQ号码；

    @TableField("xsignature")
    private String xsignature; // 签名；

    @TableField("xstatus")
    private String xstatus; // 状态；

    @TableField("xstatusDes")
    private String xstatusDes; // 状态描述；

    @TableField("xsubjectSecurityClearance")
    private Integer xsubjectSecurityClearance; // 安全审查等级；

    @TableField("xsuperior")
    private String xsuperior; // 上级ID；

    @TableField("xunique")
    private String xunique; // 唯一标识；

    @TableField("xweLinkHash")
    private String xweLinkHash; // WeLink系统的哈希值；

    @TableField("xweLinkId")
    private String xweLinkId; // WeLink系统的ID；

    @TableField("xweixin")
    private String xweixin; // 微信号码；

    @TableField("xzhengwuDingdingHash")
    private String xzhengwuDingdingHash; // 政务钉钉的哈希值；

    @TableField("xzhengwuDingdingId")
    private String xzhengwuDingdingId; // 政务钉钉的ID；

}