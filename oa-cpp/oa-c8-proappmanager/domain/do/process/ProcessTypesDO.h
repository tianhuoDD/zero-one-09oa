#pragma once
#ifndef _PROCESSTYPES_DO_
#define _PROCESSTYPES_DO_
#include "../DoInclude.h"

class ProcessTypesDO {
	// ����
	CC_SYNTHESIZE(string, xcategory, Xcategory);
	// ����������
	CC_SYNTHESIZE(int, containNums, ContainNums);
public:
	ProcessTypesDO() {
		this->xcategory = "";
		this->containNums = 0;
	}
};

#endif // !_PROCESSTYPES_DO_
