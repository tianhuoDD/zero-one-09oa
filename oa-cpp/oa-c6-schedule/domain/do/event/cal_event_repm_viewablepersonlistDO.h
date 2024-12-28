#pragma once

#ifndef _CAL_EVENT_REPM_VIEWABLEPERSONLISTDO_H_
#define _CAL_EVENT_REPM_VIEWABLEPERSONLISTDO_H_

#include "../../GlobalInclude.h"

class cal_event_repm_viewablepersonlistDO {
	//	»’÷æid
	CC_SYNTHESIZE(string, calendar_eventrepeatmaster_xid, Calendar_eventrepeatmaster_xid);
	//	
	CC_SYNTHESIZE(string, xviewablePersonList, xViewablePersonList);
	//
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);


public:
	cal_event_repm_viewablepersonlistDO() {
		calendar_eventrepeatmaster_xid = "";
		xviewablePersonList = "xadmin";
		xorderColumn = 0;
	}
};
#endif // !_CAL_EVENT_REPM_VIEWABLEPERSONLISTDO_H_
