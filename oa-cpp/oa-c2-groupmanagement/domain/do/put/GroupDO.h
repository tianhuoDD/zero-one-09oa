#pragma once
#ifndef _Group_DO_
#define _Group_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class GroupDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
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
