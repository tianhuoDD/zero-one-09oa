#pragma once

#ifndef _CAL_EVENT_MANAGEABLEPERSONLISTDO_H_
#define _CAL_EVENT_MANAGEABLEPERSONLISTDO_H_

#include "../../GlobalInclude.h"

class cal_event_manageablepersonlistDO {
	//	日志id
	CC_SYNTHESIZE(string, calendar_event_xid, Calendar_event_xid);
	//	管理者名称
	CC_SYNTHESIZE(string, xmanageablePersonList, xManageablePersonList);
	//
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);


public:
	cal_event_manageablepersonlistDO() {
		calendar_event_xid = "";
		xmanageablePersonList = "xadmin";
		xorderColumn = 0;
	}
};
#endif // !_CAL_EVENT_MANAGEABLEPERSONLISTDO_H_
