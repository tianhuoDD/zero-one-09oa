#pragma once
//身份成员表
#ifndef _OrgGroupIdentitylist_DO_
#define _OrgGroupIdentitylist_DO_
#include "../../DoInclude.h"

/**
 * 数据库实体类
 */
class OrgGroupIdentitylistDO
{
	// 唯一标识
	CC_SYNTHESIZE(string, groupxid, Groupxid);
	// 属于该组的身份成员
	CC_SYNTHESIZE(string, xidentityList, XidentityList);
	//身份成员在列表中的排序顺序
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);

public:
	OrgGroupIdentitylistDO() {
		groupxid = "0";
		xidentityList = "";
		xorderColumn = 0;
	}
};

#endif 
