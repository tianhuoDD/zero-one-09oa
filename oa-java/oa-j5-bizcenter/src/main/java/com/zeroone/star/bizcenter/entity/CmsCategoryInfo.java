package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 分类信息实体类，映射到数据库中的cms_categoryinfo表。
 */
@Data
@TableName("cms_categoryinfo")
public class CmsCategoryInfo {

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

    @TableField("xallPeoplePublish")
    private Boolean xallPeoplePublish; // 是否所有人可发布

    @TableField("xallPeopleView")
    private Boolean xallPeopleView; // 是否所有人可查看

    @TableField("xanonymousAble")
    private Boolean xanonymousAble; // 是否支持匿名

    @TableField("xappId")
    private String xappId; // 应用ID

    @TableField("xappName")
    private String xappName; // 应用名称

    @TableField("xblankToAllNotify")
    private Boolean xblankToAllNotify; // 是否空白对所有人通知

    @TableField("xcategoryAlias")
    private String xcategoryAlias; // 分类别名

    @TableField("xcategoryIcon")
    private String xcategoryIcon; // 分类图标

    @TableField("xcategoryMemo")
    private String xcategoryMemo; // 分类备注

    @TableField("xcategoryName")
    private String xcategoryName; // 分类名称

    @TableField("xcategorySeq")
    private String xcategorySeq; // 分类序列

    @TableField("xcreatorIdentity")
    private String xcreatorIdentity; // 创建者身份

    @TableField("xcreatorPerson")
    private String xcreatorPerson; // 创建者姓名

    @TableField("xcreatorTopUnitName")
    private String xcreatorTopUnitName; // 创建者顶级单位名称

    @TableField("xcreatorUnitName")
    private String xcreatorUnitName; // 创建者单位名称

    @TableField("xdefaultViewId")
    private String xdefaultViewId; // 默认视图ID

    @TableField("xdefaultViewName")
    private String xdefaultViewName; // 默认视图名称

    @TableField("xdescription")
    private String xdescription; // 描述

    @TableField("xdocumentType")
    private String xdocumentType; // 文档类型

    @TableField("xformId")
    private String xformId; // 表单ID

    @TableField("xformName")
    private String xformName; // 表单名称

    @TableField("ximportViewAppId")
    private String ximportViewAppId; // 导入视图应用ID

    @TableField("ximportViewId")
    private String ximportViewId; // 导入视图ID

    @TableField("ximportViewName")
    private String ximportViewName; // 导入视图名称

    @TableField("xparentId")
    private String xparentId; // 父分类ID

    @TableField("xprojection")
    private String xprojection; // 投影

    @TableField("xreadFormId")
    private String xreadFormId; // 阅读表单ID

    @TableField("xreadFormName")
    private String xreadFormName; // 阅读表单名称

    @TableField("xsendNotify")
    private Boolean xsendNotify; // 是否发送通知

    @TableField("xworkflowAppId")
    private String xworkflowAppId; // 工作流应用ID

    @TableField("xworkflowAppName")
    private String xworkflowAppName; // 工作流应用名称

    @TableField("xworkflowFlag")
    private String xworkflowFlag; // 工作流标志

    @TableField("xworkflowName")
    private String xworkflowName; // 工作流名称

    @TableField("xworkflowType")
    private String xworkflowType; // 工作流类型
}