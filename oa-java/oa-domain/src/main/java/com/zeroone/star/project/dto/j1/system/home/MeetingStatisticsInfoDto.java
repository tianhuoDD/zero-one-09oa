package com.zeroone.star.project.dto.j1.system.home;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：会议统计操作对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1.兔子
 * @version 1.0.0
 */
@Data
@ApiModel("会议统计操作对象")
public class MeetingStatisticsInfoDto {
    /**
     * 用户id
     */
    @ApiModelProperty(value = "唯一标识", example = "12ass22sa3")
    private String id;

}
