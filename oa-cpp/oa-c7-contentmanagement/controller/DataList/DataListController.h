#pragma once
#pragma once
/*
	栏目表单接口
	author：niuniu
*/
#ifndef _DATALISTCONTROLLER_H_
#define _DATALISTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/DataList/DataListDTO.h"
#include "domain/vo/DataList/DataListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class DataListController : public oatpp::web::server::api::ApiController
{

	API_ACCESS_DECLARE(DataListController);
public:
	
	ENDPOINT_INFO(queryDataList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("data.list.summary1"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DataListJsonVO);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("data.list.xid"), "1", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/DataList", queryDataList, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryDataDetails(id));
	}

	ENDPOINT_INFO(queryDataDetails) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("data.list.summary2"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(DataDetailsJsonVO);
		// 定义分页查询参数描述
		//API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("data.list.xid"), "1", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/DataDetails", queryDataDetails, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(executeQueryDataDetails(id));
	}

	ENDPOINT_INFO(deleteAttatch) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("delete.data"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "attatchName", ZH_WORDS_GETTER("cms_appndict.xname"), "null", true);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("cms_appndict.xid"), "1", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_DEL, "/delete", deleteAttatch, QUERY(String, attatchName)) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execdeletedata(attatchName));
	}


private:
	StringJsonVO::Wrapper executeQueryDataDetails(const String& id);
	StringJsonVO::Wrapper executeQueryDataList(const String& id);
	Uint64JsonVO::Wrapper execdeletedata(const String& id);
	//执行修改个人信息
	//StringJsonVO::Wrapper executeModifyNew(const NewDTO::Wrapper& dto);
};


#endif //!_FORMCONTROLLER_H_
