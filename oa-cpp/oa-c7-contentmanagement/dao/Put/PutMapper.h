#pragma once
#pragma once
#ifndef _PUTMAPPER_
#define _PUTMAPPER_

#include "Mapper.h"
#include "../../domain/do/New/PutDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PutMapper : public Mapper<PutDO>
{
public:
	PutDO mapper(ResultSet* resultSet) const override
	{
		PutDO data;
		data.setXappicon(resultSet->getString(1));
		data.setXallPeopleViem(resultSet->getString(2));
		data.setXallPeoplePublish(resultSet->getString(3));
		data.setXcreatorPerson(resultSet->getString(4));
		
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_