package com.zeroone.star.project.dto.j5.bizcenter;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

@Data
@AllArgsConstructor
public class ProcessFormData {
    @ApiModelProperty(value = "第一个数据",example = "$work")
    private String xpath0;

    @ApiModelProperty(value = "第一个数据的位置",example = "-1")
    private Integer xpath0Location;

    @ApiModelProperty(value = "第二个数据",example = "process")
    private String xpath1;

    @ApiModelProperty(value = "第二个数据的位置",example = "-1")
    private Integer xpath1Location;

    @ApiModelProperty(value = "第三个数据",example = "name")
    private String xpath2;

    @ApiModelProperty(value = "第三个数据的位置",example = "-1")
    private Integer xpath2Location;

    @ApiModelProperty(value = "第四个数据")
    private String xpath3;

    @ApiModelProperty(value = "第一个数据的位置")
    private Integer xpath3Location;

    @ApiModelProperty(value = "第五个数据")
    private String xpath4;

    @ApiModelProperty(value = "第五个数据的位置")
    private Integer xpath4Location;

    @ApiModelProperty(value = "第六个数据")
    private String xpath5;

    @ApiModelProperty(value = "第六个数据的位置")
    private Integer xpath5Location;

    @ApiModelProperty(value = "第七个数据")
    private String xpath6;

    @ApiModelProperty(value = "第七个数据的位置")
    private Integer xpath6Location;

    @ApiModelProperty(value = "第八个数据")
    private String xpath7;

    @ApiModelProperty(value = "第八个数据的位置")
    private Integer xpath7Location;

    @ApiModelProperty(value = "长的数据")
    private String xstringLongValue;

    @ApiModelProperty(value = "短的数据",example = "kk公司")
    private String xstringShortValue;

}
