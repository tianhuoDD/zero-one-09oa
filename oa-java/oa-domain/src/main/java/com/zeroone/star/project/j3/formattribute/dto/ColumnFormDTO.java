package com.zeroone.star.project.j3.formattribute.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * CMS表单数据传输对象
 *
 * 该类表示CMS系统中的表单信息的数据传输对象。
 *
 * @author lenyan
 * @since 2024-10-15
 */
@Data
@ApiModel(description = "CMS表单传输数据对象")
public class ColumnFormDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "表单唯一标识符")
    private String xid;

    @ApiModelProperty(value = "创建时间")
    private LocalDateTime xcreateTime;

    @ApiModelProperty(value = "表单序列号", example = "123456")
    private String xsequence;

    @ApiModelProperty(value = "更新时间")
    private LocalDateTime xupdateTime;

    @ApiModelProperty(value = "分发因子", example = "1")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "别名", example = "form1")
    private String xalias;

    @ApiModelProperty(value = "应用ID", example = "按需填写")
    private String xappId;

    @ApiModelProperty(value = "表单数据", example = "{\"field1\":\"value1\"}")
    private String xdata;

    @ApiModelProperty(value = "描述信息", example = "这是一个表单")
    private String xdescription;

    @ApiModelProperty(value = "编辑者")
    private String xeditor;

    @ApiModelProperty(value = "是否有移动端版本", example = "true")
    private Boolean xhasMobile;

    @ApiModelProperty(value = "移动端数据", example = "{\"field1\":\"value1\"}")
    private String xmobileData;

    @ApiModelProperty(value = "表单名称", example = "表单1")
    private String xname;

    @ApiModelProperty(value = "属性信息", example = "{\"property1\":\"value1\"}")
    private String xproperties;

}