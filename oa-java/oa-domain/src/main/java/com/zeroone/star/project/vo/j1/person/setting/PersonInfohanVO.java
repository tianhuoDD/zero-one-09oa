package com.zeroone.star.project.vo.j1.person.setting;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 个人信息显示对象
 */
@Data
@ApiModel("个人信息显示对象")
public class PersonInfohanVO {
    /**
     * 唯一标识
     */
    @ApiModelProperty(value = "唯一标识", example = "12ass22sa3")
    private String id;
    /**
     * 姓名
     */
    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;
    /**
     * 工号
     */
    @ApiModelProperty(value = "工号", example = "3423")
    private String number;
    /**
     * 邮箱
     */
    @ApiModelProperty(value = "邮箱", example = "123131312@qq.com")
    private String mail;
    /**
     * 办公电话
     */
    @ApiModelProperty(value = "办公电话", example = "11111111111")
    private String phone;
    /**
     * 座机
     */
    @ApiModelProperty(value = "座机", example = "132312312")
    private String telphone;
    /**
     * 微信
     */
    @ApiModelProperty(value = "微信", example = "342423423")
    private String weixin;
    /**
     * QQ
     */
    @ApiModelProperty(value = "QQ", example = "32425564463")
    private String qq;
    /**
     * 论坛名称
     */
    @ApiModelProperty(value = "论坛名称", example = "猪猪")
    private String bbsname;
    /**
     * 个性签名
     */
    @ApiModelProperty(value = "个性签名", example = "> _ <")
    private String single;
    /**
     * 头像地址
     */
    @ApiModelProperty(value = "头像地址", example = "324242342")
    private String head;

    /**
     * 语言
     */
    @ApiModelProperty(value = "语言", example = "324242342")
    private String language;

}