#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _ORG_STRUCT_CONTROLLER_
#define _ORG_STRUCT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"
#include "../../domain/vo/OrgStructVO/OrgStructVO.h"
#include "../../domain/query/OrgStructQuery/OrgStructQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/*	名称: 组织架构控制器 
 * 
 *  功能: 1. 获取组织成员(分页)
 *		 2. 获取人员名称列表
 *		 3. 添加组织
 *		 4. 删除组织
 *		 5. 修改组织成员
 *		 6. 查询组织成员
 */
class OrgStructController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(OrgStructController);

public:
	//接口定义------------------------------------------------------------------------------
	//查询组织所有成员信息
	ENDPOINT_INFO(queryOrgStruct) {
		// general
		info->summary = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgMembers.orgmembers");
		info->addResponse<OrgStructPageJsonVO::Wrapper>(Status::CODE_200, "application/json");

		// params specific
		info->queryParams.add<UInt64>("pageIndex").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgMembers.pageIndex");
		info->queryParams.add<UInt64>("pageSize").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgMembers.pageSize");
		//传入查询的组织
		info->queryParams.add<String>("xunique").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgMembers.xunique");

	}

	//响应接口------------------------------------------------------------------------------
	//响应组织所有成员信息
	ENDPOINT("GET", "/c1-org/orgmanagment/queryOrgStruct", queryOrgStruct, QUERIES(QueryParams, params)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(condtion, OrgStructPageQuery, params);
		//响应结果
		return createDtoResponse(Status::CODE_200, executeQueryOrgStruct(condtion));
	};

	//定义文档描述获取人员名称列表
	//接口定义------------------------------------------------------------------------------
	//获取人员名称列表
	ENDPOINT_INFO(queryOrgStaff) {
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();

		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("queryOrgStaff.orgmembers.members"));
		//API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Attrib_add.title.add"));

		info->addResponse<OrgStructPageJsonVO::Wrapper>(Status::CODE_200, "application/json");

		// 定义接口
		info->queryParams.add<UInt64>("pageIndex").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.pageIndex");

		info->queryParams.add<UInt64>("pageSize").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.pageSize");
		//按照拼音查询(字母缩写)
		info->queryParams.add<String>("Pinyin").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.Pinyin");

		info->queryParams.add<String>("xdistinguishedName").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.xdistinguishedName");

		info->queryParams.add<String>("xstatus").description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "queryOrgStaff.orgmembers.xstatus");
	}

	//接口响应-----------------------------------------------------------------------------------------------------------
	//响应人员列表
	ENDPOINT("POST", "/c1-org/orgmanagment/Staff", queryOrgStaff, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(condtion, OrgStaffPageQuery, params);
		//响应结果
		return createDtoResponse(Status::CODE_200, executeQueryOrgStaff(condtion));
	};

private:
	//queryOrgStruct访问后执行函数
	OrgStructPageJsonVO::Wrapper executeQueryOrgStruct(const OrgStructPageQuery::Wrapper& condtion);
	//queryPeople访问后执行函数
	OrgStaffPageJsonVO::Wrapper executeQueryOrgStaff(const OrgStaffPageQuery::Wrapper& condtion);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_ 