#pragma once
#ifndef _PROCESSSTARTABLEIDENTITY_DO_
#define _PROCESSSTARTABLEIDENTITY_DO_
#include "../DoInclude.h"

class ProcessStartableIdentityDO {
	CC_SYNTHESIZE(string, PROCESS_XID, PROCESS_XID);
	CC_SYNTHESIZE(string, xstartableIdentityList, XstartableIdentityList);
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
public:
	ProcessStartableIdentityDO() {
		this->PROCESS_XID = "";
		this->xstartableIdentityList = "";
		this->xorderColumn = 0;
		}
};

#endif // !_PROCESSSTARTABLEIDENTITY_DO_