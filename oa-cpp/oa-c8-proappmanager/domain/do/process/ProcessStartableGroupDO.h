#pragma once
#ifndef _PROCESSSTARTABLEGROUP_DO_
#define _PROCESSSTARTABLEGROUP_DO_
#include "../DoInclude.h"

class ProcessStartableGroupDO {
	CC_SYNTHESIZE(string, PROCESS_XID, PROCESS_XID);
	CC_SYNTHESIZE(string, xstartableGroupList, XstartableGroupList);
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
public:
	ProcessStartableGroupDO() {
		this->PROCESS_XID = "";
		this->xstartableGroupList = "";
		this->xorderColumn = 0;
		}
};

#endif // !_PROCESSSTARTABLEGROUP_DO_