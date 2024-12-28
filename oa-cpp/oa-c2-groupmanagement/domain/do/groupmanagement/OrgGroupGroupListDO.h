//
// Created by asd on 2024/10/23.
//

#ifndef ORGGROUPGROUPLISTDO_H
#define ORGGROUPGROUPLISTDO_H
#include <Macros.h>

class OrgGroupGroupListDO {
public:
	CC_SYNTHESIZE(std::string, groupId, GROUP_XID);
	CC_SYNTHESIZE(std::string, groupList, xgroupList);
	CC_SYNTHESIZE(int, orderColumn, xorderColumn);

	OrgGroupGroupListDO() {
		groupId = nullptr;
		groupList = nullptr;
		orderColumn = -1;
	}
};

#endif //ORGGROUPGROUPLISTDO_H
