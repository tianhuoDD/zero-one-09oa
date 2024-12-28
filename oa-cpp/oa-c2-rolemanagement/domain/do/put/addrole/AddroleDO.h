#pragma once
#ifndef _ADDROLE_DO_
#define _ADDROLE_DO_
#include "../../DoInclude.h"
#include "../../../GlobalInclude.h"

class AddroleDO {
	// ½ÇÉ«Ãû³Æ
	CC_SYNTHESIZE(string, name, Name);
	// Î¨Ò»±àÂë
	CC_SYNTHESIZE(string, key, Key);
	// ½ÇÉ«ÃèÊö
	CC_SYNTHESIZE(string, refer, Refer);
public:
	AddroleDO() {
		name = "";
		key = "";
		refer = "";
	}
};


#endif // !_ADDROLE_DO_
