#pragma once

#ifndef _ORG_PERSONDO_H_
#define _ORG_PERSONDO_H_

#include "../../GlobalInclude.h"

class org_personDO {
	//	�û�id
	CC_SYNTHESIZE(string, xid, Id);
	//	�û������
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);

public:
	org_personDO() {
		xid = "1";
		xdistinguishedName = "";
	}
};

#endif // !_ORG_PERSONDO_H_
