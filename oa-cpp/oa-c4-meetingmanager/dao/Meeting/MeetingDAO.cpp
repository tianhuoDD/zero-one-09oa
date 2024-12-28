#include"MeetingDAO.h"

list<meetingDO> MeetingDAO::selectById(const string& meetingId)
{
	string sql = "SELECT \
					 xapplicant,xtype,xstartTime,xcompletedTime,xroom,xhostPerson,xsubject,xsummary,xhostUnit,xid,xpinyin,xpinyinInitial \
				  FROM \
					 mt_meeting \
				  WHERE \
					 xid = ? \
		";
	meetingMapper mapper;
	auto res = sqlSession->executeQuery<meetingDO, meetingMapper>(sql, mapper, "%s", meetingId);
	return res;
}

list<CurrentListDO> MeetingDAO::selectListById(const string& meetingId, string table_fmt)
{
	//举例查询的字段表名为xinvitPersonList，表名为mt_meeting_invitepersonlist,table_fmt就是invitPersonList
	// 列名
	string rowName = 'x' + table_fmt;

	// 表名转换为小写并拼接
	string tableName = table_fmt;
	for (char& c : tableName) c = tolower(c);
	tableName = "mt_meeting_" + tableName;

	// 拼接 SQL 语句
	string sql = "SELECT \
                    MEETING_XID, " + rowName + ", xorderColumn \
                  FROM \
                    " + tableName + " \
                  WHERE MEETING_XID = ?";

	CurrentListMapper mapper;

	// 使用参数化查询来绑定 `meetingId`
	auto res = sqlSession->executeQuery<CurrentListDO, CurrentListMapper>(sql, mapper, "%s", meetingId);

	return res;
}
RoomDO MeetingDAO::selectRoomByRoomId(const string& roomId)
{
	string sql = "SELECT \
					xbuilding, xname \
				  FROM \
					mt_room \
				  WHERE \
					xid = ?";
	RoomMapper mapper;
	auto res = sqlSession->executeQuery<RoomDO, RoomMapper>(sql, mapper, "%s", roomId);
	return res.front();
}

BuildingDO MeetingDAO::selectBuildingByBuildingId(const string& buildingId)
{
	string sql = "SELECT \
					xid, xname \
				  FROM \
					mt_building \
				  WHERE \
					xid = ?";
	BuildingMapper mapper;
	auto res = sqlSession->executeQuery<BuildingDO, BuildingMapper>(sql, mapper, "%s", buildingId);
	return res.front();
}

int MeetingDAO::update(const meetingDO& mtDO)
{
	string sql = "UPDATE \
					`mt_meeting` \
					SET \
						xupdateTime = NOW(), xcompletedTime = ?, xhostPerson = ?, xhostUnit = ?, xpinyin = ?, xpinyinInitial = ?  \
						,xroom = ?, xstartTime = ?, xsubject = ?, xsummary = ?, xtype = ?\
					WHERE \
						xid = ?";
	auto res = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s", mtDO.getCompletedTime(), mtDO.getHostPerson(), mtDO.getHostUnit(),
		mtDO.getPinyin(), mtDO.getPinyinInitial(), mtDO.getRoom(), mtDO.getStartTime(), mtDO.getSubject(), mtDO.getSummary(), mtDO.get_Type(), mtDO.getMeetingId());
	return res;
}

int MeetingDAO::deleteCurrenListById(const string& meetingId, const string& table_fmt)
{
	// 表名转换为小写并拼接
	string tableName = table_fmt;
	for (char& c : tableName) c = tolower(c);
	tableName = "mt_meeting_" + tableName;
	string sql = "DELETE FROM " + tableName + " WHERE MEETING_XID = ? ";
	auto res = sqlSession->executeUpdate(sql, "%s", meetingId);
	return res;
}

uint64_t MeetingDAO::insertCurrenList(const CurrentListDO& curDO,const string& table_fmt)
{
	// 列名
	string rowName = 'x' + table_fmt;

	// 表名转换为小写并拼接
	string tableName = table_fmt;
	for (char& c : tableName) c = tolower(c);
	tableName = "mt_meeting_" + tableName;
	string sql = "INSERT INTO " + tableName + "(MEETING_XID, " + rowName + ", xorderColumn) VALUES (?, ? ,?)";
	auto res = sqlSession->executeInsert(sql, "%s%s%i", curDO.getMeetingId(), curDO.getXlist(), curDO.getOrderColumn());
	return 0;
}
