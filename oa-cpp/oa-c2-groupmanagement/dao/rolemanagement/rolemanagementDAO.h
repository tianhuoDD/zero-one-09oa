#pragma once

#ifndef _rolemanagement_DAO_
#define _rolemanagement_DAO_
#include "BaseDAO.h"
#include "../../domain/do/get/OrgGroupGrouplist/OrgGroupGrouplistDO.h"
#include "../../domain/do/get/OrgGroupUnitlist/OrgGroupUnitlistDO.h"
#include "../../domain/do/put/OrgGroupIdentitylist/OrgGroupIdentitylistDO.h"
#include "../../domain/query/get/GetGroupMembers/GetGroupMembersQuery.h"
#include "../../domain/query/get/GetOrganizationMembers/GetOrganizationMembersQuery.h"

/**
 * 数据库操作实现
 */
class rolemanagementDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t countG(const GetGroupMembersQuery::Wrapper& query);
	// 获取群组成员
	list<OrgGroupGrouplistDO> selectWithPage(const GetGroupMembersQuery::Wrapper& query);
	// 统计数据条数
	uint64_t countO(const GetOrganizationMembersQuery::Wrapper& query);
	//获取组织成员
	list<OrgGroupUnitlistDO> selectWithPage(const GetOrganizationMembersQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const OrgGroupIdentitylistDO& iObj);
	// 通过groupxid删除数据
	int deleteById(string groupxid);
};
#endif // !_SAMPLE_DAO_
