package com.zeroone.star.project.dto.j1.yanzhengma.phone;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 获取短信验证码
 */
@Data
@ApiModel("获取短信验证码")
public class PhoneyzInfoDTO {
    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识", example = "12ass22sa3")
    private String id;

    /**
     * 办公电话
     */
    @ApiModelProperty(value = "办公电话", example = "11111111111")
    private String phone;
}
