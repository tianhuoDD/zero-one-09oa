#include "stdafx.h"
#include "CalendarFollowDAO.h"
#include <sstream>

int CalendarFollowDAO::insert(const cal_calendar_followersDO& iObj)
{
	string sql = " INSERT INTO cal_calendar_followers (CALENDAR_XID, xfollowers, xorderColumn) VALUES (?, (SELECT xdistinguishedName FROM org_person WHERE xname = ? LIMIT 1), ?) ";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getCalenderId(), iObj.getXfollowersId(), iObj.getXorderColumn());
}

int CalendarFollowDAO::deleteByIdAndName(const cal_calendar_followersDO& iObj)
{
	string sql = " DELETE FROM cal_calendar_followers WHERE CALENDAR_XID = ? AND xorderColumn = ? AND xfollowers = ( SELECT xdistinguishedName FROM org_person WHERE xname = ? LIMIT 1) ";
	return sqlSession->executeUpdate(sql, "%s%i%s", iObj.getCalenderId(), iObj.getXorderColumn(), iObj.getXfollowersId());
}
