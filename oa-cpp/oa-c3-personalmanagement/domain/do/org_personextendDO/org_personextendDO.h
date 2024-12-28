#pragma once
#ifndef _ORG_PERSONEXTENDDO_H_
#define _ORG_PERSONEXTENDDO_H_
#include "../../DoInclude.h"

/**
 * ְ��������ݿ�ʵ����
 */
class org_identityDO
{
	// ����
	CC_SYNTHESIZE(string, xid, Xid);
	// ����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	//
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	// ����ʱ��
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	//
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	// ����
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
