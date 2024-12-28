#pragma once
#ifndef _CONFIGURATIONMAPPER_
#define _CONFIGURATIONMAPPER_

#include "Mapper.h"
#include "../../../domain/do/configuration/atq/ConfigurationDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ConfigurationMapper : public Mapper<ConfigurationDO>
{
public:
	ConfigurationDO mapper(ResultSet* resultSet) const override
	{
		ConfigurationDO data;
		data.setXcreatorUnitName(resultSet->getString(1));
		data.setXappId(resultSet->getString(2));
		data.setXalias(resultSet->getString(3));
		data.setXdocumentType(resultSet->getString(4));
		data.setXsendNotify(resultSet->getString(5));
		data.setProcess(resultSet->getString(6));
		data.setRange(resultSet->getString(7));
		data.setXcreatorPerson(resultSet->getString(8));
		data.setXmanagePerson(resultSet->getString(9));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_