#pragma once
#ifndef _ROLELIST_SERVICE_
#define _ROLELIST_SERVICE_
#include <list>
#include "domain/vo/get/queryrole/QueryRoleVO.h"
#include "domain/query/get/queryrole/QueryRoleQuery.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/queryrole/QueryRoleDTO.h"
#include "domain/do/rolemanagement/RoleManagementDO/get/queryrole/QueryRoleDO.h"

/**
*  获取角色名称列表服务实现
*/
class QueryRoleService {
public:
	// 分页查询数据
	QueryRolePageDTO::Wrapper listAll(const QueryRoleQuery::Wrapper& query);
};

#endif // !_ROLELIST_SERVICE_