package com.zeroone.star.project.dto.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;
import java.util.List;

/**
 * 一天内日程的DTO，用于辅助获取日程列表
 */
@Data
@ApiModel("存放一天内的日程列表")
@AllArgsConstructor
@NoArgsConstructor
public class InOneDayEventsDTO {
    @ApiModelProperty(value = "当天日期", example = "2024-10-21")
    private LocalDate eventDate;
    @ApiModelProperty(value = "当天日程信息", example = "")
    private List<EventDetailDTO> inOneDayEvents;
}
