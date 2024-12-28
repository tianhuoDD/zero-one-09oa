#pragma once
#ifndef _ROLELIST_DAO_
#define _ROLELIST_DAO_
#include "BaseDAO.h"
//#include "domain/do/rolemanagement/RoleManagementDO/get/queryrole/QueryRoleDO.h"
#include"domain/do/put/org_role/OrgRoleDO.h"
#include "domain/query/get/queryrole/QueryRoleQuery.h"

class QueryRoleDAO : public BaseDAO {
public:
	// 统计数据条数
	uint64_t count(const QueryRoleQuery::Wrapper& query);
	// 条件+分页 查询数据
	list<OrgRoleDO> selectWithPage(const QueryRoleQuery::Wrapper& query);
};


#endif // !_ROLELIST_DAO_
