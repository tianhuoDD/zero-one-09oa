package com.zeroone.star.project.dto.j4.form.data;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

@Data
@ApiModel("查询表单列表对象")
public class FormListDTO  extends PageQuery
{
    @ApiModelProperty(value = "表单的唯一标识符")
    private String xid;

    @ApiModelProperty(value = "表单名称")
    private String xname;

    @ApiModelProperty(value = "表单别名")
    private String xalias;

    @ApiModelProperty(value = "表单负责人")
    private String xperson;

    @ApiModelProperty(value = "分类")
    private String xcategory;
}
