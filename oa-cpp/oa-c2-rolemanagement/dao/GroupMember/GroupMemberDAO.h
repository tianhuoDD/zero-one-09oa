#pragma once
#ifndef _GROUPMEMBER_DAO_
#define _GROUPMEMBER_DAO_
#include "BaseDAO.h"
#include"domain/do/GroupMember/GroupMemberDO.h"
#include "../../domain/query/GroupMember/GroupMemberQuery.h"

/**
 * 示例表数据库操作实现
 */
class GroupMemberDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const GroupMemberQuery::Wrapper& query);
	// 分页查询数据
	list<GroupMemberDO> selectWithPage(const GroupMemberQuery::Wrapper& query);
};
#endif // !_GROUPMEMBER_DAO_