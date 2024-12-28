#pragma once
#ifndef _PROCESSCONTROLLER_DO_
#define _PROCESSCONTROLLER_DO_
#include "../DoInclude.h"

class ProcessControllerDO {
	CC_SYNTHESIZE(string, PROCESS_XID, PROCESS_XID);
	CC_SYNTHESIZE(string, xcontrollerList, XcontrollerList);
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
public:
	ProcessControllerDO() {
		this->PROCESS_XID = "";
		this->xcontrollerList = "";
		this->xorderColumn = 0;
		}
};

#endif // !_PROCESSCONTROLLER_DO_