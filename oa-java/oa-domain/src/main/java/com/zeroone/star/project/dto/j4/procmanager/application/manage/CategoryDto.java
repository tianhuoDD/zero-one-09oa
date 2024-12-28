package com.zeroone.star.project.dto.j4.procmanager.application.manage;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：流程应用的分类显示对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author nefertari
 * @version 1.0.0
 */
@Data
public class CategoryDto {
    /**
     * 分类名称
     */
    @ApiModelProperty(value = "分类名称", example = "日常")
    private String name;
    /**
     * 相同分类的应用个数
     */
    @ApiModelProperty(value = "相同分类的应用个数", example = "3")
    private Integer count;
}
