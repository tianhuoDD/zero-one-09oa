package com.zeroone.star.project.vo.j1.yanzhengma.Phone;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 短信验证码
 */
@Data
@ApiModel("短信验证码对象")
public class PhoneyzInfoVO {
    /**
     * 验证码
     */
    @ApiModelProperty(value = "验证码", example = "123456")
    private String yanzhengma;
}
