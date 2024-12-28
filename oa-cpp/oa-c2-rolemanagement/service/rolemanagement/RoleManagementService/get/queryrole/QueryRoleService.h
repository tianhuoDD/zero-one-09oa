#pragma once
#ifndef _ROLELIST_SERVICE_
#define _ROLELIST_SERVICE_
#include <list>
#include "domain/vo/get/queryrole/QueryRoleVO.h"
#include "domain/query/get/queryrole/QueryRoleQuery.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/queryrole/QueryRoleDTO.h"
#include "domain/do/rolemanagement/RoleManagementDO/get/queryrole/QueryRoleDO.h"

/**
*  ��ȡ��ɫ�����б����ʵ��
*/
class QueryRoleService {
public:
	// ��ҳ��ѯ����
	QueryRolePageDTO::Wrapper listAll(const QueryRoleQuery::Wrapper& query);
};

#endif // !_ROLELIST_SERVICE_