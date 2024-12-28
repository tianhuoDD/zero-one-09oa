package com.zeroone.star.project.query.j4.procmanager.application.manage;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：应用查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author nefertari
 * @version 1.0.0
 */
@Data
@ApiModel("应用查询对象")
public class ApplicationQuery extends PageQuery {

    @NotBlank(message = "用户名不能为空")
    @ApiModelProperty(value = "应用类型", example = "工作")
    private String category;

    @ApiModelProperty(value = "描述关键字", example = "试")
    private String keyword;
}
