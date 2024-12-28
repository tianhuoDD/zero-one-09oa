#pragma once
#ifndef _ATTRIB_MAPPER_
#define _ATTRIB_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Attrib_add/Attrib_add_DO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class Attrib_add_Mapper : public Mapper<Attrib_add_DO>
{
public:
	Attrib_add_DO mapper(ResultSet* resultSet) const override
	{
		Attrib_add_DO data;
		data.setXid(resultSet->getString(1));
		data.setXname(resultSet->getString(2));
		data.setXdistinguishedName(resultSet->getString(3));
		data.setXdistributeFactor(resultSet->getInt(4));
		data.setXdescription(resultSet->getString(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_