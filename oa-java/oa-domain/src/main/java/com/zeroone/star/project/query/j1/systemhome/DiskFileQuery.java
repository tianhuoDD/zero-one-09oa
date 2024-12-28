package com.zeroone.star.project.query.j1.systemhome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/21
 */
@Data
@ApiModel("文件查询条件")
public class DiskFileQuery {
    @NotBlank(message = "文件创建人不为空")
    @ApiModelProperty(value = "姓名", example = "ddg")
    private String xperson;

}
