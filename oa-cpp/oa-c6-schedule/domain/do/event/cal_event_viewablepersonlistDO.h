#pragma once
#ifndef _CAL_EVENT_VIEWABLEPERSONLIST_DO_
#define _CAL_EVENT_VIEWABLEPERSONLIST_DO_
#include "../../GlobalInclude.h"

/**
 * 示例数据库实体类
 */
class cal_event_viewablepersonlistDO
{
	// 重复日程id
	CC_SYNTHESIZE(string, CALENDAR_EVENTREPEATMASTER_XID, XCALENDAR_EVENTREPEATMASTER_XID);
	// 可见人表
	CC_SYNTHESIZE(string, xviewablePersonList, xViewablePersonList);
	// 
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);

public:
	cal_event_viewablepersonlistDO() {
		CALENDAR_EVENTREPEATMASTER_XID = "";
		xviewablePersonList = "";
		xorderColumn = 0;
	}
};

#endif // !_CAL_EVENT_VIEWABLEPERSONLIST_DO_