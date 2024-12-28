#pragma once
#ifndef _GROUPMEMBER_SERVICE_
#define _GROUPMEMBER_SERVICE_
#include <list>
#include"domain/dto/GroupMember/GetGroupMemberDTO.h"
#include"domain/query/GroupMember/GroupMemberQuery.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GroupMemberService
{
public:
	// 分页查询所有数据
	GetGroupMemberPageDTO::Wrapper listAll(const GroupMemberQuery::Wrapper& query);
};

#endif // !_GROUPMEMBER_SERVICE_
