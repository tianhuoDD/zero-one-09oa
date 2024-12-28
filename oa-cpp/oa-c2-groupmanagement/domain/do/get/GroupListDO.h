#pragma once

#ifndef _GroupList_DO_
#define _GroupList_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class GroupListDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 组名
	CC_SYNTHESIZE(string, name, Name);
	// 描述
	CC_SYNTHESIZE(string, describe, Describe);
	
public:
	GroupListDO() {
		id ="";
		name = "";
		describe = "";
		
	}
};

#endif // !_SAMPLE_DO_
