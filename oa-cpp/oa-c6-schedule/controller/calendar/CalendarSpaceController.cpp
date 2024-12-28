#include "stdafx.h"
#include "../../service/calendar/CalendarSpaceService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "CalendarSpaceController.h"

CalendarSpacePageJsonVO::Wrapper CalendarSpaceController::execQueryCalendarSpace(const CalendarSpaceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	CalendarSpaceService service;
	// 查询数据
	query->xfollowersId = payload.getId();
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CalendarSpacePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}