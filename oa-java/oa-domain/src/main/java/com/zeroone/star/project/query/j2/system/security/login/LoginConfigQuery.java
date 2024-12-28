package com.zeroone.star.project.query.j2.system.security.login;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.Api;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.EqualsAndHashCode;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;

/**
 * 登录配置查询
 */
@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("登录配置查询对象")
@NoArgsConstructor
@AllArgsConstructor
public class LoginConfigQuery extends PageQuery {

    @NotBlank(message = "用户名不能为空")
    @ApiModelProperty(value = "用户名", example = "zhangsan")
    private String username;

    @ApiModelProperty(value = "是否记住我", example = "true")
    private Boolean rememberMe;
    
    @ApiModelProperty(value = "用户角色", example = "admin")
    private String role;
}
