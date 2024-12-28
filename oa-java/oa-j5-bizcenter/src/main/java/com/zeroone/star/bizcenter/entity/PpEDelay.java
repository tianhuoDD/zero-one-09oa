package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示一个延迟处理的实体，用于业务中心的延迟任务管理。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_delay")
public class PpEDelay implements Serializable {

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
     * 延迟数据路径
     */
    private String xdelayDataPath;

    /**
     * 延迟分钟数
     */
    private Integer xdelayMinute;

    /**
     * 延迟脚本
     */
    private String xdelayScript;

    /**
     * 延迟脚本文本
     */
    private String xdelayScriptText;

    /**
     * 延迟时间
     */
    private LocalDateTime xdelayTime;

    /**
     * 延迟类型
     */
    private String xdelayType;

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
     * 扩展信息
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
     * 是否在工作时间分钟内处理
     */
    private Boolean xworkMinute;
}
