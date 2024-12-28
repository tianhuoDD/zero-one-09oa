#pragma once

#ifndef _ORGRESROLEMENUDO_H_
#define _ORGRESROLEMENUDO_H_

#include "../../DoInclude.h"

class OrgResRoleMenuDO
{
	// ��ɫid
	CC_SYNTHESIZE(string, role_id, Role_id);
	// ��Դ�˵�id
	CC_SYNTHESIZE(string, menuList, MenuList);
	// ���
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
