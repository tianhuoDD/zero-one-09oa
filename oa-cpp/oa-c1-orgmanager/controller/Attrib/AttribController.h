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
#ifndef _ATTRIB_CONTROLLER_
#define _ATTRIB_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Attrib/AttribQuery.h"
#include "domain/dto/Attrib/AttribDTO.h"
#include "domain/vo/Attrib/AttribVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class AttribController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AttribController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	/*ENDPOINT_INFO(queryAttrib) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Attrib.query-all.title"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AttribPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("Attrib.query-all.name"), " ", false);
		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("Attrib.query-all.id"), 1, false);
	}//删掉了mediator的查询功能
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/Attrib", queryAttrib, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, AttribQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAttrib(userQuery));//, authObject->getPayload()
	}
	*/
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addAttrib) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Attrib.add-all.title"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/c1-org/Attrib", addAttrib, BODY_DTO(AttribDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddAttrib(dto));
	}

	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Attrib.modify-all.title"), modifyAttrib, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c1-org/Attrib", modifyAttrib, BODY_DTO(AttribDTO::Wrapper, dto), execModifyAttrib(dto));

	//// 3.1 定义删除接口描述
	//ENDPOINT_INFO(removeAttrib) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("Attrib.delete-all.title"), Uint64JsonVO::Wrapper);
	//	// 定义其他路径参数说明
	//	API_DEF_ADD_PATH_PARAMS(String, "name", ZH_WORDS_GETTER("Attrib.delete-all.name"), "", true);
	//	API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("Attrib.delete-all.id"), 1, true);
	//	API_DEF_ADD_PATH_PARAMS(String, "value", ZH_WORDS_GETTER("Attrib.delete-all.attrib"), "", true);
	//}
	//// 3.2 定义删除接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/Attrib", removeAttrib, PATH(UInt64, id), execRemoveAttrib(id));

	//// 3.1 定义测试声明式服务调用的接口1描述
	//ENDPOINT_INFO(queryOne) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sample.query-one.summary"), SampleJsonVO::Wrapper);
	//	// 定义其他路径参数说明
	//	API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);
	//}
	//// 3.2 定义测试声明式服务调用的接口1处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/sample/query-one", queryOne, QUERY(UInt64, id), execQueryOne(id, authObject->getPayload()));

	//// 3.1 定义测试声明式服务调用的接口2描述
	//ENDPOINT_INFO(queryAll) {
	//	// 定义标题和返回类型以及授权支持
	//	API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sample.query-all.summary"), SamplePageJsonVO::Wrapper);
	//	// 定义分页查询参数描述
	//	API_DEF_ADD_PAGE_PARAMS();
	//	// 定义其他查询参数描述
	//	API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
	//}
	//// 3.2 定义测试声明式服务调用的接口1处理
	//API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/sample/query-all", queryAll, SampleQuery, execQueryAll(query, authObject->getPayload()));
private:
	// 3.3 演示分页查询数据
	AttribPageJsonVO::Wrapper execQueryAttrib(const AttribQuery::Wrapper& query);//, const PayloadDTO& payload
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddAttrib(const AttribDTO::Wrapper& dto);
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyAttrib(const AttribDTO::Wrapper& dto);
	//// 3.3 演示删除数据
	//Uint64JsonVO::Wrapper execRemoveAttrib(const UInt64& id);
	//// 3.3 测试声明式服务调用1
	//AttribJsonVO::Wrapper execQueryOne(const UInt64& id, const PayloadDTO& payload);
	//// 3.3 测试声明式服务调用2
	//AttribPageJsonVO::Wrapper execQueryAll(const AttribQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_