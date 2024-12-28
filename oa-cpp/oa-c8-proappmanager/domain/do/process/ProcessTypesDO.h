#pragma once
#ifndef _PROCESSTYPES_DO_
#define _PROCESSTYPES_DO_
#include "../DoInclude.h"

class ProcessTypesDO {
	// 类型
	CC_SYNTHESIZE(string, xcategory, Xcategory);
	// 包含的数量
	CC_SYNTHESIZE(int, containNums, ContainNums);
public:
	ProcessTypesDO() {
		this->xcategory = "";
		this->containNums = 0;
	}
};

#endif // !_PROCESSTYPES_DO_
