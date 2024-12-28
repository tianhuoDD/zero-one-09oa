package com.zeroone.star.project.dto.j5.bizcenter.org;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * 组织单位信息对象【精简】
 */
@Data
@ApiModel("精简组织单位信息对象")
@NoArgsConstructor
@AllArgsConstructor
public class OrgUnitSimpleInfoDTO {

    @ApiModelProperty("名称")
    private String name; // 名称；

    @ApiModelProperty("唯一标识")
    private String unique; // 唯一标识；

    @ApiModelProperty("LDAP中的唯一名称")
    private String distinguishedName; // LDAP中的唯一名称；

    @ApiModelProperty("描述")
    private String description; // 描述；

    @ApiModelProperty("简称")
    private String shortName; // 简称；

    @ApiModelProperty("层级")
    private Integer level; // 层级；

    @ApiModelProperty("层级名称")
    private String levelName; // 层级名称；

    @ApiModelProperty("层级排序编号")
    private String levelOrderNumber; // 层级排序编号；

    @ApiModelProperty("上级单位ID")
    private String superior; // 上级单位ID；

    @ApiModelProperty("排序编号")
    private Integer orderNumber; // 排序编号；

}
