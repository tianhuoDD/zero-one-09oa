#pragma once
#ifndef _CALEVENTCONTROLLER_H_
#define _CALEVENTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "oatpp-swagger/Types.hpp"
#include "domain/GlobalInclude.h"
#include "domain/query/cal/CalEventQuery.h"
#include "domain/query/cal/CalEventsQuery.h"
#include "domain/vo/cal/CalEventVO.h"
#include "domain/vo/cal/CalEventsVO.h"
#include "domain/vo/cal/CalEventJsonVO.h"
using namespace oatpp;
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController)

//日志控制器，演示日志基础接口的使用
class CalEventController :public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(CalEventController);

public:
	//定义查询日程列表描述
	ENDPOINT_INFO(queryCalEvents) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.event.xqueryEvents"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		//符合条件的所有条日程
		API_DEF_ADD_RSP_JSON_WRAPPER(CalAllEventsJsonVO);

		//定义其他查询参数描述
		//所属日历
		API_DEF_ADD_QUERY_PARAMS(String, "calendarId", ZH_WORDS_GETTER("calender.event.xcalendarId"), "66666666666",true);
		//年月
		API_DEF_ADD_QUERY_PARAMS(String, "queryDate", ZH_WORDS_GETTER("calender.event.xqueryDate"), "2024-10", true);
	}
	//定义查询日程列表接口
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/schedule/query-eventlist-by-dateAndCalendar", queryCalEvents, CalEventsQuery, execQueryCalEventsByCalendar(query));

	/*
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/schedule-event/query-by-dateAndCalendar", queryCalEvents, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(queryCalEvents, CalEventsQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCalEventsByCalendar(queryCalEvents, authObject->getPayload()));
	}
	*/

	//定义查询日志详情描述
	ENDPOINT_INFO(queryCalEvent) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.event.xqueryEvent"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CalEventJsonVO);
		//定义其他查询参数描述
		//查询日志id
		API_DEF_ADD_QUERY_PARAMS(String, "calEventId", ZH_WORDS_GETTER("calender.event.xid"), "88888888888",true);
	}
	//定义查询日志详情接口
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/schedule/query-eventinfo-by-eventId", queryCalEvent, CalEventQuery, execQueryCalEventByCalEventId(query));
private:
	//
	CalAllEventsJsonVO::Wrapper execQueryCalEventsByCalendar(const CalEventsQuery::Wrapper& calEventsQuery);

	//CalEventsPageJsonVO::Wrapper executeQueryCalEvents(const CalEventsQuery::Wrapper& calEventsQuery);


	CalEventJsonVO::Wrapper execQueryCalEventByCalEventId(const CalEventQuery::Wrapper& calEventQuery);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_CALEVENTCONTROLLER_H_
