package com.zeroone.star.project.query.j4.procmanager.application.manage;

import io.swagger.annotations.ApiModelProperty;

/**
 * 人员和顶级实体
 */
public class personTopUnitList {
    /**
     * 人员id
     */
    @ApiModelProperty(value ="人员id",example = "ceaf91f4-5226-4c4a-9bc8-29885ad57c10")
    private String personId;
    /**
     * 顶级单位id
     */
    @ApiModelProperty(value = "顶级单位id",example = "ceaf91f4-5226-4c4a-9bc8-29885ad57c10")
    private String topUnitList;
    /**
     * 排序
     */
    @ApiModelProperty(value = "排序",example = "1")
    private int xorderColumn;
}
