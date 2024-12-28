package com.zeroone.star.project.dto.j5.bizcenter;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("流程 数据对象")
public class ProcessDTO {
    @ApiModelProperty("流程ID")
    private String id;

    @ApiModelProperty("应用名称")
    private String application;

    @ApiModelProperty("流程名称")
    private String name;

    @ApiModelProperty("创建人")
    private String creatorPerson;

    @ApiModelProperty("最后更新时间")
    private LocalDateTime lastUpdateTime;

    @ApiModelProperty("版本号")
    private String edition;

    @ApiModelProperty("版本名称")
    private String editionName;

    @ApiModelProperty("版本是否启用")
    private Boolean editionEnable;

    @ApiModelProperty("版本编号")
    private Double editionNumber;

    @ApiModelProperty("创建时间")
    private LocalDateTime createTime;

    @ApiModelProperty("更新时间")
    private LocalDateTime updateTime;
}