#pragma once
#ifndef _ORG_IDENTITYDO_
#define _ORG_IDENTITYDO_
#include "../DoInclude.h"

class org_identityDO
{
	// �������
	CC_SYNTHESIZE(string, xname, Xname);
	//������֯
	CC_SYNTHESIZE(string, xunitName, XunitName);
	//Ψһ���
	CC_SYNTHESIZE(string, xid, Xid);
	// ����ְ��
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	// �����
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
