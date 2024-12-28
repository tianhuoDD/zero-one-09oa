#include "stdafx.h"
#include "EventDAO.h"
#include "EventMapper.h"
#include <sstream>


list<cal_calendarDO> EventDAO::selectCalenderByXid(const string& xid)
{
	string sql = "SELECT xisPublic,xcreateor,xsource,xtarget,xtype FROM cal_calendar WHERE `xid` = ?";
	EventMapper mapper;
	return sqlSession->executeQuery<cal_calendarDO, EventMapper>(sql, mapper, "%s", xid);

}

list<cal_calendar_manageablepersonlistDO> EventDAO::selectCalenderManeByXid(const string& xid)
{
	string sql = "SELECT xmanageablePersonList FROM cal_calendar_manageablepersonlist WHERE `CALENDAR_XID` = ?";
	EventManegerMapper mapper;
	return sqlSession->executeQuery<cal_calendar_manageablepersonlistDO, EventManegerMapper>(sql, mapper, "%s", xid);
}

int EventDAO::insertEvent(const cal_eventDO& iObj)
{
	string sql = "INSERT INTO `zo_oa`.`cal_event` ("
		"`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`,"
		"`xalarm`, `xalarmAlready`, `xalarmTime`, `xbundle`, `xcalendarId`, `xcolor`, `xcomment`, `xcommentId`, `xcreatePerson`,"
		"`xdaysOfDuration`, `xendTime`, `xendTimeStr`, `xeventType`, `xisAllDayEvent`, `xisPublic`, `xlatitude`, `xlocationName`,"
		"`xlongitude`, `xrecurrenceExc`, `xrecurrenceRule`, `xrepeatMasterId`, `xsource`, `xstartTime`, `xstartTimeStr`, "
		"`xtargetType`, `xtitle`, `xupdatePerson`, `xvalarmTime_config`, `xvalarm_Summary`, `xvalarm_description`,`xvalarm_mailto`) "
		"VALUES(?, ?, ?, ?, NULL, "
		"?, 0, ?, NULL, ?, ?, ?, NULL, ?, "
		"0, ?, ?, 'CAL_EVENT', ?, ?, NULL, ?, "
		"NULL, NULL, ?, ?, ?, ?, ?, "
		"?, ?, ?, ?, NULL, NULL, NULL);";
	int flag = sqlSession->executeUpdate(sql, "%s%s%s%s%i%s%s%s%s%s%s%s%i%i%s%s%s%s%s%s%s%s%s%s",
		iObj.getxId(), iObj.getxCreateTime(), iObj.getxSequence(), iObj.getxUpdateTime(),
		iObj.getxAlarm(), iObj.getxAlarmTime(), iObj.getxCalendarId(), iObj.getxColor(), iObj.getxComment(), iObj.getxCreatePerson(),
		iObj.getxEndTime(), iObj.getxEndTime(), iObj.getxIsAllDayEvent(), iObj.getxIsPublic(), iObj.getxLocationName(),
		iObj.getxRecurrenceRule(), iObj.getxRepeatMasterId(), iObj.getxSource(), iObj.getxStartTime(), iObj.getxStartTime(),
		iObj.getxTargetType(), iObj.getxTitle(), iObj.getxUpdatePerson(), iObj.getxValarmTime_config());

	sql = "INSERT INTO `zo_oa`.`cal_event_participants` (`CALENDAR_EVENT_XID`, `xparticipants`,"
		"`xorderColumn`) VALUES(?, ?, 0); ";
	flag &= sqlSession->executeUpdate(sql, "%s%s", iObj.getxId(), iObj.getxCreatePerson());

	sql = "INSERT INTO `zo_oa`.`cal_event_manageablepersonlist` (`CALENDAR_EVENT_XID`, `xmanageablePersonList`,"
		"`xorderColumn`) VALUES (?, ?, 0);";
	flag &= sqlSession->executeUpdate(sql, "%s%s", iObj.getxId(), iObj.getxCreatePerson());

	sql = "INSERT INTO `zo_oa`.`cal_event_viewablepersonlist` (`CALENDAR_EVENT_XID`, `xviewablePersonList`,"
		"`xorderColumn`) VALUES(?, ?, 0); ";
	flag &= sqlSession->executeUpdate(sql, "%s%s", iObj.getxId(), iObj.getxCreatePerson());

	return flag;
}

int EventDAO::insertOtherEvent(const cal_eventDO& iObj, string person, int orderColum)
{
	int flag;
	string sql = "INSERT INTO `zo_oa`.`cal_event_manageablepersonlist` (`CALENDAR_EVENT_XID`, `xmanageablePersonList`,"
		"`xorderColumn`) VALUES (?, ?, ?);";
	flag = sqlSession->executeUpdate(sql, "%s%s%i", iObj.getxId(), person, orderColum);

	sql = "INSERT INTO `zo_oa`.`cal_event_viewablepersonlist` (`CALENDAR_EVENT_XID`, `xviewablePersonList`,"
		"`xorderColumn`) VALUES(?, ?, ?); ";
	flag &= sqlSession->executeUpdate(sql, "%s%s%i", iObj.getxId(), person, orderColum);
	return flag;
}

int EventDAO::insertRepmevent(const cal_eventDO& iObj)
{
	string sql = "INSERT INTO `zo_oa`.`cal_event_repm` ("
		"`xid`, `xcreateTime`, `xsequence`, `xupdateTime`,"
		"`xdistributeFactor`, `xalarm`, `xalarmTime`, `xcalendarId`, `xcolor`, `xcomment`, `xcommentId`,"
		"`xcreatePerson`, `xdaysOfDuration`, `xendTime`, `xeventType`, `xisAllDayEvent`, `xisPublic`, `xlatitude`,"
		"`xlocationName`, `xlongitude`, `xrecurrenceExc`, `xrecurrenceRule`, `xrecurrenceStartTime`, `xrepeatStatus`,"
		"`xsource`, `xstartTime`, `xtargetType`, `xtitle`, `xupdatePerson`, `xvalarmTime_config`, `xvalarm_Summary`,"
		"`xvalarm_description`, `xvalarm_mailto`) "
		"VALUES (?, ?,?, ?, "
		"NULL, ?, ?, ?, ?, ?, NULL, "
		"?, 0, ?, 'CAL_EVENT', ?, ?, NULL,"
		"?, NULL, NULL,?, ?, 'waitForBuild',"
		"?, ?, ?, ?, ?, ?, NULL, "
		"NULL, NULL);";
	int flag = sqlSession->executeUpdate(sql, "%s%s%s%s%i%s%s%s%s%s%s%i%i%s%s%s%s%s%s%s%s%s",
		iObj.getxRepeatMasterId(), iObj.getxCreateTime(), iObj.getxSequence(), iObj.getxUpdateTime(),
		iObj.getxAlarm(), iObj.getxAlarmTime(), iObj.getxCalendarId(), iObj.getxColor(), iObj.getxComment(),
		iObj.getxCreatePerson(), iObj.getxEndTime(), iObj.getxIsAllDayEvent(), iObj.getxIsPublic(),
		iObj.getxLocationName(), iObj.getxRecurrenceRule(), iObj.getxStartTime(),
		iObj.getxSource(), iObj.getxStartTime(), iObj.getxTargetType(), iObj.getxTitle(), iObj.getxUpdatePerson(), iObj.getxValarmTime_config());


	sql = "INSERT INTO `zo_oa`.`cal_event_repm_participants` (`CALENDAR_EVENTREPEATMASTER_XID`,"
		"`xparticipants`, `xorderColumn`) VALUES (?, ?, 0);";
	flag &= sqlSession->executeUpdate(sql, "%s%s", iObj.getxRepeatMasterId(), iObj.getxCreatePerson());

	sql = "INSERT INTO `zo_oa`.`cal_event_repm_manageablepersonlist` (`CALENDAR_EVENTREPEATMASTER_XID`,"
		"`xmanageablePersonList`, `xorderColumn`) VALUES (?, ?, 0);";
	flag &= sqlSession->executeUpdate(sql, "%s%s", iObj.getxRepeatMasterId(), iObj.getxCreatePerson());

	/*sql = "INSERT INTO `zo_oa`.`cal_event_repm_createdmonthlist` (`CALENDAR_EVENTREPEATMASTER_XID`,"
		"`xcreatedMonthList`, `xorderColumn`) VALUES (?, ?, 0);";
	flag &= sqlSession->executeUpdate(sql, "%s%s", iObj.getxRepeatMasterId() , iObj.getxStartTime().substr(0,7));*/

	sql = "INSERT INTO `zo_oa`.`cal_event_repm_viewablepersonlist` (`CALENDAR_EVENTREPEATMASTER_XID`,"
		"`xviewablePersonList`, `xorderColumn`) VALUES (?, ?, 0);";
	flag &= sqlSession->executeUpdate(sql, "%s%s", iObj.getxRepeatMasterId(), iObj.getxCreatePerson());

	return flag;
}

int EventDAO::insertOtherRepmEvent(const cal_eventDO& iObj, string person, int orderColum)
{
	int flag = 1;
	string sql = "INSERT INTO `zo_oa`.`cal_event_repm_manageablepersonlist` (`CALENDAR_EVENTREPEATMASTER_XID`,"
		"`xmanageablePersonList`, `xorderColumn`) VALUES (?, ?, ?);";
	flag &= sqlSession->executeUpdate(sql, "%s%s%i", iObj.getxRepeatMasterId(), person, orderColum);

	sql = "INSERT INTO `zo_oa`.`cal_event_repm_viewablepersonlist` (`CALENDAR_EVENTREPEATMASTER_XID`,"
		"`xviewablePersonList`, `xorderColumn`) VALUES (?, ?, ?);";
	flag &= sqlSession->executeUpdate(sql, "%s%s%i", iObj.getxRepeatMasterId(), person, orderColum);
	return flag;
}

int EventDAO::insertRepmMonthlistEvent(const cal_eventDO& iObj, string date, int orderColum)
{
	int flag = 1;
	string sql = "INSERT INTO `zo_oa`.`cal_event_repm_createdmonthlist` (`CALENDAR_EVENTREPEATMASTER_XID`,"
		"`xcreatedMonthList`, `xorderColumn`) VALUES(?, ?, ?);";
	flag &= sqlSession->executeUpdate(sql, "%s%s%i", iObj.getxRepeatMasterId(), date, orderColum);

	return flag;
}

int EventDAO::updateEvnet(const cal_eventDO& uObj)
{
	/*string sql = "UPDATE `zo_oa`.`cal_event` SET `xsequence` = ?, `xupdateTime` = ?, `xalarm` = ?,"
		"`xalarmAlready` = ?, `xalarmTime` = ?, `xcalendarId` = ?, `xcolor` = ?, `xcomment` = ?,"
		"`xendTime` = ?, `xendTimeStr` = ?,"
		"`xisAllDayEvent` = ?, `xisPublic` = ?,`xlocationName` = ?,"
		"`xrecurrenceRule` =?, `xrepeatMasterId` = ?, `xsource` = ?, `xstartTime` = ?, `xstartTimeStr` = ?,"
		"`xtargetType` = ?, `xtitle` = ?, `xupdatePerson` = ?, `xvalarmTime_config` = ?, "
		"WHERE `xid` = ?;";*/

	string sql = "UPDATE `zo_oa`.`cal_event` SET `xsequence` = ?,"
		"`xupdateTime` = ?, `xalarm` = ?, `xalarmAlready` = ?, `xalarmTime` = ?,"
		"`xcalendarId` = ?, `xcolor` = ?, `xcomment` = ?,"
		"`xendTime` = ?, `xendTimeStr` = ?, "
		"`xisAllDayEvent` = ?, `xisPublic` = ?, `xlocationName` = ?,"
		"`xrecurrenceRule` = ?, `xrepeatMasterId` = ?, `xsource` = ?, `xstartTime` = ?, "
		"`xstartTimeStr` = ?, `xtargetType` = ?, `xtitle` = ?, `xupdatePerson` = ?, "
		"`xvalarmTime_config` = ?  WHERE `xid` = ? ; ";
	int flag = sqlSession->executeUpdate(sql, "%s%s%i%i%s%s%s%s%s%s%i%i%s%s%s%s%s%s%s%s%s%s%s",
		uObj.getxSequence(), uObj.getxUpdateTime(), uObj.getxAlarm(),
		uObj.getxAlarmAlready(), uObj.getxAlarmTime(), uObj.getxCalendarId(), uObj.getxColor(), uObj.getxComment(),
		uObj.getxEndTime(), uObj.getxEndTime(),
		uObj.getxIsAllDayEvent(), uObj.getxIsPublic(), uObj.getxLocationName(),
		uObj.getxRecurrenceRule(), uObj.getxRepeatMasterId(), uObj.getxSource(), uObj.getxStartTime(), uObj.getxStartTime(),
		uObj.getxTargetType(), uObj.getxTitle(), uObj.getxUpdatePerson(), uObj.getxValarmTime_config(),
		uObj.getxId());


	/*sql = "UPDATE `zo_oa`.`cal_event_manageablepersonlist` SET `CALENDAR_EVENT_XID` = ?,`xparticipants` = 'xadmin', "
		"`xorderColumn` = 0 WHERE `CALENDAR_EVENT_XID` = ? ;";
	flag &= sqlSession->executeUpdate(sql, "%s", uObj.getxId());

	sql = "UPDATE `zo_oa`.`cal_event_participants` SET `CALENDAR_EVENT_XID` = ?, `xparticipants` = 'xadmin',"
		"`xorderColumn` = 0 WHERE `CALENDAR_EVENT_XID` = ? ;";
	flag &= sqlSession->executeUpdate(sql, "%s", uObj.getxId());


	sql = "UPDATE `zo_oa`.`cal_event_viewablepersonlist` SET `CALENDAR_EVENT_XID` = ?, `xviewablePersonList` = 'xadmin', "
		"`xorderColumn` = 0 WHERE `CALENDAR_EVENT_XID` = ? ;";
	flag &= sqlSession->executeUpdate(sql, "%s", uObj.getxId());*/


	return flag;
}

int EventDAO::deleteEventByXid(string xid)
{
	string sql = "DELETE FROM `cal_event` WHERE `xid`= ? ;";
	int flag = (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_manageablepersonlist` WHERE `CALENDAR_EVENT_XID`= ? ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_participants` WHERE `CALENDAR_EVENT_XID`= ? ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_viewablepersonlist` WHERE `CALENDAR_EVENT_XID`= ? ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	return flag;
}

int EventDAO::deleteEventByRepmXid(string xid)
{
	string sql = "DELETE FROM `cal_event_repm` WHERE `xid`=? ;";
	int flag = (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_repm_createdmonthlist` WHERE `CALENDAR_EVENTREPEATMASTER_XID`=? ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_repm_manageablepersonlist` WHERE `CALENDAR_EVENTREPEATMASTER_XID`=? ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_repm_participants` WHERE `CALENDAR_EVENTREPEATMASTER_XID`=? ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_repm_viewablepersonlist` WHERE `CALENDAR_EVENTREPEATMASTER_XID`=? ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	return flag;
}

int EventDAO::deleteEventByFindRepmXid(string xid)
{
	string sql = "DELETE FROM `cal_event_repm` WHERE `xid` = (SELECT `xrepeatMasterId` FROM `cal_event` where `xid` = ?) ;";
	int flag = (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_repm_createdmonthlist` WHERE `CALENDAR_EVENTREPEATMASTER_XID` IN "
		"(SELECT `xrepeatMasterId` FROM `cal_event` where `xid` = ?) ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_repm_manageablepersonlist` WHERE `CALENDAR_EVENTREPEATMASTER_XID` IN "
		"(SELECT `xrepeatMasterId` FROM `cal_event` where `xid` = ?) ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_repm_participants` WHERE `CALENDAR_EVENTREPEATMASTER_XID` IN "
		"(SELECT `xrepeatMasterId` FROM `cal_event` where `xid` = ?) ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	sql = "DELETE FROM `cal_event_repm_viewablepersonlist` WHERE `CALENDAR_EVENTREPEATMASTER_XID` IN "
		"(SELECT `xrepeatMasterId` FROM `cal_event` where `xid` = ?) ;";
	flag &= (sqlSession->executeUpdate(sql, "%s", xid) > 0);



	return flag;
}

int EventDAO::deleteEventByFindXid(string xid)
{
	//string sql = "DELETE FROM `cal_event`  WHERE `xrepeatMasterId` IN (SELECT `xrepeatMasterId` FROM `cal_event` where `xid` = ?) ;";
	string sql = "DELETE FROM `cal_event`  WHERE `xrepeatMasterId` = ?;";
	int flag = (sqlSession->executeUpdate(sql, "%s", xid) > 0);

	return flag;
}



