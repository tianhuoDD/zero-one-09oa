#pragma once
#ifndef _CAL_EVENT_REPM_MANAGEABLEPERSONLIST_DO_
#define _CAL_EVENT_REPM_MANAGEABLEPERSONLIST_DO_
#include "../../GlobalInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class cal_event_repm_manageablepersonlistDO
{
	// �ظ��ճ�id
	CC_SYNTHESIZE(string, CALENDAR_EVENTREPEATMASTER_XID, XCALENDAR_EVENTREPEATMASTER_XID);
	// �����˱�
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