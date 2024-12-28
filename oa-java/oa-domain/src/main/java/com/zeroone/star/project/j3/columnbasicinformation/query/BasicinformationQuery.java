package com.zeroone.star.project.j3.columnbasicinformation.query;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：栏目基础信息传输对象的封装
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author chen
 * @since 2024-10-20
 */

@Data
@ApiModel("栏目基础信息查询对象")
public class BasicinformationQuery {
    @NotBlank(message = "xid不能为空")
    @ApiModelProperty(value = "主键xid")
    private String xid;

}
