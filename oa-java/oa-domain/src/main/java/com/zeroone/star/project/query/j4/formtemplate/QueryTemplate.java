package com.zeroone.star.project.query.j4.formtemplate;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * 显示表单模版对象
 */
@Data
@ApiModel("查询显示表单模版对象")
public class QueryTemplate extends PageQuery {
    /**
     * 唯一标识id
     */
    @NotBlank(message = "id不能为空")
    @ApiModelProperty(value = "id值", example = "123")
    private String xid;
    /**
     * 种类
     */
    @ApiModelProperty(value = "种类", example = "入职种类")
    private String xcategory;
}
