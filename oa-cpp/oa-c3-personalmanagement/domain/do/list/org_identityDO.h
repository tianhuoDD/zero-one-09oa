#pragma once
#ifndef _ORG_IDENTITYDO_
#define _ORG_IDENTITYDO_
#include "../DoInclude.h"

class org_identityDO
{
	// 身份名称
	CC_SYNTHESIZE(string, xname, Xname);
	//所在组织
	CC_SYNTHESIZE(string, xunitName, XunitName);
	//唯一编号
	CC_SYNTHESIZE(string, xid, Xid);
	// 担任职务
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	// 主身份
	CC_SYNTHESIZE(bool, xmajor, Xmajor);
public:
	org_identityDO() {
		
		xunitName = "";
		xname = "";
		xid = "";
		xdistinguishedName = "";
		xmajor = 0;
	}
};


#endif // !_ORG_UNITDO_
