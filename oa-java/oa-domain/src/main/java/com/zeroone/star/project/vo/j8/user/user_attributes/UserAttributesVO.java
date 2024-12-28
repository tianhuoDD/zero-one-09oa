package com.zeroone.star.project.vo.j8.user.user_attributes;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

@Data
@ApiModel("用户属性展示对象")
@Builder
public class UserAttributesVO {
    @ApiModelProperty(value = "属性名称")
    private String xName;

    @ApiModelProperty(value = "属性描述")
    private String xDescription;

    @ApiModelProperty("属性值")
    private String xAttribute;
}
