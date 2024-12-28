#pragma once

#ifndef _CAL_EVENT_PARTICIPANTSDO_H_
#define _CAL_EVENT_PARTICIPANTSDO_H_

#include "../../GlobalInclude.h"

class cal_event_participantsDO {
	//	»’÷æid
	CC_SYNTHESIZE(string, calendar_event_xid, Calendar_event_xid);
	//	
	CC_SYNTHESIZE(string, xparticipants, xParticipants);
	//
	CC_SYNTHESIZE(int, xorderColumn, xOrderColumn);


public:
	cal_event_participantsDO() {
		calendar_event_xid = "";
		xparticipants = "xadmin";
		xorderColumn = 0;
	}
};
#endif // !_CAL_EVENT_PARTICIPANTSDO_H_
