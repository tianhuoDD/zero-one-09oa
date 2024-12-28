package com.zeroone.star.project.vo.j1.userInfo;

import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;


@Data
public class UserInfoVO implements Serializable {

	@ApiModelProperty(value = "用户角色列表", example = "['ADMIN','MANAGER']")
	private List<String> roles;


	@ApiModelProperty(value = "菜单列表", example = "['ADMIN','MANAGER']")
	private MenuTreeVO menuTreeVO;
	/**
	 * 用户id
	 */
	@ApiModelProperty(value = "用户id", example = "12345")
	private String xid;

	/**
	 * 用户年龄
	 */
	@ApiModelProperty(value = "用户年龄", example = "30")
	private Integer xage;

	/**
	 * 用户生日
	 */
	@ApiModelProperty(value = "用户生日", example = "1990-01-01")
	private LocalDate xbirthday;

	/**
	 * 入职日期
	 */
	@ApiModelProperty(value = "入职日期", example = "2020-01-01")
	private LocalDate xboardDate;

	/**
	 * 上次修改密码时间
	 */
	@ApiModelProperty(value = "上次修改密码时间", example = "2023-01-01")
	private LocalDate xchangePasswordTime;

	/**
	 * 用户描述
	 */
	@ApiModelProperty(value = "用户描述", example = "这是一个管理员用户")
	private String xdescription;

	/**
	 * 钉钉ID
	 */
	@ApiModelProperty(value = "钉钉ID", example = "ding123456")
	private String xdingdingId;

	/**
	 * 用户唯一标识
	 */
	@ApiModelProperty(value = "用户唯一标识", example = "user123456")
	private String xdistinguishedName;

	/**
	 * 员工编号
	 */
	@ApiModelProperty(value = "员工编号", example = "EMP001")
	private String xemployee;

	/**
	 * 登录失败次数
	 */
	@ApiModelProperty(value = "登录失败次数", example = "2")
	private Integer xfailureCount;

	/**
	 * 上次登录失败时间
	 */
	@ApiModelProperty(value = "上次登录失败时间", example = "2023-01-01T12:00:00")
	private LocalDateTime xfailureTime;

	/**
	 * 性别
	 */
	@ApiModelProperty(value = "性别", example = "MALE")
	private String xgenderType;

	/**
	 * 是否隐藏手机号
	 */
	@ApiModelProperty(value = "是否隐藏手机号", example = "true")
	private Boolean xhiddenMobile;

	/**
	 * 用户头像
	 */
	@ApiModelProperty(value = "用户头像", example = "http://example.com/avatar.jpg")
	private String xicon;

	/**
	 * 用户头像（低分辨率）
	 */
	@ApiModelProperty(value = "用户头像（低分辨率）", example = "http://example.com/avatar_ldpi.jpg")
	private String xiconLdpi;

	/**
	 * 用户头像（中分辨率）
	 */
	@ApiModelProperty(value = "用户头像（中分辨率）", example = "http://example.com/avatar_mdpi.jpg")
	private String xiconMdpi;

	/**
	 * 上次登录IP地址
	 */
	@ApiModelProperty(value = "上次登录IP地址", example = "192.168.1.1")
	private String xipAddress;

	/**
	 * 用户语言
	 */
	@ApiModelProperty(value = "用户语言", example = "zh_CN")
	private String xlanguage;

	/**
	 * 上次登录地址
	 */
	@ApiModelProperty(value = "上次登录地址", example = "北京市")
	private String xlastLoginAddress;

	/**
	 * 上次登录客户端
	 */
	@ApiModelProperty(value = "上次登录客户端", example = "Chrome")
	private String xlastLoginClient;

	/**
	 * 上次登录时间
	 */
	@ApiModelProperty(value = "上次登录时间", example = "2023-01-01T12:00:00")
	private LocalDateTime xlastLoginTime;

	/**
	 * 账户锁定时间
	 */
	@ApiModelProperty(value = "账户锁定时间", example = "2023-01-01T12:00:00")
	private LocalDateTime xlockTime;

	/**
	 * 用户邮箱
	 */
	@ApiModelProperty(value = "用户邮箱", example = "user@example.com")
	private String xmail;

	/**
	 * 用户手机号
	 */
	@ApiModelProperty(value = "用户手机号", example = "13800138000")
	private String xmobile;

	/**
	 * 微信开放ID
	 */
	@ApiModelProperty(value = "微信开放ID", example = "wx123456")
	private String xmpwxopenId;

	/**
	 * 用户姓名
	 */
	@ApiModelProperty(value = "用户姓名", example = "张三")
	private String xname;

	/**
	 * 用户昵称
	 */
	@ApiModelProperty(value = "用户昵称", example = "小张")
	private String xnickName;

	/**
	 * 办公电话
	 */
	@ApiModelProperty(value = "办公电话", example = "010-12345678")
	private String xofficePhone;

	/**
	 * 排序号
	 */
	@ApiModelProperty(value = "排序号", example = "1")
	private Integer xorderNumber;

	/**
	 * 用户密码
	 */
	@ApiModelProperty(value = "用户密码", example = "password123")
	private String xpassword;

	/**
	 * 密码过期时间
	 */
	@ApiModelProperty(value = "密码过期时间", example = "2023-01-01")
	private LocalDate xpasswordExpiredTime;

	/**
	 * 用户拼音
	 */
	@ApiModelProperty(value = "用户拼音", example = "ZhangSan")
	private String xpinyin;

	/**
	 * 用户拼音首字母
	 */
	@ApiModelProperty(value = "用户拼音首字母", example = "ZS")
	private String xpinyinInitial;

	/**
	 * 企业微信ID
	 */
	@ApiModelProperty(value = "企业微信ID", example = "qiyeweixin123456")
	private String xqiyeweixinId;

	/**
	 * 用户QQ
	 */
	@ApiModelProperty(value = "用户QQ", example = "123456789")
	private String xqq;

	/**
	 * 用户签名
	 */
	@ApiModelProperty(value = "用户签名", example = "努力工作，快乐生活")
	private String xsignature;

	/**
	 * 用户状态
	 */
	@ApiModelProperty(value = "用户状态", example = "ACTIVE")
	private String xstatus;

	/**
	 * 用户状态描述
	 */
	@ApiModelProperty(value = "用户状态描述", example = "用户状态正常")
	private String xstatusDes;

	/**
	 * 用户安全等级
	 */
	@ApiModelProperty(value = "用户安全等级", example = "3")
	private Integer xsubjectSecurityClearance;

	/**
	 * 上级用户
	 */
	@ApiModelProperty(value = "上级用户", example = "李四")
	private String xsuperior;

	/**
	 * 用户唯一标识
	 */
	@ApiModelProperty(value = "用户唯一标识", example = "unique123456")
	private String xunique;

	/**
	 * 华为WeLink ID
	 */
	@ApiModelProperty(value = "华为WeLink ID", example = "welink123456")
	private String xweLinkId;

	/**
	 * 用户微信
	 */
	@ApiModelProperty(value = "用户微信", example = "weixin123456")
	private String xweixin;

	/**
	 * 政务钉钉ID
	 */
	@ApiModelProperty(value = "政务钉钉ID", example = "zhengwu_dingding123456")
	private String xzhengwuDingdingId;

	// Getters and Setters
}