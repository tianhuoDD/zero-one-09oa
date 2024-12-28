#pragma once
#ifndef _ADDROLE_MAPPER_
#define _ADDROLE_MAPPER_

#include "Mapper.h"
#include "domain/do/put/addrole/AddroleDO.h"

class AddroleMapper : public Mapper<AddroleDO>
{
public:
	AddroleDO mapper(ResultSet* resultSet) const override
	{
		AddroleDO data;
		data.setName(resultSet->getString(""));
		data.setKey(resultSet->getString(""));
		data.setRefer(resultSet->getString(""));
		return data;
	}
};

#endif // !_ADDROLE_MAPPER_
