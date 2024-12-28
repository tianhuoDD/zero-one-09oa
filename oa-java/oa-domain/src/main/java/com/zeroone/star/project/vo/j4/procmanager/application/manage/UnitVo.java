package com.zeroone.star.project.vo.j4.procmanager.application.manage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * 显示组织信息实体
 */
@Data
@ApiModel("组织相关对象显示")
public class UnitVo {
    /**
     * 可用组织
     */
    @ApiModelProperty(value = "可用组织", example = "研发部")
    private String availableUnit;

    /**
     * 可用组织树
     */
    @ApiModelProperty(value = "可用组织树", example = "研发部/硬件研发部")
    private String availableUnitLevelName;
}
