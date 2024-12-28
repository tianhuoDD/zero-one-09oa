#pragma once
#ifndef _PROCESS_CONTROLLER_
#define _PROCESS_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/process/ProcessTypesVO.h"
#include "domain/query/process/ProcessListQuery.h"
#include "domain/dto/process/ProcessListDTO.h"
#include "domain/vo/process/ProcessListVO.h"
#include "domain/dto/process/ProcessInfoDTO.h"
#include "domain/dto/process/ProcessSettingDTO.h"
#include "domain/vo/process/ProcessSettingVO.h"
#include "domain/vo/process/ProcessInfoVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ProcessController : public oatpp::web::server::api::ApiController {
	// 控制器访问入口
	API_ACCESS_DECLARE(ProcessController);
public: // 定义接口

	//获取接口信息
	ENDPOINT_INFO(addProcessInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.setting.get.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessInfoJsonVO);
	}
	//创建接口
	ENDPOINT(API_M_POST, "/process-app-manager/process/add", addProcessInfo, BODY_DTO(ProcessInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(AddProcess(dto, authObject->getPayload()));
	}


	ENDPOINT_INFO(modifyProcessInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.setting.put.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessInfoJsonVO);
	}
	//修改接口
	ENDPOINT(API_M_PUT, "/process-app-manager/process/modify", modifyProcessInfo, BODY_DTO(ProcessInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(ModifyProcess(dto, authObject->getPayload()));
	}


	ENDPOINT_INFO(deleteProcessInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.setting.delete.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessInfoJsonVO);
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("process-configuration.process-info.field.application"), "", true);
	}
	//删除接口
	ENDPOINT(API_M_DEL, "/process-app-manager/process/delete/{id}", deleteProcessInfo, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(DeleteProcess(id));
	}



	// 获取所有流程类型
	ENDPOINT_INFO(queryProcessTypes) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process-configuration.process-types.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessTypesListJsonVO);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/process/query-types", queryProcessTypes, QUERY(String, appId), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryProcessTypes(appId));
	}

	// 获取流程列表
	ENDPOINT_INFO(queryProcessList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process-configuration.process-list.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		String fieldPrefix = "process-configuration.process-list.field.";
		API_DEF_ADD_QUERY_PARAMS(String, "application", ZH_WORDS_GETTER(String(fieldPrefix + "application")), "application", true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER(String(fieldPrefix + "name")), "name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "alias", ZH_WORDS_GETTER(String(fieldPrefix + "alias")), "alias", false);
		API_DEF_ADD_QUERY_PARAMS(String, "category", ZH_WORDS_GETTER(String(fieldPrefix + "category")), "category", false);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/process/query-list", queryProcessList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(processListQuery, ProcessListQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryProcessList(processListQuery, authObject->getPayload()));
	}

	// 获取流程详情
	ENDPOINT_INFO(queryProcessInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process-configuration.process-info.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessInfoJsonVO);
		// 定义其他查询参数描述
		String fieldPrefix = "process-configuration.process-info.field.";
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER(String(fieldPrefix + "id")), "id", true);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/process/query-info", queryProcessInfo, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryProcessInfo(id));
	}


private: // 定义接口执行函数
	// 获取所有流程类型
	ProcessTypesListJsonVO::Wrapper execQueryProcessTypes(const String& appId);
	// 获取流程列表
	ProcessListPageJsonVO::Wrapper execQueryProcessList(const ProcessListQuery::Wrapper& query, const PayloadDTO& payload);
	// 获取流程详情
	ProcessInfoJsonVO::Wrapper execQueryProcessInfo(const String& id);


	// 执行创建
	StringJsonVO::Wrapper AddProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	StringJsonVO::Wrapper ModifyProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	StringJsonVO::Wrapper DeleteProcess(const String id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PROCESS_CONTROLLER_
