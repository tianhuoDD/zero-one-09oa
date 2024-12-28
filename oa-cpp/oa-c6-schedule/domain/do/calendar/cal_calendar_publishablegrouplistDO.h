#pragma once

#ifndef _CAL_CALENDAR_PUBLISHBLEGROUPLIST_DO_
#define _CAL_CALENDAR_PUBLISHBLEGROUPLIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
// */
class cal_calendar_publishablegrouplistDO  //可新建范围的群组数据表
{
	// 日历id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	// 可新建范围里的群组列表
	CC_SYNTHESIZE(string, xpublishablegrouplist, Filed);
	// 添加顺序
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);
public:
	cal_calendar_publishablegrouplistDO() {
		calender_xid = "0";
		xpublishablegrouplist = "";
		xorderColumn = 0;
	};
};

#endif //!_CAL_CALENDAR_PUBLISHBLEGROUPLIST_DO_
