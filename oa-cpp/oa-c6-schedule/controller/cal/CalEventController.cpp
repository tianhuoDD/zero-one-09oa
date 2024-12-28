#include "stdafx.h"
#include "CalEventController.h"

#include "service/event/EventSelectService.h"


/*��ʱ����
CalEventPageJsonVO::Wrapper CalEventController::executeQueryCalEvents(const CalEventsQuery::Wrapper& query)
{
	// ����һ��JsonVO����
	auto vo = CalEventPageJsonVO::createShared();
	return vo;
}
*/


CalAllEventsJsonVO::Wrapper CalEventController::execQueryCalEventsByCalendar(const CalEventsQuery::Wrapper& query)
{
	auto vo = CalAllEventsJsonVO::createShared();

	EventSelectService service;
	auto result = service.getListEventRows(query);
	// ����һ��JsonVO����
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

