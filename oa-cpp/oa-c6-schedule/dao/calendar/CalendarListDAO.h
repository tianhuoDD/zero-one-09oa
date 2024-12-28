#pragma once
#ifndef _CALENDARLISTDAO_H_
#define _CALENDARLISTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_followersDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablepersonlistDO.h"

class CalendarListDAO : public BaseDAO {

public:
	//	ͨ���û�id�����û����к�
//	list<org_personDO> selectById(const string& id);
	//	ͨ���û����кŲ��ҿɼ�����
	list<cal_calendarDO> selectByXsequence(const string& xsequence);
};

#endif // !_CALENDARLISTDAO_H_
