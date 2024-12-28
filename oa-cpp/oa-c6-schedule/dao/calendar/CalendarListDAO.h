#pragma once
#ifndef _CALENDARLISTDAO_H_
#define _CALENDARLISTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_followersDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablepersonlistDO.h"

class CalendarListDAO : public BaseDAO {

public:
	//	通过用户id查找用户序列号
//	list<org_personDO> selectById(const string& id);
	//	通过用户序列号查找可见日历
	list<cal_calendarDO> selectByXsequence(const string& xsequence);
};

#endif // !_CALENDARLISTDAO_H_
