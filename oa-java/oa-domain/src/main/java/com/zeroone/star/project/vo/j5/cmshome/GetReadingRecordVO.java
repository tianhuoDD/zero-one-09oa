package com.zeroone.star.project.vo.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 描述  获取阅读记录显示对象
 */
@Data
@ApiModel("阅读记录信息显示对象")
public class GetReadingRecordVO {
    /**
     * 人员名称
     */
    @ApiModelProperty(value = "人员名称", example = "开发者员工1")
    private  String xviewerName;

    /**
     * 单位
     */

    @ApiModelProperty(value = "单位", example = "开发部")
    private String xviewerUnitName;

    /**
     * 首次阅读时间
     */
    @ApiModelProperty(value = "首次阅读时间", example = "2021-09-16 11:16:44")
    private LocalDateTime xviewTime;

    /**
     * 最近阅读时间
     */
    @ApiModelProperty(value = "最后阅读时间", example = "2024-10-20 20:14:21")
    private LocalDateTime xlastViewTime;

    /**
     * 阅读次数
     */
    @ApiModelProperty(value = "阅读次数", example = "2")
    private int xviewCount;

}
