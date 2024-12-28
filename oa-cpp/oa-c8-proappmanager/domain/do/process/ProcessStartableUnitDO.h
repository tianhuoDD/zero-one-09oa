#pragma once
#ifndef _PROCESSSTARTABLEUNIT_DO_
#define _PROCESSSTARTABLEUNIT_DO_
#include "../DoInclude.h"

class ProcessStartableUnitDO {
	CC_SYNTHESIZE(string, PROCESS_XID, PROCESS_XID);
	CC_SYNTHESIZE(string, xstartableUnitList, XstartableUnitList);
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
public:
	ProcessStartableUnitDO() {
		this->PROCESS_XID = "";
		this->xstartableUnitList = "";
		this->xorderColumn = 0;
		}
};

#endif // !_PROCESSSTARTABLEUNIT_DO_