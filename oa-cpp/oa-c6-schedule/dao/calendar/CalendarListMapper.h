#pragma once
#ifndef _CALENDARLISTMAPPER_H_
#define _CALENDARLISTMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/calendar/cal_calendar_followersDO.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablepersonlistDO.h"
#include "../../domain/do/calendar/org_personDO.h"

class CalendarListMapper : public Mapper<cal_calendarDO>
{
public:
	cal_calendarDO mapper(ResultSet* resultset) const override {
		cal_calendarDO data;
		data.setxId(resultset->getString(1));
		data.setxName(resultset->getString(2));
		data.setxType(resultset->getString(3));
		data.setxColor(resultset->getString(4));
		return data;
	}
};

#endif // !_CALENDARLISTMAPPER_H_
