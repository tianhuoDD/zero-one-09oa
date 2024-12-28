package com.zeroone.star.project.query.j8.user.user_identity;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class UserIdentityQuery extends PageQuery {
    @ApiModelProperty(value = "个人id",example = "1")
    private String xperson;
}
