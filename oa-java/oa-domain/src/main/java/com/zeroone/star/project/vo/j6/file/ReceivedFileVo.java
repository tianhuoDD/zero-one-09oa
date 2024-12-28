package com.zeroone.star.project.vo.j6.file;

import io.swagger.annotations.ApiModelProperty;

public class ReceivedFileVo {
    @ApiModelProperty(value = "文件唯一标识", example = "123456")
    private String fileId;

    @ApiModelProperty(value = "文件名称", example = "项目文档.pdf")
    private String fileName;

    @ApiModelProperty(value = "发送者信息", example = "张三")
    private String sender;

    @ApiModelProperty(value = "接收时间", example = "2024-10-20T12:00:00")
    private String receivedTime;

    @ApiModelProperty(value = "文件大小", example = "1.5MB")
    private String fileSize;

    @ApiModelProperty(value = "文件类型", example = "pdf")
    private String fileType;

    @ApiModelProperty(value = "文件状态", example = "已接收")
    private String status;
}
