package com.zeroone.star.project.dto.j1.forgotPassword;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import lombok.experimental.Accessors;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Accessors(chain = true)
@ApiModel("获取短信验证码DTO")
public class SmsVerificationDTO {

    /**
     * 手机号码
     */
    @ApiModelProperty(value ="手机号码",example = "123456789")
    private String xmobile;

    /**
     * 短信验证码
     */
    @ApiModelProperty(value ="验证码",example = "666666")
    private String smsCode;

    /**
     * 提示消息
     */
    @ApiModelProperty(value ="提示消息",example = "提示消息内容")
    private String message;
}
