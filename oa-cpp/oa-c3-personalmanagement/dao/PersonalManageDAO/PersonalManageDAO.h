#pragma once
#ifndef PERSONALMANAGEDAO
#define PERSONALMANAGEDAO
#include "BaseDAO.h"
//#include "../../domain/do/PersonalManageDO/PersonalManageDO.h"
#include "../../domain/do/org_personDo/org_personDO.h"
class PersonalManageDAO : public BaseDAO {
public:
	org_personDO selectbyxunique(const string& xunique);
	bool update(const org_personDO& uObj);
};

#endif // !PERSONALMANAGEDAO
