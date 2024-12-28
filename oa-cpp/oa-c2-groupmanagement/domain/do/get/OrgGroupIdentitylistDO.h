#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 23�� ������ 23:19:41 CST
*/
#ifndef _ORGGROUPIDENTITYLIST_DO_
#define _ORGGROUPIDENTITYLIST_DO_
//#include "../DoInclude.h"
#include "../../../Macros.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class OrgGroupIdentitylistDO
{
	// Ⱥ���ʶ
	CC_SYNTHESIZE(string,GROUP_XID, Group_xid);
	// ��ݳ�Ա��ʶ
	CC_SYNTHESIZE(string ,xidentityList, Xidentity_list);
	// �ڱ��г��ֵ�λ��
	CC_SYNTHESIZE(int, xorderColumn, Xorder_column);
public:
	OrgGroupIdentitylistDO() {
		GROUP_XID = "";
		xidentityList = "";
		xorderColumn = -1;
	}
};

#endif // !_ORGGROUPIDENTITYLIST_DO_
