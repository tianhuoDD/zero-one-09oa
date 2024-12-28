package com.zeroone.star.project.j3.columnbasicinformation.dto;


import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

/**
 * 描述：栏目配置传输对象
 * @author Kokoro
 * @version 1.0.0
 */
@Data
@ApiModel("栏目配置传输对象")
public class AppinfoConfigDTO {

    @ApiModelProperty(value = "栏目唯一标识", example = "1852268060998205441")
    private String xid;

    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "栏目配置创建时间", example = "2024-10-17 21:15:51")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "栏目配置序列号", example = "2024101721155001d4245f-a8e8-4b98-a969-efaa32af674b")
    private String xsequence;

    @DateTimeFormat(pattern="yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "栏目配置最近更新时间", example = "2024-10-18 15:23:46")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "栏目配置分布因子", example = "1")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "栏目配置信息", example = "{\"ignoreTitle\":false,\"latest\":true,\"saveDraftOnClose\":true}")
    private String xconfig;
}
