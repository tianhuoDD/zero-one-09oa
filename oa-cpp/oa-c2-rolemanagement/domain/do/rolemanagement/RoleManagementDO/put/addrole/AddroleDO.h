#pragma once
#ifndef _ADDROLE_DO_
#define _ADDROLE_DO_
#include "../../../../DoInclude.h"
#include "../../../../../GlobalInclude.h"

class AddroleDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(string, xdistributeFactor, XdistributeFactor);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);
	CC_SYNTHESIZE(string, xunique, Xunique);
public:
	AddroleDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = "";
		xdescription = "";
		xdistinguishedName = "";
		xname = "";
		xorderNumber = 0;
		xpinyin = "";
		xpinyinInitial = "";
		xunique = "";
	}
};


#endif // !_ADDROLE_DO_
