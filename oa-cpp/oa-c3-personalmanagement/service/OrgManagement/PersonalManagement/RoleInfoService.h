#pragma once
#ifndef _ROLEINFOSERVICE_H_
#define _ROLEINFOSERVICE_H_
#include <list>
#include "domain/vo/Orgmanagement/PersonalManagement/RoleInfoVO.h"
#include "domain/query/OrgManagement/PersonalManagement/RoleInfoQuery.h"
#include "domain/dto/OrgManagement/PersonalManagement/RoleInfoDTO.h"


class RoleInfoService
{
public:
	// 分页查询所有数据
	RoleInfoPageDTO::Wrapper listAll(const RoleInfoQuery::Wrapper& query);
};

#endif // !_ROLEINFOSERVICE_H_
