#pragma once
#ifndef _CAL_CALENDAR_PUBLISHABLEPERSONLISTDO_H_
#define _CAL_CALENDAR_PUBLISHABLEPERSONLISTDO_H_

#include "../../GlobalInclude.h"

class cal_calendar_publishablepersonlistDO {
	//	����id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	//	���½���Χ�����Ա�б�
	CC_SYNTHESIZE(string, xpublishablePersonList, Filed);
	// ���˳��
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);
public:
	cal_calendar_publishablepersonlistDO() {
		calender_xid = "0";
		xpublishablePersonList = "xadmin";
		xorderColumn = 0;
	}
};

#endif // !_CAL_CALENDAR_PUBLISHABLEPERSONLISTDO_H_
