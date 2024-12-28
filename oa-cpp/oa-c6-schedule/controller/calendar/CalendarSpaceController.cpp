#include "stdafx.h"
#include "../../service/calendar/CalendarSpaceService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "CalendarSpaceController.h"

CalendarSpacePageJsonVO::Wrapper CalendarSpaceController::execQueryCalendarSpace(const CalendarSpaceQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	CalendarSpaceService service;
	// ��ѯ����
	query->xfollowersId = payload.getId();
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CalendarSpacePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}