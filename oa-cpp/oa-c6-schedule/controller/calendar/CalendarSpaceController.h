#pragma once
#ifndef _CALENDARSPACE_CONTROLLER_
#define _CALENDARSPACE_CONTROLLER_

#include "domain/vo/calendar/CalendarSpaceVO.h"
#include "domain/query/calendar/CalendarSpaceQuery.h"
#include "domain/dto/calendar/CalendarSpaceDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class CalendarSpaceController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CalendarSpaceController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryCalendarSpace) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.get.space"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CalendarSpacePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
	}

	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/scehdule/calendar-space-query", queryCalendarSpace, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
			API_HANDLER_QUERY_PARAM(query, CalendarSpaceQuery, queryParams);
			API_HANDLER_RESP_VO(execQueryCalendarSpace(query, authObject->getPayload()));
	}
private:
	// 3.3 查询日历广场的公开日历
	CalendarSpacePageJsonVO::Wrapper execQueryCalendarSpace(const CalendarSpaceQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CALENDARSPACE_CONTROLLER_