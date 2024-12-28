#pragma once
#ifndef _ROLEINFODAO_H_
#define _ROLEINFODAO_H_
#include "BaseDAO.h"
#include "domain/do/OrgManagement/PersonalManagement/org_roleDO.h"
#include "domain/query/OrgManagement/PersonalManagement/RoleInfoQuery.h"
#include <list>
/**
 * 查询角色
 */
class RoleInfoDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const RoleInfoQuery::Wrapper& query);
	// 分页查询数据
	list<org_roleDO> selectWithPage(const RoleInfoQuery::Wrapper& query);
};
#endif // !_ROLEINFODAO_H_