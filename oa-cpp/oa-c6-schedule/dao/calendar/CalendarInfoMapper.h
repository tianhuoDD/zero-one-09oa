#pragma once
#ifndef _CALENDARINFOMAPPER_H_
#define _CALENDARINFOMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablegrouplistDO.h"
#include "../../domain/do/calendar/cal_calendar_viewableunitlistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishablegrouplistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishableunitlistDO.h"
#include "../../domain/do/calendar/cal_calendar_manageablepersonlistDO.h"

class CalendarInfoMapper : public Mapper<cal_calendarDO>
{
public:
	

cal_calendarDO mapper(ResultSet* resultset) const override {
		cal_calendarDO data;
		//data.setxId(resultset->getString(1));
		data.setxName(resultset->getString(1));
		data.setxType(resultset->getString(2));
		data.setxColor(resultset->getString(3));
		data.setxDescription(resultset->getString(4));
		data.setxIsPublic(resultset->getInt(5));
		data.setxTarget(resultset->getString(6));
		data.setxStatus(resultset->getString(7));

		return data;
	}
};

template <class T>
class CalendarAbleMapper : public Mapper<T>
{
public:
	T mapper(ResultSet* resultset) const override {
		T data;
		data.setFiled(resultset->getString(1));

		return data;
	}


};
#endif // !_CALENDARINFOMAPPER_H_

