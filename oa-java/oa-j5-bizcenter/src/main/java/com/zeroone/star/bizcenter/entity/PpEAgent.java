package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * 代理实体类，用于表示代理相关的配置和信息
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_agent")
public class PpEAgent implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 代理的唯一标识符
     */
    private String xid;

    /**
     * 创建时间，记录代理创建的时间点
     */
    private LocalDateTime xcreateTime;

    /**
     * 代理的序列号，用于区分不同的代理
     */
    private String xsequence;

    /**
     * 更新时间，记录代理信息最近一次更新的时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 分发因子，用于代理任务分发的权重计算
     */
    private Integer xdistributeFactor;

    /**
     * 到达后脚本，指定代理在到达特定状态后执行的脚本
     */
    private String xafterArriveScript;

    /**
     * 到达后脚本文本，存储脚本的具体内容
     */
    private String xafterArriveScriptText;

    /**
     * 执行后脚本，代理完成任务后执行的脚本
     */
    private String xafterExecuteScript;

    /**
     * 执行后脚本文本，存储脚本的具体内容
     */
    private String xafterExecuteScriptText;

    /**
     * 查询后脚本，进行查询操作后执行的脚本
     */
    private String xafterInquireScript;

    /**
     * 查询后脚本文本，存储脚本的具体内容
     */
    private String xafterInquireScriptText;

    /**
     * 代理中断脚本，当代理需要中断时执行的脚本
     */
    private String xagentInterruptScript;

    /**
     * 代理中断脚本文本，存储脚本的具体内容
     */
    private String xagentInterruptScriptText;

    /**
     * 代理别名，用于更友好地识别代理
     */
    private String xalias;

    /**
     * 是否允许重新路由，指示代理是否可以被重新路由
     */
    private Boolean xallowReroute;

    /**
     * 是否允许作为重新路由目标，指示代理是否可以成为其他代理的重新路由目标
     */
    private Boolean xallowRerouteTo;

    /**
     * 到达前脚本，代理在到达特定状态前执行的脚本
     */
    private String xbeforeArriveScript;

    /**
     * 到达前脚本文本，存储脚本的具体内容
     */
    private String xbeforeArriveScriptText;

    /**
     * 执行前脚本，代理在执行任务前运行的脚本
     */
    private String xbeforeExecuteScript;

    /**
     * 执行前脚本文本，存储脚本的具体内容
     */
    private String xbeforeExecuteScriptText;

    /**
     * 查询前脚本，进行查询操作前执行的脚本
     */
    private String xbeforeInquireScript;

    /**
     * 查询前脚本文本，存储脚本的具体内容
     */
    private String xbeforeInquireScriptText;

    /**
     * 描述，提供代理的详细描述信息
     */
    private String xdescription;

    /**
     * 显示日志脚本，用于显示日志信息的脚本
     */
    private String xdisplayLogScript;

    /**
     * 显示日志脚本文本，存储脚本的具体内容
     */
    private String xdisplayLogScriptText;

    /**
     * 版本号，表示代理的当前版本
     */
    private String xedition;

    /**
     * 扩展信息，用于存储额外的扩展属性
     */
    private String xextension;

    /**
     * 表单，关联的表单信息
     */
    private String xform;

    /**
     * 组，代理所属的组
     */
    private String xgroup;

    /**
     * 名称，代理的名称
     */
    private String xname;

    /**
     * 意见组，关联的意见组信息
     */
    private String xopinionGroup;

    /**
     * 职位，代理的职位信息
     */
    private String xposition;

    /**
     * 流程，代理所涉及的流程
     */
    private String xprocess;

    /**
     * 属性，代理的属性信息
     */
    private String xproperties;

    /**
     * 阅读职责，指定谁可以阅读代理的信息
     */
    private String xreadDuty;

    /**
     * 阅读脚本，用于阅读操作的脚本
     */
    private String xreadScript;

    /**
     * 阅读脚本文本，存储脚本的具体内容
     */
    private String xreadScriptText;

    /**
     * 审核职责，指定谁可以审核代理的信息
     */
    private String xreviewDuty;

    /**
     * 审核脚本，用于审核操作的脚本
     */
    private String xreviewScript;

    /**
     * 审核脚本文本，存储脚本的具体内容
     */
    private String xreviewScriptText;

    /**
     * 路由，代理的路由信息
     */
    private String xroute;

    /**
     * 脚本，与代理相关的脚本
     */
    private String xscript;

    /**
     * 脚本文本，存储脚本的具体内容
     */
    private String xscriptText;
}
