package com.zeroone.star.project.vo.j5.cmshome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * 描述  更新阅读记录显示对象
 */
@Data
@ApiModel("阅读记录信息显示对象")
public class UpdateReadingRecordVO {


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
