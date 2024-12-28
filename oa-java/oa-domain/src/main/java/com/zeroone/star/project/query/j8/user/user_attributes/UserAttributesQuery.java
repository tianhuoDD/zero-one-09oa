package com.zeroone.star.project.query.j8.user.user_attributes;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;


@Data
@ApiModel("用户属性查询对象")
public class UserAttributesQuery extends PageQuery{

    @ApiModelProperty(value = "人物id")
    private String xPerson;
}
