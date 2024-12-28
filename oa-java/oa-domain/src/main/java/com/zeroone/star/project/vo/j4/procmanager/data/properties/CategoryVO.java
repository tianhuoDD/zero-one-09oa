package com.zeroone.star.project.vo.j4.procmanager.data.properties;

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
@ApiModel("数据配置分类显示对象")
public class CategoryVO {

  /**
   * 数据配置名称
   */
  @ApiModelProperty(value = "名称", example = "请假管理")
  private String xname;
  /**
   * 获取头像
   */
  @ApiModelProperty(value = "图标", example = "icon_url")
  private String icon;

  @ApiModelProperty(value = "表单创建时间", example = "2024-10-19")
  private String xcreateTime;

  /**
   * 配置信息
   */
  @ApiModelProperty(value = "属性", example = "空")
  private String xproperties;

}
