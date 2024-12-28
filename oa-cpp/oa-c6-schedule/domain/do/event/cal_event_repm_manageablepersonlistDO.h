#pragma once
#ifndef _CAL_EVENT_REPM_MANAGEABLEPERSONLIST_DO_
#define _CAL_EVENT_REPM_MANAGEABLEPERSONLIST_DO_
#include "../../GlobalInclude.h"

/**
 * 示例数据库实体类
 */
class cal_event_repm_manageablepersonlistDO
{
	// 重复日程id
	CC_SYNTHESIZE(string, CALENDAR_EVENTREPEATMASTER_XID, XCALENDAR_EVENTREPEATMASTER_XID);
	// 管理人表
	CC_SYNTHESIZE(string, xmanageablePersonList, xManageablePersonList);
	// 
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);

public:
	cal_event_repm_manageablepersonlistDO() {
		CALENDAR_EVENTREPEATMASTER_XID = "";
		xmanageablePersonList = "";
		xorderColumn = 0;
	}
};

#endif // !_CAL_EVENT_REPM_MANAGEABLEPERSONLIST_DO_