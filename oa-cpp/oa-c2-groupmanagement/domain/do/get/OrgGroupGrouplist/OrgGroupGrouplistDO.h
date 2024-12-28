#pragma once

#ifndef _OrgGroupGrouplist_DO_
#define _OrgGroupGrouplist_DO_
#include "../../DoInclude.h"
//群组成员表
/**
 * 数据库实体类
 */
class OrgGroupGrouplistDO
{
	// 群组的唯一标识符
	CC_SYNTHESIZE(string, groupxid, Groupxid);
	// 子群组群组列表
	CC_SYNTHESIZE(string, xgroupList, XgroupList);
	//群组在列表中的排序顺序
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	//联表	全名
	CC_SYNTHESIZE(string, allname, Allname);	
	//联表	名称
	CC_SYNTHESIZE(string, name, Name);
public:
	OrgGroupGrouplistDO() {
		groupxid = "0";
		xgroupList = "";
		xorderColumn = 0;
		allname = "";
		name = "";
	}
};

#endif 
