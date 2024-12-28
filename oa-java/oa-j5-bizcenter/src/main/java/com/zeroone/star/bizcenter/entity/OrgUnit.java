package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 组织单位实体类
 */
@Data
@TableName("org_unit")
public class OrgUnit {

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

    @TableField("xandFxHash")
    private String xandFxHash; // AndFx系统的哈希值；

    @TableField("xandFxId")
    private String xandFxId; // AndFx系统的ID；

    @TableField("xdescription")
    private String xdescription; // 描述；

    @TableField("xdingdingHash")
    private String xdingdingHash; // 钉钉系统的哈希值；

    @TableField("xdingdingId")
    private String xdingdingId; // 钉钉系统的ID；

    @TableField("xdistinguishedName")
    private String xdistinguishedName; // LDAP中的唯一名称；

    @TableField("xlevel")
    private Integer xlevel; // 层级；

    @TableField("xlevelName")
    private String xlevelName; // 层级名称；

    @TableField("xlevelOrderNumber")
    private String xlevelOrderNumber; // 层级排序编号；

    @TableField("xname")
    private String xname; // 名称；

    @TableField("xorderNumber")
    private Integer xorderNumber; // 排序编号；

    @TableField("xpinyin")
    private String xpinyin; // 拼音；

    @TableField("xpinyinInitial")
    private String xpinyinInitial; // 拼音首字母；

    @TableField("xqiyeweixinHash")
    private String xqiyeweixinHash; // 企业微信的哈希值；

    @TableField("xqiyeweixinId")
    private String xqiyeweixinId; // 企业微信的ID；

    @TableField("xshortName")
    private String xshortName; // 简称；

    @TableField("xsuperior")
    private String xsuperior; // 上级单位ID；

    @TableField("xunique")
    private String xunique; // 唯一标识；

    @TableField("xweLinkHash")
    private String xweLinkHash; // WeLink系统的哈希值；

    @TableField("xweLinkId")
    private String xweLinkId; // WeLink系统的ID；

    @TableField("xzhengwuDingdingHash")
    private String xzhengwuDingdingHash; // 政务钉钉的哈希值；

    @TableField("xzhengwuDingdingId")
    private String xzhengwuDingdingId; // 政务钉钉的ID；

}