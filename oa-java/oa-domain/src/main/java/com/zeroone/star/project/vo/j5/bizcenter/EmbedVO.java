
package com.zeroone.star.project.vo.j5.bizcenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import cn.hutool.core.annotation.Alias;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("嵌入流程信息")
public class EmbedVO {


    @ApiModelProperty(value = "唯一标识符")
    @Alias("xid")
    private String id;

    @ApiModelProperty(value = "创建时间")
    @Alias("xcreateTime")
    private LocalDateTime createTime;

//    @ApiModelProperty(value = "序列号")
//    @Alias("xsequence")
//    private String sequence;

    @ApiModelProperty(value = "更新时间")
    @Alias("xupdateTime")
    private LocalDateTime updateTime;
//
//    @ApiModelProperty(value = "分配因子")
//    @Alias("xdistributeFactor")
//    private Integer distributeFactor;

    @ApiModelProperty(value = "到达后脚本")
    @Alias("xafterArriveScript")
    private String afterArriveScript;

    @ApiModelProperty(value = "到达后脚本文本")
    @Alias("xafterArriveScriptText")
    private String afterArriveScriptText;

    @ApiModelProperty(value = "执行后脚本")
    @Alias("xafterExecuteScript")
    private String afterExecuteScript;

    @ApiModelProperty(value = "执行后脚本文本")
    @Alias("xafterExecuteScriptText")
    private String afterExecuteScriptText;

    @ApiModelProperty(value = "查询后脚本")
    @Alias("xafterInquireScript")
    private String afterInquireScript;

    @ApiModelProperty(value = "查询后脚本文本")
    @Alias("xafterInquireScriptText")
    private String afterInquireScriptText;

    @ApiModelProperty(value = "别名")
    @Alias("xalias")
    private String alias;

    @ApiModelProperty(value = "是否允许重新路由")
    @Alias("xallowReroute")
    private Boolean allowReroute;

    @ApiModelProperty(value = "是否允许路由到")
    @Alias("xallowRerouteTo")
    private Boolean allowRerouteTo;

    @ApiModelProperty(value = "到达前脚本")
    @Alias("xbeforeArriveScript")
    private String beforeArriveScript;

    @ApiModelProperty(value = "到达前脚本文本")
    @Alias("xbeforeArriveScriptText")
    private String beforeArriveScriptText;

    @ApiModelProperty(value = "执行前脚本")
    @Alias("xbeforeExecuteScript")
    private String beforeExecuteScript;

    @ApiModelProperty(value = "执行前脚本文本")
    @Alias("xbeforeExecuteScriptText")
    private String beforeExecuteScriptText;

    @ApiModelProperty(value = "查询前脚本")
    @Alias("xbeforeInquireScript")
    private String beforeInquireScript;

    @ApiModelProperty(value = "查询前脚本文本")
    @Alias("xbeforeInquireScriptText")
    private String beforeInquireScriptText;

    @ApiModelProperty(value = "描述")
    @Alias("xdescription")
    private String description;

    @ApiModelProperty(value = "显示日志脚本")
    @Alias("xdisplayLogScript")
    private String displayLogScript;

    @ApiModelProperty(value = "显示日志脚本文本")
    @Alias("xdisplayLogScriptText")
    private String displayLogScriptText;

    @ApiModelProperty(value = "版本")
    @Alias("xedition")
    private String edition;

    @ApiModelProperty(value = "嵌入创建者类型")
    @Alias("xembedCreatorType")
    private String embedCreatorType;

    @ApiModelProperty(value = "扩展名")
    @Alias("xextension")
    private String extension;

    @ApiModelProperty(value = "表单")
    @Alias("xform")
    private String form;

    @ApiModelProperty(value = "组")
    @Alias("xgroup")
    private String group;

    @ApiModelProperty(value = "是否继承附件")
    @Alias("xinheritAttachment")
    private Boolean inheritAttachment;

    @ApiModelProperty(value = "是否继承数据")
    @Alias("xinheritData")
    private Boolean inheritData;

    @ApiModelProperty(value = "名称")
    @Alias("xname")
    private String name;

    @ApiModelProperty(value = "意见组")
    @Alias("xopinionGroup")
    private String opinionGroup;

    @ApiModelProperty(value = "位置")
    @Alias("xposition")
    private String position;

    @ApiModelProperty(value = "流程")
    @Alias("xprocess")
    private String process;

    @ApiModelProperty(value = "属性")
    private Object properties;

    @ApiModelProperty(value = "读取职责")
    @Alias("xreadDuty")
    private String readDuty;

    @ApiModelProperty(value = "读取脚本")
    @Alias("xreadScript")
    private String readScript;

    @ApiModelProperty(value = "读取脚本文本")
    @Alias("xreadScriptText")
    private String readScriptText;

    @ApiModelProperty(value = "审核职责")
    @Alias("xreviewDuty")
    private String reviewDuty;

    @ApiModelProperty(value = "审核脚本")
    @Alias("xreviewScript")
    private String reviewScript;

    @ApiModelProperty(value = "审核脚本文本")
    @Alias("xreviewScriptText")
    private String reviewScriptText;

    @ApiModelProperty(value = "路由")
    @Alias("xroute")
    private String route;

    @ApiModelProperty(value = "目标应用程序")
    @Alias("xtargetApplication")
    private String targetApplication;

    @ApiModelProperty(value = "目标应用程序别名")
    @Alias("xtargetApplicationAlias")
    private String targetApplicationAlias;

    @ApiModelProperty(value = "目标应用程序名称")
    @Alias("xtargetApplicationName")
    private String targetApplicationName;

    @ApiModelProperty(value = "目标分配数据脚本")
    @Alias("xtargetAssginDataScript")
    private String targetAssginDataScript;

    @ApiModelProperty(value = "目标分配数据脚本文本")
    @Alias("xtargetAssginDataScriptText")
    private String targetAssginDataScriptText;

    @ApiModelProperty(value = "目标身份")
    @Alias("xtargetIdentity")
    private String targetIdentity;

    @ApiModelProperty(value = "目标身份脚本")
    @Alias("xtargetIdentityScript")
    private String targetIdentityScript;

    @ApiModelProperty(value = "目标身份脚本文本")
    @Alias("xtargetIdentityScriptText")
    private String targetIdentityScriptText;

    @ApiModelProperty(value = "目标流程")
    @Alias("xtargetProcess")
    private String targetProcess;

    @ApiModelProperty(value = "目标流程别名")
    @Alias("xtargetProcessAlias")
    private String targetProcessAlias;

    @ApiModelProperty(value = "目标流程名称")
    @Alias("xtargetProcessName")
    private String targetProcessName;

    @ApiModelProperty(value = "目标标题脚本")
    @Alias("xtargetTitleScript")
    private String targetTitleScript;

    @ApiModelProperty(value = "目标标题脚本文本")
    @Alias("xtargetTitleScriptText")
    private String targetTitleScriptText;

    @ApiModelProperty(value = "是否等待直到完成")
    @Alias("xwaitUntilCompleted")
    private Boolean waitUntilCompleted;

    private List<String> readDataPathList;

    private List<String> readGroupList;

    private List<String> readUnitList;

    private List<String> readIdentityList;

    private List<String> reviewDataPathList;

    private List<String> reviewGroupList;

    private List<String> reviewUnitList;

    private List<String> reviewIdentityList;



}
