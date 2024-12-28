package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.Date;


@Data
public class PublishMessage implements Serializable {

    private MsgMessage message;

    private MsgInstant msgInstant;

    private CmsDocument cmsDocument;

    private CmsLog cmsLog;

    private CmsReview cmsReview;

    private QryItem qryItem;

    private OrgCustom orgCustom;

    private CmsDocumentViewRecord cmsDocumentViewRecord;
}

@Data
@TableName("cms_log")
 class CmsLog implements Serializable {

    private static final long serialVersionUID = 1L;

    private String xid; // 主键
    private Date xcreateTime; // 创建时间
    private String xsequence; // 序列号
    private Date xupdateTime; // 更新时间
    private Integer xdistributeFactor; // 分发因子
    private String xappId; // 应用ID
    private String xcategoryId; // 分类ID
    private String xdescription; // 描述
    private String xdocumentId; // 文档ID
    private String xfileId; // 文件ID
    private String xoperationLevel; // 操作级别
    private String xoperationType; // 操作类型
    private String xoperatorName; // 操作员姓名
    private String xoperatorUid; // 操作员UID
}
@Data
@TableName("cms_review")
class CmsReview implements Serializable {

    /**
     * 消息唯一标识
     * 示例: "123e4567-e89b-12d3-a456-426614174000"
     */
    private String xid;

    /**
     * 创建时间
     * 示例: "2024-10-27T15:56:41"
     */
    private LocalDateTime xcreateTime;

    /**
     * 序列号
     * 示例: "20241027155641abc123"
     */
    private String xsequence;

    /**
     * 更新时间
     * 示例: "2024-10-27T16:00:00"
     */
    private LocalDateTime xupdateTime;

    /**
     * 分发因子
     * 示例: 10
     */
    private Integer xdistributeFactor;

    /**
     * 应用别名
     * 示例: "myApp"
     */
    private String xappAlias;

    /**
     * 应用ID
     * 示例: "app-123456"
     */
    private String xappId;

    /**
     * 应用名称
     * 示例: "My Application"
     */
    private String xappName;

    /**
     * 类别别名
     * 示例: "重要通知"
     */
    private String xcategoryAlias;

    /**
     * 类别ID
     * 示例: "category-001"
     */
    private String xcategoryId;

    /**
     * 类别名称
     * 示例: "通知类别"
     */
    private String xcategoryName;

    /**
     * 创建者身份
     * 示例: "管理员"
     */
    private String xcreatorIdentity;

    /**
     * 创建者
     * 示例: "张三"
     */
    private String xcreatorPerson;

    /**
     * 创建者顶级单位名称
     * 示例: "公司总部"
     */
    private String xcreatorTopUnitName;

    /**
     * 创建者单位名称
     * 示例: "技术部"
     */
    private String xcreatorUnitName;

    /**
     * 文档创建时间
     * 示例: "2024-10-27T15:56:41"
     */
    private LocalDateTime xdocCreateTime;

    /**
     * 文档ID
     * 示例: "doc-789012"
     */
    private String xdocId;

    /**
     * 文档序列号
     * 示例: "seq-001"
     */
    private String xdocSequence;

    /**
     * 文档状态
     * 示例: "已发布"
     */
    private String xdocStatus;

    /**
     * 文档类型
     * 示例: "公告"
     */
    private String xdocumentType;

    /**
     * 权限对象
     * 示例: "user-123456"
     */
    private String xpermissionObj;

    /**
     * 权限对象类型
     * 示例: "用户"
     */
    private String xpermissionObjType;

    /**
     * 发布时间
     * 示例: "2024-10-27T16:00:00"
     */
    private LocalDateTime xpublishTime;

    /**
     * 标题
     * 示例: "系统维护通知"
     */
    private String xtitle;
}

@Data
@TableName("org_custom")
class OrgCustom implements Serializable {

    /**
     * 唯一标识
     * 示例: "76c920fd-eade-4afd-b1b4-c4b2c9515b6f"
     */
    private String xid;

    /**
     * 创建时间
     * 示例: "2024-10-27T15:56:41"
     */
    private LocalDateTime xcreateTime;

    /**
     * 序列号
     * 示例: "20241027155641abc123"
     */
    private String xsequence;

    /**
     * 更新时间
     * 示例: "2024-10-27T16:00:00"
     */
    private LocalDateTime xupdateTime;

    /**
     * 分发因子
     * 示例: 10
     */
    private Integer xdistributeFactor;

    /**
     * 数据内容
     * 示例: "这是一个包含多个信息的文本数据"
     */
    private String xdata;

    /**
     * 名称
     * 示例: "自定义组织"
     */
    private String xname;

    /**
     * 相关人员
     * 示例: "张三"
     */
    private String xperson;
}


/*@Data
@TableName("cms_document_viewrecord")
class CmsDocumentViewRecord implements Serializable {

    *//**
     * 唯一标识
     * 示例: "76c920fd-eade-4afd-b1b4-c4b2c9515b6f"
     *//*
    private String xid;

    *//**
     * 创建时间
     * 示例: "2024-10-27T15:56:41"
     *//*
    private LocalDateTime xcreateTime;

    *//**
     * 序列号
     * 示例: "20241027155641abc123"
     *//*
    private String xsequence;

    *//**
     * 更新时间
     * 示例: "2024-10-27T16:00:00"
     *//*
    private LocalDateTime xupdateTime;

    *//**
     * 分发因子
     * 示例: 10
     *//*
    private Integer xdistributeFactor;

    *//**
     * 应用ID
     * 示例: "app123"
     *//*
    private String xappId;

    *//**
     * 应用名称
     * 示例: "我的应用"
     *//*
    private String xappName;

    *//**
     * 类别ID
     * 示例: "cat123"
     *//*
    private String xcategoryId;

    *//**
     * 类别名称
     * 示例: "文档类别"
     *//*
    private String xcategoryName;

    *//**
     * 文档ID
     * 示例: "doc123"
     *//*
    private String xdocumentId;

    *//**
     * 最近查看时间
     * 示例: "2024-10-27T15:56:41"
     *//*
    private LocalDateTime xlastViewTime;

    *//**
     * 标题
     * 示例: "文档标题"
     *//*
    private String xtitle;

    *//**
     * 查看次数
     * 示例: 100
     *//*
    private Integer xviewCount;

    *//**
     * 查看者名称
     * 示例: "张三"
     *//*
    private String xviewerName;

    *//**
     * 查看者单位名称
     * 示例: "技术部"
     *//*
    private String xviewerUnitName;

    *//**
     * 查看者顶级单位名称
     * 示例: "公司总部"
     *//*
    private String xviewerTopUnitName;
}*/
