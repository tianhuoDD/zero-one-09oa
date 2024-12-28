#pragma once
#ifndef _USERLOGINCONFIGURATIONCONTROLLER_H_
#define _USERLOGINCONFIGURATIONCONTROLLER_H_

#include"domain/vo/BaseJsonVO.h"
#include"domain/vo/userloginconfiguration/userloginconfigurationVO.h"
#include "domain/dto/userloginconfiguration/UserLoginConfigurationDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserLoginConfigurationController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(UserLoginConfigurationController);

public:

	// 获取登陆配置 接口
	ENDPOINT_INFO(queryUserLoginConfiguration) {
		// 获取登陆配置
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("userloginconfiguration.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UserLoginConfigurationJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "username", ZH_WORDS_GETTER("userloginconfiguration.field.username"), "abc123", true);
	}
	//实际传递应该是用户的用户名
	ENDPOINT(API_M_GET, "/safety/query-userloginconfiguration", queryUserLoginConfiguration, QUERY(String, username), API_HANDLER_AUTH_PARAME) {
		
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryUserLoginConfiguration(username));
	}




	// 保存登陆配置 接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("userloginconfiguration.put.summary"), modifyUserLoginConfiguration, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/safety/put-userloginconfiguration", modifyUserLoginConfiguration, BODY_DTO(UserLoginConfigurationDTO::Wrapper, dto), executeModifyUserLoginConfiguration(dto));

private:
	//执行获取用户配置
	//参数：String 用户名
	//返回值:UserLoginConfigurationJsonVO
	UserLoginConfigurationJsonVO::Wrapper executeQueryUserLoginConfiguration(const String& username);
	
	//执行保存用户配置
	//参数：DTO
	//返回值:StringJsonVO  成功或失败or int64
	StringJsonVO::Wrapper executeModifyUserLoginConfiguration(const UserLoginConfigurationDTO::Wrapper& dto);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif
