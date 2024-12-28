package com.zeroone.star.project.vo.j1.system.home;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：流程信息显示对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1.兔子
 * @version 1.0.0
 */
@Data
@ApiModel("流程信息显示对象")
public class ProcessInfoVo {
    /**
     * 待办
     */
    @ApiModelProperty(value = "待办", example = "1")
    private int task;

    /**
     * 已办
     */

    @ApiModelProperty(value = "已办", example = "1")
    private int taskCompleted;

    /**
     * 待阅
     */

    @ApiModelProperty(value = "待阅", example = "1")
    private int read;

    /**
     * 已阅
     */

    @ApiModelProperty(value = "已阅", example = "1")
    private int readCompleted;

    /**
     * 草稿
     */

    @ApiModelProperty(value = "草稿", example = "1")
    private int draft;
}
