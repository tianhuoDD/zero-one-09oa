#pragma once

#ifndef _CAL_CALENDAR_MANAGEABLEPERSONLISTDO_H_
#define _CAL_CALENDAR_MANAGEABLEPERSONLISTDO_H_

#include "../../GlobalInclude.h"

class cal_calendar_manageablepersonlistDO {
	//	���������id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	//	����������
	CC_SYNTHESIZE(string, xmanageablePersonList, Filed);
	// ���˳��
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);

public:
	cal_calendar_manageablepersonlistDO() {
		calender_xid = "";
		xmanageablePersonList = "xadmin";
		xorderColumn = 0;
	}
};
#endif // !_CAL_CALENDAR_MANAGEABLEPERSONLISTDO_H_
