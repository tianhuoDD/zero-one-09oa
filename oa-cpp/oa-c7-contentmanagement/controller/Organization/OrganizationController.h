#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Rif
 @Date: 2024/10/19 11:58:35

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
#ifndef _ORGANIZATIONCONTROLLER_H_
#define _ORGANIZATIONCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/Organization/OrganizationNameVO.h"
#include "domain/vo/Organization/OrganizationMemberVO.h"
#include "domain/query/OrgQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class OrganizationController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(OrganizationController);
public: // 定义接口

	// 1. 获取组织名称接口
	ENDPOINT_INFO(queryOrganizationInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.query-organization.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(OrganizationNameJsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(OrganizationNamePageJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("organization.query-organization.name"), "li ming", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("organization.query-organization.name"), "01 School_Shanghai", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("organization.query-organization.id"), "1", false);
	}
	// 3.2 定义查询接口处理
	//ENDPOINT(API_M_GET, "/organization/query-organization-name", queryOrganizationInfo, QUERY(String,xname)) {
	//ENDPOINT(API_M_GET, "/organization/query-organization-name", queryOrganizationInfo, QUERY(String,xname)) {
	ENDPOINT(API_M_GET, "/organization/query-organization-name", queryOrganizationInfo, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(orgQuery, OrgQuery, queryParams);
		// 呼叫执行函数响应结果
		//API_HANDLER_RESP_VO(execcuteQueryOrganizationInfo(xname));
		API_HANDLER_RESP_VO(execcuteQueryOrganizationInfo(orgQuery));
	}

	//	---------------------------------------------------------------------

		//	2. 获取组织成员名称接口
	ENDPOINT_INFO(queryOrganizationMember) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("organization.query-organization-member.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//API_DEF_ADD_RSP_JSON_WRAPPER(OrganizationMemberJsonVO);
		API_DEF_ADD_RSP_JSON_WRAPPER(OrganizationMemberPageJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("organization.query-organization-member.name"), "li ming", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("organization.query-organization-member.name"), "R", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("organization.query-organization.id"), "1", false);
	}
	// 3.2 定义查询接口处理
	//ENDPOINT(API_M_GET, "/organization/query-organization-member-name", queryOrganizationMember, QUERY(String,xname)) {
	ENDPOINT(API_M_GET, "/organization/query-organization-member-name", queryOrganizationMember, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(orgQuery, OrgQuery, queryParams);
		// 呼叫执行函数响应结果
		//API_HANDLER_RESP_VO(execcuteQueryOrganizationMember(xname));
		API_HANDLER_RESP_VO(execcuteQueryOrganizationMember(orgQuery));
	}
	//获取组织成员名称接口

private: // 定义接口执行函数
	//OrganizationNameJsonVO::Wrapper execcuteQueryOrganizationInfo(const String& xname);
	//OrganizationMemberJsonVO::Wrapper execcuteQueryOrganizationMember(const String& xname);
	OrganizationNamePageJsonVO::Wrapper execcuteQueryOrganizationInfo(const OrgQuery::Wrapper& xname);
	OrganizationMemberPageJsonVO::Wrapper execcuteQueryOrganizationMember(const OrgQuery::Wrapper& xname);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_ORGANIZATIONCONTROLLER_H_