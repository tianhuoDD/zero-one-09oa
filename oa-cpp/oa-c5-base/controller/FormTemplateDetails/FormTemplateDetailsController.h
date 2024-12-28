#pragma once

#ifndef _FORMTEMPLATEDETAILSCONTROLLER_H_
#define _FORMTEMPLATEDETAILSCONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "domain/dto/FormTemplateDetailsDTO.h"
#include "domain/vo/FormTemplateDetailsVO.h"
#include "domain/dto/PageDTO.h"
#include "domain/query/FormTemplateQuery.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)

class FormTemplateDetailsController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(FormTemplateDetailsController);

public:
	//表单详情
	//获取表单详情接口描述
	ENDPOINT_INFO(queryFormInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("formTemplate.get.summary"));
		//// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FormTemplateDetailsJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("form.field.xid"), "1234", true);
	}
	// 定义获取表单详情接口处理
	ENDPOINT(API_M_GET, "/base/query-info", queryFormInfo, QUERY(String, xid)) //API_HANDLER_AUTH_PARAME
	{
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFormInfo(xid));
	}

private:
	// 执行获取表单详情函数
	FormTemplateDetailsJsonVO::Wrapper execQueryFormInfo(const String& xid);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _FORMTEMPLATEDETAILSCONTROLLER_H_
