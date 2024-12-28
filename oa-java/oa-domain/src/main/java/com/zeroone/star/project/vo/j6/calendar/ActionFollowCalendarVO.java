package com.zeroone.star.project.vo.j6.calendar;

import com.zeroone.star.project.dto.j6.calendar.CalendarDTO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

/**
 * 关注一个公开的日历（非公开的日历不允许被关注）
 */
@Data
@Builder
public class ActionFollowCalendarVO {
    /**
     * 日历对象
     */
    @ApiModelProperty(value = "日历对象（集合）", example = "\\\"id\\\": \\\"1\\\", \\\"name\\\": \\\"公共日历\\\", \\\"descript")
    private CalendarDTO calendarDTO;

    /**
     * 状态返回码
     */
    @ApiModelProperty(value = "操作是否成功", example = "true")

    private boolean followStatus;
    /**
     * 状态信息
     */
    @ApiModelProperty(value = "状态消息", example = "succeed")
    private String message;


}
