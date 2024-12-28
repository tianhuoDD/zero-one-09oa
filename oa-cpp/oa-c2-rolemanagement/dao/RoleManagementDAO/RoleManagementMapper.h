#pragma once
#ifndef _DELROLE_MAPPER_
#define _DELROLE_MAPPER_

#include"Mapper.h"


#include"../../domain/do/get/GetRoleDO.h"

//删除角色信息
class DelRoleMapper : public Mapper<GetRoleDO>
{
public:
	GetRoleDO mapper(ResultSet* resultSet) const override
	{
		//从一个从一个数据库查询的结果中提取数据，并将这些数据设置到data 中
		GetRoleDO data;
		data.setName(resultSet->getString(""));
		data.setKey(resultSet->getString(""));
		data.setRefer(resultSet->getString(""));

		return data;
	}
};

#endif // !_DELROLE_MAPPER_


