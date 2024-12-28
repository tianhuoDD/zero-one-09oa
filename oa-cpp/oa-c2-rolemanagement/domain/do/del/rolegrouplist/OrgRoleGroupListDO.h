#pragma once

#ifndef _ORGROLEGROUPLISTDO_H_
#define _ORGROLEGROUPLISTDO_H_

#include "../../DoInclude.h"

class OrgRoleGroupListDO
{
	// 角色xid
	CC_SYNTHESIZE(string, ROLE_XID, ROLE_XID);
	// 群组成员id
	CC_SYNTHESIZE(string, xgroupList, XgroupList);
	// 序号
	CC_SYNTHESIZE(uint64_t, xorderColumn, XorderColumn);

public:
	OrgRoleGroupListDO(){}
	OrgRoleGroupListDO(string role_xid, string xgroupList, uint64_t xorderColumn)
	{
		this->ROLE_XID = role_xid;
		this->xgroupList = xgroupList;
		this->xorderColumn = xorderColumn;
	}
};


#endif // !_ORGROLEGROUPLISTDO_H_
