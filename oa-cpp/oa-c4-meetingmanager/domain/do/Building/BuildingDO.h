#pragma once
#ifndef _BUILDING_DO_
#define _BUILDING_DO_
#include "../DoInclude.h"
class BuildingDO {
	//会议室位置名称
	CC_SYNTHESIZE(string, buildName, BuildName);
	//会议室ID
	CC_SYNTHESIZE(string, buildId, BuildId);
public:

	BuildingDO() :buildId(""), buildName(""){}
};
#endif // !_BUILDING_DO_
