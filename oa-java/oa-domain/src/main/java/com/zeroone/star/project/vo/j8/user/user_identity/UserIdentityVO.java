package com.zeroone.star.project.vo.j8.user.user_identity;

import com.zeroone.star.project.dto.j8.user.user_identity.UserIdentityDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class UserIdentityVO extends UserIdentityDTO {
    //继承UserIdentityDTO,比DTO多一个职务属性
    @ApiModelProperty(value = "担任职务", example = "经理")
    private String position;

}
