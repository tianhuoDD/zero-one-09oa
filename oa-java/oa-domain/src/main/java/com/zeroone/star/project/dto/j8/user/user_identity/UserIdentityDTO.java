package com.zeroone.star.project.dto.j8.user.user_identity;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class UserIdentityDTO {

    @ApiModelProperty(value = "唯一标识", example = "001")
    private String xid;

    @ApiModelProperty(value = "身份名称", example = "干活的")
    private String xname;

    @ApiModelProperty(value = "所在组织", example = "研发部")
    private String xunitName;

    @ApiModelProperty(value = "唯一编码", example = "unique001")
    private String xunique;

    @ApiModelProperty(value = "是否是主身份", example = "true")
    private Boolean xmajor;

}