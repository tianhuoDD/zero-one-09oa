#pragma once
#ifndef _BUILDING_DO_
#define _BUILDING_DO_
#include "../DoInclude.h"
class BuildingDO {
	//������λ������
	CC_SYNTHESIZE(string, buildName, BuildName);
	//������ID
	CC_SYNTHESIZE(string, buildId, BuildId);
public:

	BuildingDO() :buildId(""), buildName(""){}
};
#endif // !_BUILDING_DO_
