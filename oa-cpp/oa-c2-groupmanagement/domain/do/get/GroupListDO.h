#pragma once

#ifndef _GroupList_DO_
#define _GroupList_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class GroupListDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// ����
	CC_SYNTHESIZE(string, describe, Describe);
	
public:
	GroupListDO() {
		id ="";
		name = "";
		describe = "";
		
	}
};

#endif // !_SAMPLE_DO_
