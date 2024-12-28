#pragma once
#ifndef _ORGUNITDUTYTREEMAPPER_H_
#define _ORGUNITDUTYTREEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/OrgUnitTree/OrgUnitDutyTreeDO.h"

class OrgUnitDutyTreeMapper : public Mapper<OrgUnitDutyTreeDO> {
public:
    OrgUnitDutyTreeDO mapper(ResultSet* resultSet) const override {
        OrgUnitDutyTreeDO data;
        data.setXid(resultSet->getString(1));
        data.setXname(resultSet->getString(2));
        data.setXunique(resultSet->getString(3));
        data.setXunit(resultSet->getString(4));
        return data;
    }
};

#endif // !_ORGUNITDUTYTREEMAPPER_H_
