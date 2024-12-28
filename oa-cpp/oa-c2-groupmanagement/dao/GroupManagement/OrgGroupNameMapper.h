//
// Created by asd on 2024/10/26.
//

#ifndef ORGGROUPNAMEMAPPER_H
#define ORGGROUPNAMEMAPPER_H
#include <Mapper.h>

#include "../../domain/do/groupmanagement/OrgGroupDO.h"

class OrgGroupNameMapper : public Mapper<OrgGroupDO> {
public:
	OrgGroupDO mapper(ResultSet* resultSet) const override{
        OrgGroupDO data;
		data.setxId(resultSet->getString(1));
		data.setxName(resultSet->getString(2));
		data.setxDistinguishedName(resultSet->getString(3));

		return data;
    }
};

#endif //ORGGROUPNAMEMAPPER_H
