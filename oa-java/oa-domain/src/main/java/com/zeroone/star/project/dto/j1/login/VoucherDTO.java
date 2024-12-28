package com.zeroone.star.project.dto.j1.login;

import com.zeroone.star.project.dto.login.LoginDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("保存凭证DTO")
public class VoucherDTO {

    /**
     * 登录信息数据传输对象
     */
    @ApiModelProperty(value = "登录信息数据传输对象", example = "admin")
    private LoginDTO loginDTO;

    /**
     * 客户端ID
     */
    @ApiModelProperty(value = "客户端ID", example = "your-client-id")
    private String clientId;



}

