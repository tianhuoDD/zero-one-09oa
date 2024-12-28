#pragma once

#ifndef _CHECKINMEETING_SERVICE_
#define _CHECKINMEETING_SERVICE_
#include <list>

#include "domain/dto/Meeting/checkinmeeting/CheckinMeetingDTO.h"

/**
 * 会议签到服务实现
 */
class CheckinMeetingService
{
public:
	// 保存数据
	uint64_t saveData(const CheckinMeetingDTO::Wrapper& dto);
};

#endif // !_CHECKINMEETING_SERVICE_