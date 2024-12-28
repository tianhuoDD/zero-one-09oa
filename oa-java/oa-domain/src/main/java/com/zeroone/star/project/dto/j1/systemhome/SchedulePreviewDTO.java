package com.zeroone.star.project.dto.j1.systemhome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/21
 */
@Data
@ApiModel("日程预览(查询指定日期创建/参与的日程)")
public class SchedulePreviewDTO {

    /**
     * 日程唯一标识
     */
    @ApiModelProperty(value = "日程唯一标识", example = "123456789")
    private String xid;

    /**
     * 日程来源
     */
    @ApiModelProperty(  value = "日程来源", example = "我创建的/组织内的/群组内的/我参与的/我管理的")
    private String xsource;

    /**
     * 日程类型
     */
    @ApiModelProperty(value = "日程类型", example = "日程/会议/任务/公告/文件")
    private String xeventType;

    /**
     * 日程标题
     */
    @ApiModelProperty(value = "日程标题", example = "六星街里还传来，巴扬琴声吗")
    private String xtitle;

}
