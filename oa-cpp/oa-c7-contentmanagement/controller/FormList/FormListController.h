#pragma once
/*
	栏目表单接口
	author：niuniu
*/
#ifndef _FORMLISTCONTROLLER_H_
#define _FORMLISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/FormList/FormListDTO.h"
#include "domain/vo/FormList/FormListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class FormListController : public oatpp::web::server::api::ApiController
{

	API_ACCESS_DECLARE(FormListController);
public:
	//获取栏目属性接口
	ENDPOINT_INFO(queryFormList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("form.list.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(FormListJsonVO);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("form.list.xid"), "1", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/FormList", queryFormList, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryFormList(id));
	}
	

private:
	StringJsonVO::Wrapper executeQueryFormList(const String& id);
	//执行修改个人信息
	//StringJsonVO::Wrapper executeModifyNew(const NewDTO::Wrapper& dto);
};


#endif //!_FORMCONTROLLER_H_
