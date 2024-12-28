#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/10/20 19:43:59

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _RESETPASSWDCONTROLLER_H_
#define _RESETPASSWDCONTROLLER_H_

#include "stdafx.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "Macros.h"
#include "domain/query/ResetPasswd/ResetPasswdQuery.h"
#include "domain/dto/ResetPasswd/ResetPasswdDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ResetPasswdController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ResetPasswdController)
public: // 定义接口

	// 根据前端传递过来的密文设置密码
	ENDPOINT_INFO(resetPasswd) {
		// 接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("personal-management.reset-passwd.title2"));

		// 定义授权参数
		API_DEF_ADD_AUTH();

		// 响应格式
		API_DEF_ADD_RSP_JSON(Int32JsonVO::Wrapper);

		// 定义参数
		API_DEF_ADD_QUERY_PARAMS(String, "id",
			ZH_WORDS_GETTER("personal-management.reset-passwd.field.id"),
			"1", true);

		API_DEF_ADD_QUERY_PARAMS(String, "passwd",
			ZH_WORDS_GETTER("personal-management.reset-passwd.field.passwd"),
			"xxxx", true);
	}

	ENDPOINT(API_M_PUT, "/personal-management/reset-passwd",
		resetPasswd, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为ResetPasswdQuery
		API_HANDLER_QUERY_PARAM(query, ResetPasswdQuery, queryParams);
	
		// 呼叫执行函数
		API_HANDLER_RESP_VO(execResetPasswd(query, authObject->getPayload()));
	}

private: // 定义接口执行函数
	Int32JsonVO::Wrapper execResetPasswd(const ResetPasswdQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_RESETPASSWDCONTROLLER_H_
