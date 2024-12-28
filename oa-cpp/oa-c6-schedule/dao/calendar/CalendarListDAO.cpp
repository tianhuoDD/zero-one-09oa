#include "stdafx.h"
#include "CalendarListDAO.h"
#include "CalendarListMapper.h"
#include <sstream>

/*
list<org_personDO> CalendarListDAO::selectById(const string& id) {
	stringstream sql;
	sql << "SELECT xdistinguishedName FROM `org_person` "
		<< "WHERE xid = '" << id << "';";
	PersonIdMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<org_personDO, PersonIdMapper>(sqlStr, mapper);
}
*/

std::list<cal_calendarDO> CalendarListDAO::selectByXsequence(const string& id) {

	stringstream sql;
	sql << "SELECT cc.xid, cc.xname, cc.xtype, cc.xcolor "
		<< "FROM cal_calendar cc "
		<< "JOIN ( " << "SELECT CALENDAR_XID " << "FROM cal_calendar_followers " << "WHERE xfollowers = ( "
		<< "SELECT xdistinguishedName FROM org_person WHERE xid = '" << id << "')"
		<< "UNION SELECT CALENDAR_XID FROM cal_calendar_viewablepersonlist WHERE xviewablePersonList = ( "
		<< "SELECT xdistinguishedName FROM org_person WHERE xid = '" << id << "')"
		<< ") AS visible_calendars ON cc.xid = visible_calendars.CALENDAR_XID;";

	CalendarListMapper mapper;
	string sqlStr = sql.str();
	
	return sqlSession->executeQuery<cal_calendarDO, CalendarListMapper>(sqlStr, mapper);
}