#pragma once

#ifndef _CAL_CALENDAR_VIEWABLEUNITLISTDO_H_
#define _CAL_CALENDAR_VIEWABLEUNITLISTDO_H_

#include "../../GlobalInclude.h"

class cal_calendar_viewableunitlistDO {
	//	����id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	//	�ɼ���֯��
	CC_SYNTHESIZE(string, xviewableUnitList, Filed);
	// ���˳��
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);
public:
	cal_calendar_viewableunitlistDO() {
		calender_xid = "";
		xviewableUnitList = "";
		xorderColumn = 0;
	}
};
#endif // !_CAL_CALENDAR_VIEWABLEUNITLISTDO_H_
