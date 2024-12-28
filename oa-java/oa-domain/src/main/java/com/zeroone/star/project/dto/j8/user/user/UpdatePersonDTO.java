package com.zeroone.star.project.dto.j8.user.user;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
public class UpdatePersonDTO extends AddPersonDTO {

    @ApiModelProperty(value = "人员唯一标识", example = "123")
    private String xid;
}
