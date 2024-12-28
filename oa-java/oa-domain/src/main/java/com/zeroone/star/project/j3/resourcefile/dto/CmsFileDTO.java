package com.zeroone.star.project.j3.resourcefile.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

@Data
@ApiModel(description = "文件资源传输对象")
public class CmsFileDTO {

    @ApiModelProperty(value = "唯一标识", required = true, example = "1")
    private String xid;


    @ApiModelProperty(value = "序列号")
    private String xsequence;


    @ApiModelProperty(value = "分配因子", example = "1")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "别名")
    private String xalias;

    @ApiModelProperty(value = "应用ID")
    private String xappId;

    @ApiModelProperty(value = "数据内容", example = "group/file")
    private String xdata;

    @ApiModelProperty(value = "描述")
    private String xdescription;

    @ApiModelProperty(value = "文件名")
    private String xfileName;

    @ApiModelProperty(value = "最后更新人")
    private String xlastUpdatePerson;

    @ApiModelProperty(value = "文件长度", example = "1")
    private Long xlength;

    @ApiModelProperty(value = "上传文件")
    private MultipartFile file;
}