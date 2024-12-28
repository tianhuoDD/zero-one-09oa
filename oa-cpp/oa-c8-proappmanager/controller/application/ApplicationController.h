#ifndef _APPLICATIONINFOCONTROLLER_H_
#define _APPLICATIONINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/application/ApplicationDTO.h"
#include "domain/dto/application/AddApplicationDTO.h"
#include "domain/dto/application/ApplicationIdDTO.h"
#include "domain/query/application/ApplicationQuery.h"
#include "domain/vo/application/ApplicationPageVO.h"
#include "domain/vo/application/ApplicationIdVO.h"
#include "domain/vo/application/ApplicationTypesVO.h"
#include "domain/vo/application/ApplicationPropertiesVO.h"
#include "domain/dto/application/ApplicationPropertiesDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class ApplicationController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ApplicationController);

public: 
	
	//分页获取应用信息(条件+分页)
	ENDPOINT_INFO(queryApplication) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("application.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplicationPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述(有坑)
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("application.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("application.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xalias", ZH_WORDS_GETTER("application.field.alias"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xapplicationCategory", ZH_WORDS_GETTER("application.field.applicationCategory"), "", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/process-app-manager/application/summary", queryApplication, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(applicationQuery, ApplicationQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryApplication(applicationQuery, authObject->getPayload()));
	}

	//新建应用
	ENDPOINT_INFO(addApplication) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("application.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplicationIdJsonVO);
	}
	ENDPOINT(API_M_POST, "/process-app-manager/application/add", addApplication, BODY_DTO(AddApplicationDTO::Wrapper, one_application), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddApplication(one_application, authObject->getPayload()));
	}

	 //删除单条应用数据
	ENDPOINT_INFO(removeApplication) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("application.delete.summary"), ApplicationIdJsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/process-app-manager/application/delete/{id}", removeApplication, PATH(String, id), execRemoveApplication(id, authObject->getPayload()));
	
	// 获取应用类型
	ENDPOINT_INFO(queryAppTypes) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("application.app-types.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplicationTypesListJsonVO);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/application/query-types", queryAppTypes, API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAppTypes());
	}

	// 获取应用属性
	ENDPOINT_INFO(queryAppProperties) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("application.app-properties.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplicationPropertiesJsonVO);
		// 查询参数:应用ID
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("application-info.pp_e_application.field.xid"), "83496759-2037-440d-8e4f-27ede60f85bd", true);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/application/query-properties", queryAppProperties, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAppProperties(id, authObject->getPayload()));
	}

	// 修改应用属性
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("application.app-properties.put.summary"), modifyAppProperties, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/process-app-manager/application/modify-properties", modifyAppProperties, BODY_DTO(ApplicationPropertiesDTO::Wrapper, dto), execModifyAppProperties(dto, authObject->getPayload()));

private: // 定义接口执行函数
	ApplicationPageJsonVO::Wrapper execQueryApplication(const ApplicationQuery::Wrapper& query, const PayloadDTO& payload);
	ApplicationIdJsonVO::Wrapper execAddApplication(const AddApplicationDTO::Wrapper& one_application, const PayloadDTO& payload);
	ApplicationIdJsonVO::Wrapper execRemoveApplication(const String id, const PayloadDTO& payload);
	// 获取应用类型
	ApplicationTypesListJsonVO::Wrapper execQueryAppTypes();
	// 获取应用属性
	ApplicationPropertiesJsonVO::Wrapper execQueryAppProperties(const String& id, const PayloadDTO& payload);
	// 修改应用属性
	Uint64JsonVO::Wrapper execModifyAppProperties(const ApplicationPropertiesDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_APPLICATIONINFOCONTROLLER_H_