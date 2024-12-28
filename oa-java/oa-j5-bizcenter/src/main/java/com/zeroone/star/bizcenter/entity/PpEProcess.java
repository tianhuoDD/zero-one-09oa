package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 该类表示流程管理中的流程定义实体。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-25
 */
@Getter
@Setter
@TableName("pp_e_process")
public class PpEProcess implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 流程定义的唯一标识符。
     */
    @TableId(value = "xid")
    private String xid;

    /**
     * 流程定义的创建时间。
     */
    private LocalDateTime xcreateTime;

    /**
     * 流程定义的序列号。
     */
    private String xsequence;

    /**
     * 流程定义的最后更新时间。
     */
    private LocalDateTime xupdateTime;

    /**
     * 分配因子，用于流程任务的分配。
     */
    private Integer xdistributeFactor;

    /**
     * 到达节点后执行的脚本。
     */
    private String xafterArriveScript;

    /**
     * 到达节点后执行的脚本的文本内容。
     */
    private String xafterArriveScriptText;

    /**
     * 开始流程后执行的脚本。
     */
    private String xafterBeginScript;

    /**
     * 开始流程后执行的脚本的文本内容。
     */
    private String xafterBeginScriptText;

    /**
     * 结束流程后执行的脚本。
     */
    private String xafterEndScript;

    /**
     * 结束流程后执行的脚本的文本内容。
     */
    private String xafterEndScriptText;

    /**
     * 执行任务后执行的脚本。
     */
    private String xafterExecuteScript;

    /**
     * 执行任务后执行的脚本的文本内容。
     */
    private String xafterExecuteScriptText;

    /**
     * 查询前执行的脚本。
     */
    private String xafterInquireScript;

    /**
     * 查询前执行的脚本的文本内容。
     */
    private String xafterInquireScriptText;

    /**
     * 流程定义的别名。
     */
    private String xalias;

    /**
     * 关联的应用程序标识符。
     */
    private String xapplication;

    /**
     * 到达节点前执行的脚本。
     */
    private String xbeforeArriveScript;

    /**
     * 到达节点前执行的脚本的文本内容。
     */
    private String xbeforeArriveScriptText;

    /**
     * 执行任务前执行的脚本。
     */
    private String xbeforeExecuteScript;

    /**
     * 执行任务前执行的脚本的文本内容。
     */
    private String xbeforeExecuteScriptText;

    /**
     * 查询前执行的脚本。
     */
    private String xbeforeInquireScript;

    /**
     * 查询前执行的脚本的文本内容。
     */
    private String xbeforeInquireScriptText;

    /**
     * 流程定义的分类。
     */
    private String xcategory;

    /**
     * 是否检查草稿。
     */
    private Boolean xcheckDraft;

    /**
     * 创建者的人员标识符。
     */
    private String xcreatorPerson;

    /**
     * 默认的启动模式。
     */
    private String xdefaultStartMode;

    /**
     * 流程定义的描述。
     */
    private String xdescription;

    /**
     * 流程定义的版本标识符。
     */
    private String xedition;

    /**
     * 版本的描述。
     */
    private String xeditionDes;

    /**
     * 是否启用版本控制。
     */
    private Boolean xeditionEnable;

    /**
     * 版本的名称。
     */
    private String xeditionName;

    /**
     * 版本的编号。
     */
    private Double xeditionNumber;

    /**
     * 流程定义的过期天数。
     */
    private Integer xexpireDay;

    /**
     * 流程定义的过期小时数。
     */
    private Integer xexpireHour;

    /**
     * 过期类型，定义如何处理过期的流程实例。
     */
    private String xexpireType;

    /**
     * 是否在工作时间内过期。
     */
    private Boolean xexpireWorkTime;

    /**
     * 流程定义的图标。
     */
    private String xicon;

    /**
     * 最后更新者的人员标识符。
     */
    private String xlastUpdatePerson;

    /**
     * 最后更新的时间。
     */
    private LocalDateTime xlastUpdateTime;

    /**
     * 流程定义的名称。
     */
    private String xname;

    /**
     * 投影方式，定义如何展示流程实例。
     */
    private String xprojection;

    /**
     * 是否完全投影。
     */
    private Boolean xprojectionFully;

    /**
     * 流程定义的属性。
     */
    private String xproperties;

    /**
     * 是否将路由名称作为意见。
     */
    private Boolean xrouteNameAsOpinion;

    /**
     * 串行活动的标识符。
     */
    private String xserialActivity;

    /**
     * 串行阶段的标识符。
     */
    private String xserialPhase;

    /**
     * 串行纹理，描述流程的串行执行路径。
     */
    private String xserialTexture;

    /**
     * 可启动的终端，定义哪些终端可以启动流程。
     */
    private String xstartableTerminal;
}
