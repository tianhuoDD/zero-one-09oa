#pragma once

#ifndef _OrgGroupGrouplist_DO_
#define _OrgGroupGrouplist_DO_
#include "../../DoInclude.h"
//Ⱥ���Ա��
/**
 * ���ݿ�ʵ����
 */
class OrgGroupGrouplistDO
{
	// Ⱥ���Ψһ��ʶ��
	CC_SYNTHESIZE(string, groupxid, Groupxid);
	// ��Ⱥ��Ⱥ���б�
	CC_SYNTHESIZE(string, xgroupList, XgroupList);
	//Ⱥ�����б��е�����˳��
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	//����	ȫ��
	CC_SYNTHESIZE(string, allname, Allname);	
	//����	����
	CC_SYNTHESIZE(string, name, Name);
public:
	OrgGroupGrouplistDO() {
		groupxid = "0";
		xgroupList = "";
		xorderColumn = 0;
		allname = "";
		name = "";
	}
};

#endif 
