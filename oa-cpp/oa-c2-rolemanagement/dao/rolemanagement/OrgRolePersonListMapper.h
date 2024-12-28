#ifndef _ORG_ROLE_PERSON_LIST_MAPPER_
#define _ORG_ROLE_PERSON_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/get/personlist/OrgRolePersonListDO.h"


class OrgRolePersonListMapper : public Mapper<OrgRolePersonListDO>
{
public:
	OrgRolePersonListDO mapper(ResultSet* resultSet) const override
	{
		OrgRolePersonListDO data;
		//data.setRole_Xid(resultSet->getString(1));
		data.setXName(resultSet->getString(1));
		data.setXEmployee(resultSet->getString(2));
		data.setXMobile(resultSet->getString(3));
		data.setXMail(resultSet->getString(4));
		data.setXid(resultSet->getString(5));
		//data.setXOrderColumn(resultSet->getUInt64(3));
		return data;
	}
};

#endif // !_ORG_ROLE_PERSON_LIST_MAPPER_