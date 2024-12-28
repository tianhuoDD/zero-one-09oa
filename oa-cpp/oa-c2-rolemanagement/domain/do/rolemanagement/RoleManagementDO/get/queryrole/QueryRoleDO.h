#pragma once
#ifndef _ROLELIST_DO_
#define _ROLELIST_DO_
#include "../../../../DoInclude.h"

/**
*  角色名称数据库实体类
*/
class OrgRoleNameDO {
	// 角色Id
	CC_SYNTHESIZE(string, xid, Xid);
	// 角色名称
	CC_SYNTHESIZE(string, xname, Xname);
public:
	OrgRoleNameDO() {
		xid = "0";
		xname = "";
	}
};

#endif // !_ROLELIST_DO_
