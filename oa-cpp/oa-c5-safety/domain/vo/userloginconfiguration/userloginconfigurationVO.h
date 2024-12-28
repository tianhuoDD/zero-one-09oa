#pragma once
#ifndef _USERLOGINFIGURATIONVO_H_
#define _USERLOGINFIGURATIONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/userloginconfiguration/UserLoginConfigurationDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * //用户配置信息显示对象
 */
class UserLoginConfigurationVO : public  JsonVO<UserLoginConfigurationDTO::Wrapper> {

	DTO_INIT(UserLoginConfigurationVO, JsonVO<UserLoginConfigurationDTO::Wrapper>);
	//传递的数据:数据唯一标识id，工号number，密码password
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("userloginconfiguration.field.id"), true, "abc123");
	API_DTO_FIELD(String, username, ZH_WORDS_GETTER("userloginconfiguration.field.username"), true, "user0");
	API_DTO_FIELD(String, password, ZH_WORDS_GETTER("userloginconfiguration.field.password"), true, "123456789");
	API_DTO_FIELD(String, lastlogintime, ZH_WORDS_GETTER("userloginconfiguration.field.lastlogintime"), true, "20010101/19:00:01");
	API_DTO_FIELD(String, emailaddress, ZH_WORDS_GETTER("userloginconfiguration.field.emailaddress"), true, "01star@163.com");
	API_DTO_FIELD(String, mobilephone, ZH_WORDS_GETTER("userloginconfiguration.field.mobilephone"), true, "13766668888");
	API_DTO_FIELD(UInt32, loginattempts, ZH_WORDS_GETTER("userloginconfiguration.field.loginattempts"), true, 3);
	API_DTO_FIELD(String, permission, ZH_WORDS_GETTER("userloginconfiguration.field.permission"), true, "normal");
	API_DTO_FIELD(String, ipaddress, ZH_WORDS_GETTER("userloginconfiguration.field.ipaddress"), true, "192.168.10.10");

};
//class SamplePageJsonVO : public JsonVO<SamplePageDTO::Wrapper>
//用户配置显示JsonVO，用于相应给客户端的Json对象
class UserLoginConfigurationJsonVO : public JsonVO<UserLoginConfigurationDTO::Wrapper> {
	DTO_INIT(UserLoginConfigurationJsonVO, JsonVO<UserLoginConfigurationDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // _USERLOGINFIGURATIONVO_H_