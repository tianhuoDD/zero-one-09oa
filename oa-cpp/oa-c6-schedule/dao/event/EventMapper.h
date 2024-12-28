#ifndef _EVENT_MAPPER_
#define _EVENT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_manageablepersonlistDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class EventMapper : public Mapper<cal_calendarDO>
{
public:
	cal_calendarDO mapper(ResultSet* resultSet) const override
	{
		cal_calendarDO data;
		data.setxIsPublic(resultSet->getInt(1));
		data.setxCreateor(resultSet->getString(2));
		data.setxSource(resultSet->getString(3));
		data.setxTarget(resultSet->getString(4));
		data.setxType(resultSet->getString(5));
		
		return data;
	}


};


class EventManegerMapper : public Mapper<cal_calendar_manageablepersonlistDO>
{
public:
	cal_calendar_manageablepersonlistDO mapper(ResultSet* resultSet) const override
	{
		cal_calendar_manageablepersonlistDO data;
		data.setFiled(resultSet->getString(1));
		return data;
	}


};

#endif // !_EVENT_MAPPER_