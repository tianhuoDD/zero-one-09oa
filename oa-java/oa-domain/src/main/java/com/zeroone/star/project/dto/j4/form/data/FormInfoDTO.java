package com.zeroone.star.project.dto.j4.form.data;




import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("查询表单详情对象")
public class FormInfoDTO
{
    @ApiModelProperty(value = "表单id")
    private String xid;

//    @ApiModelProperty(value = "表单别名")
//    private String xalias;

//    @ApiModelProperty(value = "负责人")
//    private String xperson;

//    @ApiModelProperty(value = "名称")
//    private String xname;

//    @ApiModelProperty(value = "是否有移动端")
//    private Boolean xhasMobile;
}