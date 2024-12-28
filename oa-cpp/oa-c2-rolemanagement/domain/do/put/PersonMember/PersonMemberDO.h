#pragma once
#ifndef _PERSONMEMBER_DO_
#define _PERSONMEMBER_DO_

#include "Macros.h"
#include <string>
#include <list>
#include "domain/do/DoInclude.h"
using namespace std;

class PersonMemberDO
{
	// ±àºÅ
	CC_SYNTHESIZE(string, role_xid, ROLE_XID);
	CC_SYNTHESIZE(string, xpersonList, XpersonList);
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);

public:
	PersonMemberDO() {
		role_xid = "PersonMember.field.ROLE_XID";
		xpersonList = "PersonMember.field.xpersonList";
		xorderColumn = 1;
	}
};

#endif // !_PERSONMEMBER_DO_