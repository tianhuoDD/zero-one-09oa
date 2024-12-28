package com.zeroone.star.project.dto.j6.file;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Builder;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@Builder
@ApiModel("接收用户传输数据对象")
public class ReceivedUserDTO {
    @ApiModelProperty(value = "唯一标识符", example = "12345")
    private String xid;

    @ApiModelProperty(value = "创建时间", example = "2024-10-30T12:00:00")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "序列号", example = "seq-001")
    private String xsequence;

    @ApiModelProperty(value = "更新时间", example = "2024-10-30T12:00:00")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "分配因子", example = "2")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "文件扩展名", example = ".txt")
    private String xextension;

    @ApiModelProperty(value = "文件ID", example = "file-12345")
    private String xfileId;

    @ApiModelProperty(value = "文件类型", example = "text/plain")
    private String xfileType;

    @ApiModelProperty(value = "文件大小（字节）", example = "2048")
    private Long xlength;

    @ApiModelProperty(value = "文件名称", example = "example.txt")
    private String xname;

    @ApiModelProperty(value = "上传者", example = "user123")
    private String xperson;

    @ApiModelProperty(value = "有效时间", example = "2024-12-31T23:59:59")
    private LocalDateTime xvalidTime;
}
