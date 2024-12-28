#pragma once
#ifndef _ADDROLE_MAPPER_
#define _ADDROLE_MAPPER_

#include "Mapper.h"
#include "domain/do/rolemanagement/RoleManagementDO/put/addrole/AddroleDO.h"

class AddroleMapper : public Mapper<AddroleDO>
{
public:
	AddroleDO mapper(ResultSet* resultSet) const override
	{
		AddroleDO data;
		data.setXid(resultSet->getString(""));
		data.setXcreateTime(resultSet->getString(""));
		data.setXsequence(resultSet->getString(""));
		data.setXupdateTime(resultSet->getString(""));
		data.setXdistributeFactor(resultSet->getString(""));
		data.setXdescription(resultSet->getString(""));
		data.setXdistinguishedName(resultSet->getString(""));
		data.setXname(resultSet->getString(""));
		data.setXorderNumber(resultSet->getInt(1));
		data.setXpinyin(resultSet->getString(""));
		data.setXpinyinInitial(resultSet->getString(""));
		data.setXunique(resultSet->getString(""));
		return data;
	}
};

#endif // !_ADDROLE_MAPPER_
