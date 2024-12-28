#pragma once
#ifndef _CAL_CALENDAR_PUBLISHABLEPERSONLISTDO_H_
#define _CAL_CALENDAR_PUBLISHABLEPERSONLISTDO_H_

#include "../../GlobalInclude.h"

class cal_calendar_publishablepersonlistDO {
	//	日历id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	//	可新建范围里的人员列表
	CC_SYNTHESIZE(string, xpublishablePersonList, Filed);
	// 添加顺序
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);
public:
	cal_calendar_publishablepersonlistDO() {
		calender_xid = "0";
		xpublishablePersonList = "xadmin";
		xorderColumn = 0;
	}
};

#endif // !_CAL_CALENDAR_PUBLISHABLEPERSONLISTDO_H_
