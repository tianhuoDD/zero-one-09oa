package com.zeroone.star.project.vo.j5.bizcenter;

import cn.hutool.json.JSONObject;
import io.swagger.annotations.ApiModel;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;

@Data
@ApiModel("流程表单数据")
@Builder
@AllArgsConstructor
public class ProcessFormDataVO {

    @ApiModelProperty(value = "表单数据",example = "这个一个json数据")
    private JSONObject data;
}
