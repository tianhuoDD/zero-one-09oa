#pragma once
#ifndef _DATACONFIGLISTCONTROLLER_H_
#define _DATACONFIGLISTCONTROLLER_H_
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/data/DataDetailVO.h"
#include "domain/vo/data/DataListVO.h"
#include "domain/dto/data/DataOperatorDTO.h"
#include "domain/vo/data/DataOperatorVO.h"
#include "domain/query/data/DataListQuery.h"
#include "domain/query/data/DataDetailQuery.h"
#include "service/data/DataOpService.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class DataController : public oatpp::web::server::api::ApiController {
	// 添加访问定义
	API_ACCESS_DECLARE(DataController);

public://定义接口

	//新增数据接口描述
	ENDPOINT_INFO(AddDataConfiguration) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("oprator.add.summray"));
		//设置权限访问
		API_DEF_ADD_AUTH();
		//定义响应参数格式
		//插入数据响应一个字符串吧
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}

	ENDPOINT(API_M_POST, "/process-app-manager/data/add", AddDataConfiguration, BODY_DTO(AddDataDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddDataConfiguration(dto));
	}


	ENDPOINT_INFO(ModifyDataConfiguration) {
		//修改数据接口描述
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("oprator.modify.summray"));
		//设置权限访问
		API_DEF_ADD_AUTH();
		//定义响应参数格式 
		//数据响应一个字符串
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	
	ENDPOINT(API_M_PUT, "/process-app-manager/data/modify", ModifyDataConfiguration, BODY_DTO(DataOperatorDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execModifyDataConfiguration(dto));
	}

	ENDPOINT_INFO(DeleteDataConfiguration) {
		//删除数据接口描述
		//此处根据唯一标识删除
		//删除接口描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("oprator.delete.summray"), StringJsonVO::Wrapper);
		//设置权限审查
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("dataconfiguration.datamessage.id"), "", true);
	}
	

	ENDPOINT(API_M_DEL, "/process-app-manager/data/remove/{id}", DeleteDataConfiguration, PATH(String, id), API_HANDLER_AUTH_PARAME)
	{
		//String itemid = dto->itemid;
		API_HANDLER_RESP_VO(execDeleteDataConfiguration(id));
	}


	//获取数据配置列表接口
	//查询接口描述
	ENDPOINT_INFO(queryDataConfigList) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("config.list.get.summary"), DataListPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "appid", ZH_WORDS_GETTER("config.list.get.summary"), "", true);
	}
	// 定义查询接口处理
	ENDPOINT(API_M_GET, "/process-app-manager/data/query-list", queryDataConfigList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, DataListQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryDataConfigList(query, authObject->getPayload()));
	}

	// 获取数据配置详情接口
	// 4.1 定义查询接口描述
	ENDPOINT_INFO(queryDataConfigDetail) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("config.detail.get.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(DataDetailJsonVO);
		//API_DEF_ADD_QUERY_PARAMS(String, "appid", ZH_WORDS_GETTER("config.detail.field.appid"), "13d212", true);
		API_DEF_ADD_QUERY_PARAMS(String, "dataid", ZH_WORDS_GETTER("config.detail.field.dataid"), "83496759-2037-440d-8e4f-27ede60f85bd", true);
	}
	// 4.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/process-app-manager/data/query-detail", queryDataConfigDetail, QUERY(String, dataid), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryDataConfigDetail(dataid, authObject->getPayload()));
	}


private://定义接口执行函数

	//新增配置文档的执行函数 需要传入参数 一个dto
	StringJsonVO::Wrapper execAddDataConfiguration(const AddDataDTO::Wrapper& dto);

	//修改配置文档的执行函数 需要传入参数 一个dto
	StringJsonVO::Wrapper execModifyDataConfiguration(const DataOperatorDTO::Wrapper& dto);

	//删除配置文档的执行函数 需要传入参数 一个String
	StringJsonVO::Wrapper execDeleteDataConfiguration(const String& id);

	//执行获取数据配置列表
	DataListPageJsonVO::Wrapper execQueryDataConfigList(const DataListQuery::Wrapper& query, const PayloadDTO& payload);

	// 执行获取数据配置详情
	DataDetailJsonVO::Wrapper execQueryDataConfigDetail(const std::string& dataid, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _DATACONFIGLISTCONTROLLER_H_
