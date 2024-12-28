#pragma once
#ifndef _STRING_MAPPER_
#define _STRING_MAPPER_

#include "Mapper.h"
#include "domain/do/Org/OrgDO.h"

class StringMapper
{
public:
	string mapper(ResultSet* resultSet) const
	{
		return resultSet->getString(1);
	}
};

#endif // !_STRING_MAPPER_