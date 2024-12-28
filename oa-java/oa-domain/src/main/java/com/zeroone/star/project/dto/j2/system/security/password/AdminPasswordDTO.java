package com.zeroone.star.project.dto.j2.system.security.password;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：管理员密码对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 红泥小火炉
 * @version 1.0.0
 */
@ApiModel("管理员密码对象")
@Data
public class AdminPasswordDTO {


    /**
     * 原始密码
     */
    @ApiModelProperty(value = "原始密码", example = "admin123")
    private String oldPassword;

    /**
     * 第一次输入密码
     */
    @ApiModelProperty(value = "第一次输入密码", example = "admin123")
    private String newPasswordOne;

    /**
     * 第二次密码
     */
    @ApiModelProperty(value = "第二次密码", example = "admin123")
    private String newPasswordTwo;
}
