#pragma once
#ifndef _ORGGROUPLISTDO_H_
#define _ORGGROUPLISTDO_H_


#include "../../DoInclude.h"


class OrgGroupListDO
{
public:
	
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 群组列表
	CC_SYNTHESIZE(string, groupList, GroupList);
	// 列数
	CC_SYNTHESIZE(int, orderColumn, OrderColumn);
public:
	OrgGroupListDO() {
		id = "";
		groupList = "";
		orderColumn = -1;
	}

};

#endif // !_ORGGROUPLISTDO_H_