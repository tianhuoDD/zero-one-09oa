#pragma once

#ifndef _CAL_CALENDAR_VIEWABLEPERSONLIST_DO_
#define _CAL_CALENDAR_VIEWABLEPERSONLIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
// */
class cal_calendar_viewablepersonlistDO  //�ɼ���Χ�ĸ������ݱ�
{
	// ����id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	// ���½���Χ��ĸ����б�
	CC_SYNTHESIZE(string, xviewablepersonlist, Filed);
	// ���˳��
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);
public:
	cal_calendar_viewablepersonlistDO() {
		calender_xid = "0";
		xviewablepersonlist = "";
		xorderColumn = 0;
	};
};

#endif //!_CAL_CALENDAR_VIEWABLEPERSONLIST_DO_