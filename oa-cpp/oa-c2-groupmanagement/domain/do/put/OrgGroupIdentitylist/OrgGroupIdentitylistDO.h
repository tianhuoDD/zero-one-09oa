#pragma once
//��ݳ�Ա��
#ifndef _OrgGroupIdentitylist_DO_
#define _OrgGroupIdentitylist_DO_
#include "../../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class OrgGroupIdentitylistDO
{
	// Ψһ��ʶ
	CC_SYNTHESIZE(string, groupxid, Groupxid);
	// ���ڸ������ݳ�Ա
	CC_SYNTHESIZE(string, xidentityList, XidentityList);
	//��ݳ�Ա���б��е�����˳��
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);

public:
	OrgGroupIdentitylistDO() {
		groupxid = "0";
		xidentityList = "";
		xorderColumn = 0;
	}
};

#endif 
