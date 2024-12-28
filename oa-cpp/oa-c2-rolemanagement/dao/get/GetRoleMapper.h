#pragma once
#pragma once
#ifndef _DETROLE_MAPPER_
#define _DETROLE_MAPPER_

#include"Mapper.h"

#include "../../domain/do/get/GetRoleDO.h"

//获取角色信息
class GetRoleMapper : public Mapper<GetRoleDO>
{
public:
	GetRoleDO mapper(ResultSet* resultSet) const override
	{
		//从一个从一个数据库查询的结果中提取数据，并将这些数据设置到data 中
		GetRoleDO data;
		data.setName(resultSet->getString("xname"));
		data.setKey(resultSet->getString("xunique"));
		data.setRefer(resultSet->getString("xdescription"));
		data.setFullname(resultSet->getString("xdistinguishedName"));
		data.setStartTime(resultSet->getString("xcreateTime"));
		data.setEndTime(resultSet->getString("xupdateTime"));
		


		return data;
	}
};

#endif // !_DETROLE_MAPPER_