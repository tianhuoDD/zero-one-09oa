package com.zeroone.star.project.query.j6.file;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Size;

/**
 * <p>
 * 描述：共享用户分页查询对象
 * </p>
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("共享用户分页查询对象")
public class ShareUserQuery extends PageQuery {
    @ApiModelProperty(value = "用户名（模糊查询）", example = "李", required = false)
    @Size(max = 50, message = "用户名长度不能超过50")
    private String username;

    @ApiModelProperty(value = "邮箱", example = "lisi@example.com", required = false)
    private String email;

    @ApiModelProperty(value = "共享角色", example = "领导", required = false)
    private String role;

}
