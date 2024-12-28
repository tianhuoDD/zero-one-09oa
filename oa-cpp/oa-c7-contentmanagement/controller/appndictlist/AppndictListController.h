#pragma once

#ifndef _APPNDICTLIST_CONTROLLER_
#define _APPNDICTLIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/appndictlist/AppndictListQuery.h"
#include "domain/dto/appndictlist/AppndictListDTO.h"
#include "domain/vo/appndictlist/AppndictListVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 附件列表控制器
 */
class AppndictListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AppndictListController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryAppndictList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("appndict.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AppndictListPageJsonVO);//////
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/appndictlist", queryAppndictList, QUERIES(QueryParams, queryParams)) {////???
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(appndictListQuery, AppndictListQuery, queryParams);/////????
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(appndictListQuery));
	}
private:
	AppndictListPageJsonVO::Wrapper execQueryAll(const AppndictListQuery::Wrapper& query);/////
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _APPNDICTLIST_CONTROLLER_