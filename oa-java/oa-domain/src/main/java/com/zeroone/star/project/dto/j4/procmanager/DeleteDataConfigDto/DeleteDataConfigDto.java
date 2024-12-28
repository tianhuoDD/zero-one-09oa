package com.zeroone.star.project.dto.j4.procmanager.DeleteDataConfigDto;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class DeleteDataConfigDto {
    @ApiModelProperty(value = "唯一标识", example = "18bf0ade-8059-4bb8-9a7a-6d621a112c59")
    private String id;
}