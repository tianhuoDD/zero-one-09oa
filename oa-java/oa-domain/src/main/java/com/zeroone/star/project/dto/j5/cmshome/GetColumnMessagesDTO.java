package com.zeroone.star.project.dto.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("获取栏目信息")
public class GetColumnMessagesDTO {

    /*
     * 栏目名称
     */
    @ApiModelProperty(value = "appName", example = "通知公告")
    private String name; // app名称

}
