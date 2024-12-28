#pragma once
#ifndef _GROUP_DAO_
#define _GROUP_DAO_
#include "BaseDAO.h"
#include <domain/do/put/GroupDO.h>
/**
 * 示例表数据库操作实现
 */
class GroupDAO : public BaseDAO
{
public:
	//// 统计数据条数
	//uint64_t count(const UserQuery::Wrapper& query);
	// 修改数据
	int update(const GroupDO& uObj);

};
#endif // !_GROUP_DAO_