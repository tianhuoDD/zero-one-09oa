package com.zeroone.star.bizcenter.entity;

import cn.hutool.core.annotation.Alias;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.*;

/**
 * <p>
 * 
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-25
 */
@AllArgsConstructor
@NoArgsConstructor
@Builder
@Getter
@Setter
@TableName("pp_e_manual")
public class PpEManual implements Serializable {

    /**
     * 序列化版本ID，用于标识类的版本
     */
    private static final long serialVersionUID = 1L;

    /**
     * 业务ID，唯一标识业务对象
     */
    @TableId
    @Alias("id")
    private String xid;

    /**
     * 创建时间，记录业务对象创建的时间
     */
    @Alias("createTime")
    private LocalDateTime xcreateTime;

    /**
     * 序列号，用于标识业务对象的序列
     */
    @Alias("sequence")
    private String xsequence;

    /**
     * 更新时间，记录业务对象最近一次更新的时间
     */
    @Alias("updateTime")
    private LocalDateTime xupdateTime;

    /**
     * 分配因子，用于业务对象的分配逻辑
     */
    @Alias("distributeFactor")
    private Integer xdistributeFactor;

    /**
     * 到达后脚本，定义业务对象到达后执行的脚本
     */
    @Alias("afterArriveScript")
    private String xafterArriveScript;

    /**
     * 到达后脚本文本，存储到达后脚本的具体内容
     */
    @Alias("afterArriveScriptText")
    private String xafterArriveScriptText;

    /**
     * 执行后脚本，定义业务对象执行后运行的脚本
     */
    @Alias("afterExecuteScript")
    private String xafterExecuteScript;

    /**
     * 执行后脚本文本，存储执行后脚本的具体内容
     */
    @Alias("afterExecuteScriptText")
    private String xafterExecuteScriptText;

    /**
     * 查询后脚本，定义业务对象查询后执行的脚本
     */
    @Alias("afterInquireScript")
    private String xafterInquireScript;

    /**
     * 查询后脚本文本，存储查询后脚本的具体内容
     */
    @Alias("afterInquireScriptText")
    private String xafterInquireScriptText;

    /**
     * 别名，为业务对象定义的易于理解的名称
     */
    @Alias("alias")
    private String xalias;

    /**
     * 是否允许添加分割，指示是否可以为业务对象添加分割操作
     */
    @Alias("allowAddSplit")
    private Boolean xallowAddSplit;

    /**
     * 是否允许删除工作项，指示是否可以删除业务对象的工作项
     */
    @Alias("allowDeleteWork")
    private Boolean xallowDeleteWork;

    /**
     * 是否允许暂停，指示业务对象是否可以被暂停
     */
    @Alias("allowPause")
    private Boolean xallowPause;

    /**
     * 是否允许压制，指示业务对象是否可以被压制
     */
    @Alias("allowPress")
    private Boolean xallowPress;

    /**
     * 是否允许快速处理，指示业务对象是否可以快速处理
     */
    @Alias("allowRapid")
    private Boolean xallowRapid;

    /**
     * 是否允许重新路由，指示是否可以对业务对象进行重新路由
     */
    @Alias("allowReroute")
    private Boolean xallowReroute;

    /**
     * 是否允许重新路由到，指示业务对象是否可以被重新路由到其他地方
     */
    @Alias("allowRerouteTo")
    private Boolean xallowRerouteTo;

    /**
     * 是否允许重置，指示业务对象是否可以被重置
     */
    @Alias("allowReset")
    private Boolean xallowReset;

    /**
     * 是否允许回缩，指示是否可以回缩业务对象
     */
    @Alias("allowRetract")
    private Boolean xallowRetract;

    /**
     * 是否允许回滚，指示业务对象是否可以回滚
     */
    @Alias("allowRollback")
    private Boolean xallowRollback;

    /**
     * 到达前脚本，定义业务对象到达前执行的脚本
     */
    @Alias("beforeArriveScript")
    private String xbeforeArriveScript;

    /**
     * 到达前脚本文本，存储到达前脚本的具体内容
     */
    @Alias("beforeArriveScriptText")
    private String xbeforeArriveScriptText;

    /**
     * 执行前脚本，定义业务对象执行前运行的脚本
     */
    @Alias("beforeExecuteScript")
    private String xbeforeExecuteScript;

    /**
     * 执行前脚本文本，存储执行前脚本的具体内容
     */
    @Alias("beforeExecuteScriptText")
    private String xbeforeExecuteScriptText;

    /**
     * 查询前脚本，定义业务对象查询前执行的脚本
     */
    @Alias("beforeInquireScript")
    private String xbeforeInquireScript;

    /**
     * 查询前脚本文本，存储查询前脚本的具体内容
     */
    @Alias("beforeInquireScriptText")
    private String xbeforeInquireScriptText;

    /**
     * 描述，存储业务对象的详细描述信息
     */
    @Alias("description")
    private String xdescription;

    /**
     * 显示日志脚本，定义如何显示业务对象的日志信息
     */
    @Alias("displayLogScript")
    private String xdisplayLogScript;

    /**
     * 显示日志脚本文本，存储显示日志脚本的具体内容
     */
    @Alias("displayLogScriptText")
    private String xdisplayLogScriptText;

    /**
     * 版本，标识业务对象的版本
     */
    @Alias("edition")
    private String xedition;

    /**
     * 扩展信息，存储业务对象的扩展信息
     */
    @Alias("extension")
    private String xextension;

    /**
     * 表单信息，定义业务对象相关的表单信息
     */
    @Alias("form")
    private String xform;

    /**
     * 组信息，业务对象所属的组
     */
    @Alias("group")
    private String xgroup;

    /**
     * 手动完成任务后脚本，定义手动完成任务后执行的脚本
     */
    @Alias("manualAfterTaskScript")
    private String xmanualAfterTaskScript;

    /**
     * 手动完成任务后脚本文本，存储手动完成任务后脚本的具体内容
     */
    @Alias("manualAfterTaskScriptText")
    private String xmanualAfterTaskScriptText;

    /**
     * 手动完成任务前脚本，定义手动完成任务前执行的脚本
     */
    @Alias("manualBeforeTaskScript")
    private String xmanualBeforeTaskScript;

    /**
     * 手动完成任务前脚本文本，存储手动完成任务前脚本的具体内容
     */
    @Alias("manualBeforeTaskScriptText")
    private String xmanualBeforeTaskScriptText;

    /**
     * 手动合并相同作业活动，指示是否手动合并相同的作业活动
     */
    @Alias("manualMergeSameJobActivity")
    private Boolean xmanualMergeSameJobActivity;

    /**
     * 手动模式，定义业务对象的手动模式
     */
    @Alias("manualMode")
    private String xmanualMode;

    /**
     * 手动停留脚本，定义手动模式下的停留脚本
     */
    @Alias("manualStayScript")
    private String xmanualStayScript;

    /**
     * 手动停留脚本文本，存储手动停留脚本的具体内容
     */
    @Alias("manualStayScriptText")
    private String xmanualStayScriptText;

    /**
     * 手动未完成任务是否可读，指示手动模式下未完成的任务是否可读
     */
    @Alias("manualUncompletedTaskToRead")
    private Boolean xmanualUncompletedTaskToRead;

    /**
     * 名称，业务对象的名称
     */
    @Alias("name")
    private String xname;

    /**
     * 意见组，业务对象相关的意见组
     */
    @Alias("opinionGroup")
    private String xopinionGroup;

    /**
     * 位置，业务对象的位置信息
     */
    @Alias("position")
    private String xposition;

    /**
     * 流程信息，业务对象所属的流程
     */
    @Alias("process")
    private String xprocess;

    /**
     * 属性，存储业务对象的属性信息
     */
    @Alias("properties")
    private String xproperties;

    /**
     * 阅读职责，定义谁可以阅读业务对象的信息
     */
    @Alias("readDuty")
    private String xreadDuty;


    /**
     * 阅读脚本，定义如何阅读业务对象的信息
     */
    @Alias("readScript")
    private String xreadScript;

    @Alias("readScriptText")
    /*
     * 阅读脚本文本，存储阅读脚本的具体内容
     */
    private String xreadScriptText;

    @Alias("resetCount")
    /*
     * 重置计数，记录业务对象被重置的次数
     */
    private Integer xresetCount;

    @Alias("resetRange")
    /*
     * 重置范围，定义业务对象的重置范围
     */
    private String xresetRange;

    @Alias("resetRangeScriptText")
    /*
     * 重置范围脚本文本，存储与重置范围相关的脚本内容
     */
    private String xresetRangeScriptText;

    @Alias("reviewDuty")
    /*
     * 审核职责，定义谁负责审核业务对象
     */
    private String xreviewDuty;

    @Alias("reviewScript")
    /*
     * 审核脚本，定义如何审核业务对象
     */
    private String xreviewScript;

    @Alias("reviewScriptText")
    /*
     * 审核脚本文本，存储审核脚本的具体内容
     */
    private String xreviewScriptText;

    @Alias("taskDuty")
    /*
     * 任务职责，定义业务对象的职责
     */
    private String xtaskDuty;

    @Alias("taskExpireDay")
    /*
     * 任务过期天数，记录任务过期的天数
     */
    private Integer xtaskExpireDay;

    @Alias("taskExpireHour")
    /*
     * 任务过期小时数，记录任务过期的小时数
     */
    private Integer xtaskExpireHour;

    @Alias("taskExpireScript")
    /*
     * 任务过期脚本，定义任务过期时执行的脚本
     */
    private String xtaskExpireScript;

    @Alias("taskExpireScriptText")
    /*
     * 任务过期脚本文本，存储任务过期脚本的具体内容
     */
    private String xtaskExpireScriptText;

    @Alias("taskExpireType")
    /*
      任务过期类型，定义任务过期的类型
     */
    private String xtaskExpireType;

    @Alias("taskExpireWorkTime")
    /*
      任务过期是否在工作时间，指示任务是否在工作时间内过期
     */
    private Boolean xtaskExpireWorkTime;

    @Alias("taskScript")
    /*
      任务脚本，定义与任务相关的脚本
     */
    private String xtaskScript;

    @Alias("taskScriptText")
    /*
      任务脚本文本，存储任务脚本的具体内容
     */
    private String xtaskScriptText;



}
