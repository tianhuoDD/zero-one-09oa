#pragma once
#ifndef _ORGUNIT_SERVICE_
#define _ORGUNIT_SERVICE_
#include <list>
#include "domain/vo/OrgUnitVO.h"
#include "domain/query/OrgUnitQuery.h"
#include "domain/dto/OrgUnitDTO.h"

class OrgUnitService
{
public:
	// 分页查询所有数据
	//OrgUnitPageDTO::Wrapper listAll(const OrgUnitQuery::Wrapper& query);
	//根据name查询
	OrgUnitDTO::Wrapper listOne(const OrgUnitQuery::Wrapper& query);
	// 修改数据
	bool updateData(const OrgUnitDTO::Wrapper& dto);
	
};

#endif // !_ORGUNIT_SERVICE_
