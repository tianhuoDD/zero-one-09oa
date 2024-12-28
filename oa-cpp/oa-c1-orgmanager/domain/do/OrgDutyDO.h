#pragma once

#ifndef _ORGDUTY_DO_
#define _ORGDUTY_DO_
#include "DoInclude.h"


class OrgDutyDO
{
	// ְ��id
	CC_SYNTHESIZE(string, xid, Xid);
	// ְ������
	CC_SYNTHESIZE(string, xname, Xname);
	// ְ������
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	// ƴ��
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	// ƴ������ĸ
	CC_SYNTHESIZE(string, xpinyinInitial, XpinyinInitial);

#if 0
	// ����ʱ��
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	// ����
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	// �޸�ʱ��
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	// �ֲ�Ҫ��
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	// ��ʶ��
	CC_SYNTHESIZE(string, xdistinguishedName, XdistinguishedName);
	// ������
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	// Ψһ��ʶ
	CC_SYNTHESIZE(string, xunique, Xunique);
	// ��Ԫ
	CC_SYNTHESIZE(string, xunit, Xunit);
#endif
public:
	OrgDutyDO() {
		xid = "";
		xname = "";
		xdescription = "";
		xpinyin = "";
		xpinyinInitial = "";
#if 0
		xsequence = "";
		xcreateTime = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xdistinguishedName = "";
		xorderNumber = 0;
		xunique = "";
#endif
	}
};


#endif
