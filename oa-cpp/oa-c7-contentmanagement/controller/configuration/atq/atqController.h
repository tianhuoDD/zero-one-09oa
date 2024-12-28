#pragma once

#ifndef  _ATQCONTROLLER
#define  _ATQCONTROLLER

#include "domain/vo/BaseJsonVO.h"
#include"domain/vo/configuration/atq/configurationVo.h"
#include"domain/dto/configuration/atq/configurationDto.h"
#include "../../../service/configuration/atq/ConfigurationService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class atqController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(atqController);
public: // 定义接口
    //获取栏目分类列表接口
    // 3.1 定义查询接口描述
	ENDPOINT_INFO(queryConfiguration) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("configuration.atq.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ConfigurationPageJsonVO);
		// 定义按照文件标识查询参数
		API_DEF_ADD_QUERY_PARAMS(String, "logo", ZH_WORDS_GETTER("configuration.atq.basic.logo"), "abc", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/configuration/atq", queryConfiguration, QUERY(String, logo), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execucateconfigquery(logo));
	}
//修改栏目分类接口
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("configuration.atq.put.summary"), modifyconfiguration,StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/configuration/atq", modifyconfiguration, BODY_DTO(ConfigurationDTO::Wrapper, dto), execucatemodify(dto));
//新增栏目分类接口
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addConfiguration) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("configuration.atq.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/configuration/atq", addConfiguration, BODY_DTO(ConfigurationDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execucateadd(dto));
	}

	// 删除栏目分类接口
	ENDPOINT_INFO(removeConfiguration) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("configuration.atq.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("configuration.atq.basic.logo"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sample/{id}", removeConfiguration, PATH(String, id), execRemoveConfiguration(id));

private: // 定义接口执行函数
	//执行获取栏目分类列表
	ConfigurationPageJsonVO::Wrapper execucateconfigquery(const String& logo);
	//执行修改栏目分类接口
	StringJsonVO::Wrapper execucatemodify(const ConfigurationDTO::Wrapper& dto);
	//新增栏目分类接口
	Uint64JsonVO::Wrapper execucateadd(const ConfigurationDTO::Wrapper& dto);
	// 删除栏目分类接口
	Uint64JsonVO::Wrapper execRemoveConfiguration(const String& logo);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //