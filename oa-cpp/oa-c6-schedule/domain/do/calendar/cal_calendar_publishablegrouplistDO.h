#pragma once

#ifndef _CAL_CALENDAR_PUBLISHBLEGROUPLIST_DO_
#define _CAL_CALENDAR_PUBLISHBLEGROUPLIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
// */
class cal_calendar_publishablegrouplistDO  //���½���Χ��Ⱥ�����ݱ�
{
	// ����id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	// ���½���Χ���Ⱥ���б�
	CC_SYNTHESIZE(string, xpublishablegrouplist, Filed);
	// ���˳��
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);
public:
	cal_calendar_publishablegrouplistDO() {
		calender_xid = "0";
		xpublishablegrouplist = "";
		xorderColumn = 0;
	};
};

#endif //!_CAL_CALENDAR_PUBLISHBLEGROUPLIST_DO_
