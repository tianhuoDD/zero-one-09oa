package com.zeroone.star.project.dto.j8.user.user;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
public class AddPersonDTO {

    @ApiModelProperty(value = "序列号", example = "ABC123")
    private String xsequence;

    @ApiModelProperty(value = "分配因子", example = "10")
    private Integer xdistributeFactor;

    @ApiModelProperty(value = "年龄", example = "30")
    private Integer xage;

    @ApiModelProperty(value = "Fx Hash", example = "hash123")
    private String xandFxHash;

    @ApiModelProperty(value = "Fx ID", example = "FxID123")
    private String xandFxId;

    @ApiModelProperty(value = "生日", example = "1990-01-01")
    private String xbirthday;

    @ApiModelProperty(value = "上岗日期", example = "2022-01-01")
    private String xboardDate;

    @ApiModelProperty(value = "密码更改时间", example = "2022-05-01")
    private String xchangePasswordTime;

    @ApiModelProperty(value = "描述", example = "该员工表现优秀")
    private String xdescription;

    @ApiModelProperty(value = "钉钉 Hash", example = "dingdingHash123")
    private String xdingdingHash;

    @ApiModelProperty(value = "钉钉 ID", example = "dingdingID123")
    private String xdingdingId;

    @ApiModelProperty(value = "识别名", example = "DN123")
    private String xdistinguishedName;

    @ApiModelProperty(value = "员工", example = "employee123")
    private String xemployee;

    @ApiModelProperty(value = "性别", example = "M")
    private String xgenderType;

    @ApiModelProperty(value = "是否隐藏手机号", example = "false")
    private Boolean xhiddenMobile;

    @ApiModelProperty(value = "头像", example = "icon123")
    private String xicon;

    @ApiModelProperty(value = "低分辨率头像", example = "iconLdpi123")
    private String xiconLdpi;

    @ApiModelProperty(value = "中分辨率头像", example = "iconMdpi123")
    private String xiconMdpi;

    @ApiModelProperty(value = "语言", example = "zh-CN")
    private String xlanguage;

    @ApiModelProperty(value = "邮箱", example = "example@domain.com")
    private String xmail;

    @ApiModelProperty(value = "手机号", example = "1234567890")
    private String xmobile;

    @ApiModelProperty(value = "昵称", example = "三哥")
    private String xnickName;

    @ApiModelProperty(value = "办公电话", example = "010-12345678")
    private String xofficePhone;

    @ApiModelProperty(value = "状态", example = "active")
    private String xstatus;

    @ApiModelProperty(value = "状态描述", example = "正在工作")
    private String xstatusDes;

    @ApiModelProperty(value = "上级", example = "John Doe")
    private String xsuperior;

    @ApiModelProperty(value = "微信", example = "weixin123")
    private String xweixin;

    @ApiModelProperty(value = "QQ号", example = "987654321")
    private String xqq;

    @ApiModelProperty(value = "微信Open ID", example = "mpwxopenId123")
    private String xmpwxopenId;

    @ApiModelProperty(value = "姓名", example = "张三")
    private String xname;

    @ApiModelProperty(value = "第一个Open ID", example = "open1Id123")
    private String xopen1Id;

    @ApiModelProperty(value = "第二个Open ID", example = "open2Id123")
    private String xopen2Id;

    @ApiModelProperty(value = "第三个Open ID", example = "open3Id123")
    private String xopen3Id;

    @ApiModelProperty(value = "第四个Open ID", example = "open4Id123")
    private String xopen4Id;

    @ApiModelProperty(value = "第五个Open ID", example = "open5Id123")
    private String xopen5Id;

    @ApiModelProperty(value = "排序号", example = "1")
    private Integer xorderNumber;

    @ApiModelProperty(value = "密码", example = "password123")
    private String xpassword;
    @ApiModelProperty(value = "拼音", example = "zhangsan")
    private String xpinyin;

    @ApiModelProperty(value = "拼音首字母", example = "zs")
    private String xpinyinInitial;

    @ApiModelProperty(value = "企业微信哈希", example = "qiyeweixinHash123")
    private String xqiyeweixinHash;

    @ApiModelProperty(value = "企业微信ID", example = "qiyeweixinID123")
    private String xqiyeweixinId;

    @ApiModelProperty(value = "签名", example = "张三的签名")
    private String xsignature;

    @ApiModelProperty(value = "安全清理", example = "安全")
    private String xsubjectSecurityClearance;

    @ApiModelProperty(value = "唯一标识", example = "uniqueIdentifier123")
    private String xunique;

    @ApiModelProperty(value = "WeLink哈希", example = "weLinkHash123")
    private String xweLinkHash;

    @ApiModelProperty(value = "WeLink ID", example = "weLinkID123")
    private String xweLinkId;

    @ApiModelProperty(value = "政务钉钉哈希", example = "zhengwuDingdingHash123")
    private String xzhengwuDingdingHash;

    @ApiModelProperty(value = "政务钉钉ID", example = "zhengwuDingdingID123")
    private String xzhengwuDingdingId;
}
