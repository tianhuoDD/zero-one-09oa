package com.zeroone.star.project.vo.j4.procmanager.data.properties;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：获取数据配置详细
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
@ApiModel("数据配置详细显示对象")
public class DetailedConfigurationVO {

    /**
     * 数据配置名称
     */
    @ApiModelProperty(value = "名称", example = "请假管理")
    private String xname;

    /**
     * 数据配置别名
     */
    @ApiModelProperty(value = "别名", example = "请假")
    private String alias;

    /**
     * 描述
     */
    @ApiModelProperty(value = "描述", example = "管理请假手续的流程")
    private String xdescription;

}
