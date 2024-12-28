#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: W.C.K.D
 @Date: 2024/10/22 21:13:13

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
#ifndef _DELETECONTROLLER_H
#define _DELETECONTROLLER_H

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/GetLists/GetListsVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GetListsController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GetListsController);
public: // 定义接口

	// 1. 获取组织名称接口
	ENDPOINT_INFO(getLists) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("get lists"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetListsJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("status"), "null", true);
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("xid"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "params", ZH_WORDS_GETTER("params"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xalias", ZH_WORDS_GETTER("xalias"), "1", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/get_lists", getLists, QUERY(String, xid)) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execcuteQueryGetListsInfo(xid));
	}

	//	---------------------------------------------------------------------

		//	2. 获取组织成员名称接口
		//ENDPOINT_INFO(queryOrganizationMember) {
		//	// 定义接口标题
		//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.query-organization-member.summary"));
		//	// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//	//API_DEF_ADD_AUTH();
		//	// 定义响应参数格式
		//	API_DEF_ADD_RSP_JSON_WRAPPER(OrganizationMemberJsonVO);
		//	// 定义其他查询参数描述
		//	API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("organization.query-organization-member.name"), "li ming", true);
		//	//API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("organization.query-organization.id"), "1", false);
		//}
		//// 3.2 定义查询接口处理
		//ENDPOINT(API_M_DEL, "/delete_attatch", queryOrganizationMember, QUERY(String,name)) {
		//	// 呼叫执行函数响应结果
		//	API_HANDLER_RESP_VO(execcuteQueryOrganizationMember(name));
		//}
		//获取组织成员名称接口

private: // 定义接口执行函数
	GetListsJsonVO::Wrapper execcuteQueryGetListsInfo(const String& xid);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGANIZATIONCONTROLLER_H_