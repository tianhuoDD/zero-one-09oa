#pragma once
#ifndef _CAL_EVENT_REPM_CREATEDMONTHLIST_DO_
#define _CAL_EVENT_REPM_CREATEDMONTHLIST_DO_
#include "../../GlobalInclude.h"

/**
 * 示例数据库实体类
 */
class cal_event_repm_createdmonthlistDO
{
	// 重复日程id
	CC_SYNTHESIZE(string, CALENDAR_EVENTREPEATMASTER_XID, XCALENDAR_EVENTREPEATMASTER_XID);
	// 创建月份
	CC_SYNTHESIZE(string, xcreatedMonthList, xCreatedMonthList);
	// 
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);

public:
	cal_event_repm_createdmonthlistDO() {
		CALENDAR_EVENTREPEATMASTER_XID = "";
		xcreatedMonthList = "";
		xorderColumn = 0;
	}
};

#endif // !_CAL_EVENT_REPM_CREATEDMONTHLIST_DO_