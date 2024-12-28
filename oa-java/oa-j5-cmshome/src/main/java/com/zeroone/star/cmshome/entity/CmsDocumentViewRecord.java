package com.zeroone.star.cmshome.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author 阿伟
 * @since 2024-10-31
 */
@Getter
@Setter
@TableName("cms_document_viewrecord")
public class CmsDocumentViewRecord implements Serializable {

    private static final long serialVersionUID = 1L;

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
     * 应用ID
     * 示例: "app123"
     */
    private String xappId;

    /**
     * 应用名称
     * 示例: "我的应用"
     */
    private String xappName;

    /**
     * 类别ID
     * 示例: "cat123"
     */
    private String xcategoryId;

    /**
     * 类别名称
     * 示例: "文档类别"
     */
    private String xcategoryName;

    /**
     * 文档ID
     * 示例: "doc123"
     */
    private String xdocumentId;

    /**
     * 最近查看时间
     * 示例: "2024-10-27T15:56:41"
     */
    private LocalDateTime xlastViewTime;

    /**
     * 标题
     * 示例: "文档标题"
     */
    private String xtitle;

    /**
     * 查看次数
     * 示例: 100
     */
    private Integer xviewCount;

    /**
     * 查看者名称
     * 示例: "张三"
     */
    private String xviewerName;

    /**
     * 查看者单位名称
     * 示例: "技术部"
     */
    private String xviewerUnitName;

    /**
     * 查看者顶级单位名称
     * 示例: "公司总部"
     */
    private String xviewerTopUnitName;


}
