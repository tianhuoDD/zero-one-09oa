package com.zeroone.star.login.entity;


import io.github.classgraph.json.Id;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.Size;
import java.sql.Timestamp;

/**
 * org_authcode
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
@Builder
public class OrgAuthcode {

    @Id
    @ApiModelProperty(value = "唯一标识", required = true)
    private String xid;


    @ApiModelProperty(value = "创建时间")
    private Timestamp xcreateTime;


    @Size(max = 128, message = "序列号长度不能超过128")
    @ApiModelProperty(value = "序列号", required = true)
    private String xsequence;


    @ApiModelProperty(value = "更新时间")
    private Timestamp xupdateTime;


    @ApiModelProperty(value = "分配因子")
    private Integer xdistributeFactor;


    @Size(max = 64, message = "访问令牌长度不能超过64")
    @ApiModelProperty(value = "访问令牌")
    private String xaccessToken;


    @Size(max = 255, message = "客户端ID长度不能超过255")
    @ApiModelProperty(value = "客户端ID", required = true)
    private String xclientId;


    @Size(max = 64, message = "授权码长度不能超过64")
    @ApiModelProperty(value = "授权码", required = true)
    private String xcode;


    @ApiModelProperty(value = "授权码是否已使用")
    private Boolean xcodeUsed;


    @Size(max = 64, message = "用户标识长度不能超过64")
    @ApiModelProperty(value = "用户标识")
    private String xperson;


    @Size(max = 255, message = "作用域长度不能超过255")
    @ApiModelProperty(value = "作用域")
    private String xscope;
}
