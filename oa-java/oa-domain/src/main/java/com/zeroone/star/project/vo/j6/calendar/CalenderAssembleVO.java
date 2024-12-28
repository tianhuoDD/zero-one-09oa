package com.zeroone.star.project.vo.j6.calendar;

import com.zeroone.star.project.dto.j6.calendar.CalendarDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

@Data
@ApiModel
public class CalenderAssembleVO {
//TODO
    /*
    可看见的个人，组，的可公开集合给前端？
    后期需要增加？？
ar> calendarList = null;
		Boolean check = true;
		List<String> ids = null;
		List<String> unitNames = null;
		List<String> groupNames = null;
     */


    @ApiModelProperty(value = "日历列表")
    private List<CalendarDTO> data;
    @ApiModelProperty(value = "响应生成日期")
    private String date;
    @ApiModelProperty(value = "请求处理耗时（毫秒）")
    private long spent;
    @ApiModelProperty(value = "总记录数")
    private long count;

}
