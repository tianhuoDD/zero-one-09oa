package com.zeroone.star.bizcenter.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * 该类表示一个流程引擎的调用配置实体。
 * 它包含了流程引擎在不同阶段（如到达、执行、查询等）的脚本以及相关元数据。
 * 此类实现Serializable接口以支持对象的序列化和反序列化。
 *
 * @author xiongjian
 * @since 2024-10-27
 */
@Getter
@Setter
@TableName("pp_e_invoke")
public class PpEInvoke implements Serializable {

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
     * 是否允许作为重路由目标
     */
    private Boolean xallowRerouteTo;

    /**
     * 是否异步执行
     */
    private Boolean xasync;

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
     * 是否内部使用
     */
    private Boolean xinternal;

    /**
     * 内部项目
     */
    private String xinternalProject;

    /**
     * 调用模式
     */
    private String xinvokeMode;

    /**
     * JAX-RS地址
     */
    private String xjaxrsAddress;

    /**
     * JAX-RS请求体脚本
     */
    private String xjaxrsBodyScript;

    /**
     * JAX-RS请求体脚本文本
     */
    private String xjaxrsBodyScriptText;

    /**
     * JAX-RS内容类型
     */
    private String xjaxrsContentType;

    /**
     * JAX-RS头部脚本
     */
    private String xjaxrsHeadScript;

    /**
     * JAX-RS头部脚本文本
     */
    private String xjaxrsHeadScriptText;

    /**
     * JAX-RS请求方法
     */
    private String xjaxrsMethod;

    /**
     * JAX-RS参数脚本
     */
    private String xjaxrsParameterScript;

    /**
     * JAX-RS参数脚本文本
     */
    private String xjaxrsParameterScriptText;

    /**
     * JAX-RS响应脚本
     */
    private String xjaxrsResponseScript;

    /**
     * JAX-RS响应脚本文本
     */
    private String xjaxrsResponseScriptText;

    /**
     * JAX-RS是否使用加密
     */
    private Boolean xjaxrsWithCipher;

    /**
     * JAX-WS地址
     */
    private String xjaxwsAddress;

    /**
     * JAX-WS请求方法
     */
    private String xjaxwsMethod;

    /**
     * JAX-WS参数脚本
     */
    private String xjaxwsParameterScript;

    /**
     * JAX-WS参数脚本文本
     */
    private String xjaxwsParameterScriptText;

    /**
     * JAX-WS响应脚本
     */
    private String xjaxwsResponseScript;

    /**
     * JAX-WS响应脚本文本
     */
    private String xjaxwsResponseScriptText;

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
}
