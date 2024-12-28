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
����ֻ��һ�� �������� �ļ���Ϊroom,����Ҫ��ΪRoom��Linux��Сд����
*/
class MeetingDAO : public BaseDAO {
public:
	//ͨ������Id��ѯ������Ϣ
	list<meetingDO>  selectById(const string& meetingId);
	//ͨ������ID��ѯMT_XXXXXX_LIST
	list<CurrentListDO> selectListById(const string& meetingId, string table_fmt);
	//ͨ��������ID�������
	RoomDO selectRoomByRoomId(const string& roomId);
	//ͨ��������ID�������λ��
	BuildingDO selectBuildingByBuildingId(const string& buildingId);
	//ͨ������ID���»��������Ϣ
	int update(const meetingDO& mtDO);
	//ͨ������IDɾ�������Ա�б�
	int deleteCurrenListById(const string& meetingId, const string& table_fmt);
	//ͨ��������id�������Ա�б��в���
	uint64_t insertCurrenList(const CurrentListDO& curDO,const string& table_fmt);
};
#endif // !_MEETING_DAO_
