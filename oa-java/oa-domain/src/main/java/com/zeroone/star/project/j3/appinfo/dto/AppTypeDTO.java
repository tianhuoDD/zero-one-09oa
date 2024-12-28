package com.zeroone.star.project.j3.appinfo.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("栏目类型对象")
public class AppTypeDTO {
    @ApiModelProperty(value = "栏目类型",example = "新闻")
    private String xappType;

    @ApiModelProperty(value = "该类型的栏目个数",example = "1")
    private Integer xappCount;

}
