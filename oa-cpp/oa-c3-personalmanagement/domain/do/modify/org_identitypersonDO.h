#pragma once
#ifndef _ORG_IDENTITYDO_
#define _ORG_IDENTITYDO_
#include "../DoInclude.h"

class org_identitypersonDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, xid, Xid);
	// 身份名称
	CC_SYNTHESIZE(string, xname, Xname);

	// 主身份
	CC_SYNTHESIZE(bool, xmajor, Xmajor);
public:
	org_identitypersonDO() {
		xid = "";
		xname = "";
		xmajor = 0;
	}
};


#endif // !_ORG_UNITDO_
