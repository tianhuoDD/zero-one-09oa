//
// Created by asd on 2024/10/26.
//

#ifndef ORGUNITNAMEMAPPER_H
#define ORGUNITNAMEMAPPER_H
#include <Mapper.h>

#include "../../domain/do/groupmanagement/OrgUnitDO.h"

class OrgUnitNameMapper : public Mapper<OrgUnitDO> {
public:
	OrgUnitDO mapper(ResultSet* resultSet) const override{
		OrgUnitDO data;
		data.setxid(resultSet->getString(1));
		data.setxname(resultSet->getString(2));
		data.setxlevelName(resultSet->getString(3));

		return data;
	}
};

#endif //ORGGROUPNAMEMAPPER_H
