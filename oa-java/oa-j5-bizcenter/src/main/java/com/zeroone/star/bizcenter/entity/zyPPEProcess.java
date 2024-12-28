package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 流程实体类，映射到数据库中的pp_e_process表。
 */
@Data
@TableName("pp_e_process")
public class zyPPEProcess {

    @TableId(value = "xid",type =IdType.ASSIGN_ID )//雪花算法生成ID
    private String xid; // 流程ID

    @TableField("xcreateTime")
    private LocalDateTime xcreateTime; // 创建时间

    @TableField("xsequence")
    private String xsequence; // 序列

    @TableField("xupdateTime")
    private LocalDateTime xupdateTime; // 更新时间

    @TableField("xdistributeFactor")
    private Integer xdistributeFactor; // 分发因子

    @TableField("xafterArriveScript")
    private String xafterArriveScript; // 到达后执行的脚本名称

    @TableField("xafterArriveScriptText")
    private String xafterArriveScriptText; // 到达后执行的脚本内容

    @TableField("xafterBeginScript")
    private String xafterBeginScript; // 开始后执行的脚本名称

    @TableField("xafterBeginScriptText")
    private String xafterBeginScriptText; // 开始后执行的脚本内容

    @TableField("xafterEndScript")
    private String xafterEndScript; // 结束后执行的脚本名称

    @TableField("xafterEndScriptText")
    private String xafterEndScriptText; // 结束后执行的脚本内容

    @TableField("xafterExecuteScript")
    private String xafterExecuteScript; // 执行后执行的脚本名称

    @TableField("xafterExecuteScriptText")
    private String xafterExecuteScriptText; // 执行后执行的脚本内容

    @TableField("xafterInquireScript")
    private String xafterInquireScript; // 询问后执行的脚本名称

    @TableField("xafterInquireScriptText")
    private String xafterInquireScriptText; // 询问后执行的脚本内容

    @TableField("xalias")
    private String xalias; // 别名

    @TableField("xapplication")
    private String xapplication; // 应用ID

    @TableField("xbeforeArriveScript")
    private String xbeforeArriveScript; // 到达前执行的脚本名称

    @TableField("xbeforeArriveScriptText")
    private String xbeforeArriveScriptText; // 到达前执行的脚本内容

    @TableField("xbeforeExecuteScript")
    private String xbeforeExecuteScript; // 执行前执行的脚本名称

    @TableField("xbeforeExecuteScriptText")
    private String xbeforeExecuteScriptText; // 执行前执行的脚本内容

    @TableField("xbeforeInquireScript")
    private String xbeforeInquireScript; // 询问前执行的脚本名称

    @TableField("xbeforeInquireScriptText")
    private String xbeforeInquireScriptText; // 询问前执行的脚本内容

    @TableField("xcategory")
    private String xcategory; // 类别

    @TableField("xcheckDraft")
    private Boolean xcheckDraft; // 是否检查草稿

    @TableField("xcreatorPerson")
    private String xcreatorPerson; // 创建人

    @TableField("xdefaultStartMode")
    private String xdefaultStartMode; // 默认启动模式

    @TableField("xdescription")
    private String xdescription; // 描述

    @TableField("xedition")
    private String xedition; // 版本

    @TableField("xeditionDes")
    private String xeditionDes; // 版本描述

    @TableField("xeditionEnable")
    private Boolean xeditionEnable; // 是否启用版本

    @TableField("xeditionName")
    private String xeditionName; // 版本名称

    @TableField("xeditionNumber")
    private Double xeditionNumber; // 版本号

    @TableField("xexpireDay")
    private Integer xexpireDay; // 过期天数

    @TableField("xexpireHour")
    private Integer xexpireHour; // 过期小时数

    @TableField("xexpireType")
    private String xexpireType; // 过期类型

    @TableField("xexpireWorkTime")
    private Boolean xexpireWorkTime; // 是否工作时间内过期

    @TableField("xicon")
    private String xicon; // 图标

    @TableField("xlastUpdatePerson")
    private String xlastUpdatePerson; // 最后更新人

    @TableField("xlastUpdateTime")
    private LocalDateTime xlastUpdateTime; // 最后更新时间

    @TableField("xname")
    private String xname; // 名称

    @TableField("xprojection")
    private String xprojection; // 投影

    @TableField("xprojectionFully")
    private Boolean xprojectionFully; // 是否完全投影

    @TableField("xproperties")
    private String xproperties; // 属性

    @TableField("xrouteNameAsOpinion")
    private Boolean xrouteNameAsOpinion; // 路由名称作为意见

    @TableField("xserialActivity")
    private String xserialActivity; // 串行活动

    @TableField("xserialPhase")
    private String xserialPhase; // 串行阶段

    @TableField("xserialTexture")
    private String xserialTexture; // 串行纹理

    @TableField("xstartableTerminal")
    private String xstartableTerminal; // 可启动终端
}