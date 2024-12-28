#pragma once
#ifndef MEETINGDAO_H
#define MEETINGDAO_H
#include "../domain/do/MeetingDO.h"
#include "../domain/dto/Meeting/MeetingDTO.h"
#include "MeetingMapper.h"
#include "BaseDAO.h"
class MeetingDAO : public BaseDAO {
public:
	//新增会议
	uint64_t addMeeting(const MeetingDO& meetingdo);

	//取消会议
	uint64_t celMeeting(const string id);

	//会议冲突检查
	bool checkMeetingTimeConflict(const string start_time, const string end_time, const string room_id);

	//时间转换格式
	static string convertDate(const string& date);

};

//struct MeetingRoom {
//	string xid;
//};

//// 定义一个Mapper类
//class MeetingRoomMapper {
//public:
//	MeetingRoom mapper(ResultSet* res) {
//		MeetingRoom room;
//		room.xid = res->getString("xid"); // 获取xid字段
//		return room;
//	}
//};



#endif