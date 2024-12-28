#pragma once
#ifndef _MEETING_MAPPER_
#define _MEETING_MAPPER_
#include"Mapper.h"
#include"domain/do/Meeting/MeetingDO.h"
class meetingMapper : Mapper<meetingDO> {
public:
	meetingDO mapper(ResultSet* resultSet)const override {
		meetingDO data;
		data.setApplicant(resultSet->getString(1));
		data.set_Type(resultSet->getString(2));
		data.setStartTime(resultSet->getString(3));
		data.setCompletedTime(resultSet->getString(4));
		data.setRoom(resultSet->getString(5));
		data.setHostPerson(resultSet->getString(6));
		data.setSubject(resultSet->getString(7));
		data.setSummary(resultSet->getString(8));
		data.setHostUnit(resultSet->getString(9));
		data.setMeetingId(resultSet->getString(10));
		data.setPinyin(resultSet->getString(11));
		data.setPinyinInitial(resultSet->getString(12));
		return data;
	}
};
#endif // !_MEETING_MAPPER_
