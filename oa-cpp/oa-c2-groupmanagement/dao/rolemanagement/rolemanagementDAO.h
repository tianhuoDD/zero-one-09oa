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
 * ���ݿ����ʵ��
 */
class rolemanagementDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t countG(const GetGroupMembersQuery::Wrapper& query);
	// ��ȡȺ���Ա
	list<OrgGroupGrouplistDO> selectWithPage(const GetGroupMembersQuery::Wrapper& query);
	// ͳ����������
	uint64_t countO(const GetOrganizationMembersQuery::Wrapper& query);
	//��ȡ��֯��Ա
	list<OrgGroupUnitlistDO> selectWithPage(const GetOrganizationMembersQuery::Wrapper& query);
	// ��������
	uint64_t insert(const OrgGroupIdentitylistDO& iObj);
	// ͨ��groupxidɾ������
	int deleteById(string groupxid);
};
#endif // !_SAMPLE_DAO_
