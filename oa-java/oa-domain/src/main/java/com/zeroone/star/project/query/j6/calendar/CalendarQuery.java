package com.zeroone.star.project.query.j6.calendar;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class CalendarQuery {
    /**
     * 日历ID
     */
    @ApiModelProperty(value = "查询日历的id", example = "[3b21409e-446d-49c8-8292-a24ad4884f62]")

    private String calendarId;

}
