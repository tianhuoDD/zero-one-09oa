package com.zeroone.star.project.dto.j1.person.setting;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("个人设置")
public class MotifyPhonehanDTO {
    /**
     * 电话
     */
    @ApiModelProperty(value = "电话", example = "121312123")
    private String phone;
    /**
     * 新电话
     */
    @ApiModelProperty(value = "新电话", example = "123412341")
    private String newphone;
    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识", example = "12ass22sa3")
    private String id;

    /**
     * 验证码
     */
    @ApiModelProperty(value = "验证码", example = "12345")
    private String verifyCode;
}
