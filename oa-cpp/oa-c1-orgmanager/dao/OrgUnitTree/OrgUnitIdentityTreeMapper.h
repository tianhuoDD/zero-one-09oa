#pragma once
#ifndef _ORGUNITIDENTITYTREEMAPPER_H_
#define _ORGUNITIDENTITYTREEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/OrgUnitTree/OrgUnitIdentityTreeDO.h"

class OrgUnitIdentityTreeMapper : public Mapper<OrgUnitIdentityTreeDO>
{
public:
    OrgUnitIdentityTreeDO mapper(ResultSet* resultSet) const override
    {
        OrgUnitIdentityTreeDO data;
        data.setXid(resultSet->getString(1));
        data.setXname(resultSet->getString(2));
        data.setXunique(resultSet->getString(3));
        data.setXunit(resultSet->getString(4));
        return data;
    }
};

#endif // !_ORGUNITIDENTITYTREEMAPPER_H_
