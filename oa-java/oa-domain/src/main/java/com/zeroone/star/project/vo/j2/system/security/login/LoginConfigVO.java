package com.zeroone.star.project.vo.j2.system.security.login;

import lombok.Data;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;

@Data
@ApiModel("系统登录配置VO")
public class LoginConfigVO {

    @ApiModelProperty(value = "是否启用短信验证码登录", example = "true")
    private Boolean enableSmsLogin;

    @ApiModelProperty(value = "是否启用图片验证码登录", example = "false")
    private Boolean enablePicLogin;

}
