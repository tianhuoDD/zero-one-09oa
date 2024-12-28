package com.zeroone.star.project.dto.j4.procmanager.data.properties;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：获取数据配置列表
 * </p>
 * <p>
 * 版权：&copy;01星球
 * </p>
 * <p>
 * 地址：01星球总部
 * </p>
 * 
 * @author 阳林
 * @version 1.0.0
 */
@Data
@ApiModel("数据配置分类查询对象")
public class CategoryDTO {

    /**
     * 数据配置名称
     */
    @ApiModelProperty(value = "名称", example = "请假管理")
    private String xname;

}
