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
	//ͨ��ID��ѯ������Ϣ
	MeetingInfoVO::Wrapper queryMeetingInfoById(const oatpp::String& meetingId);
	//�޸Ļ�����Ϣ
	bool modifyMeetingInfo(const MeetingInfo::Wrapper& meetingInfo);
	//�޸�����
	
};
#endif // !_MEETING_SERVICE_
