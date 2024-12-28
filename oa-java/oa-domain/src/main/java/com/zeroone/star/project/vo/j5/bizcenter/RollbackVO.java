
package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.core.annotation.Alias;
import com.zeroone.star.project.vo.j5.bizcenter.ActivityVO;
import com.zeroone.star.project.vo.j5.bizcenter.RecordProperties;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("工作回滚信息")
public class RollbackVO {

    @ApiModelProperty(value = "数据库主键")
    @Alias("xid")
    private String id;

    @ApiModelProperty(value = "路由名称")
    private String routeName;

    @ApiModelProperty(value = "意见")
    private String opinion;

//    @ApiModelProperty(value = "多媒体意见")
//    private String mediaOpinion;

//    @ApiModelProperty(value = "授权自身份")
//    private String empowerFromIdentity;

    @ApiModelProperty(value = "后续人工环节")
    private List<ActivityVO> nextManualList;

    @ApiModelProperty(value = "后续人工环节处理人")
    private List<String> nextManualTaskIdentityList;

    @ApiModelProperty(value = "开始时间")
    private LocalDateTime startTime;

    @ApiModelProperty(value = "应用")
    @Alias("xapplication")
    private String application;

    @ApiModelProperty(value = "流程ID")
    @Alias("xprocess")
    private String process;

    @ApiModelProperty(value = "任务标识")
    @Alias("xjob")
    private String job;

    @ApiModelProperty(value = "工作")
    @Alias("xwork")
    private String work;


    @ApiModelProperty(value = "是否完成")
    @Alias("xcompleted")
    private Boolean completed;

    @ApiModelProperty(value = "是否显示")
    @Alias("xdisplay")
    private Boolean display;

    @ApiModelProperty(value = "时间戳")
    @Alias("xorder")
    private Long order;

    @ApiModelProperty(value = "属性对象存储字段")
    @Alias("xproperties")
    private String properties;

    @ApiModelProperty(value = "开始活动Id")
    @Alias("xfromActivity")
    private String fromActivity;

    @ApiModelProperty(value = "开始活动类型")
    @Alias("xfromActivityType")
    private String fromActivityType;

    @ApiModelProperty(value = "开始活动名称")
    @Alias("xfromActivityName")
    private String fromActivityName;

    @ApiModelProperty(value = "开始活动别名")
    @Alias("xfromActivityAlias")
    private String fromActivityAlias;

    @ApiModelProperty(value = "开始节点Token")
    @Alias("xfromActivityToken")
    private String fromActivityToken;

    @ApiModelProperty(value = "记录时间")
    @Alias("xrecordTime")
    private LocalDateTime recordTime;

    @ApiModelProperty(value = "记录人员")
    @Alias("xperson")
    private String person;

    @ApiModelProperty(value = "记录身份")
    @Alias("xidentity")
    private String identity;

    @ApiModelProperty(value = "记录人员所在组织")
    @Alias("xunit")
    private String unit;

    @ApiModelProperty(value = "类型")
    @Alias("xtype")
    private String type;

    @ApiModelProperty(value = "创建时间")
    @Alias("xcreateTime")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "修改时间")
    @Alias("xupdateTime")
    private LocalDateTime updateTime;


}

