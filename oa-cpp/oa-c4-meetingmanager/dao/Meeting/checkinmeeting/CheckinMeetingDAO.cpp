#include "stdafx.h"
#include "CheckinMeetingDAO.h"
#include "CheckinMeetingMapper.h"
#include <sstream>

uint64_t CheckinMeetingDAO::insert(const CheckinMeetingDO& iObj)
{
	string sql =
		"INSERT INTO `mt_meeting_checkinpersonlist` (`MEETING_XID`, `xcheckinPersonList`, `xorderColumn`) VALUES (?, ?, ?)";

	return sqlSession->executeUpdate(sql, "%s%s%i",
		iObj.getMeetingId(), iObj.getXcheckinPersonList(), iObj.getXorderColumn());
}
