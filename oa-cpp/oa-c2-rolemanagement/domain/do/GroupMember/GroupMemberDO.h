#pragma once
#ifndef _GROUPMEMBER_DO_
#define _GROUPMEMBER_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class GroupMemberDO
{
	// Ⱥ������
	CC_SYNTHESIZE(string, groupname, Groupname);
	// Ⱥ��ȫ��
	CC_SYNTHESIZE(string, groupnameA, GroupnameA);
	// Ⱥ������
	CC_SYNTHESIZE(string, groupdes, Groupdes);;
public:
	GroupMemberDO() {
		groupname = "Ⱥ������";
		groupnameA = "Ⱥ��ȫ��";
		groupdes = "Ⱥ������";
	}
};

#endif // !_GROUPMEMBER_DO_