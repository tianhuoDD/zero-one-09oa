#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 25日 星期五 19:40:34 CST
*/
#ifndef _ADDPERSON_MAPPER_
#define _ADDPERSON_MAPPER_

#include "Mapper.h"
#include "../../../domain/do/put/OrgGroupPersonlistDO.h"

/**
 * 示例表字段匹配映射
 */
class AddPersonMapper : public Mapper<OrgGroupPersonlistDO>
{
public:
	OrgGroupPersonlistDO mapper(ResultSet* resultSet) const override
	{
		OrgGroupPersonlistDO data;
		data.setGroup_xid(resultSet->getString(1));
		data.setXperson_list(resultSet->getString(2));
		data.setXorder_column(resultSet->getInt(3));
		return data;
	}
};

#endif // !_ADDPERSON_MAPPER_