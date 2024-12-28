#pragma once
#ifndef _ORGUNITDUTYTREEDO_H_
#define _ORGUNITDUTYTREEDO_H_

#include "../DoInclude.h"

/**
 * 组织职务数据库实体
 */
class OrgUnitDutyTreeDO {
    CC_SYNTHESIZE(string, xid, Xid);             // 唯一ID
    CC_SYNTHESIZE(string, xname, Xname);         // 职务名称
    CC_SYNTHESIZE(string, xunique, Xunique);     // 职务唯一标识
    CC_SYNTHESIZE(string, xunit, Xunit);         // 对应组织单位的ID
};

#endif // !_ORGUNITDUTYTREEDO_H_
