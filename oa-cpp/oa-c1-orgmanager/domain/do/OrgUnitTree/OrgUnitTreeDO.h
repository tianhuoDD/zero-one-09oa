#pragma once
#ifndef _ORGUNITTREEDO_H_
#define _ORGUNITTREEDO_H_

#include "../DoInclude.h"

/**
 * 组织单位数据库实体
 */
class OrgUnitTreeDO
{
    CC_SYNTHESIZE(string, xid, Xid);               // 唯一ID
    CC_SYNTHESIZE(string, xname, Xname);           // 单位名称
    CC_SYNTHESIZE(string, xlevelName, XlevelName); // 层级名称
    CC_SYNTHESIZE(int, xlevel, Xlevel);            // 层级
    CC_SYNTHESIZE(string, xunique, Xunique);       // 唯一标识
    CC_SYNTHESIZE(string, xsuperior, Xsuperior);   // 上级ID
};

#endif // !_ORGUNITTREEDO_H_
