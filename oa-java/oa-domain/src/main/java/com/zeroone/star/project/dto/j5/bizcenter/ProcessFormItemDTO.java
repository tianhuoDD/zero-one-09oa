package com.zeroone.star.project.dto.j5.bizcenter;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

@Data
@ApiModel("表单数据，项目条款")
public class ProcessFormItemDTO {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "数据xid",example = "00b17ed7-5879-4fbe-af2f-9ed5c9c3c26e")
    private String xid;

    @JsonFormat(pattern = "yyyy-MM-dd HH-mm-ss")
    @ApiModelProperty(value = "创建时间",example = "2024-10-25 20:25:27")
    private LocalDateTime xcreateTime;

    @JsonFormat(pattern = "yyyy-MM-dd HH-mm-ss")
    @ApiModelProperty(value = "修改时间",example = "2024-10-25 20:25:27")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "一组的标识",example = "98fc4849-617c-4505-b7de-33f86c80cb5b")
    private String xbundle;

    @JsonFormat(pattern = "yyyy-MM-dd HH-mm-ss")
    @ApiModelProperty(value = "时间数据",example = "2024-10-25 20:25:27")
    private LocalDateTime xdateTimeValue;

    @ApiModelProperty(value = "xdateValue")
    private LocalDate xdateValue;

    @ApiModelProperty(value = "分类",example = "pp")
    private String xitemCategory;

    @ApiModelProperty(value = "基元类型",example = "s")
    private String xitemPrimitiveType;

    @ApiModelProperty(value = "字符串值的类型",example = "s")
    private String xitemStringValueType;

    @ApiModelProperty(value = "类型",example = "s")
    private String xitemType;

    @ApiModelProperty(value = "数字类型")
    private Double xnumberValue;

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

    @ApiModelProperty(value = "项目数据")
    private LocalTime xtimeValue;

}
