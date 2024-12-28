#pragma once
#ifndef MEETINGDAO_H
#define MEETINGDAO_H
#include "../domain/do/MeetingDO.h"
#include "../domain/dto/Meeting/MeetingDTO.h"
#include "MeetingMapper.h"
#include "BaseDAO.h"
class MeetingDAO : public BaseDAO {
public:
	//��������
	uint64_t addMeeting(const MeetingDO& meetingdo);

	//ȡ������
	uint64_t celMeeting(const string id);

	//�����ͻ���
	bool checkMeetingTimeConflict(const string start_time, const string end_time, const string room_id);

	//ʱ��ת����ʽ
	static string convertDate(const string& date);

};

//struct MeetingRoom {
//	string xid;
//};

//// ����һ��Mapper��
//class MeetingRoomMapper {
//public:
//	MeetingRoom mapper(ResultSet* res) {
//		MeetingRoom room;
//		room.xid = res->getString("xid"); // ��ȡxid�ֶ�
//		return room;
//	}
//};



#endif