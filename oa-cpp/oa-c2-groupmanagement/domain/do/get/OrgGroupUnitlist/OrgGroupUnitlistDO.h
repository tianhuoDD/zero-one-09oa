#pragma once

#ifndef _OrgGroupUnitlist_DO_
#define _OrgGroupUnitlist_DO_
#include "../../DoInclude.h"
//组织成员表
/**
 * 数据库实体类
 */
class OrgGroupUnitlistDO
{
	// 群组唯一标识
	CC_SYNTHESIZE(string, groupxid, Groupxid);
	// 属于该群组的单位
	CC_SYNTHESIZE(string, xunitList, XunitList);
	//单位在列表中的排序顺序
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	//联表	名称
	CC_SYNTHESIZE(string, name, Name);
public:
	OrgGroupUnitlistDO() {
		groupxid = "0";
		xunitList = "";
		xorderColumn = 0;
		name = "";
	}
};

#endif 
