package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("工作日志")
public class WorkLogVO {

    @Alias("xid")
    @ApiModelProperty("ID")
    private String id;

    @Alias("xcreateTime")
    @ApiModelProperty("创建时间")
    private LocalDateTime createTime;

    @Alias("xsequence")
    @ApiModelProperty("序列")
    private String sequence;

    @Alias("xupdateTime")
    @ApiModelProperty("更新时间")
    private LocalDateTime updateTime;

    @Alias("xdistributeFactor")
    @ApiModelProperty("分配因子")
    private Integer distributeFactor;

    @Alias("xapplication")
    @ApiModelProperty("应用程序")
    private String application;

    @Alias("xapplicationAlias")
    @ApiModelProperty("应用程序别名")
    private String applicationAlias;

    @Alias("xapplicationName")
    @ApiModelProperty("应用程序名称")
    private String applicationName;

    @Alias("xarrivedActivity")
    @ApiModelProperty("到达活动")
    private String arrivedActivity;

    @Alias("xarrivedActivityAlias")
    @ApiModelProperty("到达活动别名")
    private String arrivedActivityAlias;

    @Alias("xarrivedActivityName")
    @ApiModelProperty("到达活动名称")
    private String arrivedActivityName;

    @Alias("xarrivedActivityToken")
    @ApiModelProperty("到达活动令牌")
    private String arrivedActivityToken;

    @Alias("xarrivedActivityType")
    @ApiModelProperty("到达活动类型")
    private String arrivedActivityType;

    @Alias("xarrivedGroup")
    @ApiModelProperty("到达组")
    private String arrivedGroup;

    @Alias("xarrivedOpinionGroup")
    @ApiModelProperty("到达意见组")
    private String arrivedOpinionGroup;

    @Alias("xarrivedTime")
    @ApiModelProperty("到达时间")
    private LocalDateTime arrivedTime;

    @Alias("xcompleted")
    @ApiModelProperty("是否完成")
    private Boolean completed;

    @Alias("xconnected")
    @ApiModelProperty("是否连接")
    private Boolean connected;

    @Alias("xduration")
    @ApiModelProperty("持续时间")
    private Long duration;

    @Alias("xfromActivity")
    @ApiModelProperty("来源活动")
    private String fromActivity;

    @Alias("xfromActivityAlias")
    @ApiModelProperty("来源活动别名")
    private String fromActivityAlias;

    @Alias("xfromActivityName")
    @ApiModelProperty("来源活动名称")
    private String fromActivityName;

    @Alias("xfromActivityToken")
    @ApiModelProperty("来源活动令牌")
    private String fromActivityToken;

    @Alias("xfromActivityType")
    @ApiModelProperty("来源活动类型")
    private String fromActivityType;

    @Alias("xfromGroup")
    @ApiModelProperty("来源组")
    private String fromGroup;

    @Alias("xfromOpinionGroup")
    @ApiModelProperty("来源意见组")
    private String fromOpinionGroup;

    @Alias("xfromTime")
    @ApiModelProperty("来源时间")
    private LocalDateTime fromTime;

    @Alias("xjob")
    @ApiModelProperty("工作")
    private String job;

    @Alias("xprocess")
    @ApiModelProperty("流程")
    private String process;

    @Alias("xprocessAlias")
    @ApiModelProperty("流程别名")
    private String processAlias;

    @Alias("xprocessName")
    @ApiModelProperty("流程名称")
    private String processName;

    @Alias("xproperties")
    @ApiModelProperty("属性")
    private String properties;

    @Alias("xroute")
    @ApiModelProperty("路由")
    private String route;

    @Alias("xrouteName")
    @ApiModelProperty("路由名称")
    private String routeName;

    @Alias("xsplitToken")
    @ApiModelProperty("分割令牌")
    private String splitToken;

    @Alias("xsplitValue")
    @ApiModelProperty("分割值")
    private String splitValue;

    @Alias("xsplitWork")
    @ApiModelProperty("分割工作")
    private String splitWork;

    @Alias("xsplitting")
    @ApiModelProperty("是否分割")
    private Boolean splitting;

    @Alias("xtype")
    @ApiModelProperty("类型")
    private String type;

    @Alias("xwork")
    @ApiModelProperty("工作")
    private String work;

    @Alias("xworkCompleted")
    @ApiModelProperty("工作完成")
    private String workCompleted;

}
