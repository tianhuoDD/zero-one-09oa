package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * 选择题实体类
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_choice")
public class PpEChoice implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 选择题的唯一标识符
     */
    private String xid;

    /**
     * 创建选择题的时间
     */
    private LocalDateTime xcreateTime;

    /**
     * 选择题的序列号
     */
    private String xsequence;

    /**
     * 更新选择题的时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 分发因子，用于确定选择题的分发策略
     */
    private Integer xdistributeFactor;

    /**
     * 到达后执行的脚本标识
     */
    private String xafterArriveScript;

    /**
     * 到达后执行的脚本文本
     */
    private String xafterArriveScriptText;

    /**
     * 执行后执行的脚本标识
     */
    private String xafterExecuteScript;

    /**
     * 执行后执行的脚本文本
     */
    private String xafterExecuteScriptText;

    /**
     * 查询后执行的脚本标识
     */
    private String xafterInquireScript;

    /**
     * 查询后执行的脚本文本
     */
    private String xafterInquireScriptText;

    /**
     * 选择题的别名
     */
    private String xalias;

    /**
     * 是否允许重新路由选择题
     */
    private Boolean xallowReroute;

    /**
     * 是否允许作为重新路由的目标
     */
    private Boolean xallowRerouteTo;

    /**
     * 到达前执行的脚本标识
     */
    private String xbeforeArriveScript;

    /**
     * 到达前执行的脚本文本
     */
    private String xbeforeArriveScriptText;

    /**
     * 执行前执行的脚本标识
     */
    private String xbeforeExecuteScript;

    /**
     * 执行前执行的脚本文本
     */
    private String xbeforeExecuteScriptText;

    /**
     * 查询前执行的脚本标识
     */
    private String xbeforeInquireScript;

    /**
     * 查询前执行的脚本文本
     */
    private String xbeforeInquireScriptText;

    /**
     * 选择题的描述信息
     */
    private String xdescription;

    /**
     * 显示日志的脚本标识
     */
    private String xdisplayLogScript;

    /**
     * 显示日志的脚本文本
     */
    private String xdisplayLogScriptText;

    /**
     * 选择题的版本号
     */
    private String xedition;

    /**
     * 扩展信息
     */
    private String xextension;

    /**
     * 表单标识，关联的表单
     */
    private String xform;

    /**
     * 组标识，选择题所属的组
     */
    private String xgroup;

    /**
     * 选择题的名称
     */
    private String xname;

    /**
     * 意见组标识，关联的意见组
     */
    private String xopinionGroup;

    /**
     * 位置标识，选择题所在的位置
     */
    private String xposition;

    /**
     * 流程标识，选择题所属的流程
     */
    private String xprocess;

    /**
     * 属性信息，以字符串形式存储的属性
     */
    private String xproperties;

    /**
     * 读取职责，谁可以读取选择题的信息
     */
    private String xreadDuty;

    /**
     * 读取脚本标识，用于读取操作的脚本
     */
    private String xreadScript;

    /**
     * 读取脚本文本
     */
    private String xreadScriptText;

    /**
     * 审核职责，谁可以审核选择题
     */
    private String xreviewDuty;

    /**
     * 审核脚本标识，用于审核操作的脚本
     */
    private String xreviewScript;

    /**
     * 审核脚本文本
     */
    private String xreviewScriptText;

}
