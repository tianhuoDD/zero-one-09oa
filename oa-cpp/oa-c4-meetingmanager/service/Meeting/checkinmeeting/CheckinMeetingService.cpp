#include "stdafx.h"
#include "CheckinMeetingService.h"
#include "../../../dao/Meeting/checkinmeeting/CheckinMeetingDAO.h"

uint64_t CheckinMeetingService::saveData(const CheckinMeetingDTO::Wrapper& dto)
{
	// ��װDO����
	CheckinMeetingDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		MeetingId, meetingId, XcheckinPersonList, xcheckinPersonList, XorderColumn, xorderColumn)

	// ִ���������
	CheckinMeetingDAO dao;
	return dao.insert(data);
}
