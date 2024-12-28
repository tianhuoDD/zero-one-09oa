package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * 并行处理实体类
 * 用于定义并行处理过程中的各项属性和配置
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_parallel")
public class PpEParallel implements Serializable {

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
     * 到达后脚本标识
     */
    private String xafterArriveScript;

    /**
     * 到达后脚本文本
     */
    private String xafterArriveScriptText;

    /**
     * 执行后脚本标识
     */
    private String xafterExecuteScript;

    /**
     * 执行后脚本文本
     */
    private String xafterExecuteScriptText;

    /**
     * 查询后脚本标识
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
     * 到达前脚本标识
     */
    private String xbeforeArriveScript;

    /**
     * 到达前脚本文本
     */
    private String xbeforeArriveScriptText;

    /**
     * 执行前脚本标识
     */
    private String xbeforeExecuteScript;

    /**
     * 执行前脚本文本
     */
    private String xbeforeExecuteScriptText;

    /**
     * 查询前脚本标识
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
     * 显示日志脚本标识
     */
    private String xdisplayLogScript;

    /**
     * 显示日志脚本文本
     */
    private String xdisplayLogScriptText;

    /**
     * 版本号
     */
    private String xedition;

    /**
     * 扩展信息
     */
    private String xextension;

    /**
     * 表单标识
     */
    private String xform;

    /**
     * 组标识
     */
    private String xgroup;

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
     * 流程标识
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
     * 读取脚本标识
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
     * 审核脚本标识
     */
    private String xreviewScript;

    /**
     * 审核脚本文本
     */
    private String xreviewScriptText;

}
