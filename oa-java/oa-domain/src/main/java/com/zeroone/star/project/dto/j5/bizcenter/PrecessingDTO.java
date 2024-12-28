package com.zeroone.star.project.dto.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("继续流转")
public class PrecessingDTO {


    @ApiModelProperty("待办处理类型")
    private String act;

    @ApiModelProperty(value = "活动标识")
    @Alias("xactivity")
    private String activity;

    @ApiModelProperty(value = "活动别名")
    @Alias("xactivityAlias")
    private String activityAlias;

    @ApiModelProperty(value = "活动描述")
    @Alias("xactivityDescription")
    private String activityDescription;


    @ApiModelProperty(value = "活动名称")
    @Alias("xactivityName")
    private String activityName;

    @ApiModelProperty(value = "活动令牌")
    @Alias("xactivityToken")
    private String activityToken;

    @ApiModelProperty(value = "活动类型")
    @Alias("xactivityType")
    private String activityType;

    @ApiModelProperty(value = "是否允许快速处理")
    @Alias("xallowRapid")
    private Boolean allowRapid;

    @ApiModelProperty(value = "应用标识")
    @Alias("xapplication")
    private String application;

    @ApiModelProperty(value = "应用别名")
    @Alias("xapplicationAlias")
    private String applicationAlias;

    @ApiModelProperty(value = "应用名称")
    @Alias("xapplicationName")
    private String applicationName;


    @ApiModelProperty(value = "创建时间")
    @Alias("xcreateTime")
    private String createTime;


    @ApiModelProperty(value = "创建者身份")
    @Alias("xcreatorIdentity")
    private String creatorIdentity;

    @ApiModelProperty(value = "创建者身份 DN")
    @Alias("xcreatorIdentityDn")
    private String creatorIdentityDn;

    @ApiModelProperty(value = "创建者个人标识")
    @Alias("xcreatorPerson")
    private String creatorPerson;

    @ApiModelProperty(value = "创建者个人标识")
    @Alias("xcreatorPersonDn")
    private String creatorPersonDn;

    @ApiModelProperty(value = "创建者单位标识")
    @Alias("xcreatorUnit")
    private String creatorUnit;

    @ApiModelProperty(value = "创建者单位标识")
    @Alias("xcreatorUnitDn")
    private String creatorUnitDn;

    @ApiModelProperty(value = "创建者单位标识")
    @Alias("xcreatorUnitDnList")
    private String creatorUnitDnList;

    @ApiModelProperty(value = "区分名称")
    @Alias("xdistinguishedName")
    private String distinguishedName;

    @ApiModelProperty(value = "授权来源身份")
    @Alias("xempowerFromIdentity")
    private String empowerFromIdentity;

    @ApiModelProperty(value = "是否已过期")
    @Alias("xexpired")
    private Boolean expired;

    @ApiModelProperty(value = "是否首次")
    @Alias("xfirst")
    private Boolean first;

    @ApiModelProperty(value = "标识")
    @Alias("xid")
    private String id;


    @ApiModelProperty(value = "身份")
    @Alias("xidentity")
    private String identity;

    @ApiModelProperty(value = "身份")
    @Alias("xidentityDn")
    private String identityDn;


    @ApiModelProperty(value = "忽略授权身份")
    @Alias("xignoreEmpowerIdentityList")
    private List<String> ignoreEmpowerIdentityList;

    @ApiModelProperty(value = "工作标识")
    @Alias("xjob")
    private String job;

    @ApiModelProperty(value = "标签")
    @Alias("xlabel")
    private String label;

    @ApiModelProperty(value = "是否修改")
    @Alias("xmodified")
    private Boolean modified;

    @ApiModelProperty(value = "意见")
    @Alias("xopinion")
    private String opinion;

    @ApiModelProperty(value = "个人标识")
    @Alias("xperson")
    private String person;

    @ApiModelProperty(value = "个人标识")
    @Alias("xpersonDn")
    private String personDn;

    @ApiModelProperty(value = "上一次处理人标识")
    @Alias("xprevTaskIdentity")
    private List<String> prevTaskIdentityList;

    @ApiModelProperty(value = "流程标识")
    @Alias("xprocess")
    private String process;

    @ApiModelProperty(value = "流程别名")
    @Alias("xprocessAlias")
    private String processAlias;

    @ApiModelProperty(value = "流程名称")
    @Alias("xprocessName")
    private String processName;

    @ApiModelProperty(value = "属性")
    @Alias("xproperties")
    private Object properties;

    @ApiModelProperty(value = "路由别名")
    private String routerAlias;

    @ApiModelProperty(value = "路由名称")
    private List<String> routeDecisionOpinionList;

    @ApiModelProperty(value = "路由")
    private List<String> routeList;

    @ApiModelProperty(value = "路由名称")
    @Alias("xrouteName")
    private String routeName;

    @ApiModelProperty(value = "路由名称集合")
    private List<String> routeNameList;

    @ApiModelProperty(value = "路由意见集合")
    private List<String> routeOpinionList;

    @ApiModelProperty(value = "串行")
    @Alias("xserial")
    private String serial;

    @ApiModelProperty(value = "系列号")
    @Alias("xseries")
    private String series;

    @ApiModelProperty(value = "开始时间")
    @Alias("xstartTime")
    private String startTime;

    @ApiModelProperty(value = "开始时间月份")
    @Alias("xstartTimeMonth")
    private String startTimeMonth;

    @ApiModelProperty(value = "标题")
    @Alias("xtitle")
    private String title;

    @ApiModelProperty(value = "单位")
    @Alias("xunit")
    private String unit;

    @ApiModelProperty(value = "单位")
    @Alias("xunitDn")
    private String unitDn;

    @ApiModelProperty(value = "单位")
    @Alias("xunitDnList")
    private String unitDnList;

    @ApiModelProperty(value = "更新时间")
    @Alias("xupdateTime")
    private String updateTime;

    @ApiModelProperty(value = "是否催办")
    @Alias("xurged")
    private Boolean urged;

    @ApiModelProperty(value = "工作")
    @Alias("xwork")
    private String work;

    @ApiModelProperty(value = "工作创建方式")
    @Alias("xworkCreateType")
    private String workCreateType ;



}
