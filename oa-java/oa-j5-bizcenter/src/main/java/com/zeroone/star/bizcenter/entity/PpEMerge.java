package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * 该类表示流程合并节点的配置信息
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_merge")
public class PpEMerge implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 节点ID，唯一标识一个合并节点
     */
    private String xid;

    /**
     * 创建时间，记录该节点配置的创建时间
     */
    private LocalDateTime xcreateTime;

    /**
     * 序列号，用于区分不同版本的节点配置
     */
    private String xsequence;

    /**
     * 更新时间，记录该节点配置的最近更新时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 分发因子，决定任务分发的策略
     */
    private Integer xdistributeFactor;

    /**
     * 到达后脚本ID，用于执行到达节点后的脚本
     */
    private String xafterArriveScript;

    /**
     * 到达后脚本内容，存储实际的脚本代码
     */
    private String xafterArriveScriptText;

    /**
     * 执行后脚本ID，用于执行节点任务完成后脚本
     */
    private String xafterExecuteScript;

    /**
     * 执行后脚本内容，存储实际的脚本代码
     */
    private String xafterExecuteScriptText;

    /**
     * 查询后脚本ID，用于执行查询相关信息后的脚本
     */
    private String xafterInquireScript;

    /**
     * 查询后脚本内容，存储实际的脚本代码
     */
    private String xafterInquireScriptText;

    /**
     * 节点别名，用于更直观地标识节点
     */
    private String xalias;

    /**
     * 是否允许重新路由，控制任务是否可以被重新分配
     */
    private Boolean xallowReroute;

    /**
     * 是否允许作为重路由目标，控制节点是否可以成为任务重分配的目标
     */
    private Boolean xallowRerouteTo;

    /**
     * 到达前脚本ID，用于执行任务到达节点前的脚本
     */
    private String xbeforeArriveScript;

    /**
     * 到达前脚本内容，存储实际的脚本代码
     */
    private String xbeforeArriveScriptText;

    /**
     * 执行前脚本ID，用于执行节点任务开始前的脚本
     */
    private String xbeforeExecuteScript;

    /**
     * 执行前脚本内容，存储实际的脚本代码
     */
    private String xbeforeExecuteScriptText;

    /**
     * 查询前脚本ID，用于执行查询相关信息前的脚本
     */
    private String xbeforeInquireScript;

    /**
     * 查询前脚本内容，存储实际的脚本代码
     */
    private String xbeforeInquireScriptText;

    /**
     * 节点描述，对节点功能或用途的详细说明
     */
    private String xdescription;

    /**
     * 显示日志脚本ID，用于执行显示日志信息的脚本
     */
    private String xdisplayLogScript;

    /**
     * 显示日志脚本内容，存储实际的脚本代码
     */
    private String xdisplayLogScriptText;

    /**
     * 版本号，标识节点配置的版本
     */
    private String xedition;

    /**
     * 扩展信息，用于存储额外的配置或信息
     */
    private String xextension;

    /**
     * 表单ID，关联的表单用于任务处理
     */
    private String xform;

    /**
     * 组ID，标识节点所属的组
     */
    private String xgroup;

    /**
     * 节点名称，对节点的直观称呼
     */
    private String xname;

    /**
     * 意见组ID，用于收集任务处理的意见
     */
    private String xopinionGroup;

    /**
     * 位置ID，标识节点在流程中的位置
     */
    private String xposition;

    /**
     * 流程ID，标识节点所属的流程
     */
    private String xprocess;

    /**
     * 属性，存储节点的额外属性信息
     */
    private String xproperties;

    /**
     * 读取职责ID，定义谁可以读取节点的相关信息
     */
    private String xreadDuty;

    /**
     * 读取脚本ID，用于执行读取操作前的脚本
     */
    private String xreadScript;

    /**
     * 读取脚本内容，存储实际的脚本代码
     */
    private String xreadScriptText;

    /**
     * 审核职责ID，定义谁可以审核节点的任务
     */
    private String xreviewDuty;

    /**
     * 审核脚本ID，用于执行审核操作前的脚本
     */
    private String xreviewScript;

    /**
     * 审核脚本内容，存储实际的脚本代码
     */
    private String xreviewScriptText;

    /**
     * 路由信息，定义节点之间的路由规则
     */
    private String xroute;
}
