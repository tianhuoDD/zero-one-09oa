 #pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/gets-person-lists/PersonlistVO.h"
#include "domain/query/gets-person-lists/Personlistquery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class PersonlistController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PersonlistController);
	// 3 定义接口
public:
	// 获取个人信息接口
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryPersonlist) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("person.setting.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PersonlistPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义状态的查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xstatus", ZH_WORDS_GETTER("person.setting.get.field.xstatus"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "input", ZH_WORDS_GETTER("person.setting.get.field.input"), "", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "personal-management/gets-person-lists", queryPersonlist, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, PersonlistQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryPersonList(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	PersonlistPageJsonVO::Wrapper executeQueryPersonList(const PersonlistQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_