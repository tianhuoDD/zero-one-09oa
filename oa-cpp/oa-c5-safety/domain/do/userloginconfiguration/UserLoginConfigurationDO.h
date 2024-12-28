#pragma once

#ifndef _USERLOGINCONFIGURATION_DO_
#define _USERLOGINCONFIGURATION_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UserLoginConfigurationDO
{	//关于用户配置：主要有 编号、用户名、密码、上一次登陆时间、绑定邮箱、绑定手机号、半小时内尝试登陆次数、权限（admin、普通用户）、登陆地址IP
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 用户名
	CC_SYNTHESIZE(string, username, UserName);
	// 密码
	CC_SYNTHESIZE(string, password, Password);
	// 上一次登陆时间
	CC_SYNTHESIZE(string, lastlogintime, LastLoginTime);
	//绑定邮箱
	CC_SYNTHESIZE(string, emailaddress, EmailAddress);
	//绑定手机号
	CC_SYNTHESIZE(string, mobilephone, MobilePhone);
	//尝试登陆次数
	CC_SYNTHESIZE(uint64_t, loginattempts, LoginAttempts);
	//权限
	CC_SYNTHESIZE(string, permission, Permission);
	//登陆IP
	CC_SYNTHESIZE(string, ipaddress, IpAddress);



public:
	UserLoginConfigurationDO() {
		id = "";
		username = "";
		password = "123456789";
		lastlogintime = "";
		emailaddress = "";
		mobilephone = "";
		loginattempts = 0;
		permission = "normal";
		ipaddress = "";
	}
};

#endif // !_USERLOGINCONFIGURATION_DO_
