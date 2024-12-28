package com.zeroone.star.project.vo.j5.bizcenter;


import com.zeroone.star.project.vo.j5.bizcenter.formData.Form;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

import java.util.HashMap;

@Data
@ApiModel("流程表单格式数据")
@Builder
public class ProcessFormVO {

    @ApiModelProperty(value = "表单格式数据")
    public Form form;

    @ApiModelProperty(value = "表单关联表")
    private HashMap<String,String> relatedFormMap;

    @ApiModelProperty(value = "表单关联脚本")
    private HashMap<String,String> relatedScriptMap;

    @ApiModelProperty(value = "最大存在时间",example = "86400")
    private Integer maxAge;
}
