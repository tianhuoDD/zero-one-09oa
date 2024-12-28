package com.zeroone.star.project.dto.j8.user.user_attributes;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

@ApiModel("人物属性对象")
@Data
@Builder
public class UserAttributesDTO1 {
    @ApiModelProperty(value = "属性表id")
    private String xid;

    @ApiModelProperty(value = "属性名称")
    private String xName;

    @ApiModelProperty(value = "属性描述")
    private String xDescription;
}
