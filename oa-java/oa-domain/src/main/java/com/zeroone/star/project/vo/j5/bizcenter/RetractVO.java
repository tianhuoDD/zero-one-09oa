
package com.zeroone.star.project.vo.j5.bizcenter;

import com.zeroone.star.project.vo.j5.bizcenter.ActivityVO;
import com.zeroone.star.project.vo.j5.bizcenter.RecordProperties;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("工作召回信息")
public class RetractVO {

    @ApiModelProperty(value = "数据库主键")
    private String id;

    @ApiModelProperty(value = "路由名称")
    private String routeName;

    @ApiModelProperty(value = "意见")
    private String opinion;

    @ApiModelProperty(value = "多媒体意见")
    private String mediaOpinion;

    @ApiModelProperty(value = "授权自身份")
    private String empowerFromIdentity;

    @ApiModelProperty(value = "后续人工环节")
    private List<ActivityVO> nextManualList;

    @ApiModelProperty(value = "后续人工环节处理人")
    private List<String> nextManualTaskIdentityList;

    @ApiModelProperty(value = "开始时间")
    private LocalDateTime startTime;

    @ApiModelProperty(value = "应用")
    private String application;

    @ApiModelProperty(value = "流程ID")
    private String process;

    @ApiModelProperty(value = "任务标识")
    private String job;

    @ApiModelProperty(value = "工作")
    private String work;

    @ApiModelProperty(value = "已完成工作")
    private String workCompleted;

    @ApiModelProperty(value = "是否完成")
    private Boolean completed;

    @ApiModelProperty(value = "是否显示")
    private Boolean display;

    @ApiModelProperty(value = "排序")
    private Long order;

    @ApiModelProperty(value = "属性对象存储字段")
    private RecordProperties properties;

    @ApiModelProperty(value = "开始活动Id")
    private String fromActivity;

    @ApiModelProperty(value = "开始活动类型")
    private String fromActivityType;

    @ApiModelProperty(value = "开始活动名称")
    private String fromActivityName;

    @ApiModelProperty(value = "开始活动别名")
    private String fromActivityAlias;

    @ApiModelProperty(value = "开始节点Token")
    private String fromActivityToken;

    @ApiModelProperty(value = "记录时间")
    private String recordTime;

    @ApiModelProperty(value = "记录人员")
    private String person;

     @ApiModelProperty(value = "记录身份")
    private String identity;

     @ApiModelProperty(value = "记录人员所在组织")
    private String unit;

     @ApiModelProperty(value = "类型")
    private String type;

     @ApiModelProperty(value = "创建时间")
    private LocalDateTime createTime;

     @ApiModelProperty(value = "修改时间")
    private LocalDateTime updateTime;


}

