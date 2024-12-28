#pragma once
#ifndef _GETPERSONMEMBER_DO_
#define _GETPERSONMEMBER_DO_
#include "domain/do/DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class GetPersonMemberDO
{
	// ��Ա����
	CC_SYNTHESIZE(string, role_xid, ROLE_XID);
	// �����
	CC_SYNTHESIZE(string, xgroupList, XgroupList);
	// ˳��
	CC_SYNTHESIZE(uint64_t, xorderColumn, XorderColumn);

public:
	GetPersonMemberDO() {
		role_xid = "";
		xgroupList = "";
		xorderColumn = 0;
	}
};

#endif // !_GETPERSONMEMBER_DO_