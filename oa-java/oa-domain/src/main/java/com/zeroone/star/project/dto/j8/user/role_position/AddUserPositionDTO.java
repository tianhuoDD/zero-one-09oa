package com.zeroone.star.project.dto.j8.user.role_position;

import io.swagger.annotations.ApiModelProperty;
import java.io.Serializable;
import javax.validation.constraints.NotBlank;
import lombok.Data;

@Data
public class AddUserPositionDTO implements Serializable {

    @ApiModelProperty(value = "身份ID", required = true)
    @NotBlank(message = "身份ID不能为空")
    private String identity;

    @ApiModelProperty(value = "职务ID", required = true)
    @NotBlank(message = "职务ID不能为空")
    private String unitdutyId;


}
