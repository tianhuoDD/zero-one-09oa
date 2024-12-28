#pragma once
#ifndef _ORGUNIT_CONTROLLER_
#define _ORGUNIT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/OrgUnitQuery.h"
#include "domain/dto/OrgUnitDTO.h"
#include "domain/vo/OrgUnitVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class OrgUnitController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(OrgUnitController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryOrgInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("org.unit.query"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OrgUnitJsonVO);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "unit_xname", ZH_WORDS_GETTER("org.unit.unit_name"), "01daxue", false);
		
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/c1-org/orgmanagment/queryOrgInfo", queryOrgInfo, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, OrgUnitQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySample(userQuery, authObject->getPayload()));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("org.unit.update"), modifyOrgInfo, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c1-org/orgmanagment/modifyOrgInfo", modifyOrgInfo, BODY_DTO(OrgUnitDTO::Wrapper, dto), execModifySample(dto));

	// 3.3 演示分页查询数据
	OrgUnitJsonVO::Wrapper execQuerySample(const OrgUnitQuery::Wrapper& query, const PayloadDTO& payload);
	
	// 3.3 演示修改数据
	StringJsonVO::Wrapper execModifySample(const OrgUnitDTO::Wrapper& dto);
};






// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ORGUNIT_CONTROLLER_
