#pragma once
#ifndef _ORGGROUPLISTDO_H_
#define _ORGGROUPLISTDO_H_


#include "../../DoInclude.h"


class OrgGroupListDO
{
public:
	
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// Ⱥ���б�
	CC_SYNTHESIZE(string, groupList, GroupList);
	// ����
	CC_SYNTHESIZE(int, orderColumn, OrderColumn);
public:
	OrgGroupListDO() {
		id = "";
		groupList = "";
		orderColumn = -1;
	}

};

#endif // !_ORGGROUPLISTDO_H_