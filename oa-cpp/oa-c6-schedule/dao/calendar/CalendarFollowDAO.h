#pragma once
#ifndef _CALENDARFOLLOW_DAO_
#define _CALENDARFOLLOW_DAO_
#include "BaseDAO.h"
#include "../../domain/do/calendar/cal_calendar_followersDO.h"

/**
 * 示例表数据库操作实现
 */
class CalendarFollowDAO : public BaseDAO
{
public:
	// 插入数据
	int insert(const cal_calendar_followersDO& iObj);
	// 通过ID删除数据
	int deleteByIdAndName(const cal_calendar_followersDO& iObj);
};
#endif // !_CALENDARFOLLOW_DAO_