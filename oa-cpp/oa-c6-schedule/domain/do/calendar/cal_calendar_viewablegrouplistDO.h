#pragma once
#ifndef _CAL_CALENDAR_VIEWABLEGROUPLISTDO_H_
#define _CAL_CALENDAR_VIEWABLEGROUPLISTDO_H_

#include "../../GlobalInclude.h"

class cal_calendar_viewablegrouplistDO {
	//	����id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	//	�ɼ���Χ�ڵ���֯����
	CC_SYNTHESIZE(string, xviewableGroupList, Filed);
	// ���˳��
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);
public:
	cal_calendar_viewablegrouplistDO() {
		calender_xid = "";
		xviewableGroupList = "";
		xorderColumn = 0;
	}
};

#endif // !_CAL_CALENDAR_VIEWABLEGROUPLISTDO_H_
