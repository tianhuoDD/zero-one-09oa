#pragma once

#ifndef _OrgGroupUnitlist_DO_
#define _OrgGroupUnitlist_DO_
#include "../../DoInclude.h"
//��֯��Ա��
/**
 * ���ݿ�ʵ����
 */
class OrgGroupUnitlistDO
{
	// Ⱥ��Ψһ��ʶ
	CC_SYNTHESIZE(string, groupxid, Groupxid);
	// ���ڸ�Ⱥ��ĵ�λ
	CC_SYNTHESIZE(string, xunitList, XunitList);
	//��λ���б��е�����˳��
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	//����	����
	CC_SYNTHESIZE(string, name, Name);
public:
	OrgGroupUnitlistDO() {
		groupxid = "0";
		xunitList = "";
		xorderColumn = 0;
		name = "";
	}
};

#endif 
