package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 应用信息实体类，映射到数据库中的cms_appinfo表。
 */
@Data
@TableName("cms_appinfo")
public class CmsAppInfo {

    @TableId(value = "xid",type =IdType.ASSIGN_ID )//雪花算法生成ID
    private String xid; // 应用ID

    @TableField("xcreateTime")
    private LocalDateTime xcreateTime; // 创建时间

    @TableField("xsequence")
    private String xsequence; // 序列

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime; // 更新时间

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor; // 分发因子

    @TableField("xallPeoplePublish")
    private Boolean xallPeoplePublish; // 是否所有人可发布

    @TableField("xallPeopleView")
    private Boolean xallPeopleView; // 是否所有人可查看

    @TableField("xshowAllDocuments")
    private Boolean xshowAllDocuments; // 是否显示所有文档

    @TableField("xanonymousAble")
    private Boolean xanonymousAble; // 是否支持匿名

    @TableField("xappAlias")
    private String xappAlias; // 应用别名

    @TableField("xappIcon")
    private String xappIcon; // 应用图标

    @TableField("xappInfoSeq")
    private String xappInfoSeq; // 应用信息序列

    @TableField("xappMemo")
    private String xappMemo; // 应用备注

    @TableField("xappName")
    private String xappName; // 应用名称

    @TableField("xappType")
    private String xappType; // 应用类型

    @TableField("xcreatorIdentity")
    private String xcreatorIdentity; // 创建者身份

    @TableField("xcreatorPerson")
    private String xcreatorPerson; // 创建者姓名

    @TableField("xcreatorTopUnitName")
    private String xcreatorTopUnitName; // 创建者顶级单位名称

    @TableField("xcreatorUnitName")
    private String xcreatorUnitName; // 创建者单位名称

    @TableField("xdefaultEditForm")
    private String xdefaultEditForm; // 默认编辑表单

    @TableField("xdefaultReadForm")
    private String xdefaultReadForm; // 默认阅读表单

    @TableField("xdescription")
    private String xdescription; // 描述

    @TableField("xdocumentType")
    private String xdocumentType; // 文档类型

    @TableField("xiconColor")
    private String xiconColor; // 图标颜色

    @TableField("xsendNotify")
    private Boolean xsendNotify; // 是否发送通知
}