package com.zeroone.star.project.query.j4.procmanager.application.manage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;

import java.util.Date;

/**
 * 查询组织机构实体
 */
@ApiModel("组织机构实体")
public class unitQuery {
    /**
     * 组织id
     */
    @ApiModelProperty(value = "组织id", example = "aaa01")
    private String id;
    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2022-01-01 12")
    private Date create_time;
    /**
     * 排序
     */
    @ApiModelProperty(value = "排序", example = "2024101917262710a55bce-d25f-4601-81c2-2d586b174581")
    private String sequence;
    /**
     * 更新时间
     */
    @ApiModelProperty(value = "更新时间", example = "2022-01-01 12")
    private Date update_time;
    /**
     * 组织总名称
     */
    @ApiModelProperty(value = "组织总名称", example = "01星球/图灵院(北京分院)")
    private String leveName;
    /**
     * 组织名称
     */
    @ApiModelProperty(value = "组织名称", example = "图灵院(北京分院)")
    private String name;
    /**
     * 上级组织id
     */
    @ApiModelProperty(value = "上级组织id", example = "aaa01")
    private String superior;
    /**
     * 组织唯一标识
     */
    @ApiModelProperty(value = "组织唯一标识", example = "001")
    private String unique;

}
