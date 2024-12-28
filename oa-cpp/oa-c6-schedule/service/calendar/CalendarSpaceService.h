#pragma once
#ifndef _CALENDARSPACE_SERVICE_
#define _CALENDARSPACE_SERVICE_
#include <list>
#include "domain/query/calendar/CalendarSpaceQuery.h"
#include "domain/dto/calendar/CalendarSpaceDTO.h"

/**
 * ��֪����ô�ͳ��ֵķ���ʵ��
 */
class CalendarSpaceService
{
public:
	// ��ҳ��ѯ��������
	CalendarSpacePageDTO::Wrapper listAll(const CalendarSpaceQuery::Wrapper& query);
};

#endif // !_CALENDARSPACE_SERVICE_