
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("延迟信息")
public class DelayVO {

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

//    @ApiModelProperty(value = "分发因子")
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

    @ApiModelProperty(value = "是否允许作为重新路由的目标")
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

    @ApiModelProperty(value = "延迟数据路径")
    @Alias("xdelayDataPath")
    private String delayDataPath;

    @ApiModelProperty(value = "延迟分钟数")
    @Alias("xdelayMinute")
    private Integer delayMinute;

    @ApiModelProperty(value = "延迟脚本")
    @Alias("xdelayScript")
    private String delayScript;

    @ApiModelProperty(value = "延迟脚本文本")
    @Alias("xdelayScriptText")
    private String delayScriptText;

    @ApiModelProperty(value = "延迟时间")
    @Alias("xdelayTime")
    private LocalDateTime delayTime;

    @ApiModelProperty(value = "延迟类型")
    @Alias("xdelayType")
    private String delayType;

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

    @ApiModelProperty(value = "扩展信息")
    @Alias("xextension")
    private String extension;

    @ApiModelProperty(value = "表单")
    @Alias("xform")
    private String form;

    @ApiModelProperty(value = "组")
    @Alias("xgroup")
    private String group;

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

    @ApiModelProperty(value = "是否在工作时间分钟内处理")
    @Alias("xworkMinute")
    private Boolean workMinute;


    private List<String> readDataPathList;

    private List<String> readGroupList;

    private List<String> readUnitList;

    private List<String> readIdentityList;

    private List<String> reviewDataPathList;

    private List<String> reviewGroupList;

    private List<String> reviewUnitList;

    private List<String> reviewIdentityList;




}
