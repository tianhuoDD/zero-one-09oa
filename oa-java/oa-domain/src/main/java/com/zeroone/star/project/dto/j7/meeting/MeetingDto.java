package com.zeroone.star.project.dto.j7.meeting;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.time.LocalTime;

@Data
@ApiModel("会议管理传输数据对象")
public class MeetingDto {

    @ApiModelProperty(value = "会议id",example = "1")
    private String xid;
    @ApiModelProperty(value = "会议创建时间",example = "2024-10-21 19:47:42")
    private LocalDateTime xcreateTime;
    @ApiModelProperty(value = "会议修改时间",example = "2024-10-21 19:47:42")
    private LocalDateTime xupdateTime;
    @ApiModelProperty(value = "会议实际完成时间",example = "2024-10-21 19:47:42")
    private LocalTime xactualCompletedTime;
    @ApiModelProperty(value = "会议实际开始时间",example = "2024-10-21 19:47:42")
    private LocalTime xactualStartTime;
    @ApiModelProperty(value = "会议室id",example = "22")
    private String xroomId;
    @ApiModelProperty(value = "会议室链接",example = "url:......")
    private String xroomLink;
    @ApiModelProperty(value = "会议开始时间",example = "2024-10-21 19:47:42")
    private LocalDateTime xstartTime;

}
