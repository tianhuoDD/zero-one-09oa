package com.zeroone.star.project.vo.j1.yanzhengma.mail;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 邮箱验证码
 */
@Data
@ApiModel("邮箱验证码对象")
public class MailyzInfoVO {
    /**
     * 验证码
     */
    @ApiModelProperty(value = "验证码", example = "123456")
    private String yanzhengma;
}
