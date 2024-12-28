package com.zeroone.star.project.vo.j4.form.manage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data

@ApiModel("表单更新操作对象")
public class UpdateFormVO {

  @ApiModelProperty(value = "表单的别名",example = "表单1")
  private String xalias;
  @ApiModelProperty(value = "表单类别",example = "请假")
  private String xcategory;
  @ApiModelProperty(value = "表单数据",example = "文本框")
  private String xdata;
  @ApiModelProperty(value = "表单描述",example = "用于请假")
  private String xdescription;
  @ApiModelProperty(value = "是否适用于移动设备",example = "true")
  private String xhasMobile;
  @ApiModelProperty(value = "表单图标",example = "NULL")
  private String xicon;
  @ApiModelProperty(value = "表单名",example = "表单1")
  private String xname;

}
