#pragma once
#ifndef ORG_PERSONATTRIBUTEDO_H
#define ORG_PERSONATTRIBUTEDO_H

#include "../DoInclude.h"

//do里面有这么多属性 一个do代表一条数据
class org_PersonAttributeDO 
{
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(int, xdistributeFactor, XDistributeFactor);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xdistinguishedName, XDistinguishedName);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	CC_SYNTHESIZE(string, xperson, Xperson);
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);
	CC_SYNTHESIZE(string, xunique, Xunique);

public:
	org_PersonAttributeDO() {
		xid = "";
		xsequence = "";
		xupdateTime = "";
		xcreateTime = "";
		xdistributeFactor = 0;
		xdescription = "";
		xdistinguishedName = "";
		xname = "";
		xorderNumber = 0;
		xperson = "";
		xpinyin = "";
		xpinyinInitial = "";
		xunique = "";
	}
};

#endif