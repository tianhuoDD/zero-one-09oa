package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * 任务拆分实体类
 * 用于表示和管理任务拆分的相关信息
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_split")
public class PpESplit implements Serializable {

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
     * 到达后脚本ID
     */
    private String xafterArriveScript;

    /**
     * 到达后脚本文本
     */
    private String xafterArriveScriptText;

    /**
     * 执行后脚本ID
     */
    private String xafterExecuteScript;

    /**
     * 执行后脚本文本
     */
    private String xafterExecuteScriptText;

    /**
     * 查询后脚本ID
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
     * 到达前脚本ID
     */
    private String xbeforeArriveScript;

    /**
     * 到达前脚本文本
     */
    private String xbeforeArriveScriptText;

    /**
     * 执行前脚本ID
     */
    private String xbeforeExecuteScript;

    /**
     * 执行前脚本文本
     */
    private String xbeforeExecuteScriptText;

    /**
     * 查询前脚本ID
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
     * 显示日志脚本ID
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
     * 扩展信息
     */
    private String xextension;

    /**
     * 表单ID
     */
    private String xform;

    /**
     * 组ID
     */
    private String xgroup;

    /**
     * 名称
     */
    private String xname;

    /**
     * 意见组ID
     */
    private String xopinionGroup;

    /**
     * 位置ID
     */
    private String xposition;

    /**
     * 流程ID
     */
    private String xprocess;

    /**
     * 属性
     */
    private String xproperties;

    /**
     * 读取职责ID
     */
    private String xreadDuty;

    /**
     * 读取脚本ID
     */
    private String xreadScript;

    /**
     * 读取脚本文本
     */
    private String xreadScriptText;

    /**
     * 审核职责ID
     */
    private String xreviewDuty;

    /**
     * 审核脚本ID
     */
    private String xreviewScript;

    /**
     * 审核脚本文本
     */
    private String xreviewScriptText;

    /**
     * 路由规则ID
     */
    private String xroute;

    /**
     * 脚本ID
     */
    private String xscript;

    /**
     * 脚本文本
     */
    private String xscriptText;

}
