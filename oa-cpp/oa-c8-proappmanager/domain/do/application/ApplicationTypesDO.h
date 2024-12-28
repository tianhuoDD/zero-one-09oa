#pragma once
#ifndef _APPLICATIONTYPES_DO_
#define _APPLICATIONTYPES_DO_
#include "../DoInclude.h"

class ApplicationTypesDO {
	CC_SYNTHESIZE(string, xapplicationCategory, XapplicationCategory);
	CC_SYNTHESIZE(int, xcount, Xcount);
public:
	ApplicationTypesDO() {
		this->xapplicationCategory = "";
		this->xcount = 0;
	}
};

#endif // !_APPLICATIONTYPES_DO_
