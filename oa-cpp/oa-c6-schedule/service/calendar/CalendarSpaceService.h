#pragma once
#ifndef _CALENDARSPACE_SERVICE_
#define _CALENDARSPACE_SERVICE_
#include <list>
#include "domain/query/calendar/CalendarSpaceQuery.h"
#include "domain/dto/calendar/CalendarSpaceDTO.h"

/**
 * 不知道怎么就出现的服务实现
 */
class CalendarSpaceService
{
public:
	// 分页查询所有数据
	CalendarSpacePageDTO::Wrapper listAll(const CalendarSpaceQuery::Wrapper& query);
};

#endif // !_CALENDARSPACE_SERVICE_