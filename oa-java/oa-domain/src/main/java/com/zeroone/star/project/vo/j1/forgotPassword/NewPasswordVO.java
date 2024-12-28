package com.zeroone.star.project.vo.j1.forgotPassword;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("设置新密码VO")
public class NewPasswordVO {

    /**
     * 新密码，用于修改用户密码
     */
    @ApiModelProperty(value ="新密码",example = "123456789")
    private String newPassword;

    /**
     * 状态显示信息
     */
    @ApiModelProperty(value ="修改成功",example = "修改成功")
    private String message;

}
