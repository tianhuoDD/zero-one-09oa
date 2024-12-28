#pragma once
#ifndef _GETROLE_SERVICE_
#define _GETROLE_SERVICE_
#include <list>
#include"domain/do/get/GetRoleDO.h"
#include"domain/dto/get/GetroleDTO.h"
#include"domain/query/GetRole/GetRoleMemberQuery.h"
#include"dao/get/GetRoleDAO.h"
#include"domain/vo/get/GetroleVO.h"
/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GetRoleService
{
public:
	GetroleVO::Wrapper GetRoleById(const string roleId);
	// 通过name查询群组信息
	//GetroleVO::Wrapper GetRoleByName(const string roleName);
};



#endif // !_GETROLE_SERVICE_