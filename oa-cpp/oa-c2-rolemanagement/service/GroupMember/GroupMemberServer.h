#pragma once
#ifndef _GROUPMEMBER_SERVICE_
#define _GROUPMEMBER_SERVICE_
#include <list>
#include"domain/dto/GroupMember/GetGroupMemberDTO.h"
#include"domain/query/GroupMember/GroupMemberQuery.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class GroupMemberService
{
public:
	// ��ҳ��ѯ��������
	GetGroupMemberPageDTO::Wrapper listAll(const GroupMemberQuery::Wrapper& query);
};

#endif // !_GROUPMEMBER_SERVICE_
