#pragma once

#ifndef _FORMTEMPLATECATEGORYCONTROLLER_H_
#define _FORMTEMPLATECATEGORYCONTROLLER_H_

#include "oatpp-swagger/Types.hpp"
#include "domain/dto/FormTemplateCategoryDTO.h"
#include "domain/vo/FormTemplateCategoryVO.h"
#include "domain/dto/PageDTO.h"
#include "domain/query/FormTemplateQuery.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController)
class FormTemplateCategoryController :public oatpp::web::server::api::ApiController
{
public:// 定义接口
	// 定义控制器访问入口
	API_ACCESS_DECLARE(FormTemplateCategoryController);//宏定义 为FormController 类添加构造函数和 createShared 方法

	//表单类型及数量
	//获取表单类型及数量接口描述
	ENDPOINT_INFO(queryFormCategory) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("formTemplate.category.get.summary"));
		//// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		//定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FormTemplateCategoryJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xapplication", ZH_WORDS_GETTER("formTemplate.field.xapplication"), "111", true);//所属应用
	}
	// 定义获取表单列表接口处理
	ENDPOINT(API_M_GET, "/base/query-category", queryFormCategory, QUERY(String, xid)) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryFormCategory(xid));
	}
private: // 定义接口执行函数
	// 执行获取表单类型及数量函数
	FormTemplateCategoryJsonVO::Wrapper execQueryFormCategory(const String& xid);

};


#include OATPP_CODEGEN_END(ApiController)

#endif