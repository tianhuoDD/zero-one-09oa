package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示流程嵌入（Process Embed）实体，用于定义和管理流程中的嵌入式脚本和配置信息。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_embed")
public class PpEEmbed implements Serializable {

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
     * 分配因子
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
     * 是否允许路由到
     */
    private Boolean xallowRerouteTo;

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
     * 嵌入创建者类型
     */
    private String xembedCreatorType;

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
     * 是否继承数据
     */
    private Boolean xinheritData;

    /**
     * 名称
     */
    private String xname;

    /**
     * 意见组
     */
    private String xopinionGroup;

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
     * 读取职责
     */
    private String xreadDuty;

    /**
     * 读取脚本
     */
    private String xreadScript;

    /**
     * 读取脚本文本
     */
    private String xreadScriptText;

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
     * 目标应用程序
     */
    private String xtargetApplication;

    /**
     * 目标应用程序别名
     */
    private String xtargetApplicationAlias;

    /**
     * 目标应用程序名称
     */
    private String xtargetApplicationName;

    /**
     * 目标分配数据脚本
     */
    private String xtargetAssginDataScript;

    /**
     * 目标分配数据脚本文本
     */
    private String xtargetAssginDataScriptText;

    /**
     * 目标身份
     */
    private String xtargetIdentity;

    /**
     * 目标身份脚本
     */
    private String xtargetIdentityScript;

    /**
     * 目标身份脚本文本
     */
    private String xtargetIdentityScriptText;

    /**
     * 目标流程
     */
    private String xtargetProcess;

    /**
     * 目标流程别名
     */
    private String xtargetProcessAlias;

    /**
     * 目标流程名称
     */
    private String xtargetProcessName;

    /**
     * 目标标题脚本
     */
    private String xtargetTitleScript;

    /**
     * 目标标题脚本文本
     */
    private String xtargetTitleScriptText;

    /**
     * 是否等待直到完成
     */
    private Boolean xwaitUntilCompleted;

}
