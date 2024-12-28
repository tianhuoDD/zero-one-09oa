package com.zeroone.star.project.dto.j4.process;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("统计流程类型")
public class CountCategoryDTO {

    @ApiModelProperty(value = "分类", example = "类别1")
    private String xcategory;

    @ApiModelProperty(value = "对应分类数量",example ="1" )
    private Integer count;
}
