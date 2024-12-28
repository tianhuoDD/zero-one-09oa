#pragma once
#ifndef _CAL_CALENDAR_FOLLOWERSDO_H_
#define _CAL_CALENDAR_FOLLOWERSDO_H_

#include "../../GlobalInclude.h"

class cal_calendar_followersDO {
	//	日历id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	//	关注者名称id
	CC_SYNTHESIZE(string, xfollowersId, XfollowersId);
	//  优先级
	CC_SYNTHESIZE(int8_t, xorderColumn, XorderColumn);
public:
	cal_calendar_followersDO() {
		calender_xid = "";
		xfollowersId = "";
		xorderColumn = 0;
	}
};

#endif // !_CAL_CALENDAR_FOLLOWERSDO_H_
