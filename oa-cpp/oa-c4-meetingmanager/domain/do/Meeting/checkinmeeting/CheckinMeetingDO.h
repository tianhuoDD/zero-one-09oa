#pragma once

#ifndef _CHECKINMEETING_DO_
#define _CHECKINMEETING_DO_
#include "../../DoInclude.h"

/**
 * 会议签到表数据库实体类
 */
class CheckinMeetingDO
{
	// 会议ID
	CC_SYNTHESIZE(string, meetingId, MeetingId);
	// 用户名
	CC_SYNTHESIZE(string, xcheckinPersonList, XcheckinPersonList);
	// 排序号
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	
public:
	CheckinMeetingDO() {
		meetingId = "";
		xcheckinPersonList = "";
		xorderColumn = 0;
	}
};

#endif // !_CHECKINMEETING_DO_