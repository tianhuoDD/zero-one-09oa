
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel(value = "平行节点")
public class ParallelVO {

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
    @ApiModelProperty(value = "到达后脚本标识")
    private String afterArriveScript;

    @Alias("xafterArriveScriptText")
    @ApiModelProperty(value = "到达后脚本文本")
    private String afterArriveScriptText;

    @Alias("xafterExecuteScript")
    @ApiModelProperty(value = "执行后脚本标识")
    private String afterExecuteScript;

    @Alias("xafterExecuteScriptText")
    @ApiModelProperty(value = "执行后脚本文本")
    private String afterExecuteScriptText;

    @Alias("xafterInquireScript")
    @ApiModelProperty(value = "查询后脚本标识")
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
    @ApiModelProperty(value = "是否允许作为重新路由的目标")
    private Boolean allowRerouteTo;

    @Alias("xbeforeArriveScript")
    @ApiModelProperty(value = "到达前脚本标识")
    private String beforeArriveScript;

    @Alias("xbeforeArriveScriptText")
    @ApiModelProperty(value = "到达前脚本文本")
    private String beforeArriveScriptText;

    @Alias("xbeforeExecuteScript")
    @ApiModelProperty(value = "执行前脚本标识")
    private String beforeExecuteScript;

    @Alias("xbeforeExecuteScriptText")
    @ApiModelProperty(value = "执行前脚本文本")
    private String beforeExecuteScriptText;

    @Alias("xbeforeInquireScript")
    @ApiModelProperty(value = "查询前脚本标识")
    private String beforeInquireScript;

    @Alias("xbeforeInquireScriptText")
    @ApiModelProperty(value = "查询前脚本文本")
    private String beforeInquireScriptText;

    @Alias("xdescription")
    @ApiModelProperty(value = "描述")
    private String description;

    @Alias("xdisplayLogScript")
    @ApiModelProperty(value = "显示日志脚本标识")
    private String displayLogScript;

    @Alias("xdisplayLogScriptText")
    @ApiModelProperty(value = "显示日志脚本文本")
    private String displayLogScriptText;

    @Alias("xedition")
    @ApiModelProperty(value = "版本号")
    private String edition;

    @Alias("xextension")
    @ApiModelProperty(value = "扩展信息")
    private String extension;

    @Alias("xform")
    @ApiModelProperty(value = "表单标识")
    private String form;

    @Alias("xgroup")
    @ApiModelProperty(value = "组标识")
    private String group;

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
    @ApiModelProperty(value = "流程标识")
    private String process;


    @ApiModelProperty(value = "属性")
    private Object properties;

    @Alias("xreadDuty")
    @ApiModelProperty(value = "读取职责")
    private String readDuty;

    @Alias("xreadScript")
    @ApiModelProperty(value = "读取脚本标识")
    private String readScript;

    @Alias("xreadScriptText")
    @ApiModelProperty(value = "读取脚本文本")
    private String readScriptText;

    @Alias("xreviewDuty")
    @ApiModelProperty(value = "审核职责")
    private String reviewDuty;

    @Alias("xreviewScript")
    @ApiModelProperty(value = "审核脚本标识")
    private String reviewScript;

    @Alias("xreviewScriptText")
    @ApiModelProperty(value = "审核脚本文本")
    private String reviewScriptText;

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
