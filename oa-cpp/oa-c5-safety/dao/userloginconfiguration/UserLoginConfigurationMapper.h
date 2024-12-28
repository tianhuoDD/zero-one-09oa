#pragma once

#ifndef _USERLOGINCONFIGURATION_MAPPER_
#define _USERLOGINCONFIGURATION_MAPPER_

#include "Mapper.h"
#include "../../domain/do/userloginconfiguration/UserLoginConfigurationDO.h"

/**
 * 字段匹配映射
 */
class UserLoginConfigurationMapper : public Mapper<UserLoginConfigurationDO>
{
public:
	UserLoginConfigurationDO mapper(ResultSet* resultSet) const override
	{
		UserLoginConfigurationDO data;
		data.setId(resultSet->getString(1));
		data.setUserName(resultSet->getString(2));
		data.setPassword(resultSet->getString(3));
		data.setLastLoginTime(resultSet->getString(4));
		data.setEmailAddress(resultSet->getString(5));
		data.setMobilePhone(resultSet->getString(6));
		data.setLoginAttempts(resultSet->getUInt64(7));
		data.setPermission(resultSet->getString(8));
		data.setIpAddress(resultSet->getString(9));


		return data;
	}
};

#endif // !_USERLOGINCONFIGURATION_MAPPER_
