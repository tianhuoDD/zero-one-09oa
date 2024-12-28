#pragma once
#ifndef _rolemanagement_SERVICE_
#define _rolemanagement_SERVICE_
#include <list>
//#include "domain/vo/"
#include "domain/query/get/GetGroupMembers/GetGroupMembersQuery.h"
#include "domain/query/get/GetOrganizationMembers/GetOrganizationMembersQuery.h"
#include "domain/dto/put/AddOrRemoveIdentityMembers/AddOrRemoveIdentityMembersDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class rolemanagementService
{
public:
	// 分页查询所有数据
	GetGroupMembersPageQuery::Wrapper listAllG(const GetGroupMembersQuery::Wrapper& query);
	// 分页查询所有数据
	GetOrganizationMembersPageQuery::Wrapper listAllO(const GetOrganizationMembersQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const AddOrRemoveIdentityMembersDTO::Wrapper& dto);
	// 通过groupxid删除数据
	bool removeData(string groupxid);
};

#endif // !_rolemanagement_SERVICE_

