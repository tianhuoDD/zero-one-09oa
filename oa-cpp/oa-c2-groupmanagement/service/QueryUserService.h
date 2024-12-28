#pragma once
#ifndef _USER_SERVICE_
#define _USER_SERVICE_
#include <list>
#include "domain/vo/group/GroupVO.h"
#include "domain/dto/group/GroupDTO.h"
#include "domain/query/user/UserQuery.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */

class UserService
{
public:

	// 分页查询所有数据
	UserPageDTO::Wrapper listAll(const UserQuery::Wrapper& query);
};

#endif // !_USER_SERVICE_
