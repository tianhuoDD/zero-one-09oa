#pragma once
#ifndef _ROLELIST_DO_
#define _ROLELIST_DO_
#include "../../../../DoInclude.h"

/**
*  ��ɫ�������ݿ�ʵ����
*/
class OrgRoleNameDO {
	// ��ɫId
	CC_SYNTHESIZE(string, xid, Xid);
	// ��ɫ����
	CC_SYNTHESIZE(string, xname, Xname);
public:
	OrgRoleNameDO() {
		xid = "0";
		xname = "";
	}
};

#endif // !_ROLELIST_DO_
