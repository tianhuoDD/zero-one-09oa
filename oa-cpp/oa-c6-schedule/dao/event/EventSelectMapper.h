#pragma once
#ifndef _EVENTSELECTMAPPER_H_
#define _EVENTSELECTMAPPER_H_

#include "Mapper.h"
#include "domain/do/event/cal_eventDO.h"
#include "domain/do/event/cal_event_repmDO.h"

class RepmSelectMapper :public Mapper<cal_event_repmDO>
{
public:
	cal_event_repmDO mapper(ResultSet* resultSet) const override
	{
		cal_event_repmDO data;
		data.setxId(resultSet->getString(1));
		data.setxSequence(resultSet->getString(2));
		data.setxDistributeFactor(resultSet->getInt(3));
		data.setxAlarm(resultSet->getInt(4));
		data.setxAlarmTime(resultSet->getString(5));
		data.setxCalendarId(resultSet->getString(6));
		data.setxColor(resultSet->getString(7));
		data.setxComment(resultSet->getString(8));
		data.setxCommentId(resultSet->getString(9));
		data.setxCreatePerson(resultSet->getString(10));
		data.setxDaysOfDuration(resultSet->getInt(11));
		data.setxEndTime(resultSet->getString(12));
		data.setxEventType(resultSet->getString(13));
		data.setxIsAllDayEvent(resultSet->getInt(14));
		data.setxIsPublic(resultSet->getInt(15));
		data.setxLocationName(resultSet->getString(16));
		data.setxRecurrenceRule(resultSet->getString(17));
		data.setxRecurrenceStartTime(resultSet->getString(18));
		data.setxSource(resultSet->getString(19));
		data.setxStartTime(resultSet->getString(20));
		data.setxTargetType(resultSet->getString(21));
		data.setxTitle(resultSet->getString(22));
		data.setxUpdatePerson(resultSet->getString(23));
		data.setxValarmTime_config(resultSet->getString(24));
		data.setxValarm_Summary(resultSet->getString(25));
		data.setxCreateTime(resultSet->getString(26));
		data.setxUpdateTime(resultSet->getString(27));
		return data;
	}
};

class EventsSelectMapper :public Mapper<cal_eventDO>
{
public:
	cal_eventDO mapper(ResultSet* resultSet) const override
	{
		cal_eventDO data;
		data.setxId(resultSet->getString(1));
		data.setxTitle(resultSet->getString(2));
		data.setxStartTime(resultSet->getString(3));
		data.setxEndTime(resultSet->getString(4));
		data.setxColor(resultSet->getString(5));
		data.setxLocationName(resultSet->getString(6));
		data.setxIsAllDayEvent(resultSet->getInt(7));

		return data;
	}
};

class EventSelectMapper :public Mapper<cal_eventDO>
{
public:
	cal_eventDO mapper(ResultSet* resultSet) const override
	{
		cal_eventDO data;
		data.setxCalendarId(resultSet->getString(1));
		data.setxTitle(resultSet->getString(2));
		data.setxStartTime(resultSet->getString(3));
		data.setxEndTime(resultSet->getString(4));
		data.setxColor(resultSet->getString(5));
		data.setxComment(resultSet->getString(6));
		data.setxLocationName(resultSet->getString(7));
		data.setxRecurrenceRule(resultSet->getString(8));
		data.setxIsAllDayEvent(resultSet->getInt(9));

		return data;
	}
};
#endif // !_EVENTMAPPER_H_
