#pragma once

#ifndef _CAL_EVENT_REPM_PARTICIPANTSDO_H_
#define _CAL_EVENT_REPM_PARTICIPANTSDO_H_

#include "../../GlobalInclude.h"

class cal_event_repm_participantsDO {
	//	»’÷æid
	CC_SYNTHESIZE(string,calendar_eventrepeatmaster_xid, Calendar_eventrepeatmaster_xid);
	//	
	CC_SYNTHESIZE(string, xparticipants, xParticipants);
	//
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);


public:
	cal_event_repm_participantsDO() {
		calendar_eventrepeatmaster_xid = "";
		xparticipants = "xadmin";
		xorderColumn = 0;
	}
};
#endif // !_CAL_EVENT_REPM_PARTICIPANTSDO_H_
