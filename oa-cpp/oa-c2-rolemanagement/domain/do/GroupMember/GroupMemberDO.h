#pragma once
#ifndef _GROUPMEMBER_DO_
#define _GROUPMEMBER_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class GroupMemberDO
{
	// 群组名称
	CC_SYNTHESIZE(string, groupname, Groupname);
	// 群组全称
	CC_SYNTHESIZE(string, groupnameA, GroupnameA);
	// 群组描述
	CC_SYNTHESIZE(string, groupdes, Groupdes);;
public:
	GroupMemberDO() {
		groupname = "群组名称";
		groupnameA = "群组全称";
		groupdes = "群组描述";
	}
};

#endif // !_GROUPMEMBER_DO_