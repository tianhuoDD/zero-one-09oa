#pragma once

#ifndef _CHECKINMEETING_DO_
#define _CHECKINMEETING_DO_
#include "../../DoInclude.h"

/**
 * ����ǩ�������ݿ�ʵ����
 */
class CheckinMeetingDO
{
	// ����ID
	CC_SYNTHESIZE(string, meetingId, MeetingId);
	// �û���
	CC_SYNTHESIZE(string, xcheckinPersonList, XcheckinPersonList);
	// �����
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	
public:
	CheckinMeetingDO() {
		meetingId = "";
		xcheckinPersonList = "";
		xorderColumn = 0;
	}
};

#endif // !_CHECKINMEETING_DO_