package com.zeroone.star.bizcenter.entity;

import cn.hutool.core.annotation.Alias;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 类PpEBegin表示流程结束节点的属性和配置信息。该类用于在系统中定义和管理流程开始时的行为和特性。
 * </p>
 *
 * @author xiongjian
 * @since 2024-10-25
 */
@Getter
@Setter
@Data
@TableName("pp_e_begin")
public class PpEBegin implements Serializable {

    /**
     * 序列化ID，用于对象序列化时的身份标识
     */
    private static final long serialVersionUID = 1L;

    /**
     * 唯一标识符，用于标识特定对象
     */
    @TableId
    private String xid;

    /**
     * 创建时间，记录对象创建的时间点
     */

    private LocalDateTime xcreateTime;

    /**
     * 序列号，用于对象的排序或序列组织
     */
//    @Alias("sequence")
    private String xsequence;

    /**
     * 更新时间，记录对象最近一次更新的时间点
     */

    private LocalDateTime xupdateTime;

    /**
     * 分发因子，用于对象的分发或路由决策
     */
//    @Alias("distributeFactor")
    private Integer xdistributeFactor;

    /**
     * 到达后脚本标识，指示到达特定状态后执行的脚本
     */

    private String xafterArriveScript;

    /**
     * 到达后脚本文本，包含实际执行的脚本内容
     */

    private String xafterArriveScriptText;

    /**
     * 执行后脚本标识，指示执行特定操作后运行的脚本
     */

    private String xafterExecuteScript;

    /**
     * 执行后脚本文本，包含实际执行的脚本内容
     */

    private String xafterExecuteScriptText;

    /**
     * 查询后脚本标识，指示查询操作后执行的脚本
     */

    private String xafterInquireScript;

    /**
     * 查询后脚本文本，包含实际执行的脚本内容
     */

    private String xafterInquireScriptText;

    /**
     * 别名，为对象提供一个易于读取的名称
     */

    private String xalias;

    /**
     * 是否允许重新路由，指示对象是否可以被重新路由
     */

    private Boolean xallowReroute;

    /**
     * 是否允许作为重新路由目标，指示对象是否可以成为其他对象的重新路由目标
     */

    private Boolean xallowRerouteTo;

    /**
     * 到达前脚本标识，指示到达特定状态前执行的脚本
     */

    private String xbeforeArriveScript;

    /**
     * 到达前脚本文本，包含实际执行的脚本内容
     */

    private String xbeforeArriveScriptText;

    /**
     * 执行前脚本标识，指示执行特定操作前运行的脚本
     */

    private String xbeforeExecuteScript;

    /**
     * 执行前脚本文本，包含实际执行的脚本内容
     */

    private String xbeforeExecuteScriptText;

    /**
     * 查询前脚本标识，指示查询操作前执行的脚本
     */

    private String xbeforeInquireScript;

    /**
     * 查询前脚本文本，包含实际执行的脚本内容
     */

    private String xbeforeInquireScriptText;

    /**
     * 描述，提供对象的详细描述信息
     */

    private String xdescription;

    /**
     * 显示日志脚本标识，指示用于显示日志信息的脚本
     */

    private String xdisplayLogScript;

    /**
     * 显示日志脚本文本，包含实际执行的脚本内容
     */

    private String xdisplayLogScriptText;

    /**
     * 版本，表示对象的当前版本号
     */

    private String xedition;

    /**
     * 扩展信息，用于存储附加的可扩展属性
     */

    private String xextension;

    /**
     * 表单标识，关联对象与特定的表单
     */

    private String xform;

    /**
     * 组标识，将对象归类到特定的组
     */

    private String xgroup;

    /**
     * 名称，提供对象的名称
     */

    private String xname;

    /**
     * 意见组，用于收集或归类意见
     */

    private String xopinionGroup;

    /**
     * 位置，指示对象的位置或场所
     */

    private String xposition;

    /**
     * 流程标识，关联对象与特定的流程
     */

    private String xprocess;

    /**
     * 属性，包含对象的自定义属性信息
     */

    private String xproperties;

    /**
     * 读取职责，定义谁可以读取对象信息
     */
    @Alias("readDuty")
    private String xreadDuty;

    /**
     * 读取脚本标识，指示用于读取操作的脚本
     */
    @Alias("readScript")
    private String xreadScript;

    /**
     * 读取脚本文本，包含实际执行的脚本内容
     */
    @Alias("readScriptText")
    private String xreadScriptText;

    /**
     * 审核职责，定义谁可以审核对象
     */
    @Alias("reviewDuty")
    private String xreviewDuty;

    /**
     * 审核脚本标识，指示用于审核操作的脚本
     */
    @Alias("reviewScript")
    private String xreviewScript;

    /**
     * 审核脚本文本，包含实际执行的脚本内容
     */
    @Alias("reviewScriptText")
    private String xreviewScriptText;

    /**
     * 路由信息，用于对象的路由决策或路径选择
     */
    @Alias("route")
    private String xroute;
}
