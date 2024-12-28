package com.zeroone.star.project.dto.j2.system.security.login;

import lombok.Data;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;

@Data
@ApiModel("保存登录配置DTO")
public class LoginSaveDTO {

    @ApiModelProperty(value = "配置在数据库里的唯一标识", example = "1")
    private  int id;

    @ApiModelProperty(value = "是否启用短信验证码登录", example = "true")
    private Boolean enableSmsLogin;

    @ApiModelProperty(value = "是否启用图片验证码登录", example = "false")
    private Boolean enablePicLogin;

}
