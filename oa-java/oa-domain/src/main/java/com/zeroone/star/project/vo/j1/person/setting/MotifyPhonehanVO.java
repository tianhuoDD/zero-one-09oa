package com.zeroone.star.project.vo.j1.person.setting;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("个人设置")
public class MotifyPhonehanVO {
    /**
     * 是否成功
     */
    @ApiModelProperty(value = "状态码", example = "1")
    private String tojy;
}
