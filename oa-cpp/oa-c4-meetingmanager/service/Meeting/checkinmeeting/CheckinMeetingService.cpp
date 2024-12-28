#include "stdafx.h"
#include "CheckinMeetingService.h"
#include "../../../dao/Meeting/checkinmeeting/CheckinMeetingDAO.h"

uint64_t CheckinMeetingService::saveData(const CheckinMeetingDTO::Wrapper& dto)
{
	// 组装DO数据
	CheckinMeetingDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		MeetingId, meetingId, XcheckinPersonList, xcheckinPersonList, XorderColumn, xorderColumn)

	// 执行数据添加
	CheckinMeetingDAO dao;
	return dao.insert(data);
}
