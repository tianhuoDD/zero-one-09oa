#pragma once
#ifndef ORG_PERSON_CONTROLLERLIST	
#define ORG_PERSON_CONTROLLERLIST
#include "../GlobalInclude.h"

class OrgPersonControllerList {
	CC_SYNTHESIZE(string, xcontrollerList, xControllerList);
	CC_SYNTHESIZE(string, PERSON_XID, XPERSON_XID);
	CC_SYNTHESIZE(uint64_t, xorderColumn, xOrderColumn);
public:
	OrgPersonControllerList() {
		xcontrollerList = "";
		PERSON_XID = "";
		xorderColumn = 0;
	}
};

#endif // !ORG_PERSON_CONTROLLERLIST