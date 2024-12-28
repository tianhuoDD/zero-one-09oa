package com.zeroone.star.project.vo.j6.calendar;

import com.zeroone.star.project.dto.j6.calendar.InOneDayEventsDTO;
import com.zeroone.star.project.dto.j6.calendar.EventDetailDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel("获取日程列表显示对象")
public class EventsListVO {
    /*
    存放日程持续时间跨越一天的日程，比如从2024-10-21 15：00：00 到2024-10-22 3：00：00
    这个时候这个日程不属于某一天 所以另外存放
     */
    @ApiModelProperty(value = "存放日程持续时间跨越一天的日程", example = "")
    private List<EventDetailDTO> wholeDayEvents;
    /*
    存放日程持续时间在一天内的日程
     */
    @ApiModelProperty(value = "存放日程持续时间在一天内的日程", example = "")
    private List<InOneDayEventsDTO> inOneDayEvents;

}
