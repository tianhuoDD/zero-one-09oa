#pragma once
#ifndef _ACCEPTFILECONTROLLER_H_
#define _ACCEPTFILECONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/accept/file/AcceptFileListVO.h"
#include "domain/query/accept/file/AcceptFileListQuery.h"
#include "domain/dto/accept/file/AcceptFileListDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class AcceptFileController : public oatpp::web::server::api::ApiController // 1 继承控制器
{

	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AcceptFileController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(querySample)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tital.acceptfile"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AcceptFileListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "xperson", ZH_WORDS_GETTER("accept.file.upload"), "xiaogang@314159@P", true);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/companynetdisk/query-filelist-filed", querySample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(acceptfilequery, AcceptFileListQuery, queryParams);
		//获取负载的xid
		acceptfilequery->xid = authObject->getPayload().getId();
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execqueryUsersByXunique(acceptfilequery));
	}

private:
	AcceptFileListJsonVO::Wrapper execqueryUsersByXunique(const AcceptFileListQuery::Wrapper& query);

};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ACCEPTFILECONTROLLER_H_