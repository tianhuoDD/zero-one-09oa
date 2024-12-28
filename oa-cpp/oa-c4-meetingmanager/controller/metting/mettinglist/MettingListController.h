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
#ifndef _MettingList_CONTROLLER_
#define _MettingList_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/metting/mettingList/MettingListQuery.h"
#include "domain/dto/metting/mettinglist/MettingListDTO.h"
#include "domain/vo/metting/mettingList/MettingListVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class MettingListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{

	API_ACCESS_DECLARE(MettingListController);

public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(querymetting) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("des.metting.title1"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MettingListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("des.metting.name"), "123", true);
		API_DEF_ADD_QUERY_PARAMS(Boolean, "mtinvite", ZH_WORDS_GETTER("query.metting.mettingList.invite"), "true/false", true);
		API_DEF_ADD_QUERY_PARAMS(Boolean, "reject", ZH_WORDS_GETTER("query.metting.mettingList.reject"), "true/false", true);
		API_DEF_ADD_QUERY_PARAMS(UInt64, "time", ZH_WORDS_GETTER("query.metting.mettingList.time"), 1, true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/metting/mettinglist", querymetting, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, MettingListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execMettingListQuery(userQuery));
	}

private:
	// 3.3 演示分页查询数据
	MettingListPageJsonVO::Wrapper execMettingListQuery(const MettingListQuery::Wrapper& usertquery);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MettingList_CONTROLLER_