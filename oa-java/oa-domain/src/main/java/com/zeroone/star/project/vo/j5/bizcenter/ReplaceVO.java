
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.ArrayList;

import java.util.List;

@Data
@ApiModel("重置处理人信息")
public class ReplaceVO {

    @Alias("xid")
    @ApiModelProperty(value = "数据库主键")
    private String id;

    @Alias("xrouteName")
    @ApiModelProperty(value = "路由名称")
    private String routeName;

    @Alias("xopinion")
    @ApiModelProperty(value = "意见")
    private String opinion;

    @Alias("xmediaOpinion")
    @ApiModelProperty(value = "多媒体意见")
    private String mediaOpinion;

    @Alias("xforce")
    @ApiModelProperty(value = "是否强制处理")
    private Boolean force;

    @Alias("xempowerFromIdentity")
    @ApiModelProperty(value = "授权自身份")
    private String empowerFromIdentity;

//    @Alias("xnextManualList")
    @ApiModelProperty(value = "后续人工环节")
    private Object nextManualList;

//    @Alias("xnextManualTaskIdentityList")
    @ApiModelProperty(value = "后续人工环节处理人")
    private Object nextManualTaskIdentityList;

    @Alias("xstartTime")
    @ApiModelProperty(value = "开始时间")
    private LocalDateTime startTime;

    @Alias("xapplication")
    @ApiModelProperty(value = "应用")
    private String application;

    @Alias("xprocess")
    @ApiModelProperty(value = "流程ID")
    private String process;

    @Alias("xjob")
    @ApiModelProperty(value = "任务标识")
    private String job;

    @Alias("xwork")
    @ApiModelProperty(value = "工作")
    private String work;

    @Alias("xworkCompleted")
    @ApiModelProperty(value = "已完成工作")
    private String workCompleted;

    @Alias("xcompleted")
    @ApiModelProperty(value = "是否完成")
    private Boolean completed;

    @Alias("xdisplay")
    @ApiModelProperty(value = "是否显示")
    private Boolean display;

    @Alias("xorder")
    @ApiModelProperty(value = "排序")
    private Long order;

//    @Alias("xproperties")
    @ApiModelProperty(value = "属性对象存储字段")
    private Object properties;

    @Alias("xfromActivity")
    @ApiModelProperty(value = "开始活动Id")
    private String fromActivity;

    @Alias("xfromActivityType")
    @ApiModelProperty(value = "开始活动类型")
    private String fromActivityType;

    @Alias("xfromActivityName")
    @ApiModelProperty(value = "开始活动名称")
    private String fromActivityName;

    @Alias("xfromActivityAlias")
    @ApiModelProperty(value = "开始活动别名")
    private String fromActivityAlias;

    @Alias("xfromActivityToken")
    @ApiModelProperty(value = "开始节点Token")
    private String fromActivityToken;

    @Alias("xrecordTime")
    @ApiModelProperty(value = "记录时间")
    private LocalDateTime recordTime;

    @Alias("xperson")
    @ApiModelProperty(value = "记录人员")
    private String person;

    @Alias("xidentity")
    @ApiModelProperty(value = "记录身份")
    private String identity;

    @Alias("xunit")
    @ApiModelProperty(value = "记录人员所在组织")
    private String unit;

    @Alias("xtype")
    @ApiModelProperty(value = "类型")
    private String type;

    @Alias("xcreateTime")
    @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

    @Alias("xupdateTime")
    @ApiModelProperty(value = "修改时间")
    private LocalDateTime updateTime;

}
