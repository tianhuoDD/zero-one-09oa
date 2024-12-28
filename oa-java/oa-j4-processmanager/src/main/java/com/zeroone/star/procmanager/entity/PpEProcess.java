package com.zeroone.star.procmanager.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 *  流程do
 * </p>
 *
 * @author nefertari
 * @since 2024-10-22
 */
// Lombok 注解，自动为类生成 getter 和 setter 方法
@Getter
@Setter
// MyBatis Plus 注解，指定这个类映射到数据库中的表名为 "pp_e_process"
@TableName("pp_e_process")
public class PpEProcess implements Serializable {


    // 唯一标识符
    @TableId(value = "xid",type = IdType.ASSIGN_ID)
    private String xid;

    // 创建时间
    private LocalDateTime xcreateTime;

    // 序号
    private String xsequence;

    // 更新时间
    private LocalDateTime xupdateTime;

    // 分发因子
    private Integer xdistributeFactor;

    // 到达后执行的脚本
    private String xafterArriveScript;

    // 到达后执行的脚本文本
    private String xafterArriveScriptText;

    // 开始后执行的脚本
    private String xafterBeginScript;

    // 开始后执行的脚本文本
    private String xafterBeginScriptText;

    // 结束后执行的脚本
    private String xafterEndScript;

    // 结束后执行的脚本文本
    private String xafterEndScriptText;

    // 执行后执行的脚本
    private String xafterExecuteScript;

    // 执行后执行的脚本文本
    private String xafterExecuteScriptText;

    // 询问后执行的脚本
    private String xafterInquireScript;

    // 询问后执行的脚本文本
    private String xafterInquireScriptText;

    // 别名
    private String xalias;

    // 应用程序
    private String xapplication;

    // 到达前执行的脚本
    private String xbeforeArriveScript;

    // 到达前执行的脚本文本
    private String xbeforeArriveScriptText;

    // 执行前执行的脚本
    private String xbeforeExecuteScript;

    // 执行前执行的脚本文本
    private String xbeforeExecuteScriptText;

    // 询问前执行的脚本
    private String xbeforeInquireScript;

    // 询问前执行的脚本文本
    private String xbeforeInquireScriptText;

    // 类别
    private String xcategory;

    // 是否检查草稿
    private Boolean xcheckDraft;

    // 创建人
    private String xcreatorPerson;

    // 默认开始模式
    private String xdefaultStartMode;

    // 描述
    private String xdescription;

    // 版本
    private String xedition;

    // 版本描述
    private String xeditionDes;

    // 版本是否启用
    private Boolean xeditionEnable;

    // 版本名称
    private String xeditionName;

    // 版本号
    private Double xeditionNumber;

    // 过期天数
    private Integer xexpireDay;

    // 过期小时数
    private Integer xexpireHour;

    // 过期类型
    private String xexpireType;

    // 是否在工作时间过期
    private Boolean xexpireWorkTime;

    // 图标
    private String xicon;

    // 最后更新人
    private String xlastUpdatePerson;

    // 最后更新时间
    private LocalDateTime xlastUpdateTime;

    // 名称
    private String xname;

    // 投影
    private String xprojection;

    // 是否完全投影
    private Boolean xprojectionFully;

    // 属性
    private String xproperties;

    // 是否将路由名称作为意见
    private Boolean xrouteNameAsOpinion;

    // 串行活动
    private String xserialActivity;

    // 串行阶段
    private String xserialPhase;

    // 串行纹理
    private String xserialTexture;

    // 可启动的终端
    private String xstartableTerminal;

}
