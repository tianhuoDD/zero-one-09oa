#pragma once
#ifndef _GETGROUPINFOMAPPER_H_
#define _GETGROUPINFOMAPPER_H_

#include "../../../domain/do/groupmanagement/OrgGroupDO.h"
#include "Mapper.h"

class GetGroupInfoMapper: public Mapper<OrgGroupDO>
{
public:
	OrgGroupDO mapper(ResultSet* resultSet) const override
	{
		OrgGroupDO data;
		
		data.setxName(resultSet->getString(1));
		data.setxId(resultSet->getString(2));
		data.setxDescription(resultSet->getString(3));

		return data;
	}

};

#endif // !_GETGROUPINFOMAPPER_H_