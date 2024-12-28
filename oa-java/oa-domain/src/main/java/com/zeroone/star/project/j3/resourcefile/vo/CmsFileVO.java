package com.zeroone.star.project.j3.resourcefile.vo;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel(description = "文件资源视图对象")
public class CmsFileVO {

    @ApiModelProperty(value = "唯一标识", required = true)
    private String xid;

    @ApiModelProperty(value = "创建时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "序列号")
    private String xsequence;

    @ApiModelProperty(value = "更新时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "分配因子")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "别名")
    private String xalias;

    @ApiModelProperty(value = "应用ID")
    private String xappId;

    @ApiModelProperty(value = "数据内容")
    private String xdata;

    @ApiModelProperty(value = "描述")
    private String xdescription;

    @ApiModelProperty(value = "文件名")
    private String xfileName;

    @ApiModelProperty(value = "最后更新人")
    private String xlastUpdatePerson;

    @ApiModelProperty(value = "最后更新时间")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime xlastUpdateTime;

    @ApiModelProperty(value = "文件长度")
    private Long xlength;

    @ApiModelProperty(value = "文件名")
    private String xname;
}
