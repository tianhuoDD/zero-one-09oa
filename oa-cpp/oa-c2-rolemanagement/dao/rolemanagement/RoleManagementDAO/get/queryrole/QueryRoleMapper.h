#ifndef _ROLELIST_MAPPER_
#define _ROLELIST_MAPPER_

#include "Mapper.h"
#include "domain/do/rolemanagement/RoleManagementDO/get/queryrole/QueryRoleDO.h"
#include "domain/do/rolemanagement/RoleManagementDO/put/addrole/AddroleDO.h"

class QueryRoleMapper : public Mapper<OrgRoleDO>
{
public:
	OrgRoleDO mapper(ResultSet* resultSet) const override
	{
		OrgRoleDO data;
		data.setXName(resultSet->getString(2));
		data.setXid(resultSet->getString(1));
		data.setXUnique(resultSet->getString(3));
		return data;
	}
};

#endif // !_ROLELIST_MAPPER_
