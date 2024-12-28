#pragma once

#ifndef _USERPASSWORD_CONTROLLER_H_
#define _USERPASSWORD_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/UserPassword/UserPasswordDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserPasswordController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(UserPasswordController);

public:
	// 保存用户密码设置
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sys.setting.put.user_password"), saveUserPasswordSettings, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/user_password/settings/save", saveUserPasswordSettings, BODY_DTO(UserPasswordDTO::Wrapper, dto), executeSaveUserPasswordSettings(dto, authObject->getPayload()));

private:
	// 执行保存用户密码设置
	StringJsonVO::Wrapper executeSaveUserPasswordSettings(const UserPasswordDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_USERPASSWORD_CONTROLLER_H_
