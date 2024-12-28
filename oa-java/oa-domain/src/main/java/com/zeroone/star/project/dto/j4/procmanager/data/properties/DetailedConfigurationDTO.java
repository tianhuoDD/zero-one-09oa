package com.zeroone.star.project.dto.j4.procmanager.data.properties;

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
@ApiModel("获取数据配置详细")
public class DetailedConfigurationDTO {

    /**
     * 数据配置名称
     */
    @ApiModelProperty(value = "配置列表名称", example = "测试流程字典1")
    private String xname;
    /**
     * 数据配置别名
     */
    @ApiModelProperty(value = "配置列表别名", example = "1")
    private String alias;
    /**
     * 描述
     */
    @ApiModelProperty(value = "描述", example = "这是测试流程字典")
    private String xdescription;

}/*
  * @ApiModelProperty(value = "表单更新时间", example = "2024-10-19")
  * private String xupdateTime;
  * 
  * @ApiModelProperty(value = "表单创建人", example = "xadmin")
  * private String xcreatorPerson;
  * 
  * @ApiModelProperty(value = "表单创建时间", example = "xamdmin")
  * private String xlastUpdatePerson;
  * 
  * @ApiModelProperty(value = "表单最新更新时间", example = "2024-10-19")
  * private String xlastUpDateTime;
  */
