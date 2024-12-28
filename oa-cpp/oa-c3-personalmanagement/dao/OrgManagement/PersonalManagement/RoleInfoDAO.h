#pragma once
#ifndef _ROLEINFODAO_H_
#define _ROLEINFODAO_H_
#include "BaseDAO.h"
#include "domain/do/OrgManagement/PersonalManagement/org_roleDO.h"
#include "domain/query/OrgManagement/PersonalManagement/RoleInfoQuery.h"
#include <list>
/**
 * ��ѯ��ɫ
 */
class RoleInfoDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const RoleInfoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<org_roleDO> selectWithPage(const RoleInfoQuery::Wrapper& query);
};
#endif // !_ROLEINFODAO_H_