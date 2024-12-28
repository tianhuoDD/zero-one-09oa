package com.zeroone.star.project.dto.j1.settings;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("保存个人信息")
public class SaveInfoDTO {

    @ApiModelProperty(value = "编号", example = "1")
    private String id;

    @ApiModelProperty(value = "办公电话", example = "1881114514")
    private String officePhone;

    @ApiModelProperty(value = "微信号", example = "wx_id12319848")
    private String weixin;

    @ApiModelProperty(value = "qq号", example = "138418362")
    private String qq;

    @ApiModelProperty(value = "个人签名", example = "求求你阻止我")
    private String signature;

    @ApiModelProperty(value = "论坛昵称", example = "句号")
    private String nickname;

    @ApiModelProperty(value = "语言设置", example = "English")
    private String language;
}
