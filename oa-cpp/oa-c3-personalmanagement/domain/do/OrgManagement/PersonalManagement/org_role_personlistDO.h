#pragma once
#ifndef _ORG_ROLE_PERSONLISTDO_H_
#define _ORG_ROLE_PERSONLISTDO_H_
#include "../../DoInclude.h"

/**
 * 职工-角色数据库实体类
 */
class org_role_personlistDO
{
	//角色主码
	CC_SYNTHESIZE(string, ROLE_XID, ROLE_XID);
	//职工主码
	CC_SYNTHESIZE(string, xpersonList, XpersonList);
	//
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
public:
	org_role_personlistDO() {
		ROLE_XID = "";
		xpersonList = "";
		xorderColumn = 0;
	}
};

#endif // !_ORG_IDENTITYDO_H_
