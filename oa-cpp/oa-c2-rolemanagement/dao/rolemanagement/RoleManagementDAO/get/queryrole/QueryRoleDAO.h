#pragma once
#ifndef _ROLELIST_DAO_
#define _ROLELIST_DAO_
#include "BaseDAO.h"
//#include "domain/do/rolemanagement/RoleManagementDO/get/queryrole/QueryRoleDO.h"
#include"domain/do/put/org_role/OrgRoleDO.h"
#include "domain/query/get/queryrole/QueryRoleQuery.h"

class QueryRoleDAO : public BaseDAO {
public:
	// ͳ����������
	uint64_t count(const QueryRoleQuery::Wrapper& query);
	// ����+��ҳ ��ѯ����
	list<OrgRoleDO> selectWithPage(const QueryRoleQuery::Wrapper& query);
};


#endif // !_ROLELIST_DAO_
