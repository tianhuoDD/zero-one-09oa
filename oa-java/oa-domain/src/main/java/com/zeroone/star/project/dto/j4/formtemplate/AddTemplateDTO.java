package com.zeroone.star.project.dto.j4.formtemplate;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 新增模块操作对象
 */
@Data
@ApiModel("新增模块操作对象")
public class AddTemplateDTO {
    /**
     * 唯一标识id
     */
    @ApiModelProperty(value = "id值", example = "123")
    private String xid;
    /**
     * 种类
     */
    @ApiModelProperty(value = "种类", example = "入职")
    private String xcategory;
    /**
     * 数据
     */
    @ApiModelProperty(value = "数据", example = "123")
    private String xdata;
    /**
     * 描述
     */
    @ApiModelProperty(value = "描述", example = "描述是一个")
    private String xdescription;
    /**
     * 图标
     */
    @ApiModelProperty(value = "图标", example = "图片")
    private String xicon;
    /**
     * 名字
     */
    @ApiModelProperty(value = "名字", example = "haha")
    private String xname;

}
