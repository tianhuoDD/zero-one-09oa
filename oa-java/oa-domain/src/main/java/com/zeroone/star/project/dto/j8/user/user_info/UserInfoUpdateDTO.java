package com.zeroone.star.project.dto.j8.user.user_info;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * @author 西北卓越青年
 */
@Data
@ApiModel("人员信息修改dto")
public class UserInfoUpdateDTO implements Serializable {
    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "姓名", example = "张三")
    private String xname;

    @ApiModelProperty(value = "手机号", example = "1234567890")
    private String xmobile;

    @ApiModelProperty(value = "性别", example = "M")
    private String xgenderType;

    @ApiModelProperty(value = "邮箱", example = "example@domain.com")
    private String xmail;

    @ApiModelProperty(value = "QQ号", example = "987654321")
    private String xqq;

    @ApiModelProperty(value = "上岗日期", example = "2022-01-01")
    private Date xboardDate ;

    @ApiModelProperty(value = "IP地址", example = "192.168.1.1")
    private String xipAddress ;


    @ApiModelProperty(value = "密级标识(100/200/300/400)", example = "100")
    private Integer xsubjectSecurityClearance;


    @ApiModelProperty(value = "唯一标识", example = "uniqueIdentifier123")
    private String xunique;


    @ApiModelProperty(value = "员工", example = "employee123")
    private String xemployee;


    @ApiModelProperty(value = "上级", example = "John Doe")
    private String xsuperior;

    @ApiModelProperty(value = "微信", example = "weixin123")
    private String xweixin;

    @ApiModelProperty(value = "办公电话", example = "010-12345678")
    private String xofficePhone;

    @ApiModelProperty(value = "生日", example = "1990-01-01")
    private Date xbirthday;

    @ApiModelProperty(value = "描述", example = "该员工表现优秀")
    private String xdescription;

    @ApiModelProperty(value = "状态", example = "active")
    private String xstatus;
}
