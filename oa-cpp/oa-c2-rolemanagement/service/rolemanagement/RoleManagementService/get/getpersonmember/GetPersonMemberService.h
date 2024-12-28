#pragma once
#ifndef _GETPERSONMEMBER_SERVICE_
#define _GETPERSONMEMBER_SERVICE_
#include <list>
#include"domain/query/get/getpersonmember/GetPersonMemberQuery.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/get/getpersonmember/GetPersonMemberDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GetPersonMemberService
{
public:
	// 分页查询所有数据
	GetPersonMemberPageDTO::Wrapper listAll(const GetPersonMemberQuery::Wrapper& query);
};

#endif // !_GETPERSONMEMBER_SERVICE_