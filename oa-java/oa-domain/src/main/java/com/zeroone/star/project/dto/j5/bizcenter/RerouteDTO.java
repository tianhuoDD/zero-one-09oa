package com.zeroone.star.project.dto.j5.bizcenter;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("调度路由模型")
public class RerouteDTO {

    @ApiModelProperty(value = "目标节点", example = "",required = true)
    private String activity;


    @ApiModelProperty(value = "目标节点类型", example = "",required = true)
    private String activityType;


    @ApiModelProperty(value = "是否合并", example = "",required = true)
    private boolean mergeWork;

    @ApiModelProperty(value = "处理人标识集合",required = true)
    private List<String> distinguishedNameList;

    @ApiModelProperty(value = "强制处理人标识集合")
    private List<String> manualForceTaskIdentityList;

    @ApiModelProperty(value = "待办选择路由名称",required = true)
    private String routeName;

    @ApiModelProperty(value = "待办办理意见")
    private String opinion;


}
