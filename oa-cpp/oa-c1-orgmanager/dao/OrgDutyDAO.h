#pragma once

#ifndef _ORGDUTY_DAO_
#define _ORGDUTY_DAO_
#include "BaseDAO.h"
#include "../domain/do/OrgDutyDO.h"

class OrgDutyDAO : public BaseDAO
{
public:
	// ��������
	string insert(const OrgDutyDO& iObj);
	// �޸�����
	int update(const OrgDutyDO& uObj);
};
#endif