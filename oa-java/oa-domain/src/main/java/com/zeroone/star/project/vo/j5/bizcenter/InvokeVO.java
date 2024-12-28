
package com.zeroone.star.project.vo.j5.bizcenter;


import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("流程调用信息")
public class InvokeVO {

    @Alias("xid")
    @ApiModelProperty(value = "唯一标识符")
    private String id;

    @Alias("xcreateTime")
    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

//    @Alias("xsequence")
//    @ApiModelProperty(value = "序列号")
//    private String sequence;

    @Alias("xupdateTime")
    @ApiModelProperty(value = "更新时间")
    private LocalDateTime updateTime;
//
//    @Alias("xdistributeFactor")
//    @ApiModelProperty(value = "分发因子")
//    private Integer distributeFactor;

    @Alias("xafterArriveScript")
    @ApiModelProperty(value = "到达后脚本")
    private String afterArriveScript;

    @Alias("xafterArriveScriptText")
    @ApiModelProperty(value = "到达后脚本文本")
    private String afterArriveScriptText;

    @Alias("xafterExecuteScript")
    @ApiModelProperty(value = "执行后脚本")
    private String afterExecuteScript;

    @Alias("xafterExecuteScriptText")
    @ApiModelProperty(value = "执行后脚本文本")
    private String afterExecuteScriptText;

    @Alias("xafterInquireScript")
    @ApiModelProperty(value = "查询后脚本")
    private String afterInquireScript;

    @Alias("xafterInquireScriptText")
    @ApiModelProperty(value = "查询后脚本文本")
    private String afterInquireScriptText;

    @Alias("xalias")
    @ApiModelProperty(value = "别名")
    private String alias;

    @Alias("xallowReroute")
    @ApiModelProperty(value = "是否允许重新路由")
    private Boolean allowReroute;

    @Alias("xallowRerouteTo")
    @ApiModelProperty(value = "是否允许作为重路由目标")
    private Boolean allowRerouteTo;

    @Alias("xasync")
    @ApiModelProperty(value = "是否异步执行")
    private Boolean async;

    @Alias("xbeforeArriveScript")
    @ApiModelProperty(value = "到达前脚本")
    private String beforeArriveScript;

    @Alias("xbeforeArriveScriptText")
    @ApiModelProperty(value = "到达前脚本文本")
    private String beforeArriveScriptText;

    @Alias("xbeforeExecuteScript")
    @ApiModelProperty(value = "执行前脚本")
    private String beforeExecuteScript;

    @Alias("xbeforeExecuteScriptText")
    @ApiModelProperty(value = "执行前脚本文本")
    private String beforeExecuteScriptText;

    @Alias("xbeforeInquireScript")
    @ApiModelProperty(value = "查询前脚本")
    private String beforeInquireScript;

    @Alias("xbeforeInquireScriptText")
    @ApiModelProperty(value = "查询前脚本文本")
    private String beforeInquireScriptText;

    @Alias("xdescription")
    @ApiModelProperty(value = "描述")
    private String description;

    @Alias("xdisplayLogScript")
    @ApiModelProperty(value = "显示日志脚本")
    private String displayLogScript;

    @Alias("xdisplayLogScriptText")
    @ApiModelProperty(value = "显示日志脚本文本")
    private String displayLogScriptText;

    @Alias("xedition")
    @ApiModelProperty(value = "版本")
    private String edition;

    @Alias("xextension")
    @ApiModelProperty(value = "扩展信息")
    private String extension;

    @Alias("xform")
    @ApiModelProperty(value = "表单")
    private String form;

    @Alias("xgroup")
    @ApiModelProperty(value = "组")
    private String group;

    @Alias("xinternal")
    @ApiModelProperty(value = "是否内部使用")
    private Boolean internal;

    @Alias("xinternalProject")
    @ApiModelProperty(value = "内部项目")
    private String internalProject;

    @Alias("xinvokeMode")
    @ApiModelProperty(value = "调用模式")
    private String invokeMode;

    @Alias("xjaxrsAddress")
    @ApiModelProperty(value = "JAX-RS地址")
    private String jaxrsAddress;

    @Alias("xjaxrsBodyScript")
    @ApiModelProperty(value = "JAX-RS请求体脚本")
    private String jaxrsBodyScript;

    @Alias("xjaxrsBodyScriptText")
    @ApiModelProperty(value = "JAX-RS请求体脚本文本")
    private String jaxrsBodyScriptText;

    @Alias("xjaxrsContentType")
    @ApiModelProperty(value = "JAX-RS内容类型")
    private String jaxrsContentType;

    @Alias("xjaxrsHeadScript")
    @ApiModelProperty(value = "JAX-RS头部脚本")
    private String jaxrsHeadScript;

    @Alias("xjaxrsHeadScriptText")
    @ApiModelProperty(value = "JAX-RS头部脚本文本")
    private String jaxrsHeadScriptText;

    @Alias("xjaxrsMethod")
    @ApiModelProperty(value = "JAX-RS请求方法")
    private String jaxrsMethod;

    @Alias("xjaxrsParameterScript")
    @ApiModelProperty(value = "JAX-RS参数脚本")
    private String jaxrsParameterScript;

    @Alias("xjaxrsParameterScriptText")
    @ApiModelProperty(value = "JAX-RS参数脚本文本")
    private String jaxrsParameterScriptText;

    @Alias("xjaxrsResponseScript")
    @ApiModelProperty(value = "JAX-RS响应脚本")
    private String jaxrsResponseScript;

    @Alias("xjaxrsResponseScriptText")
    @ApiModelProperty(value = "JAX-RS响应脚本文本")
    private String jaxrsResponseScriptText;

    @Alias("xjaxrsWithCipher")
    @ApiModelProperty(value = "JAX-RS是否使用加密")
    private Boolean jaxrsWithCipher;

    @Alias("xjaxwsAddress")
    @ApiModelProperty(value = "JAX-WS地址")
    private String jaxwsAddress;

    @Alias("xjaxwsMethod")
    @ApiModelProperty(value = "JAX-WS请求方法")
    private String jaxwsMethod;

    @Alias("xjaxwsParameterScript")
    @ApiModelProperty(value = "JAX-WS参数脚本")
    private String jaxwsParameterScript;

    @Alias("xjaxwsParameterScriptText")
    @ApiModelProperty(value = "JAX-WS参数脚本文本")
    private String jaxwsParameterScriptText;

    @Alias("xjaxwsResponseScript")
    @ApiModelProperty(value = "JAX-WS响应脚本")
    private String jaxwsResponseScript;

    @Alias("xjaxwsResponseScriptText")
    @ApiModelProperty(value = "JAX-WS响应脚本文本")
    private String jaxwsResponseScriptText;

    @Alias("xname")
    @ApiModelProperty(value = "名称")
    private String name;

    @Alias("xopinionGroup")
    @ApiModelProperty(value = "意见组")
    private String opinionGroup;

    @Alias("xposition")
    @ApiModelProperty(value = "位置")
    private String position;

    @Alias("xprocess")
    @ApiModelProperty(value = "流程")
    private String process;

    @ApiModelProperty(value = "属性")
    private Object properties;

    @Alias("xreadDuty")
    @ApiModelProperty(value = "读取职责")
    private String readDuty;

    @Alias("xreadScript")
    @ApiModelProperty(value = "读取脚本")
    private String readScript;

    @Alias("xreadScriptText")
    @ApiModelProperty(value = "读取脚本文本")
    private String readScriptText;

    @Alias("xreviewDuty")
    @ApiModelProperty(value = "审核职责")
    private String reviewDuty;

    @Alias("xreviewScript")
    @ApiModelProperty(value = "审核脚本")
    private String reviewScript;

    @Alias("xreviewScriptText")
    @ApiModelProperty(value = "审核脚本文本")
    private String reviewScriptText;

    @Alias("xroute")
    @ApiModelProperty(value = "路由")
    private String route;


    private List<String> readDataPathList;

    private List<String> readGroupList;

    private List<String> readUnitList;

    private List<String> readIdentityList;

    private List<String> reviewDataPathList;

    private List<String> reviewGroupList;

    private List<String> reviewUnitList;

    private List<String> reviewIdentityList;

    private List<String> routeList;

}
