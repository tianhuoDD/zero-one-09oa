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
#ifndef _MettingCreate_CONTROLLER_
#define _MettingCreate_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/metting/mettingcreate/MettingCreateQuery.h"
#include "domain/dto/metting/mettingcreate/MettingCreateDTO.h"
#include "domain/vo/metting/mettingCreate/MettingCreateVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class MettingCreateController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(MettingCreateController);
	// 定义接口
public:
	// 定义会议室查询接口描述
	ENDPOINT_INFO(queryroom) {
		// 定义接口标题
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("metting.cquery.room"), StringJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}
	// 定义查询接口处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/metting/mettingcreate/room", queryroom, MettingRoomQuery, execQueryRoom());
	//
	//ENDPOINT(API_M_GET, "/metting/mettingcreate", queryroom, API_HANDLER_AUTH_PARAME) {API_HANDLER_RESP_VO(execQueryRoom());}

	// hoster query description
	ENDPOINT_INFO(queryhoster) {
		// 定义接口标题
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("metting.cquery.hoster"), MettingHostPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("metting.cqury.hoster"), "li ming", true);
	}
	// 定义查询接口处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/metting/mettingcreate/host", queryhoster, MettingHosterQuery, execQueryHoster(query, authObject->getPayload()));
	// 
	//ENDPOINT(API_M_GET, "/metting/mettingcreate", queryhoster, QUERY(String, name), API_HANDLER_AUTH_PARAME){//呼叫执行函数响应结果API_HANDLER_RESP_VO(execQueryHoster(name));}

	//department query description
	ENDPOINT_INFO(querydepart) {
		// 定义接口标题
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("metting.cquery.department"), MettingDepartPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "depart", ZH_WORDS_GETTER("metting.cqury.depart"), "bu men", true);
	}
	//department query
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/metting/mettingcreate/depart", querydepart, MettingDepartQuery, execQueryDepart(query, authObject->getPayload()));
	// 
	//ENDPOINT(API_M_GET, "/metting/mettingcreate", querydepart, QUERY(String, depart), API_HANDLER_AUTH_PARAME) {// 呼叫执行函数响应结果API_HANDLER_RESP_VO(execQueryDepart(depart));}

	//member decription
	ENDPOINT_INFO(querymember) {
		// 定义接口标题
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("metting.cquery.member"), MettingMemebrPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "identify", ZH_WORDS_GETTER("metting.cqury.identify"), "ge ren/shen fen/zu zhi/qun ti", true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("metting.cqury.name"), "zhang san", true);
	}
	//member query
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/metting/mettingcreate/member", querymember, MettingMemberQuery, execQueryDepart(query, authObject->getPayload()));
	// 
	//ENDPOINT(API_M_GET, "/metting/mettingcreate", querymember, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		//API_HANDLER_QUERY_PARAM(userQuery, MettingMemberQuery, queryParams);
		// 呼叫执行函数响应结果API_HANDLER_RESP_VO(execQueryMember(userQuery));}


	// 3.1 定义新增接口描述
	ENDPOINT_INFO(mettingcreate) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("metting.cquery.cmetting"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MettingCreateJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/metting/mettingcreate", mettingcreate, BODY_DTO(MettingCreateDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execMettingCreate(dto));
	}

	
private:
	Uint64JsonVO::Wrapper execMettingCreate(const MettingCreateDTO::Wrapper& dto);

	MettingRoomPageJsonVO::Wrapper execQueryRoom();

	MettingHostPageJsonVO::Wrapper execQueryHoster(const PageQuery::Wrapper& userquery, const PayloadDTO& payload);

	MettingDepartPageJsonVO::Wrapper execQueryDepart(const PageQuery::Wrapper& userquery, const PayloadDTO& payload);

	MettingMemebrPageJsonVO::Wrapper execQueryMember(const PageQuery::Wrapper& userquery, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MettingCreate_CONTROLLER_