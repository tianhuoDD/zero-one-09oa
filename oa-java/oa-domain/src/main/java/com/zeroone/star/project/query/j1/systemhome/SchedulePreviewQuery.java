package com.zeroone.star.project.query.j1.systemhome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/21
 */
@ApiModel("日程管理")
@Data
public class SchedulePreviewQuery {

    @ApiModelProperty(value = "选择的日期", example = "2024-10-21 00:00:00")
    private String chooseDate;

    @ApiModelProperty(value = "用户", example = "ddg")
    private String person;
}
