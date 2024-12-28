#pragma once

#ifndef _ORGDUTY_DAO_
#define _ORGDUTY_DAO_
#include "BaseDAO.h"
#include "../domain/do/OrgDutyDO.h"

class OrgDutyDAO : public BaseDAO
{
public:
	// 插入数据
	string insert(const OrgDutyDO& iObj);
	// 修改数据
	int update(const OrgDutyDO& uObj);
};
#endif