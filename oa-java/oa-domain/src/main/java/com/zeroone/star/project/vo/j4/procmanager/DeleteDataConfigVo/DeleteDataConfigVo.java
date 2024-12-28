package com.zeroone.star.project.vo.j4.procmanager.DeleteDataConfigVo;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("删除数据配置显示对象")
public class DeleteDataConfigVo {
    @ApiModelProperty(value = "唯一标识", example = "18bf0ade-8059-4bb8-9a7a-6d621a112c59")
    private String id;
}