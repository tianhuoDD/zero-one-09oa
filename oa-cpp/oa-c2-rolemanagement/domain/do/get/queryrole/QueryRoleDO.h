#pragma once
#ifndef _ROLELIST_DO_
#define _ROLELIST_DO_
#include "../../DoInclude.h"

/**
*  角色名称数据库实体类
*/
class QueryRoleDO {
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
public:
	QueryRoleDO() {
		id = 0;
		name = "";
	}
};

#endif // !_ROLELIST_DO_
