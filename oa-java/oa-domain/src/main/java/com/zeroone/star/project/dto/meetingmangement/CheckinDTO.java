package com.zeroone.star.project.dto.meetingmangement;

import lombok.Data;

import javax.validation.constraints.Min;

@Data
public class CheckinDTO {
    @Min(value = 1, message = "会议ID不能为空")
    private int meetingXid;
}
