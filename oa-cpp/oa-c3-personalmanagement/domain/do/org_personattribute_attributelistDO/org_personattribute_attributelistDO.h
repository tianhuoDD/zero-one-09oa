#pragma once
#ifndef _ORG_PERSONATTRIBUTE_ATTRIBUTELISTDO_
#define _ORG_PERSONATTRIBUTE_ATTRIBUTELISTDO_
#include "../DoInclude.h"

class org_personattribute_attributelistDO {
	CC_SYNTHESIZE(string, PERSONATTRIBUTE_XID, XPERSONATTRIBUTE_XID);
	CC_SYNTHESIZE(string, xattributeList, XattributeList);
	CC_SYNTHESIZE(uint64_t, xorderColumn, XorderColumn);
public:
	org_personattribute_attributelistDO() {
		PERSONATTRIBUTE_XID = "";
		xattributeList = "";
		xorderColumn = 0;
	}
};

#endif // !_ORG_PERSONATTRIBUTE_ATTRIBUTELISTDO_