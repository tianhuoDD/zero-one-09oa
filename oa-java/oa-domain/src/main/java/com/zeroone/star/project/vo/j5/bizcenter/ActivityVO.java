package com.zeroone.star.project.vo.j5.bizcenter;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("待办活动信息")
public class ActivityVO {

    @ApiModelProperty(value = "活动标识",example = "123")
    private String activity;

    @ApiModelProperty(value = "活动类型",example = "123")
    private String activityType;

    @ApiModelProperty(value = "活动名称")
    private String activityName;

    @ApiModelProperty(value = "活动别名")
    private String activityAlias;
    @ApiModelProperty(value = "活动Token")
    private String activityToken;
    @ApiModelProperty(value = "活动处理人标识集合",example = "")
    private List<String> taskIdentityList;

}
