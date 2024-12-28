package com.zeroone.star.project.vo.j2.system.security.password;

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
public class AdminPasswordVO {

    /**
     * 管理员id
     */
    @ApiModelProperty(value = "管理员id", example = "1234")
    private Integer id;

    /**
     * 密码
     */
    @ApiModelProperty(value = "管理员密码", example = "aadmin123")
    private String password;
}
