#pragma once
#ifndef _CALENDARINFODAO_H_
#define _CALENDARINFODAO_H_

#include "BaseDAO.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablegrouplistDO.h"
#include "../../domain/do/calendar/cal_calendar_viewableunitlistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishablegrouplistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishableunitlistDO.h"
#include "../../domain/do/calendar/cal_calendar_manageablepersonlistDO.h"

class CalendarInfoDAO : public BaseDAO {
private:
	//	通过日历ID查询范围的模板
	template<class T>
	list<T> execSelect(const string& table, const string& find_name, const string& cal_xid);

public:
	//	通过日历ID查询日历基本信息
	list<cal_calendarDO> selectCalendarInfoById(const string& cal_xid);
	//	通过日历ID查询日历管理人的范围
	list<cal_calendar_manageablepersonlistDO> selectManageablePersonById(const string& cal_xid);
	//	通过日历ID查询日历可见人的范围
	list<cal_calendar_viewablepersonlistDO> selectViewablePersonById(const string& cal_xid);
	//	通过日历ID查询日历可见群组的范围
	list<cal_calendar_viewablegrouplistDO> selectViewableGroupById(const string& cal_xid);
	//	通过日历ID查询日历可见组织的范围
	list<cal_calendar_viewableunitlistDO> selectViewableUnitById(const string& cal_xid);
	//	通过日历ID查询日历可新建人的范围
	list<cal_calendar_publishablepersonlistDO> selectPublishablePersonById(const string& cal_xid);
	//	通过日历ID查询日历可新建群组的范围
	list<cal_calendar_publishablegrouplistDO> selectPublishableGroupById(const string& cal_xid);
	//	通过日历ID查询日历可新建组织的范围
	list<cal_calendar_publishableunitlistDO> selectPublishableUnitById(const string& cal_xid);

};

#endif // !_CALENDARINFODAO_H_
