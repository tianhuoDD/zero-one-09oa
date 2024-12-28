#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024�� 10�� 25�� ������ 19:40:34 CST
*/
#ifndef _ORGGROUPPERSONLIST_DO_
#define _ORGGROUPPERSONLIST_DO_
#include "../../../Macros.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class OrgGroupPersonlistDO
{																																																					
	// Ⱥ���ʶ
	CC_SYNTHESIZE(string, GROUP_XID, Group_xid);
	//���˳�Ա��ʶ
	CC_SYNTHESIZE(string, xpersonList, Xperson_list);
	//�ڱ��г��ֵ�λ��
	CC_SYNTHESIZE(int, xorderColumn, Xorder_column);
public:
	OrgGroupPersonlistDO() {
		GROUP_XID = "";
		xpersonList = "";
		xorderColumn = 0;
	}
};

#endif // !_ORGGROUPPERSONLIST_DO_
