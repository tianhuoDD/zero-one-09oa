#pragma once
#ifndef _ORGUNITIDENTITYTREEDO_H_
#define _ORGUNITIDENTITYTREEDO_H_

#include "../DoInclude.h"

class OrgUnitIdentityTreeDO
{
    CC_SYNTHESIZE(string, xid, Xid);
    CC_SYNTHESIZE(string, xname, Xname);
    CC_SYNTHESIZE(string, xunique, Xunique);
    CC_SYNTHESIZE(string, xunit, Xunit); // 对应组织单位的ID
};

#endif // !_ORGUNITIDENTITYTREEDO_H_
