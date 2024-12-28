#pragma once

#ifndef _ORG_PERSONDO_H_
#define _ORG_PERSONDO_H_

#include "../../GlobalInclude.h"

class org_personDO {
	//	用户id
	CC_SYNTHESIZE(string, xid, Id);
	//	用户辨别名
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);

public:
	org_personDO() {
		xid = "1";
		xdistinguishedName = "";
	}
};

#endif // !_ORG_PERSONDO_H_
