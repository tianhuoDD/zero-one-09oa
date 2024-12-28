#pragma once
#ifndef _ORGUNIT_MAPPER_
#define _ORGUNIT_MAPPER_

#include "Mapper.h"
#include "../domain/do/OrgUnitDO.h"

/**
 * ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class OrgUnitMapper : public Mapper<OrgUnitDO>
{
public:
	OrgUnitDO mapper(ResultSet* resultSet) const override
	{
		OrgUnitDO data;
		data.setXid(resultSet->getString(1));
		data.setUnit_xname(resultSet->getString(2));
		data.setXunique(resultSet->getString(3));
		data.setXtypeList(resultSet->getString(4));
		data.setXshortName(resultSet->getString(5));
		data.setXdescription(resultSet->getString(6));
		data.setPerson_xname(resultSet->getString(7));
		data.setXsuperior(resultSet->getString(8));
		data.setXorderNumber(resultSet->getInt(9));
		return data;
	}
};

#endif // !_ORGUNIT_MAPPER_