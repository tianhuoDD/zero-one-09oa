package com.zeroone.star.project.dto.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotEmpty;

/**
 * @program: oa-java
 * @description:
 * @author: Mr.Wang
 * @create: 2024-11-02 15:14
 **/
@Data
@ApiModel("下载文件数据对象")
public class DownloadFileDTO {
    /**
     * 服务器分组
     */
    @ApiModelProperty(value = "服务器分组",required = true,example = "")
    @NotEmpty
    private String group;
    /**
     * 对应的存储资源ID
     */
    @ApiModelProperty(value = "对应的存储资源ID",required = true, example = "")
    @NotEmpty
    private String storageId;
}
