package com.zeroone.star.project.dto.j1.yanzhengma.mail;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 获取邮箱验证码
 */
@Data
@ApiModel("获取邮箱验证码")
public class MailyzInfoDTO {
    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识", example = "12ass22sa3")
    private String id;

    /**
     * 邮箱
     */
    @ApiModelProperty(value = "邮箱", example = "123131312@qq.com")
    private String mail;
}
