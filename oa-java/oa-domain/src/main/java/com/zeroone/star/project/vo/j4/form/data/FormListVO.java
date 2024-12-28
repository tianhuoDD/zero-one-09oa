package com.zeroone.star.project.vo.j4.form.data;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.Date;

@Data
@ApiModel("表单列表")
public class FormListVO
{
    @ApiModelProperty(value = "表单的唯一标识符")
    private String xid;

    @ApiModelProperty(value = "表单名称")
    private String xname;

    @ApiModelProperty(value = "表单类别")
    private String xcategory;

    @ApiModelProperty(value = "表单别名")
    private String xalias;

    @ApiModelProperty(value = "表单创建时间")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "表单负责人")
    private String xperson;

    @ApiModelProperty(value = "表单所属应用")
    private String xapplication;

    @ApiModelProperty(value = "数据")
    private String xdata;

    @ApiModelProperty(value = "描述")
    private String xdescription;

    @ApiModelProperty(value = "是否有移动端")
    private Boolean xhasMobile;

}
