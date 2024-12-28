#pragma once

#ifndef _CALENDERGETCONTROLLER_H_
#define _CALENDERGETCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/calender/CalenderInfoDTO.h"
#include "domain/vo/calender/CalenderInfoVO.h"
#include "domain/dto/calender/CalenderListDTO.h"
#include "domain/vo/calender/CalenderListVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CalenderGetController : public oatpp::web::server::api::ApiController {
	//	定义控制器访问入口
	API_ACCESS_DECLARE(CalenderGetController);

public:	//	定义接口


	/*
	//	获取日历列表 接口
	ENDPOINT_INFO(queryCalenderList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.get.summary_list"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CalenderListJsonVO);
		// 定义查询参数描述(用户唯一id)
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("calender.user.xid"), "68", true);
	}
	//  定义接口处理
	ENDPOINT(API_M_GET, "/schedule-calender/query-calenderlist", queryCalenderList, QUERY(String, xid), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型，但是这里一个参数不需要解析，故注释
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCalenderList(xid));
	}
	*/


	//	获取日历列表 接口
	//	定义接口描述
	ENDPOINT_INFO(queryCalenderList) {
		//	定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.get.summary_list"));
		//	定义默认授权函数
		API_DEF_ADD_AUTH();
		//	定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CalenderListJsonVO);
		//	定义查询参数描述（用户序列号）
		//API_DEF_ADD_QUERY_PARAMS(String, "xdistinguishedName", ZH_WORDS_GETTER("calender.user.xdistinguishedName"), "1068", true);
	}

	//	定义接口处理
	ENDPOINT(API_M_GET, "/schedule/query-calenderlist-by-userid", queryCalenderList, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryCalenderList(authObject->getPayload()));
	}


	//	获取日历详情 接口
	//  定义接口描述
	ENDPOINT_INFO(queryCalenderInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.get.summary_info"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CalenderInfoJsonVo);
		// 定义查询参数描述(日历唯一id)
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("calender.field.xid"), "68", true);
	}
	//  定义接口处理
	ENDPOINT(API_M_GET, "/schedule/query-calenderinfo-by-calenderid", queryCalenderInfo, QUERY(String, xid), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型，但是这里一个参数不需要解析，故注释
		//API_HANDLER_QUERY_PARAM(userQuery, SampleQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCalenderInfo(xid, authObject->getPayload()));
	}

private: //	定义接口执行函数

	//	定义 获取日历详情 接口执行函数，参数：xid->日历ID
	CalenderInfoJsonVo::Wrapper execQueryCalenderInfo(const String& xid, const PayloadDTO& payload);

	//	定义 获取日历列表 接口执行函数，参数：payload->负载信息
	//CalenderListJsonVO::Wrapper execQueryCalenderList(const PayloadDTO& payload);

	CalenderListJsonVO::Wrapper execQueryCalenderList(const PayloadDTO& payload);

};



#include OATPP_CODEGEN_END(ApiController)

#endif // !_CALENDERGETCONTROLLER_H_
