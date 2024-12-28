#pragma once
#ifndef _GROUPMEMBER_DAO_
#define _GROUPMEMBER_DAO_
#include "BaseDAO.h"
#include"domain/do/GroupMember/GroupMemberDO.h"
#include "../../domain/query/GroupMember/GroupMemberQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class GroupMemberDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const GroupMemberQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GroupMemberDO> selectWithPage(const GroupMemberQuery::Wrapper& query);
};
#endif // !_GROUPMEMBER_DAO_