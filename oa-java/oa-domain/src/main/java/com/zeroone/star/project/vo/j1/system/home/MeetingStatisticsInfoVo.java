package com.zeroone.star.project.vo.j1.system.home;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：会议统计显示对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1.兔子
 * @version 1.0.0
 */
@Data
@ApiModel("会议统计显示对象")
public class MeetingStatisticsInfoVo {

    /**
     * 会议主题
     */

    @ApiModelProperty(value = "会议主题", example = "项目立项")
    private String meetingSubject;

    /**
     * 会议开始时间
     */

    @ApiModelProperty(value = "会议开始时间", example = "2024-10-22 08:00:00")
    private LocalDateTime meetingStartTime;

    /**
     * 会议结束时间
     */

    @ApiModelProperty(value = "会议结束时间", example = "2024-10-22 09:00:00")
    private LocalDateTime meetingCompletedTime;

    /**
     * 会议室建筑名
     */

    @ApiModelProperty(value = "会议建筑名", example = "1栋")
    private String roomName;

    /**
     * 会议室名字
     */

    @ApiModelProperty(value = "会议室名字", example = "601会议室")
    private String buildingName;

}
