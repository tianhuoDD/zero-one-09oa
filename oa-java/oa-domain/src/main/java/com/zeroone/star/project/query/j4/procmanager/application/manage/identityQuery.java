package com.zeroone.star.project.query.j4.procmanager.application.manage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.models.auth.In;

import java.util.Date;

/**
 * 查询身份实体
 */
@ApiModel("查询人员实体")
public class identityQuery {
    /**
     * 唯一编码
     */
    @ApiModelProperty(value = "唯一编码", example = "ccc123")
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
     *  姓名
     */
    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;
    /**
     * 人员id号
     */
    @ApiModelProperty(value = "人员id号", example = "2024101917262710a55bce-d25f-4601-81c2-2d586b174581")
    private String person;
    /**
     * unit单位id号
     */
    @ApiModelProperty(value = "unit单位id号", example = "2024101917262710a55bce-d25f-4601-81c2-2d586b174581")
    private String unit;
    /**
     * 单位名称(大组织/小组织)
     */
    @ApiModelProperty(value = "单位总名称", example = "01星球/图灵院(北京分部)")
    private String unitLevelName;
    /**
     * 单位名称
     */
    @ApiModelProperty(value = "单位名称", example = "图灵院(北京分部)")
    private String unitName;


}
