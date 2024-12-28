#pragma once

#ifndef _CAL_CALENDAR_VIEWABLEPERSONLIST_DO_
#define _CAL_CALENDAR_VIEWABLEPERSONLIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
// */
class cal_calendar_viewablepersonlistDO  //可见范围的个人数据表
{
	// 日历id
	CC_SYNTHESIZE(string, calender_xid, CalenderId);
	// 可新建范围里的个人列表
	CC_SYNTHESIZE(string, xviewablepersonlist, Filed);
	// 添加顺序
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);
public:
	cal_calendar_viewablepersonlistDO() {
		calender_xid = "0";
		xviewablepersonlist = "";
		xorderColumn = 0;
	};
};

#endif //!_CAL_CALENDAR_VIEWABLEPERSONLIST_DO_