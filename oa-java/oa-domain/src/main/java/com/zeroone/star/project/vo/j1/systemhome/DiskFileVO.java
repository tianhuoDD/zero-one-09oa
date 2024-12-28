package com.zeroone.star.project.vo.j1.systemhome;

import com.zeroone.star.project.dto.j1.systemhome.DiskFileDTO;
import com.zeroone.star.project.dto.j1.systemhome.SchedulePreviewDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * @author 李云毅
 * @version 1.0.0
 * 2024/10/24
 */
@Data
@ApiModel("网盘文件查询列表")
public class DiskFileVO {
    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识",example = "123456789")
    private String xid;
    /**
     * 查询文件列表
     */
    @ApiModelProperty(value = "查询文件列表",example = "[null,null,null]")
    private List<DiskFileDTO> diskFileDTOList;

}