#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 24日 星期四 09:14:46 CST
*/
#ifndef _IDMEMBER_MAPPER_
#define _IDMEMBER_MAPPER_

#include "Mapper.h"
//#include "../../../domain/do/get/OrgGroupIdentitylistDO.h"
#include "../../../domain/do/get/IDmemberDO.h"

/**
 * 示例表字段匹配映射
 */
class IDmemberMapper : public Mapper<IDmemberDO>
{
public:
	IDmemberDO mapper(ResultSet* resultSet) const override
	{
		IDmemberDO data;
		data.setXname(resultSet->getString(1));
		data.setXunit_level_name(resultSet->getString(2));
		//data.setXorder_column(resultSet->getInt(3));
		return data;
	}
};

#endif // !_IDMEMBER_MAPPER_