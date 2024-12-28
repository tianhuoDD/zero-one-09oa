#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 25日 星期五 19:40:34 CST
*/
#ifndef _ORGGROUPPERSONLIST_DO_
#define _ORGGROUPPERSONLIST_DO_
#include "../../../Macros.h"

/**
 * 示例数据库实体类
 */
class OrgGroupPersonlistDO
{																																																					
	// 群组标识
	CC_SYNTHESIZE(string, GROUP_XID, Group_xid);
	//个人成员标识
	CC_SYNTHESIZE(string, xpersonList, Xperson_list);
	//在表中出现的位置
	CC_SYNTHESIZE(int, xorderColumn, Xorder_column);
public:
	OrgGroupPersonlistDO() {
		GROUP_XID = "";
		xpersonList = "";
		xorderColumn = 0;
	}
};

#endif // !_ORGGROUPPERSONLIST_DO_
