
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("流程合并信息")
public class MergeVO {

    @Alias("xid")
    @ApiModelProperty(value = "节点ID，唯一标识一个合并节点")
    private String id;

    @Alias("xcreateTime")
    @ApiModelProperty(value = "创建时间，记录该节点配置的创建时间")
    private LocalDateTime createTime;

//    @Alias("xsequence")
//    @ApiModelProperty(value = "序列号，用于区分不同版本的节点配置")
//    private String sequence;

    @Alias("xupdateTime")
    @ApiModelProperty(value = "更新时间，记录该节点配置的最近更新时间")
    private LocalDateTime updateTime;

//    @Alias("xdistributeFactor")
//    @ApiModelProperty(value = "分发因子，决定任务分发的策略")
//    private Integer distributeFactor;

    @Alias("xafterArriveScript")
    @ApiModelProperty(value = "到达后脚本ID，用于执行到达节点后的脚本")
    private String afterArriveScript;

    @Alias("xafterArriveScriptText")
    @ApiModelProperty(value = "到达后脚本内容，存储实际的脚本代码")
    private String afterArriveScriptText;

    @Alias("xafterExecuteScript")
    @ApiModelProperty(value = "执行后脚本ID，用于执行节点任务完成后脚本")
    private String afterExecuteScript;

    @Alias("xafterExecuteScriptText")
    @ApiModelProperty(value = "执行后脚本内容，存储实际的脚本代码")
    private String afterExecuteScriptText;

    @Alias("xafterInquireScript")
    @ApiModelProperty(value = "查询后脚本ID，用于执行查询相关信息后的脚本")
    private String afterInquireScript;

    @Alias("xafterInquireScriptText")
    @ApiModelProperty(value = "查询后脚本内容，存储实际的脚本代码")
    private String afterInquireScriptText;

    @Alias("xalias")
    @ApiModelProperty(value = "节点别名，用于更直观地标识节点")
    private String alias;

    @Alias("xallowReroute")
    @ApiModelProperty(value = "是否允许重新路由，控制任务是否可以被重新分配")
    private Boolean allowReroute;

    @Alias("xallowRerouteTo")
    @ApiModelProperty(value = "是否允许作为重路由目标，控制节点是否可以成为任务重分配的目标")
    private Boolean allowRerouteTo;

    @Alias("xbeforeArriveScript")
    @ApiModelProperty(value = "到达前脚本ID，用于执行任务到达节点前的脚本")
    private String beforeArriveScript;

    @Alias("xbeforeArriveScriptText")
    @ApiModelProperty(value = "到达前脚本内容，存储实际的脚本代码")
    private String beforeArriveScriptText;

    @Alias("xbeforeExecuteScript")
    @ApiModelProperty(value = "执行前脚本ID，用于执行节点任务开始前的脚本")
    private String beforeExecuteScript;

    @Alias("xbeforeExecuteScriptText")
    @ApiModelProperty(value = "执行前脚本内容，存储实际的脚本代码")
    private String beforeExecuteScriptText;

    @Alias("xbeforeInquireScript")
    @ApiModelProperty(value = "查询前脚本ID，用于执行查询相关信息前的脚本")
    private String beforeInquireScript;

    @Alias("xbeforeInquireScriptText")
    @ApiModelProperty(value = "查询前脚本内容，存储实际的脚本代码")
    private String beforeInquireScriptText;

    @Alias("xdescription")
    @ApiModelProperty(value = "节点描述，对节点功能或用途的详细说明")
    private String description;

    @Alias("xdisplayLogScript")
    @ApiModelProperty(value = "显示日志脚本ID，用于执行显示日志信息的脚本")
    private String displayLogScript;

    @Alias("xdisplayLogScriptText")
    @ApiModelProperty(value = "显示日志脚本内容，存储实际的脚本代码")
    private String displayLogScriptText;

    @Alias("xedition")
    @ApiModelProperty(value = "版本号，标识节点配置的版本")
    private String edition;

    @Alias("xextension")
    @ApiModelProperty(value = "扩展信息，用于存储额外的配置或信息")
    private String extension;

    @Alias("xform")
    @ApiModelProperty(value = "表单ID，关联的表单用于任务处理")
    private String form;

    @Alias("xgroup")
    @ApiModelProperty(value = "组ID，标识节点所属的组")
    private String group;

    @Alias("xname")
    @ApiModelProperty(value = "节点名称，对节点的直观称呼")
    private String name;

    @Alias("xopinionGroup")
    @ApiModelProperty(value = "意见组ID，用于收集任务处理的意见")
    private String opinionGroup;

    @Alias("xposition")
    @ApiModelProperty(value = "位置ID，标识节点在流程中的位置")
    private String position;

    @Alias("xprocess")
    @ApiModelProperty(value = "流程ID，标识节点所属的流程")
    private String process;

    @ApiModelProperty(value = "属性，存储节点的额外属性信息")
    private Object properties;

    @Alias("xreadDuty")
    @ApiModelProperty(value = "读取职责ID，定义谁可以读取节点的相关信息")
    private String readDuty;

    @Alias("xreadScript")
    @ApiModelProperty(value = "读取脚本ID，用于执行读取操作前的脚本")
    private String readScript;

    @Alias("xreadScriptText")
    @ApiModelProperty(value = "读取脚本内容，存储实际的脚本代码")
    private String readScriptText;

    @Alias("xreviewDuty")
    @ApiModelProperty(value = "审核职责ID，定义谁可以审核节点的任务")
    private String reviewDuty;

    @Alias("xreviewScript")
    @ApiModelProperty(value = "审核脚本ID，用于执行审核操作前的脚本")
    private String reviewScript;

    @Alias("xreviewScriptText")
    @ApiModelProperty(value = "审核脚本内容，存储实际的脚本代码")
    private String reviewScriptText;

    @Alias("xroute")
    @ApiModelProperty(value = "路由信息，定义节点之间的路由规则")
    private String route;

    private List<String> readDataPathList;

    private List<String> readGroupList;

    private List<String> readUnitList;

    private List<String> readIdentityList;

    private List<String> reviewDataPathList;

    private List<String> reviewGroupList;

    private List<String> reviewUnitList;

    private List<String> reviewIdentityList;

}
