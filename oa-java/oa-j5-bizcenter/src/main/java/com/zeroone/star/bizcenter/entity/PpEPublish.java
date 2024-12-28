package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示电子出版物的相关信息。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_publish")
public class PpEPublish implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识符
     */
    private String xid;

    /**
     * 创建时间
     */
    private LocalDateTime xcreateTime;

    /**
     * 序列号
     */
    private String xsequence;

    /**
     * 更新时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 分发因子
     */
    private Integer xdistributeFactor;

    /**
     * 到达后脚本
     */
    private String xafterArriveScript;

    /**
     * 到达后脚本文本
     */
    private String xafterArriveScriptText;

    /**
     * 执行后脚本
     */
    private String xafterExecuteScript;

    /**
     * 执行后脚本文本
     */
    private String xafterExecuteScriptText;

    /**
     * 查询后脚本
     */
    private String xafterInquireScript;

    /**
     * 查询后脚本文本
     */
    private String xafterInquireScriptText;

    /**
     * 别名
     */
    private String xalias;

    /**
     * 是否允许重新路由
     */
    private Boolean xallowReroute;

    /**
     * 是否允许作为重新路由的目标
     */
    private Boolean xallowRerouteTo;

    /**
     * 作者数据路径列表
     */
    private String xauthorDataPathList;

    /**
     * 到达前脚本
     */
    private String xbeforeArriveScript;

    /**
     * 到达前脚本文本
     */
    private String xbeforeArriveScriptText;

    /**
     * 执行前脚本
     */
    private String xbeforeExecuteScript;

    /**
     * 执行前脚本文本
     */
    private String xbeforeExecuteScriptText;

    /**
     * 查询前脚本
     */
    private String xbeforeInquireScript;

    /**
     * 查询前脚本文本
     */
    private String xbeforeInquireScriptText;

    /**
     * 分类ID
     */
    private String xcategoryId;

    /**
     * 分类ID数据路径
     */
    private String xcategoryIdDataPath;

    /**
     * 分类选择类型
     */
    private String xcategorySelectType;

    /**
     * 内容管理系统创建者身份
     */
    private String xcmsCreatorIdentity;

    /**
     * 内容管理系统创建者脚本
     */
    private String xcmsCreatorScript;

    /**
     * 内容管理系统创建者脚本文本
     */
    private String xcmsCreatorScriptText;

    /**
     * 发布的内容管理系统创建者类型
     */
    private String xpublishCmsCreatorType;

    /**
     * 描述
     */
    private String xdescription;

    /**
     * 显示日志脚本
     */
    private String xdisplayLogScript;

    /**
     * 显示日志脚本文本
     */
    private String xdisplayLogScriptText;

    /**
     * 版本
     */
    private String xedition;

    /**
     * 扩展名
     */
    private String xextension;

    /**
     * 表单
     */
    private String xform;

    /**
     * 组
     */
    private String xgroup;

    /**
     * 是否继承附件
     */
    private Boolean xinheritAttachment;

    /**
     * 名称
     */
    private String xname;

    /**
     * 通知数据路径列表
     */
    private String xnotifyDataPathList;

    /**
     * 意见组
     */
    private String xopinionGroup;

    /**
     * 图片数据路径列表
     */
    private String xpictureDataPathList;

    /**
     * 位置
     */
    private String xposition;

    /**
     * 流程
     */
    private String xprocess;

    /**
     * 属性
     */
    private String xproperties;

    /**
     * 发布目标
     */
    private String xpublishTarget;

    /**
     * 阅读职责
     */
    private String xreadDuty;

    /**
     * 阅读脚本
     */
    private String xreadScript;

    /**
     * 阅读脚本文本
     */
    private String xreadScriptText;

    /**
     * 阅读者数据路径列表
     */
    private String xreaderDataPathList;

    /**
     * 审核职责
     */
    private String xreviewDuty;

    /**
     * 审核脚本
     */
    private String xreviewScript;

    /**
     * 审核脚本文本
     */
    private String xreviewScriptText;

    /**
     * 路由
     */
    private String xroute;

    /**
     * 目标分配数据脚本
     */
    private String xtargetAssignDataScript;

    /**
     * 目标分配数据脚本文本
     */
    private String xtargetAssignDataScriptText;

    /**
     * 标题数据路径
     */
    private String xtitleDataPath;

    /**
     * 是否使用流程表单
     */
    private Boolean xuseProcessForm;
}
