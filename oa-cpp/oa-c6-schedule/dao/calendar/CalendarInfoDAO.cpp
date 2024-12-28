#include "stdafx.h"
#include "CalendarInfoDAO.h"
#include "CalendarInfoMapper.h"
#include <sstream>


//	通过日历ID查询范围的模板
template<class T>
list<T> CalendarInfoDAO::execSelect(const string& table, const string& find_name, const string& cal_xid) {
	stringstream sql;
	sql << "SELECT " << find_name << " FROM " << table
		<< " WHERE CALENDAR_XID = '" << cal_xid << "';";
	string sqlStr = sql.str();
	CalendarAbleMapper<T> mapper;
	return sqlSession->executeQuery<T, CalendarAbleMapper<T>>(sqlStr, mapper);
}

list<cal_calendarDO> CalendarInfoDAO::selectCalendarInfoById(const string& cal_xid) {

	stringstream sql;
	sql << "SELECT xname, xtype, xcolor, xdescription, xisPublic, xtarget, xstatus "
		<< "FROM cal_calendar "
		<< "WHERE xid = '" << cal_xid << "';";
	CalendarInfoMapper mapper;
	string sqlStr = sql.str();

	return sqlSession->executeQuery<cal_calendarDO, CalendarInfoMapper>(sqlStr, mapper);
}

list<cal_calendar_manageablepersonlistDO> CalendarInfoDAO::selectManageablePersonById(const string& cal_xid) {
	return execSelect<cal_calendar_manageablepersonlistDO>("cal_calendar_manageablepersonlist", "xmanageablePersonList", cal_xid);
}

list<cal_calendar_publishablepersonlistDO> CalendarInfoDAO::selectPublishablePersonById(const string& cal_xid){
	return execSelect< cal_calendar_publishablepersonlistDO>("cal_calendar_publishablepersonlist", "xpublishablePersonList", cal_xid);
}

list<cal_calendar_publishablegrouplistDO> CalendarInfoDAO::selectPublishableGroupById(const string& cal_xid) {
	return execSelect< cal_calendar_publishablegrouplistDO>("cal_calendar_publishablegrouplist", "xpublishableGroupList", cal_xid);
}

list<cal_calendar_publishableunitlistDO> CalendarInfoDAO::selectPublishableUnitById(const string& cal_xid) {

	return execSelect< cal_calendar_publishableunitlistDO>("cal_calendar_publishableunitlist", "xpublishableUnitList", cal_xid);
}

list<cal_calendar_viewablepersonlistDO> CalendarInfoDAO::selectViewablePersonById(const string& cal_xid) {

	return execSelect< cal_calendar_viewablepersonlistDO>("cal_calendar_viewablepersonlist", "xviewablePersonList", cal_xid);
}

list<cal_calendar_viewablegrouplistDO> CalendarInfoDAO::selectViewableGroupById(const string& cal_xid) {

	return execSelect< cal_calendar_viewablegrouplistDO>("cal_calendar_viewablegrouplist", "xviewableGroupList", cal_xid);
}

list<cal_calendar_viewableunitlistDO> CalendarInfoDAO::selectViewableUnitById(const string& cal_xid) {

	return execSelect< cal_calendar_viewableunitlistDO>("cal_calendar_viewableunitlist", "xviewableUnitList", cal_xid);
}


