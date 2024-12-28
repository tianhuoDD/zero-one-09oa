package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * 服务实体类，用于表示电子服务的相关信息和属性
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_service")
public class PpEService implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 服务的唯一标识符
     */
    private String xid;

    /**
     * 服务的创建时间
     */
    private LocalDateTime xcreateTime;

    /**
     * 服务的序列号
     */
    private String xsequence;

    /**
     * 服务的更新时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 分发因子，用于服务分发的权重或优先级
     */
    private Integer xdistributeFactor;

    /**
     * 到达后执行的脚本，用于处理服务到达后的逻辑
     */
    private String xafterArriveScript;

    /**
     * 到达后执行脚本的文本内容
     */
    private String xafterArriveScriptText;

    /**
     * 执行后执行的脚本，用于处理服务执行后的逻辑
     */
    private String xafterExecuteScript;

    /**
     * 执行后执行脚本的文本内容
     */
    private String xafterExecuteScriptText;

    /**
     * 查询后执行的脚本，用于处理服务查询后的逻辑
     */
    private String xafterInquireScript;

    /**
     * 查询后执行脚本的文本内容
     */
    private String xafterInquireScriptText;

    /**
     * 服务的别名
     */
    private String xalias;

    /**
     * 是否允许重新路由服务
     */
    private Boolean xallowReroute;

    /**
     * 是否允许作为重新路由的目标
     */
    private Boolean xallowRerouteTo;

    /**
     * 到达前执行的脚本，用于处理服务到达前的逻辑
     */
    private String xbeforeArriveScript;

    /**
     * 到达前执行脚本的文本内容
     */
    private String xbeforeArriveScriptText;

    /**
     * 执行前执行的脚本，用于处理服务执行前的逻辑
     */
    private String xbeforeExecuteScript;

    /**
     * 执行前执行脚本的文本内容
     */
    private String xbeforeExecuteScriptText;

    /**
     * 查询前执行的脚本，用于处理服务查询前的逻辑
     */
    private String xbeforeInquireScript;

    /**
     * 查询前执行脚本的文本内容
     */
    private String xbeforeInquireScriptText;

    /**
     * 服务的描述信息
     */
    private String xdescription;

    /**
     * 显示日志的脚本，用于记录服务的日志信息
     */
    private String xdisplayLogScript;

    /**
     * 显示日志脚本的文本内容
     */
    private String xdisplayLogScriptText;

    /**
     * 服务的版本号
     */
    private String xedition;

    /**
     * 服务的扩展信息
     */
    private String xextension;

    /**
     * 服务的表单信息
     */
    private String xform;

    /**
     * 服务所属的组
     */
    private String xgroup;

    /**
     * 服务的名称
     */
    private String xname;

    /**
     * 意见组，用于收集服务的反馈意见
     */
    private String xopinionGroup;

    /**
     * 服务的位置信息
     */
    private String xposition;

    /**
     * 服务的处理流程
     */
    private String xprocess;

    /**
     * 服务的属性信息
     */
    private String xproperties;

    /**
     * 服务的读取职责，定义谁可以读取服务信息
     */
    private String xreadDuty;

    /**
     * 服务的读取脚本
     */
    private String xreadScript;

    /**
     * 读取脚本的文本内容
     */
    private String xreadScriptText;

    /**
     * 服务的审核职责，定义谁可以审核服务
     */
    private String xreviewDuty;

    /**
     * 服务的审核脚本
     */
    private String xreviewScript;

    /**
     * 审核脚本的文本内容
     */
    private String xreviewScriptText;

    /**
     * 服务的路由信息
     */
    private String xroute;

    /**
     * 服务的脚本
     */
    private String xscript;

    /**
     * 脚本的文本内容
     */
    private String xscriptText;
}
