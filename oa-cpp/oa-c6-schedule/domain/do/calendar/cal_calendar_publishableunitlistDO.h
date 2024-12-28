#pragma once

#ifndef _CAL_CALENDAR_PUBLISHABLEUNITLISTDO_H_
#define _CAL_CALENDAR_PUBLISHABLEUNITLISTDO_H_

#include "../../GlobalInclude.h"

class cal_calendar_publishableunitlistDO {
	//	日历id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	//	可新建组织名
	CC_SYNTHESIZE(string, xpublishableUnitList, Filed);
	// 添加顺序
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);
public:
	cal_calendar_publishableunitlistDO() {
		calender_xid = "";
		xpublishableUnitList = "";
		xorderColumn = 0;
	}
};
#endif // !_CAL_CALENDAR_VIEWABLEUNITLISTDO_H_
