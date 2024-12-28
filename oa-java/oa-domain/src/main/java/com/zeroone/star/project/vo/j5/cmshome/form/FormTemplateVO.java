package com.zeroone.star.project.vo.j5.cmshome.form;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;


/**
 * 描述：消息表单模板
 *
 * @author Henry
 */
@Data
@ApiModel("消息表单模板VO")
public class FormTemplateVO {
    /**
     * 唯一标识
     */
    @ApiModelProperty("唯一标识")
    private String xid;
    /**
     * 表单创建时间
     */
    @ApiModelProperty("表单创建时间")
    private LocalDateTime xcreateTime;
    /**
     * 表单次序
     */
    @ApiModelProperty("表单次序")
    private String xsequence;
    /**
     * 表单更新时间
     */
    @ApiModelProperty("表单更新时间")
    private LocalDateTime xupdateTime;
    /**
     * 分配因子
     */
    @ApiModelProperty("分配因子")
    private Integer xdistributeFactor;
    /**
     * 表单别名
     */
    @ApiModelProperty("表单别名")
    private String xalias;
    /**
     * 表单类型
     */
    @ApiModelProperty("表单类型")
    private String xcategory;
    /**
     * 表单数据
     */
    @ApiModelProperty("表单数据")
    private String xdata;
    /**
     * 表单描述
     */
    @ApiModelProperty("表单描述")
    private String xdescription;
    /**
     * 表单图标
     */
    @ApiModelProperty("表单图标")
    private String xicon;
    /**
     * 表单可变数据
     */
    @ApiModelProperty("表单可变数据")
    private String xmobileData;
    /**
     * 表单名称
     */
    @ApiModelProperty("表单名称")
    private String xname;
    /**
     * 表单概述
     */
    @ApiModelProperty("表单概述")
    private String xoutline;
}
