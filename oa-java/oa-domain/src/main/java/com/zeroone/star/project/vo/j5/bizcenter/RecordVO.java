package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("记录信息")
public class RecordVO {

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

    @Alias("xcompleted")
    @ApiModelProperty("是否完成")
    private Boolean completed;

    @Alias("xdisplay")
    @ApiModelProperty("是否显示")
    private Boolean display;

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

    @Alias("xidentity")
    @ApiModelProperty("身份")
    private String identity;

    @Alias("xjob")
    @ApiModelProperty("工作")
    private String job;

    @Alias("xorder")
    @ApiModelProperty("顺序")
    private Long order;

    @Alias("xperson")
    @ApiModelProperty("人员")
    private String person;

    @Alias("xprocess")
    @ApiModelProperty("流程")
    private String process;

    @ApiModelProperty("属性")
    private Object properties;

    @Alias("xrecordTime")
    @ApiModelProperty("记录时间")
    private LocalDateTime recordTime;

    @Alias("xtype")
    @ApiModelProperty("类型")
    private String type;

    @Alias("xunit")
    @ApiModelProperty("单位")
    private String unit;

    @Alias("xwork")
    @ApiModelProperty("工作")
    private String work;

    @Alias("xworkCompleted")
    @ApiModelProperty("工作完成")
    private String workCompleted;

}
