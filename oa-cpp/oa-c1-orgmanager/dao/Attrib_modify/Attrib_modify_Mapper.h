#pragma once
#ifndef _ATTRIB_MAPPER_
#define _ATTRIB_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Attrib_modify/Attrib_modify_DO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class Attrib_modify_Mapper : public Mapper<Attrib_modify_DO>
{
public:
	Attrib_modify_DO mapper(ResultSet* resultSet) const override
	{
		Attrib_modify_DO data;
		data.setXid(resultSet->getString(1));
		data.setXdistinguishedName_pre(resultSet->getString(2));
		data.setXdistinguishedName_last(resultSet->getString(3));
		data.setXdistributeFactor(resultSet->getInt(4));
		data.setXdescription(resultSet->getString(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_