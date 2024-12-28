package com.zeroone.star.project.vo.j5.bizcenter.org;

import com.zeroone.star.project.dto.j5.bizcenter.org.OrgUnitSimpleInfoDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("个人身份单位信息对象")
public class OrgInfoVO {
    @ApiModelProperty("唯一标识")
    private String matchKey;

    @ApiModelProperty("唯一名称")
    private String distinguishedName; // 唯一名称

    @ApiModelProperty("唯一标识")
    private String unique; // 唯一标识

    @ApiModelProperty("身份名称")
    private String name; // 身份名称

    @ApiModelProperty("身份描述")
    private String description; // 身份描述

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

    @ApiModelProperty("单位信息对象")
    private OrgUnitSimpleInfoDTO woUnit; // 单位信息对象

}
