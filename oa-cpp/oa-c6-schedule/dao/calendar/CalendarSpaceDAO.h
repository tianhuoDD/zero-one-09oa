#pragma once
#ifndef _CALENDARSPACE_DAO_
#define _CALENDARSPACE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/calendar/cal_calendar_spaceDO.h"
#include "../../domain/query/calendar/CalendarSpaceQuery.h"

/**
 * 数据库操作实现了吗？我不道啊
 */
class CalendarSpaceDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count();
	// 查询所有
	std::list<cal_calendar_spaceDO> queryAll(const CalendarSpaceQuery::Wrapper& query);
};
#endif // !_CALENDARSPACE_DAO_