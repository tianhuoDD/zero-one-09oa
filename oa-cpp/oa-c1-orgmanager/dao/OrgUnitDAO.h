#pragma once
#ifndef _ORGUNIT_DAO_
#define _ORGUNIT_DAO_
#include "BaseDAO.h"
#include "../domain/do/OrgUnitDO.h"
#include "../domain/query/OrgUnitQuery.h"

class OrgUnitDAO : public BaseDAO
{
public:
	// ͳ����������
	//uint64_t count(const OrgUnitQuery::Wrapper& query);
	// ��ҳ��ѯ����
	//list<OrgUnitDO> selectWithPage(const OrgUnitQuery::Wrapper& query);
	// ͨ����֯���Ʋ�ѯ����
	list<OrgUnitDO> selectByName(const string& unit_xname);
	// �޸�����
	int update(const OrgUnitDO& uObj);
};
#endif // !_ORGUNIT_DAO_