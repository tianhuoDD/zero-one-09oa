package com.zeroone.star.project.vo.j4.procmanager.application.manage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 显示人员实体
 */
@Data
@ApiModel("可用身份显示对象")
public class IdentityVo {
    /**
     * 可用身份
     */
    @ApiModelProperty(value = "可用身份", example = "张三")
    private String availableIdentity;
    /**
     * 可用身份的组织
     */
    @ApiModelProperty(value = "可用身份的组织", example = "研发部")
    private String availableIdentityUnit;
}
