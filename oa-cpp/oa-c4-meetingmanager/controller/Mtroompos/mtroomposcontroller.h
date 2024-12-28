#pragma once

#ifndef _MTROOMPOS_CONTROLLER_
#define _MTROOMPOS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/getmtroompos/GetmtroomposQuery.h"
#include "domain/dto/getmtroompos/GetmtroomposDTO.h"
#include "domain/vo/getmtroompos/GetmtroomposVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class MtroomposController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(MtroomposController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryMtroompos) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("mtroom.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(GetmtroomposPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("mtroom.field.xname"), "111", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/meetingroom/get", queryMtroompos, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetmtroomposQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryMtroompos(userQuery, authObject->getPayload()));
	}

	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addMtroompos) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("mtroom.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/meetingroom/add", addMtroompos, BODY_DTO(AddmtroomposDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddMtroompos(dto));
	}

private:
	// 3.3 演示分页查询数据
	GetmtroomposPageJsonVO::Wrapper execQueryMtroompos(const GetmtroomposQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddMtroompos(const AddmtroomposDTO::Wrapper& dto);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MTROOMPOS_CONTROLLER_