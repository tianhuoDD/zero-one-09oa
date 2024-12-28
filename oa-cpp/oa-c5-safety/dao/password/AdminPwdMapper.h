#pragma once

#ifndef _ADMINPWDMAPPER_H_
#define _ADMINPWDMAPPER_H_

#include "Mapper.h"
#include "domain/do/password/admin/AdminPwdDO.h"

/**
 * 字段匹配映射
 */
class AdminPwdMapper : public Mapper<AdminPwdDO>
{
public:
	AdminPwdDO mapper(ResultSet* resultSet) const override
	{


		AdminPwdDO data;
		data.setId(resultSet->getUInt64(1));
		data.setOldPassword(resultSet->getString(2));
		data.setNewPassword(resultSet->getString(3));
		data.setConfirmPassword(resultSet->getString(4));
		data.setChangePasswordTime(resultSet->getString(5));
		data.setPasswordExpiredTime(resultSet->getString(6));



		return data;
	}
};

#endif // !_ADMINPWD_MAPPER_
