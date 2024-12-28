package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 身份实体
 */
@Data
@TableName("org_identity")
public class OrgIdentity {

    @TableId(value = "xid",type =IdType.ASSIGN_ID )//雪花算法生成ID
    private String xid; // 主键ID

    @TableField("xcreateTime")
    private LocalDateTime xcreateTime; // 创建时间

    @TableField("xsequence")
    private String xsequence; // 序列

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime; // 更新时间

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor; // 分发因子

    @TableField("xdescription")
    private String xdescription; // 身份描述

    @TableField("xdistinguishedName")
    private String xdistinguishedName; // 唯一名称

    @TableField("xmajor")
    private Boolean xmajor; // 是否主要身份

    @TableField("xname")
    private String xname; // 身份名称

    @TableField("xorderNumber")
    private Integer xorderNumber; // 排序编号

    @TableField("xperson")
    private String xperson; // 关联的个人ID

    @TableField("xpinyin")
    private String xpinyin; // 名称的拼音

    @TableField("xpinyinInitial")
    private String xpinyinInitial; // 名称的拼音首字母

    @TableField("xunique")
    private String xunique; // 唯一标识

    @TableField("xunit")
    private String xunit; // 关联的单位ID

    @TableField("xunitLevel")
    private Integer xunitLevel; // 单位级别

    @TableField("xunitLevelName")
    private String xunitLevelName; // 单位级别名称

    @TableField("xunitName")
    private String xunitName; // 关联的单位名称

}