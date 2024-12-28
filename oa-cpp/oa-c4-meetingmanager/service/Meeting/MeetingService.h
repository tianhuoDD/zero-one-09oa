#pragma once
#ifndef _MEETING_SERVICE_
#define _MEETING_SERVICE_
#include"domain/dto/Meeting/MeetingInfoDTO.h"
#include"domain/vo/MeetingInfo/meetingInfoVO.h"
#include"domain/do/Meeting/MeetingDO.h"
#include"dao/Meeting/MeetingDAO.h"
#include"dao/Attachment/AttachmentDAO.h"

class MeetingService {
public:
	//通过ID查询会议信息
	MeetingInfoVO::Wrapper queryMeetingInfoById(const oatpp::String& meetingId);
	//修改会议信息
	bool modifyMeetingInfo(const MeetingInfo::Wrapper& meetingInfo);
	//修改数据
	
};
#endif // !_MEETING_SERVICE_
