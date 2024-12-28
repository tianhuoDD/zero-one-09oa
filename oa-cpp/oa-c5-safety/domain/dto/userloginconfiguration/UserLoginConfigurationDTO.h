#pragma once
#ifndef _UserLoginConfigurationDTO_H_
#define _UserLoginConfigurationDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class UserLoginConfigurationDTO : public oatpp::DTO
{
	DTO_INIT(UserLoginConfigurationDTO, DTO);


	////关于用户配置：主要有 编号(唯一标识)、用户名、密码、上一次登陆时间、绑定邮箱、绑定手机号、半小时内尝试登陆次数、权限（admin、普通用户）、登陆地址IP

	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("userloginconfiguration.field.id"), true, "abc123");
	API_DTO_FIELD(String, username, ZH_WORDS_GETTER("userloginconfiguration.field.username"), true, "user0");
	API_DTO_FIELD(String, password, ZH_WORDS_GETTER("userloginconfiguration.field.password"), true, "123456789");
	API_DTO_FIELD(String, lastlogintime, ZH_WORDS_GETTER("userloginconfiguration.field.lastlogintime"), true, "2001.1.1-19:00:01");
	API_DTO_FIELD(String, emailaddress, ZH_WORDS_GETTER("userloginconfiguration.field.emailaddress"), true, "01star@163.com");
	API_DTO_FIELD(String, mobilephone, ZH_WORDS_GETTER("userloginconfiguration.field.mobilephone"), true, "13766668888");
	API_DTO_FIELD(UInt32, loginattempts, ZH_WORDS_GETTER("userloginconfiguration.field.loginattempts"), true, 3);
	API_DTO_FIELD(String, permission, ZH_WORDS_GETTER("userloginconfiguration.field.permission"), true, "normal");
	API_DTO_FIELD(String, ipaddress, ZH_WORDS_GETTER("userloginconfiguration.field.ipaddress"), true, "192.168.10.10");

};


#include OATPP_CODEGEN_END(DTO)
#endif // _UserLoginConfigurationDTO_H_