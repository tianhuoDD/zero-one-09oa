#pragma once
#ifndef _ORGUNITTREEDAO_H_
#define _ORGUNITTREEDAO_H_

#include "BaseDAO.h"
#include "../../domain/do/OrgUnitTree/OrgUnitTreeDO.h"
#include "../../domain/do/OrgUnitTree/OrgUnitIdentityTreeDO.h"
#include "../../domain/do/OrgUnitTree/OrgUnitDutyTreeDO.h"

class OrgUnitTreeDAO : public BaseDAO {
public:
    list<OrgUnitTreeDO> selectAllOrgUnitTree();
    map<string, list<OrgUnitIdentityTreeDO>> selectAllOrgUnitIdentities();
    map<string, list<OrgUnitDutyTreeDO>> selectAllOrgUnitDuties();
};

#endif // !_ORGUNITTREEDAO_H_
