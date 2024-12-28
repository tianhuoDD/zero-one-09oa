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
	// ��ҳ��ѯ��������
	//OrgUnitPageDTO::Wrapper listAll(const OrgUnitQuery::Wrapper& query);
	//����name��ѯ
	OrgUnitDTO::Wrapper listOne(const OrgUnitQuery::Wrapper& query);
	// �޸�����
	bool updateData(const OrgUnitDTO::Wrapper& dto);
	
};

#endif // !_ORGUNIT_SERVICE_
