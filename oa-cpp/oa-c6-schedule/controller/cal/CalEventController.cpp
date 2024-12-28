#include "stdafx.h"
#include "CalEventController.h"

#include "service/event/EventSelectService.h"


/*暂时弃用
CalEventPageJsonVO::Wrapper CalEventController::executeQueryCalEvents(const CalEventsQuery::Wrapper& query)
{
	// 定义一个JsonVO对象
	auto vo = CalEventPageJsonVO::createShared();
	return vo;
}
*/


CalAllEventsJsonVO::Wrapper CalEventController::execQueryCalEventsByCalendar(const CalEventsQuery::Wrapper& query)
{
	auto vo = CalAllEventsJsonVO::createShared();

	EventSelectService service;
	auto result = service.getListEventRows(query);
	// 定义一个JsonVO对象
	vo->success(result);
	return vo;
}




CalEventJsonVO::Wrapper CalEventController::execQueryCalEventByCalEventId(const CalEventQuery::Wrapper& query)
{
	EventSelectService service;
	auto result = service.getDetaileEvent(query);
	auto vo = CalEventJsonVO::createShared();
	vo->success(result);
	return vo;
}

