package com.zeroone.star.project.vo.j1.systemhome;

import com.zeroone.star.project.dto.j1.systemhome.SchedulePreviewDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/21
 */
@Data
@ApiModel("日程预览(查询指定日期的日程)")
public class SchedulePreviewVO {

    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识",example = "123456789")
    private String xid;
    /**
     * 指定日期所有日程
     */
    @ApiModelProperty(value = "指定日期所有日程",example = "[{},{}]")
    private List<SchedulePreviewDTO> previewList;
}
