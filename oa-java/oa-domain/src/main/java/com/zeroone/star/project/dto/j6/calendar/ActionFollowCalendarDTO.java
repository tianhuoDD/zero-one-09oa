package com.zeroone.star.project.dto.j6.calendar;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;

/**
 * 关注一个公开的日历（非公开的日历不允许被关注）
 */
@Data
@ApiModel
public class ActionFollowCalendarDTO {
    /**
     * 日历ID
     */
    @ApiModelProperty(value = "日历id", required = true,example = "8d33cc48-1abf-4f83-b4a5-fa52f96956aa")
    private String calendarId;
    /**
     * 用户ID
     */
    @ApiModelProperty(value = "用户id", required = true,example = "aa@32131@P")
    private String userId;
    /**
     * 用户状态
     */
    @ApiModelProperty(value = "状态消息",required = false, example = "关注/取消")

    private String userStatus;
    /**
     * 是否公开
     */
    @ApiModelProperty(value = "状态消息true为公开false为不公开", required = false,example = "true")
    private boolean xisPublic;
}
