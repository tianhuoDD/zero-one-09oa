#pragma once
#ifndef ORG_PERSON_TOPUNITLISTDO_H
#define ORG_PERSON_TOPUNITLISTDO_H

#include "../DoInclude.h"

class org_person_topunitlist {
	CC_SYNTHESIZE(string, PERSON_XID, XPERSON_XID);
	CC_SYNTHESIZE(string, xtopUnitList, XtopUnitList);
	CC_SYNTHESIZE(uint64_t, xorderColumn, XorderColumn);
public:
	org_person_topunitlist() {
		PERSON_XID = "";
		xtopUnitList = "";
		xorderColumn = 0;
	}
};
#endif // ORG_PERSON_TOPUNITLISTDO_H