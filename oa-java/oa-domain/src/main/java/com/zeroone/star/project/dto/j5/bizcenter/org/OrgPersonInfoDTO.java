package com.zeroone.star.project.dto.j5.bizcenter.org;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * 组织人员信息对象
 */
@Data
@ApiModel("组织人员信息对象")
@NoArgsConstructor
@AllArgsConstructor
public class OrgPersonInfoDTO {
    @ApiModelProperty("主键ID")
    private String id; // 主键ID；

    @ApiModelProperty("性别类型")
    private String genderType; // 性别类型；

    @ApiModelProperty("低分辨率头像")
    private String iconLdpi; // 低分辨率头像；

    @ApiModelProperty("中分辨率头像")
    private String iconMdpi; // 中分辨率头像；

    @ApiModelProperty("签名")
    private String signature; // 签名；

    @ApiModelProperty("拼音")
    private String pinyin; // 拼音；

    @ApiModelProperty("拼音首字母")
    private String pinyinInitial; // 拼音首字母；

    @ApiModelProperty("描述")
    private String description; // 描述

    @ApiModelProperty("姓名")
    private String name; // 姓名

    @ApiModelProperty("员工编号")
    private String employee; // 员工编号

    @ApiModelProperty("唯一标识")
    private String unique; // 唯一标识；

    @ApiModelProperty("LDAP中的唯一名称")
    private String distinguishedName; // LDAP中的唯一名称

    @ApiModelProperty("排序编号")
    private Integer orderNumber; // 排序编号

    @ApiModelProperty("语言")
    private String language; // 语言

    @ApiModelProperty("登录失败次数")
    private Integer failureCount; // 登录失败次数；

    @ApiModelProperty("登录失败时间")
    private LocalDateTime failureTime; // 登录失败时间；

    @ApiModelProperty("办公电话")
    private String officePhone; // 办公电话；

    @ApiModelProperty("手机号码")
    private String mobile; // 手机号码；

    @ApiModelProperty("QQ号码")
    private String qq; // QQ号码；

    @ApiModelProperty("微信号码")
    private String weixin; // 微信号码；

    @ApiModelProperty("邮件地址")
    private String mail; // 邮件地址；

    @ApiModelProperty("IP地址")
    private String ipAddress; // IP地址；

    @ApiModelProperty("最后登录地址")
    private String lastLoginAddress; // 最后登录地址；

    @ApiModelProperty("最后登录客户端")
    private String lastLoginClient; // 最后登录客户端；

    @ApiModelProperty("最后登录时间")
    private LocalDateTime lastLoginTime; // 最后登录时间；

    @ApiModelProperty("最后修改密码时间")
    private LocalDateTime changePasswordTime; // 最后修改密码时间；

    @ApiModelProperty("上级ID")
    private String superior; // 上级ID；
}