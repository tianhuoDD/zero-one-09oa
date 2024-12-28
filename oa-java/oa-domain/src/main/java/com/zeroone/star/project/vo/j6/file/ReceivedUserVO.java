package com.zeroone.star.project.vo.j6.file;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("接收用户展示对象")
public class ReceivedUserVO {

    @ApiModelProperty(value = "用户ID", example = "1")
    private Long userId;

    @ApiModelProperty(value = "用户名", example = "李四")
    private String username;

    @ApiModelProperty(value = "接收文件数", example = "5")
    private Integer receivedFileCount;

    @ApiModelProperty(value = "上次接收时间", example = "2023-10-12T08:45:30")
    private String lastReceivedTime;

    @ApiModelProperty(value = "接收者邮箱", example = "lisi@example.com")
    private String email;
}
