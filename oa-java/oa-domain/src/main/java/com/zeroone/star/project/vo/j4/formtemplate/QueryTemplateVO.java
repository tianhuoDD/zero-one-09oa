package com.zeroone.star.project.vo.j4.formtemplate;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 *显示表单模版对象
 */
@Data
@ApiModel("显示表单模版对象")
public class QueryTemplateVO {
    /**
     * 名字
     */
    @ApiModelProperty(value = "名字", example = "模版123")
    private String xname;
    /**
     * 图片
     */
    @ApiModelProperty(value = "图片", example = "这是一个兔宝宝图片")
    private String xicon;

//    /**
//     * 唯一标识id
//     */
//    @ApiModelProperty(value = "id值", example = "123")
//    private String xid;
//    /**
//     * 创建时间
//     */
//    @ApiModelProperty(value = "时间值", example = "2024.10.19")
//    private String xcreateTime;
//    /**
//     * 顺序
//     */
//    @ApiModelProperty(value = "顺序", example = "1")
//    private String xsequence;
//    /**
//     * 修改时间
//     */
//    @ApiModelProperty(value = "修改时间", example = "2024.10.20")
//    private String xupdateTime;
//    /**
//     * 分配因素
//     */
//    @ApiModelProperty(value = "分配因素", example = "无")
//    private String xdistributeFactor;
//    /**
//     * 别名
//     */
//    @ApiModelProperty(value = "别名", example = "haha")
//    private String xalias;
//    /**
//     * 种类
//     */
//    @ApiModelProperty(value = "种类", example = "入职")
//    private String xcategory;
//    /**
//     * 数据
//     */
//    @ApiModelProperty(value = "数据", example = "123")
//    private String xdata;
//    /**
//     * 描述
//     */
//    @ApiModelProperty(value = "描述", example = "这是一个描述")
//    private String xdescription;
//    /**
//     * 图标
//     */
//    @ApiModelProperty(value = "图标", example = "这是一个兔宝宝")
//    private String xicon;
//    /**
//     * 移动数据
//     */
//    @ApiModelProperty(value = "移动数据", example = "移动数据")
//    private String xmobileData;
//    /**
//     * 名字
//     */
//    @ApiModelProperty(value = "名字", example = "模版123")
//    private String xname;
//    /**
//     * 概述
//     */
//    @ApiModelProperty(value = "概述", example = "这是一个概述")
//    private String xoutline;

}
