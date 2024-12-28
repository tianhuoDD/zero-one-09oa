#pragma once
#ifndef _Group_DO_
#define _Group_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class GroupDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 描述
	CC_SYNTHESIZE(string, info, Info);
public:
	//GruopDO() {}
	/*ModifyDO(string id, string name, string info)
	{
		this->id = id;
		this->name = name;
		this->info = info;
	}*/
	GroupDO() {
		id = 0;
		name = "";
		info = "";
	}
};

#endif // !_GROUP_DO_
