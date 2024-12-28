package com.zeroone.star.project.dto.j1.settings;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;

@Data
@ApiModel("修改密码")
public class ModifyPasswordDTO {

    @NotNull(message = "用户ID不能为空")
    @ApiModelProperty(value = "编号", example = "1")
    private String id;

    @NotNull(message = "旧密码不能为空")
    @Size(min = 6, max = 20, message = "新密码长度必须在 6 到 20 个字符之间")
    @Pattern(regexp = "^(?=.*[a-z])(?=.*\\d)[a-zA-Z\\d]{6,20}$", message = "新密码必须包含小写字母和数字")
    @ApiModelProperty(value = "旧密码", example = "admin123")
    private String prePassword;

    @NotNull(message = "新密码不能为空")
    @Size(min = 6, max = 20, message = "新密码长度必须在 6 到 20 个字符之间")
    @Pattern(regexp = "^(?=.*[a-z])(?=.*\\d)[a-zA-Z\\d]{6,20}$", message = "新密码必须包含小写字母和数字")
    @ApiModelProperty(value = "新密码", example = "admin456")
    private String newPassword;
}
