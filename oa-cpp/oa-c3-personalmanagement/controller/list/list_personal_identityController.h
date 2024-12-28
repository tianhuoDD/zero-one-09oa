#pragma once

#ifndef _LIST_PERSONAL_IDENTITYCONTROLLER_
#define _LIST_PERSONAL_IDENTITYCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/query/list/list_personal_identityQuery.h"
#include "../../domain/vo/list/list_personal_identityJsonVO.h"
#include "../../domain/dto/list/list_personal_identityDTO.h"




#include OATPP_CODEGEN_BEGIN(ApiController)

class list_personal_identityController : public oatpp::web::server::api::ApiController
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(list_personal_identityController);
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(query_list_personal_identity) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式 
		API_DEF_ADD_RSP_JSON_WRAPPER(listPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("sample.field.xid"), "221c0b2a-09d5-4820-8ac8-33f5747881bf", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("sample.field.xname"), "jack", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "personal-management/list-personal-identity", query_list_personal_identity, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		//定义了授权参数 
		//API_HANDLER_AUTH_PARAME()
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, list_personal_identityQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerylist_personal_identity(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	listPageJsonVO::Wrapper execQuerylist_personal_identity(const list_personal_identityQuery::Wrapper& query, const PayloadDTO& payload);
};


#endif // !_LIST_PERSONAL_IDENTITYCONTROLLER_
