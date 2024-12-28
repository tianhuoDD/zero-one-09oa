package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * 该类表示流程取消事件的实体类
 * 用于记录和处理流程取消相关的属性和信息
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_cancel")
public class PpECancel implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 流程取消事件的唯一标识符
     */
    private String xid;

    /**
     * 创建流程取消事件的时间
     */
    private LocalDateTime xcreateTime;

    /**
     * 流程取消事件的序列号
     */
    private String xsequence;

    /**
     * 最后一次更新流程取消事件的时间
     */
    private LocalDateTime xupdateTime;

    /**
     * 分发因子，用于确定事件的处理优先级或顺序
     */
    private Integer xdistributeFactor;

    /**
     * 到达后执行的脚本，用于处理特定的业务逻辑
     */
    private String xafterArriveScript;

    /**
     * 到达后执行脚本的文本内容
     */
    private String xafterArriveScriptText;

    /**
     * 执行后执行的脚本，用于处理特定的业务逻辑
     */
    private String xafterExecuteScript;

    /**
     * 执行后执行脚本的文本内容
     */
    private String xafterExecuteScriptText;

    /**
     * 查询后执行的脚本，用于处理特定的业务逻辑
     */
    private String xafterInquireScript;

    /**
     * 查询后执行脚本的文本内容
     */
    private String xafterInquireScriptText;

    /**
     * 流程取消事件的别名
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
     * 到达前执行的脚本，用于处理特定的业务逻辑
     */
    private String xbeforeArriveScript;

    /**
     * 到达前执行脚本的文本内容
     */
    private String xbeforeArriveScriptText;

    /**
     * 执行前执行的脚本，用于处理特定的业务逻辑
     */
    private String xbeforeExecuteScript;

    /**
     * 执行前执行脚本的文本内容
     */
    private String xbeforeExecuteScriptText;

    /**
     * 查询前执行的脚本，用于处理特定的业务逻辑
     */
    private String xbeforeInquireScript;

    /**
     * 查询前执行脚本的文本内容
     */
    private String xbeforeInquireScriptText;

    /**
     * 流程取消事件的描述
     */
    private String xdescription;

    /**
     * 显示日志的脚本，用于记录和展示日志信息
     */
    private String xdisplayLogScript;

    /**
     * 显示日志脚本的文本内容
     */
    private String xdisplayLogScriptText;

    /**
     * 流程取消事件的版本号
     */
    private String xedition;

    /**
     * 扩展信息，用于存储附加的数据或配置
     */
    private String xextension;

    /**
     * 表单标识，关联到特定的表单
     */
    private String xform;

    /**
     * 组标识，用于将事件归类到特定的组
     */
    private String xgroup;

    /**
     * 流程取消事件的名称
     */
    private String xname;

    /**
     * 意见组标识，用于关联到特定的意见组
     */
    private String xopinionGroup;

    /**
     * 位置标识，指示事件发生的位置
     */
    private String xposition;

    /**
     * 流程标识，关联到特定的流程
     */
    private String xprocess;

    /**
     * 属性信息，存储事件的附加属性
     */
    private String xproperties;

    /**
     * 读取职责，定义谁可以读取事件信息
     */
    private String xreadDuty;

    /**
     * 读取时执行的脚本，用于处理读取操作时的特定逻辑
     */
    private String xreadScript;

    /**
     * 读取脚本的文本内容
     */
    private String xreadScriptText;

    /**
     * 审核职责，定义谁可以审核事件
     */
    private String xreviewDuty;

    /**
     * 审核时执行的脚本，用于处理审核操作时的特定逻辑
     */
    private String xreviewScript;

    /**
     * 审核脚本的文本内容
     */
    private String xreviewScriptText;
}
