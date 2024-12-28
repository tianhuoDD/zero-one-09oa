#pragma once
#ifndef _EVENT_DAO_
#define _EVNET_DAO_

#include "BaseDAO.h"
#include "../../domain/do/event/cal_eventDO.h"
#include "../../domain/do/event/cal_event_manageablepersonlistDO.h"
#include "../../domain/do/event/cal_event_participantsDO.h"
#include "../../domain/do/event/cal_event_repmDO.h"
#include "../../domain/do/event/cal_event_repm_createdmonthlistDO.h"
#include "../../domain/do/event/cal_event_repm_manageablepersonlistDO.h"
#include "../../domain/do/event/cal_event_repm_participantsDO.h"
#include "../../domain/do/event/cal_event_repm_viewablepersonlistDO.h"
#include "../../domain/do/event/cal_event_viewablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_manageablepersonlistDO.h"


class EventDAO : public BaseDAO
{
private:

	//

public:
	//查询日历表
	list<cal_calendarDO> selectCalenderByXid(const string& xid);
	//查询日历管理者表
	list<cal_calendar_manageablepersonlistDO> selectCalenderManeByXid(const string& xid);
	// 插入数据
	int insertEvent(const cal_eventDO& iObj);
	// 插入其他数据
	int insertOtherEvent(const cal_eventDO& iObj, string preson, int orderColum);
	// 插入repm表
	int insertRepmevent(const cal_eventDO& iObj);
	// 插入repm表其他数据
	int insertOtherRepmEvent(const cal_eventDO& iObj, string preson, int orderColum);
	// 插入repm_monthlist表
	int insertRepmMonthlistEvent(const cal_eventDO& iObj, string date, int orderColum);
	//修改数据
	int updateEvnet(const cal_eventDO& uObj);
	// 通过ID删除Evnet数据
	int deleteEventByXid(string xid);
	// 通过Repeat_id删除数据
	int deleteEventByRepmXid(string xid);
	// 通过eventId查询repmId后删除数据
	int deleteEventByFindRepmXid(string xid);
	// 通过repmId删除eventId
	int deleteEventByFindXid(string xid);

};


#endif // !_EVENT_DAO_