#include "stdafx.h"
#include "CalendarSpaceDAO.h"
#include "CalendarSpaceMapper.h"
#include <sstream>

uint64_t CalendarSpaceDAO::count()
{
	string sql = "SELECT COUNT(*) FROM cal_calendar WHERE xisPublic = 1";
	return sqlSession->executeQueryNumerical(sql);
}

std::list<cal_calendar_spaceDO> CalendarSpaceDAO::queryAll(const CalendarSpaceQuery::Wrapper& query)
{
	stringstream sql;
	sql << " SELECT t1.xid, t1.xcreateTime, t1.xcolor, t1.xcreateor, t1.xname, t1.xtype, t1.xdescription, ";
	sql << " CASE ";
	sql << " WHEN t2.xfollowers = ( ";
	sql << " SELECT xdistinguishedName ";
	sql << " FROM org_person ";
	sql << " WHERE xname = '";
	sql << string(query->xfollowersId);
	sql << "' ";
	sql << " ) AND t1.xid = t2.CALENDAR_XID ";
	sql << " THEN 'true' ELSE 'false' ";
	sql << " END AS xisfollow ";
	sql << " FROM cal_calendar as t1 ";
	sql << " LEFT JOIN cal_calendar_followers as t2 ";
	sql << " ON t1.xid = t2.CALENDAR_XID ";
	sql << " WHERE t1.xisPublic = 1 ";
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CalendarSpaceMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<cal_calendar_spaceDO, CalendarSpaceMapper>(sqlStr, mapper);
}