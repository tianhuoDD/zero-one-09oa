#pragma once
#ifndef _BUILDING_MAPPER_
#define _BUILDING_MAPPER_
#include"Mapper.h"
#include"domain/do/Building/BuildingDO.h"
class BuildingMapper : Mapper<BuildingDO> {
public:
	BuildingDO mapper(ResultSet* resultSet)const override {
		BuildingDO data;
		data.setBuildId(resultSet->getString(1));
		data.setBuildName(resultSet->getString(2));
		return data;
	}
};
#endif // !_BUILDING_MAPPER_
