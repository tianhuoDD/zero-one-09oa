package com.zeroone.star.project.dto.j1.forgotPassword;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("设置新密码DTO")
public class NewPasswordDTO {


    @ApiModelProperty(value ="手机号",example = "12345678910")
    private String xmobile;
    /**
     * 新密码，用于修改用户密码
     */
    @ApiModelProperty(value ="新密码",example = "123456789")
    private String newPassword;

    /**
     * 确认密码，用于确认新密码的输入
     */
    @ApiModelProperty(value ="确认密码",example = "123456789")
    private String confirmPassword;
}
