#pragma once
#ifndef _SEARCHDUTYDAO_H_
#define _SEARCHDUTYDAO_H_
#include "BaseDAO.h"
#include "domain/do/OrgManagement/PersonalManagement/org_unitdutyDO.h"
#include "domain/do/OrgManagement/PersonalManagement/org_unitDO.h"
#include <list>
/**
 * 查询职务
 */
class SearchDutyDAO : public BaseDAO
{
public:
	//查询职务及所属的公司
	std::list<pair<org_unitdutyDO, org_unitDO>> selectDuty(const oatpp::String& query);
};
#endif // !_SEARCHDUTYDAO_H_