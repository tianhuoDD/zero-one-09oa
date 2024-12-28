package com.zeroone.star.project.query.j8.user.role_position;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class IdentityListQuery {

    @ApiModelProperty(value = "用户ID")
    private String uid;
}
