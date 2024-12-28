#pragma once
#ifndef _GETPERSONMEMBER_DO_
#define _GETPERSONMEMBER_DO_
#include "domain/do/DoInclude.h"

/**
 * 示例数据库实体类
 */
class GetPersonMemberDO
{
	// 人员工号
	CC_SYNTHESIZE(string, role_xid, ROLE_XID);
	// 分组号
	CC_SYNTHESIZE(string, xgroupList, XgroupList);
	// 顺序
	CC_SYNTHESIZE(uint64_t, xorderColumn, XorderColumn);

public:
	GetPersonMemberDO() {
		role_xid = "";
		xgroupList = "";
		xorderColumn = 0;
	}
};

#endif // !_GETPERSONMEMBER_DO_