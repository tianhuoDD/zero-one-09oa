#pragma once
#ifndef _ROLELIST_DO_
#define _ROLELIST_DO_
#include "../../DoInclude.h"

/**
*  ��ɫ�������ݿ�ʵ����
*/
class QueryRoleDO {
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
	CC_SYNTHESIZE(string, name, Name);
public:
	QueryRoleDO() {
		id = 0;
		name = "";
	}
};

#endif // !_ROLELIST_DO_
