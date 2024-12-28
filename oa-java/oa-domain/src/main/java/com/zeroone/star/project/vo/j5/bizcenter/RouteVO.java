
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("流程路由信息")
public class RouteVO {
    @ApiModelProperty(value = "活动id")
    @Alias("xactivity")
    private String activity;

    @ApiModelProperty(value = "活动类型")
    @Alias("xactivityType")
    private String activityType;

    @ApiModelProperty(value = "活动别名")
    @Alias("xalias")
    private String alias;

    @ApiModelProperty(value = "附加任务身份类型")
    @Alias("xappendTaskIdentityScript")
    private String appendTaskIdentityType;

    @ApiModelProperty(value = "是否支持异步")
    private Boolean asyncSupported;

    @ApiModelProperty(value = "创建时间")
    @Alias("xcreateTime")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "决策意见")
    @Alias("xdecisionOpinion")
    private Boolean decisionOpinion;

    @ApiModelProperty(value = "活动描述")
    @Alias("xdescription")
    private String description;

    @ApiModelProperty(value = "版本")
    @Alias("xedition")
    private String edition;

    @ApiModelProperty(value = "路由id")
    @Alias("xid")
    private String id;

    @ApiModelProperty(value = "活动名称")
    @Alias("xname")
    private String name;

    @ApiModelProperty(value = "活动意见")
    @Alias("xopinion")
    private String opinion;

    @ApiModelProperty(value = "是否需要填写意见")
    @Alias("xopinionRequired")
    private Boolean opinionRequired;

    @ApiModelProperty(value = "是否通过后是否跳过")
    @Alias("xpassExpired")
    private Boolean passExpired;

    @ApiModelProperty(value = "是否通过相同的目标")
    @Alias("xpassSameTarget")
    private Boolean passSameTarget;

    @ApiModelProperty(value = "活动位置")
    @Alias("xposition")
    private String position;

    @ApiModelProperty(value = "流程id")
    @Alias("xprocess")
    private String process;

    @ApiModelProperty(value = "活动属性")
    private Object properties;

    @ApiModelProperty(value = "活动脚本文本")
    @Alias("xscriptText")
    private String scriptText;

    @ApiModelProperty(value = "是否独占")
    @Alias("xsole")
    private Boolean sole;

    @ApiModelProperty(value = "是否独占直接")
    private Boolean soleDirect;

    @ApiModelProperty(value = "是否跟踪")
    @Alias("xtrack")
    private String track;

    @ApiModelProperty(value = "活动类型")
    @Alias("xtype")
    private String type;

    @ApiModelProperty(value = "修改时间")
    @Alias("xupdateTime")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "验证脚本")
    @Alias("xvalidationScript")
    private String validationScript;

    @ApiModelProperty(value = "验证脚本文本")
    @Alias("xvalidationScriptText")
    private String validationScriptText;

    @ApiModelProperty(value = "活动脚本")
    @Alias("xscript")
    private String script;

    @ApiModelProperty(value = "选择配置")
    @Alias("xselectConfig")
    private String selectConfig;

    @ApiModelProperty(value = "排序号")
    @Alias("xorderNumber")
    private Integer orderNumber;

    @ApiModelProperty(value = "是否隐藏")
    @Alias("xhiddenScript")
    private String hiddenScript;

    @ApiModelProperty(value = "是否隐藏脚本文本")
    @Alias("xhiddenScriptText")
    private String hiddenScriptText;

    @ApiModelProperty(value = "显示名称脚本")
    @Alias("xdisplayNameScript")
    private String displayNameScript;

    @ApiModelProperty(value = "显示名称脚本文本")
    @Alias("xdisplayNameScriptText")
    private String displayNameScriptText;


}
