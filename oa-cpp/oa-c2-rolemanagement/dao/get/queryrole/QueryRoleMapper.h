#ifndef _ROLELIST_MAPPER_
#define _ROLELIST_MAPPER_

#include "Mapper.h"
#include "./domain/do/get/queryrole/QueryRoleDO.h"

class QueryRoleMapper : public Mapper<QueryRoleDO>
{
public:
	QueryRoleDO mapper(ResultSet* resultSet) const override
	{
		QueryRoleDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_ROLELIST_MAPPER_
