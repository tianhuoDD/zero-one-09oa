#pragma once
#ifndef _rolemanagement_SERVICE_
#define _rolemanagement_SERVICE_
#include <list>
//#include "domain/vo/"
#include "domain/query/get/GetGroupMembers/GetGroupMembersQuery.h"
#include "domain/query/get/GetOrganizationMembers/GetOrganizationMembersQuery.h"
#include "domain/dto/put/AddOrRemoveIdentityMembers/AddOrRemoveIdentityMembersDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class rolemanagementService
{
public:
	// ��ҳ��ѯ��������
	GetGroupMembersPageQuery::Wrapper listAllG(const GetGroupMembersQuery::Wrapper& query);
	// ��ҳ��ѯ��������
	GetOrganizationMembersPageQuery::Wrapper listAllO(const GetOrganizationMembersQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const AddOrRemoveIdentityMembersDTO::Wrapper& dto);
	// ͨ��groupxidɾ������
	bool removeData(string groupxid);
};

#endif // !_rolemanagement_SERVICE_

