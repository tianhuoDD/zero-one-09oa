/*
 Copyright Zero One Star. All rights reserved.

 @Author: Detachment
 @Date: 2024/10/19 17:07:08

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
#ifndef _SYSTEM_INFORMATION_CONTROLLER_H_
#define _SYSTEM_INFORMATION_CONTROLLER_H_

//#include "domain/BaseJsonVO.h"
#include "domain/vo/BaseJsonVO.h"
#include"../service/SystemInformationService.h"
#include"../domain/dto/SystemInformationDTO.h"
#include"../domain/vo/SystemInformationVO.h"
#include"../domain/query/SystemInformationQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class SystemInformationController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(SystemInformationController);
public: // 定义接口
	//查询未读消息ENDPOINT
	//参数描述
	ENDPOINT_INFO(modify_message_status) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Information.get.modifyMessageStatus"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SystemInformationJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("Information.field.name"), "li ming", false);
	}
	//修改信息状态ENDPOINT
	ENDPOINT(API_M_GET, "/base/SysInformation", modify_message_status,QUERIES(QueryParams,queryParams))
	{
		//
		API_HANDLER_QUERY_PARAM(messageQuery, SystemInformationQuery, queryParams);
		//std::cout << std::string(messageQuery->name);
		API_HANDLER_RESP_VO(execSystemInformation(messageQuery));
	}


private: // 定义接口执行函数
	SystemInformationJsonVO::Wrapper execSystemInformation(const SystemInformationQuery::Wrapper&);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_SYSTEM_INFORMATION_CONTROLLER_H_