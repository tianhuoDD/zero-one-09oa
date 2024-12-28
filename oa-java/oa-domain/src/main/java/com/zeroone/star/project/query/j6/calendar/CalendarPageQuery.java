package com.zeroone.star.project.query.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.Min;

@Data
@ApiModel("获取日历广场分页查询的query参数")
@AllArgsConstructor
@NoArgsConstructor
public class CalendarPageQuery {

    @Min(value = 1, message = "页码必须大于0")
    @ApiModelProperty(value = "页码",required = true, example = "1")
    private Long pageIndex;

    @Min(value = 1, message = "查询条数必须大于0")
    @ApiModelProperty(value = "查询条数",required = true, example = "10")
    private Long pageSize;

}
