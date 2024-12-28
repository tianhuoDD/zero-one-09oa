#pragma once
#ifndef _USER_SERVICE_
#define _USER_SERVICE_
#include <list>
#include "domain/vo/group/GroupVO.h"
#include "domain/dto/group/GroupDTO.h"
#include "domain/query/user/UserQuery.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */

class UserService
{
public:

	// ��ҳ��ѯ��������
	UserPageDTO::Wrapper listAll(const UserQuery::Wrapper& query);
};

#endif // !_USER_SERVICE_
