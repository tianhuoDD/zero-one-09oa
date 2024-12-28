#pragma once
#ifndef _ORG_UNITDUTY_IDENTITYLISTDO_H_
#define _ORG_UNITDUTY_IDENTITYLISTDO_H_
#include "../../DoInclude.h"

/**
 * 职务-身份数据库实体类
 */
class org_unitduty_identitylistDO
{
	//职务主码
	CC_SYNTHESIZE(string, UNITDUTY_XID, UNITDUTY_XID);
	//身份主码
	CC_SYNTHESIZE(string, xidentityList, XidentityList);
	//
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
public:
	org_unitduty_identitylistDO() {
		UNITDUTY_XID = "";
		xidentityList = "";
		xorderColumn = 0;
	}
};

#endif // !_ORG_UNITDUTY_IDENTITYLISTDO_H_
