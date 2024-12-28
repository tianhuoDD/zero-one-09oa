package com.zeroone.star.project.vo.j5.bizcenter;


import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

import java.util.List;




@Data
@ApiModel("代理信息")
public class AgentVO {

    @ApiModelProperty(value = "代理的唯一标识符")
    @Alias("xid")
    private String id;

    @ApiModelProperty(value = "创建时间，记录代理创建的时间点")
    @Alias("xcreateTime")
    private LocalDateTime createTime;

//    @ApiModelProperty(value = "代理的序列号，用于区分不同的代理")
//    @Alias("xsequence")
//    private String xsequence;

    @ApiModelProperty(value = "更新时间，记录代理信息最近一次更新的时间")
    @Alias("xupdateTime")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "分发因子，用于代理任务分发的权重计算")
    @Alias("xdistributeFactor")
    private Integer distributeFactor;

    @ApiModelProperty(value = "到达后脚本，指定代理在到达特定状态后执行的脚本")
    @Alias("xafterArriveScript")
    private String afterArriveScript;

    @ApiModelProperty(value = "到达后脚本文本，存储脚本的具体内容")
    @Alias("xafterArriveScriptText")
    private String afterArriveScriptText;

    @ApiModelProperty(value = "执行后脚本，代理完成任务后执行的脚本")
    @Alias("xafterExecuteScript")
    private String afterExecuteScript;

    @ApiModelProperty(value = "执行后脚本文本，存储脚本的具体内容")
    @Alias("xafterExecuteScriptText")
    private String afterExecuteScriptText;

    @ApiModelProperty(value = "查询后脚本，进行查询操作后执行的脚本")
    @Alias("xafterInquireScript")
    private String afterInquireScript;

    @ApiModelProperty(value = "查询后脚本文本，存储脚本的具体内容")
    @Alias("xafterInquireScriptText")
    private String afterInquireScriptText;

    @ApiModelProperty(value = "代理中断脚本，当代理需要中断时执行的脚本")
    @Alias("xagentInterruptScript")
    private String agentInterruptScript;

    @ApiModelProperty(value = "代理中断脚本文本，存储脚本的具体内容")
    @Alias("xagentInterruptScriptText")
    private String agentInterruptScriptText;

    @ApiModelProperty(value = "代理别名，用于更友好地识别代理")
    @Alias("xalias")
    private String alias;

    @ApiModelProperty(value = "是否允许重新路由，指示代理是否可以被重新路由")
    @Alias("xallowReroute")
    private Boolean allowReroute;

    @ApiModelProperty(value = "是否允许作为重新路由目标，指示代理是否可以成为其他代理的重新路由目标")
    @Alias("xallowRerouteTo")
    private Boolean allowRerouteTo;

    @ApiModelProperty(value = "到达前脚本，代理在到达特定状态前执行的脚本")
    @Alias("xbeforeArriveScript")
    private String beforeArriveScript;

    @ApiModelProperty(value = "到达前脚本文本，存储脚本的具体内容")
    @Alias("xbeforeArriveScriptText")
    private String beforeArriveScriptText;

    @ApiModelProperty(value = "执行前脚本，代理在执行任务前运行的脚本")
    @Alias("xbeforeExecuteScript")
    private String beforeExecuteScript;

    @ApiModelProperty(value = "执行前脚本文本，存储脚本的具体内容")
    @Alias("xbeforeExecuteScriptText")
    private String beforeExecuteScriptText;

    @ApiModelProperty(value = "查询前脚本，进行查询操作前执行的脚本")
    @Alias("xbeforeInquireScript")
    private String beforeInquireScript;

    @ApiModelProperty(value = "查询前脚本文本，存储脚本的具体内容")
    @Alias("xbeforeInquireScriptText")
    private String beforeInquireScriptText;

    @ApiModelProperty(value = "描述，提供代理的详细描述信息")
    @Alias("xdescription")
    private String description;

    @ApiModelProperty(value = "显示日志脚本，用于显示日志信息的脚本")
    @Alias("xdisplayLogScript")
    private String displayLogScript;

    @ApiModelProperty(value = "显示日志脚本文本，存储脚本的具体内容")
    @Alias("xdisplayLogScriptText")
    private String displayLogScriptText;

    @ApiModelProperty(value = "版本号，表示代理的当前版本")
    @Alias("xedition")
    private String edition;

    @ApiModelProperty(value = "扩展信息，用于存储额外的扩展属性")
    @Alias("xextension")
    private String extension;

    @ApiModelProperty(value = "表单，关联的表单信息")
    @Alias("xform")
    private String form;

    @ApiModelProperty(value = "组，代理所属的组")
    @Alias("xgroup")
    private String group;

    @ApiModelProperty(value = "名称，代理的名称")
    @Alias("xname")
    private String name;

    @ApiModelProperty(value = "意见组，关联的意见组信息")
    @Alias("xopinionGroup")
    private String opinionGroup;

    @ApiModelProperty(value = "职位，代理的职位信息")
    @Alias("xposition")
    private String position;

    @ApiModelProperty(value = "流程，代理所涉及的流程")
    @Alias("xprocess")
    private String process;

    @ApiModelProperty(value = "属性，代理的属性信息")
    private Object properties;

    @ApiModelProperty(value = "阅读职责，指定谁可以阅读代理的信息")
    @Alias("xreadDuty")
    private String readDuty;

    @ApiModelProperty(value = "阅读脚本，用于阅读操作的脚本")
    @Alias("xreadScript")
    private String readScript;

    @ApiModelProperty(value = "阅读脚本文本，存储脚本的具体内容")
    @Alias("xreadScriptText")
    private String readScriptText;

    @ApiModelProperty(value = "审核职责，指定谁可以审核代理的信息")
    @Alias("xreviewDuty")
    private String reviewDuty;

    @ApiModelProperty(value = "审核脚本，用于审核操作的脚本")
    @Alias("xreviewScript")
    private String reviewScript;

    @ApiModelProperty(value = "审核脚本文本，存储脚本的具体内容")
    @Alias("xreviewScriptText")
    private String reviewScriptText;

    @ApiModelProperty(value = "路由，代理的路由信息")
    @Alias("xroute")
    private String route;

    @ApiModelProperty(value = "脚本，与代理相关的脚本")
    @Alias("xscript")
    private String script;

    @ApiModelProperty(value = "脚本文本，存储脚本的具体内容")
    @Alias("xscriptText")
    private String scriptText;

    @ApiModelProperty(value = "阅读数据路径列表")
    private List<String> readDataPathList;

    @ApiModelProperty(value = "阅读组列表")
    private List<String> readGroupList;

    @ApiModelProperty(value = "阅读单位列表")
    private List<String> readUnitList;

    @ApiModelProperty(value = "阅读身份列表")
    private List<String> readIdentityList;

    @ApiModelProperty(value = "审核数据路径列表")
    private List<String> reviewDataPathList;

    @ApiModelProperty(value = "审核组列表")
    private List<String> reviewGroupList;

    @ApiModelProperty(value = "审核单位列表")
    private List<String> reviewUnitList;

    @ApiModelProperty(value = "审核身份列表")
    private List<String> reviewIdentityList;
}
