package com.zeroone.star.project.dto.j4.form.data;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

@Data
@ApiModel("查询表单类型对象")
public class CategoryDTO
{


    @ApiModelProperty(value = "表单id")
    private String xid;

    @ApiModelProperty(value = "应用")
    private String xapplication;


    @ApiModelProperty(value = "是否有移动端")
    private Boolean xhasMobile;


//    @ApiModelProperty(value = "负责人")
//    private String xperson;

    @ApiModelProperty(value = "表单别名")
    private String xalias;


    @ApiModelProperty(value = "名称")
    private String xname;

}
