#pragma once

#ifndef _SortByPinYin_Controller_
#define _SortByPinYin_Controller_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Sort/SortByPinYinQuery.h"
#include "domain/dto/Sort/SortByPinYinDTO.h"
#include "domain/vo/Sort/SortByPinYinVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class SortByPinYinController : public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SortByPinYinController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(querySortByPinYin) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sort.sort_res"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SortByPinYinPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c1-org/querySortByPinYin", querySortByPinYin, QUERIES(QueryParams, Params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, SortByPinYinQuery, Params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySortByPinYin(query, authObject->getPayload()));
	}


private:
	SortByPinYinPageJsonVO::Wrapper execQuerySortByPinYin(const SortByPinYinQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_