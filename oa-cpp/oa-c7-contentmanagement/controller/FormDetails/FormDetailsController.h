#pragma once
#pragma once
/*
	栏目表单接口
	author：niuniu
*/
#ifndef _FORMDETAILSCONTROLLER_H_
#define _FORMDETAILSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/FormDetails/FormDetailsDTO.h"
#include "domain/vo/FormDetails/FormDetailsVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class FormDetailsController : public oatpp::web::server::api::ApiController
{

	API_ACCESS_DECLARE(FormDetailsController);
public:
	//获取栏目属性接口
	ENDPOINT_INFO(queryFormDetails) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.list.summary2"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FormDetailsJsonVO);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("form.list.xid"), "1", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/FormDetails", queryFormDetails, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryFormDetails(id));
	}

	ENDPOINT_INFO(addForm) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.list.summary3"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_POST, "/FormDetails", addForm, BODY_DTO(FormDetailsDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddForm(dto));
	}
private:
	StringJsonVO::Wrapper executeQueryFormDetails(const String& id);
	//执行修改个人信息
	//StringJsonVO::Wrapper executeModifyNew(const NewDTO::Wrapper& dto);
	StringJsonVO::Wrapper execAddForm(const FormDetailsDTO::Wrapper& dto);
};


#endif //!_FORMCONTROLLER_H_
