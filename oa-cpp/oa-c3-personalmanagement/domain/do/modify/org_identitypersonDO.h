#pragma once
#ifndef _ORG_IDENTITYDO_
#define _ORG_IDENTITYDO_
#include "../DoInclude.h"

class org_identitypersonDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, xid, Xid);
	// �������
	CC_SYNTHESIZE(string, xname, Xname);

	// �����
	CC_SYNTHESIZE(bool, xmajor, Xmajor);
public:
	org_identitypersonDO() {
		xid = "";
		xname = "";
		xmajor = 0;
	}
};


#endif // !_ORG_UNITDO_
