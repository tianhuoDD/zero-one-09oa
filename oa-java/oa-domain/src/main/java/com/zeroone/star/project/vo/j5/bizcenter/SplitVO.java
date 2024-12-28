
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("流程拆分信息")
public class SplitVO {

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
//    @ApiModelProperty(value = "分配因子")
//    private Integer distributeFactor;

    @Alias("xafterArriveScript")
    @ApiModelProperty(value = "到达后脚本ID")
    private String afterArriveScript;

    @Alias("xafterArriveScriptText")
    @ApiModelProperty(value = "到达后脚本文本")
    private String afterArriveScriptText;

    @Alias("xafterExecuteScript")
    @ApiModelProperty(value = "执行后脚本ID")
    private String afterExecuteScript;

    @Alias("xafterExecuteScriptText")
    @ApiModelProperty(value = "执行后脚本文本")
    private String afterExecuteScriptText;

    @Alias("xafterInquireScript")
    @ApiModelProperty(value = "查询后脚本ID")
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
    @ApiModelProperty(value = "是否允许路由到")
    private Boolean allowRerouteTo;

    @Alias("xbeforeArriveScript")
    @ApiModelProperty(value = "到达前脚本ID")
    private String beforeArriveScript;

    @Alias("xbeforeArriveScriptText")
    @ApiModelProperty(value = "到达前脚本文本")
    private String beforeArriveScriptText;

    @Alias("xbeforeExecuteScript")
    @ApiModelProperty(value = "执行前脚本ID")
    private String beforeExecuteScript;

    @Alias("xbeforeExecuteScriptText")
    @ApiModelProperty(value = "执行前脚本文本")
    private String beforeExecuteScriptText;

    @Alias("xbeforeInquireScript")
    @ApiModelProperty(value = "查询前脚本ID")
    private String beforeInquireScript;

    @Alias("xbeforeInquireScriptText")
    @ApiModelProperty(value = "查询前脚本文本")
    private String beforeInquireScriptText;

    @Alias("xdescription")
    @ApiModelProperty(value = "描述")
    private String description;

    @Alias("xdisplayLogScript")
    @ApiModelProperty(value = "显示日志脚本ID")
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
    @ApiModelProperty(value = "表单ID")
    private String form;

    @Alias("xgroup")
    @ApiModelProperty(value = "组ID")
    private String group;

    @Alias("xname")
    @ApiModelProperty(value = "名称")
    private String name;

    @Alias("xopinionGroup")
    @ApiModelProperty(value = "意见组ID")
    private String opinionGroup;

    @Alias("xposition")
    @ApiModelProperty(value = "位置ID")
    private String position;

    @Alias("xprocess")
    @ApiModelProperty(value = "流程ID")
    private String process;

//    @Alias("xproperties")
    @ApiModelProperty(value = "属性")
    private Object properties;

    @Alias("xreadDuty")
    @ApiModelProperty(value = "读取职责ID")
    private String readDuty;

    @Alias("xreadScript")
    @ApiModelProperty(value = "读取脚本ID")
    private String readScript;

    @Alias("xreadScriptText")
    @ApiModelProperty(value = "读取脚本文本")
    private String readScriptText;

    @Alias("xreviewDuty")
    @ApiModelProperty(value = "审核职责ID")
    private String reviewDuty;

    @Alias("xreviewScript")
    @ApiModelProperty(value = "审核脚本ID")
    private String reviewScript;

    @Alias("xreviewScriptText")
    @ApiModelProperty(value = "审核脚本文本")
    private String reviewScriptText;

    @Alias("xroute")
    @ApiModelProperty(value = "路由规则ID")
    private String route;

    @Alias("xscript")
    @ApiModelProperty(value = "脚本ID")
    private String script;

    @Alias("xscriptText")
    @ApiModelProperty(value = "脚本文本")
    private String scriptText;



    private List<String> readDataPathList;

    private List<String> readGroupList;

    private List<String> readUnitList;

    private List<String> readIdentityList;

    private List<String> reviewDataPathList;

    private List<String> reviewGroupList;

    private List<String> reviewUnitList;

    private List<String> reviewIdentityList;

}
