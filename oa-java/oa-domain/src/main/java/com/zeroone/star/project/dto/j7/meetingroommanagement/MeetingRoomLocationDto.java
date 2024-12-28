package com.zeroone.star.project.dto.j7.meetingroommanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author: zlw
 * @date: 2024-10-22
 */

@Data
@ApiModel("会议室位置新增修改dto")
public class MeetingRoomLocationDto {

    @ApiModelProperty("会议室位置id")
    private String xid;
    @ApiModelProperty("会议室位置名字")
    private String name;
    @ApiModelProperty("会议室位置地址")
    private String address;
}
