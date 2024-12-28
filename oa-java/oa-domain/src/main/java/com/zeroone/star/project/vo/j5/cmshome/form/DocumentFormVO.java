package com.zeroone.star.project.vo.j5.cmshome.form;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

@Data
@ApiModel("消息表单模板")
public class DocumentFormVO {
    @ApiModelProperty(value = "表单模板",example = "一个json数据")
    private String xdata;
}
