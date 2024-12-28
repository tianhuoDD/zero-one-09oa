
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("服务信息")
public class ServiceVO {

    @Alias("xid")
    @ApiModelProperty(value = "服务的唯一标识符")
    private String id;

    @Alias("xcreateTime")
    @ApiModelProperty(value = "服务的创建时间")
    private LocalDateTime createTime;

//    @Alias("xsequence")
//    @ApiModelProperty(value = "服务的序列号")
//    private String sequence;

    @Alias("xupdateTime")
    @ApiModelProperty(value = "服务的更新时间")
    private LocalDateTime updateTime;
//
//    @Alias("xdistributeFactor")
//    @ApiModelProperty(value = "分发因子，用于服务分发的权重或优先级")
//    private Integer distributeFactor;

    @Alias("xafterArriveScript")
    @ApiModelProperty(value = "到达后执行的脚本，用于处理服务到达后的逻辑")
    private String afterArriveScript;

    @Alias("xafterArriveScriptText")
    @ApiModelProperty(value = "到达后执行脚本的文本内容")
    private String afterArriveScriptText;

    @Alias("xafterExecuteScript")
    @ApiModelProperty(value = "执行后执行的脚本，用于处理服务执行后的逻辑")
    private String afterExecuteScript;

    @Alias("xafterExecuteScriptText")
    @ApiModelProperty(value = "执行后执行脚本的文本内容")
    private String afterExecuteScriptText;

    @Alias("xafterInquireScript")
    @ApiModelProperty(value = "查询后执行的脚本，用于处理服务查询后的逻辑")
    private String afterInquireScript;

    @Alias("xafterInquireScriptText")
    @ApiModelProperty(value = "查询后执行脚本的文本内容")
    private String afterInquireScriptText;

    @Alias("xalias")
    @ApiModelProperty(value = "服务的别名")
    private String alias;

    @Alias("xallowReroute")
    @ApiModelProperty(value = "是否允许重新路由服务")
    private Boolean allowReroute;

    @Alias("xallowRerouteTo")
    @ApiModelProperty(value = "是否允许作为重新路由的目标")
    private Boolean allowRerouteTo;

    @Alias("xbeforeArriveScript")
    @ApiModelProperty(value = "到达前执行的脚本，用于处理服务到达前的逻辑")
    private String beforeArriveScript;

    @Alias("xbeforeArriveScriptText")
    @ApiModelProperty(value = "到达前执行脚本的文本内容")
    private String beforeArriveScriptText;

    @Alias("xbeforeExecuteScript")
    @ApiModelProperty(value = "执行前执行的脚本，用于处理服务执行前的逻辑")
    private String beforeExecuteScript;

    @Alias("xbeforeExecuteScriptText")
    @ApiModelProperty(value = "执行前执行脚本的文本内容")
    private String beforeExecuteScriptText;

    @Alias("xbeforeInquireScript")
    @ApiModelProperty(value = "查询前执行的脚本，用于处理服务查询前的逻辑")
    private String beforeInquireScript;

    @Alias("xbeforeInquireScriptText")
    @ApiModelProperty(value = "查询前执行脚本的文本内容")
    private String beforeInquireScriptText;

    @Alias("xdescription")
    @ApiModelProperty(value = "服务的描述信息")
    private String description;

    @Alias("xdisplayLogScript")
    @ApiModelProperty(value = "显示日志的脚本，用于记录服务的日志信息")
    private String displayLogScript;

    @Alias("xdisplayLogScriptText")
    @ApiModelProperty(value = "显示日志脚本的文本内容")
    private String displayLogScriptText;

    @Alias("xedition")
    @ApiModelProperty(value = "服务的版本号")
    private String edition;

    @Alias("xextension")
    @ApiModelProperty(value = "服务的扩展信息")
    private String extension;

    @Alias("xform")
    @ApiModelProperty(value = "服务的表单信息")
    private String form;

    @Alias("xgroup")
    @ApiModelProperty(value = "服务所属的组")
    private String group;

    @Alias("xname")
    @ApiModelProperty(value = "服务的名称")
    private String name;

    @Alias("xopinionGroup")
    @ApiModelProperty(value = "意见组，用于收集服务的反馈意见")
    private String opinionGroup;

    @Alias("xposition")
    @ApiModelProperty(value = "服务的位置信息")
    private String position;

    @Alias("xprocess")
    @ApiModelProperty(value = "服务的处理流程")
    private String process;

//    @Alias("xproperties")
    @ApiModelProperty(value = "服务的属性信息")
    private Object properties;

    @Alias("xreadDuty")
    @ApiModelProperty(value = "服务的读取职责，定义谁可以读取服务信息")
    private String readDuty;

    @Alias("xreadScript")
    @ApiModelProperty(value = "服务的读取脚本")
    private String readScript;

    @Alias("xreadScriptText")
    @ApiModelProperty(value = "读取脚本的文本内容")
    private String readScriptText;

    @Alias("xreviewDuty")
    @ApiModelProperty(value = "服务的审核职责，定义谁可以审核服务")
    private String reviewDuty;

    @Alias("xreviewScript")
    @ApiModelProperty(value = "服务的审核脚本")
    private String reviewScript;

    @Alias("xreviewScriptText")
    @ApiModelProperty(value = "审核脚本的文本内容")
    private String reviewScriptText;

    @Alias("xroute")
    @ApiModelProperty(value = "服务的路由信息")
    private String route;

    @Alias("xscript")
    @ApiModelProperty(value = "服务的脚本")
    private String script;

    @Alias("xscriptText")
    @ApiModelProperty(value = "脚本的文本内容")
    private String scriptText;



    private List<String> readDataPathList;

    private List<String> readGroupList;

    private List<String> readUnitList;

    private List<String> readIdentityList;

    private List<String> reviewDataPathList;

    private List<String> reviewGroupList;

    private List<String> reviewUnitList;

    private List<String> reviewIdentityList;

    private List<String> trustaddresslist;
}


