package com.zeroone.star.project.dto.j1.systemhome;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/21
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("文件统计")
public class FileStaticsDTO {
    /**
     * 上传文件数量
     */
    @ApiModelProperty(value = "上传文件数量", example = "12")
    private Long uploadFileCount;
    /**
     * 删除文件数量（按照日历划分周数，统计每周总数量）
     */
    @ApiModelProperty(value = "删除文件数量", example = "18")
    private Long deleteFileCount;
    /**
     * 共享文件数量
     */
    @ApiModelProperty(value = "共享文件数量", example = "25")
    private Long shareFileCount;
    /**
     * 发送文件数量
     */
    @ApiModelProperty(value = "发送文件数量", example = "92")
    private Long sendFileCount;

}
