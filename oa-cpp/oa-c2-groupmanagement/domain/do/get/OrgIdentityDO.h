#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 23�� ������ 23:19:41 CST
*/
//org_identity
#ifndef _ORGIDENTITY_DO_
#define _ORGIDENTITY_DO_
#include "../../../Macros.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class OrgIdentityDO
{

	// ���
	//CC_SYNTHESIZE(uint64_t, id, Id);

	//��Ա��ʶ
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, Xcreate_time);
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	CC_SYNTHESIZE(string, xupdateTime, Xupdate_time);
	CC_SYNTHESIZE(int, xdistributeFactor, Xdistribute_factor);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xdistinguishedName, Xdistinguished_name);
	CC_SYNTHESIZE(int64_t, xmajor, Xmajor);
	//����
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(int, xorderNumber, Xorder_number);
	CC_SYNTHESIZE(string, xperson, Xperson);
	CC_SYNTHESIZE(string, xpinyin, Xpinyin);
	CC_SYNTHESIZE(string, xpinyinInitial, Xpinyin_initial);
	CC_SYNTHESIZE(string, xunique, Xunique);
	CC_SYNTHESIZE(string, xunit, Xunit);
	CC_SYNTHESIZE(int, xunitLevel, Xunit_level);
	//�㼶����
	CC_SYNTHESIZE(string, xunitLevelName, Xunit_level_name);
	CC_SYNTHESIZE(string, xunitName, Xunit_name);
public:
	OrgIdentityDO() {
		xid = "";
		xcreateTime = "";
		xsequence = "";
		xupdateTime = "";
		xdistributeFactor = 0;
		xdescription = "";
		xdistinguishedName = "";
		xmajor = 0;
		xname = "";
		xorderNumber = 0;
		xperson = "";
		xpinyin = "";
		xpinyinInitial = "";
		xunique = "";
		xunit = "";
		xunitLevel = 0;
		xunitLevelName = "";
		xunitName = "";
	}
};

#endif // !_ORGIDENTITY_DO_
