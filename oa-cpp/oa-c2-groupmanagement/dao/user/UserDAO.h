#pragma once
#ifndef _USER_DAO_
#define _USER_DAO_
#include "BaseDAO.h"
#include <domain/do/get/UserDO.h>
#include "domain/query/user/UserQuery.h"
/**
 * 示例表数据库操作实现
 */
class UserDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const UserQuery::Wrapper& query);
	// 分页查询数据
	list<UserDO> selectWithPage(const UserQuery::Wrapper& query);
	//// 通过姓名查询数据
	//list<UserDO> selectByName(const string& name);
	// 修改数据
	/*int update(const UserDO& uObj);*/

};
#endif // !_USER_DAO_