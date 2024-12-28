#pragma once
#ifndef _ORG_PERSONEXTENDDO_H_
#define _ORG_PERSONEXTENDDO_H_
#include "../../DoInclude.h"

/**
 * 职工身份数据库实体类
 */
class org_identityDO
{
	// 主码
	CC_SYNTHESIZE(string, xid, Xid);
	// 创建时间
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	//
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	// 更新时间
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	//
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	// 个人
	CC_SYNTHESIZE(string, xperson, Xperson);
	// 
	CC_SYNTHESIZE(string, xproperties, Xproperties);
	//
	CC_SYNTHESIZE(string, xtype, Xtype);

public:
	org_identityDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xperson = "";
		xproperties = "";
		xtype = "";
	}
};

#endif // !_ORG_IDENTITYDO_H_
