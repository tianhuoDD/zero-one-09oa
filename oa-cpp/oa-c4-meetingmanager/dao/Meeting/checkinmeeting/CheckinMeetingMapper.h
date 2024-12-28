#pragma once
#ifndef _CHECKINMEETING_MAPPER_
#define _CHECKINMEETING_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/Meeting/checkinmeeting/CheckinMeetingDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class CheckinMeetingMapper : public Mapper<CheckinMeetingDO>
{
public:
	CheckinMeetingDO mapper(ResultSet* resultSet) const override
	{
		CheckinMeetingDO data;
		data.setMeetingId(resultSet->getString(1));
		data.setXcheckinPersonList(resultSet->getString(2));
		data.setXorderColumn(resultSet->getInt(3));
		return data;
	}
};

#endif // !_CHECKINMEETING_MAPPER_