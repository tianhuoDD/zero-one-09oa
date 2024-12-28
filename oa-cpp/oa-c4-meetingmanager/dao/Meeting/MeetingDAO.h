#pragma once
#ifndef _MEETING_DAO_
#define _MEETING_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Meeting/MeetingDO.h"
#include "../../dao/Meeting/MeetingMapper.h"
#include "dao/Meeting/CurrentListMapper.h"
#include "../../domain/do/CurrentList/CurrentList.h"
#include "../../domain/do/Building/BuildingDO.h"
#include "../../domain/do/room-new/RoomDO.h"
#include "dao/Meeting/BuildingMaper.h"
#include "dao/Meeting/RoomMapper.h"

/*
问题只是一个 ——》》 文件名为room,这里要求为Room，Linux大小写敏感
*/
class MeetingDAO : public BaseDAO {
public:
	//通过会议Id查询会议信息
	list<meetingDO>  selectById(const string& meetingId);
	//通过会议ID查询MT_XXXXXX_LIST
	list<CurrentListDO> selectListById(const string& meetingId, string table_fmt);
	//通过会议室ID查会议室
	RoomDO selectRoomByRoomId(const string& roomId);
	//通过会议室ID查会议室位置
	BuildingDO selectBuildingByBuildingId(const string& buildingId);
	//通过会议ID更新会议相关信息
	int update(const meetingDO& mtDO);
	//通过会议ID删除相关人员列表
	int deleteCurrenListById(const string& meetingId, const string& table_fmt);
	//通过会议室id向相关人员列表中插入
	uint64_t insertCurrenList(const CurrentListDO& curDO,const string& table_fmt);
};
#endif // !_MEETING_DAO_
