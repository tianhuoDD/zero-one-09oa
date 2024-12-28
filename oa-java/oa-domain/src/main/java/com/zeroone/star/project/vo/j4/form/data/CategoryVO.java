package com.zeroone.star.project.vo.j4.form.data;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("表单所有类型")
public class CategoryVO
{
    @ApiModelProperty(value = "分类")
    private String xcategory;

}
