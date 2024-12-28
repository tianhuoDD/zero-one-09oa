#pragma once
#ifndef _ORGUNIT_DAO_
#define _ORGUNIT_DAO_
#include "BaseDAO.h"
#include "../domain/do/OrgUnitDO.h"
#include "../domain/query/OrgUnitQuery.h"

class OrgUnitDAO : public BaseDAO
{
public:
	// 统计数据条数
	//uint64_t count(const OrgUnitQuery::Wrapper& query);
	// 分页查询数据
	//list<OrgUnitDO> selectWithPage(const OrgUnitQuery::Wrapper& query);
	// 通过组织名称查询数据
	list<OrgUnitDO> selectByName(const string& unit_xname);
	// 修改数据
	int update(const OrgUnitDO& uObj);
};
#endif // !_ORGUNIT_DAO_