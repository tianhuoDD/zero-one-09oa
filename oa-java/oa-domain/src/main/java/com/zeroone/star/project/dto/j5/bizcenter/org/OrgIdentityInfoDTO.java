package com.zeroone.star.project.dto.j5.bizcenter.org;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;


/**
 * 组织身份信息对象
 */
@Data
@ApiModel("组织身份信息对象")
@NoArgsConstructor
@AllArgsConstructor
public class OrgIdentityInfoDTO {
    @ApiModelProperty("创建时间")
    private LocalDateTime createTime; // 创建时间；

    @ApiModelProperty("更新时间")
    private LocalDateTime updateTime; // 更新时间；

    @ApiModelProperty("是否主要身份")
    private Boolean major; // 是否主要身份

    @ApiModelProperty("排序编号")
    private Integer orderNumber; // 排序编号

    @ApiModelProperty("单位级别名称")
    private String unitLevelName; // 单位级别名称

    @ApiModelProperty("单位级别")
    private Integer unitLevel; // 单位级别

    @ApiModelProperty("关联的单位名称")
    private String unitName; // 关联的单位名称

    @ApiModelProperty("关联的单位ID")
    private String unit; // 关联的单位ID

    @ApiModelProperty("关联的个人ID")
    private String person; // 关联的个人ID

    @ApiModelProperty("唯一名称")
    private String distinguishedName; // 唯一名称

    @ApiModelProperty("唯一标识")
    private String unique; // 唯一标识

    @ApiModelProperty("身份名称")
    private String name; // 身份名称

    @ApiModelProperty("身份描述")
    private String description; // 身份描述

    @ApiModelProperty("名称的拼音")
    private String pinyin; // 名称的拼音

    @ApiModelProperty("名称的拼音首字母")
    private String pinyinInitial; // 名称的拼音首字母

    @ApiModelProperty("主键ID")
    private String id; // 主键ID
}