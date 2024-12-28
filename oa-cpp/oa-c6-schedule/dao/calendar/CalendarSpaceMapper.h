#pragma once
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/calendar/cal_calendar_spaceDO.h"

/**
 * 啥都不知道的匹配映射
 */
class CalendarSpaceMapper : public Mapper<cal_calendar_spaceDO>
{
public:
	cal_calendar_spaceDO mapper(ResultSet* resultSet) const override
	{
		cal_calendar_spaceDO data;
		data.setXid(resultSet->getString(1));
		data.setXcreateTime(resultSet->getString(2));
		data.setXcolor(resultSet->getString(3));
		data.setXcreateor(resultSet->getString(4));
		data.setXname(resultSet->getString(5));
		data.setXtype(resultSet->getString(6));
		data.setXdescription(resultSet->getString(7));
		data.setXisfollow(resultSet->getString(8));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_