#pragma once

#ifndef _CHECKINMEETING_DAO_
#define _CHECKINMEETING_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/Meeting/checkinmeeting/CheckinMeetingDO.h"

/**
 * 会议签到表数据库操作实现
 */
class CheckinMeetingDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const CheckinMeetingDO& iObj);
};

#endif // !_CHECKINMEETING_DAO_