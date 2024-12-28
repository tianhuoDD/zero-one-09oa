#pragma once

#ifndef _ORGRESROLEMENUDO_H_
#define _ORGRESROLEMENUDO_H_

#include "../../DoInclude.h"

class OrgResRoleMenuDO
{
	// 角色id
	CC_SYNTHESIZE(string, role_id, Role_id);
	// 资源菜单id
	CC_SYNTHESIZE(string, menuList, MenuList);
	// 序号
	CC_SYNTHESIZE(uint64_t, xorderColumn, XorderColumn);

public:
	OrgResRoleMenuDO(){}
	OrgResRoleMenuDO(string role_id, string menuList, uint64_t xorderColumn)
	{
		this->role_id = role_id;
		this->menuList = menuList;
		this->xorderColumn = xorderColumn;
	}

};



#endif // !_ORGRESROLEMENUDO_H_
