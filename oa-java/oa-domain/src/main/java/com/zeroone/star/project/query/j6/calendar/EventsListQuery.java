package com.zeroone.star.project.query.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.List;

@Data
@ApiModel("获取日程列表的query参数")
@AllArgsConstructor
@NoArgsConstructor
public class EventsListQuery {
    /*
    查询的日历id（可以查询多个日历）
     */
    @ApiModelProperty(value = "查询日历的id", example = "[3b21409e-446d-49c8-8292-a24ad4884f62]")
    private List<String>  calendarIds;
    /*
    查询的日程开始时间
     */
    @ApiModelProperty(value = "查询日程的开始时间", example = "2024-10-21 23:59:59")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime startTime;
    /*
    查询日程的结束时间
     */
    @ApiModelProperty(value = "查询日程的结束时间", example = "2024-10-22 23:59:59")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime endTime;
}
