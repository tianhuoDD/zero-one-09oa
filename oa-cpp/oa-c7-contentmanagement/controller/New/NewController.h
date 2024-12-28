#pragma once
#pragma once
#pragma once
#ifndef  _NewController_H_
#define  _NewController_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/New/NewVO.h"
#include "domain/dto/New/NewDTO.h"
#include "domain/dto/New/PutDTO.h"
#include "domain/vo/New/PutVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class NewController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(NewController);
public:
	//获取栏目属性接口
	ENDPOINT_INFO(queryNew) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("newdto.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(NewJsonVO);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("newdto.put.id"), 1, true);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/attribute", queryNew, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryNew(id));
	}
	//新建栏目接口
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("newdto.put.summary"), modifyNew, PutJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/New", modifyNew, BODY_DTO(PutDTO::Wrapper, dto), executeModifyNew(dto));

private:
	NewJsonVO::Wrapper executeQueryNew(const String& id);
	//执行修改个人信息
	PutJsonVO::Wrapper executeModifyNew(const PutDTO::Wrapper& dto);
};

#endif // ! _NewController_H_