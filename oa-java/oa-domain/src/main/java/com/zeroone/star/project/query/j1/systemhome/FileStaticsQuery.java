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
@ApiModel("文件统计查询条件")
public class FileStaticsQuery {

    @NotBlank(message = "姓名不能为空")
    @ApiModelProperty(value = "姓名", example = "东东哥")
    private String xperson;


    @NotBlank(message = "开始时间不为空")
    @ApiModelProperty(value = "开始时间", example = "2024-10-31 00:00:00")
    private String startDate;

    @NotBlank(message = "结束时间不为空")
    @ApiModelProperty(value = "结束时间", example = "2024-11-23 00:00:00")
    private String endDate;
}
