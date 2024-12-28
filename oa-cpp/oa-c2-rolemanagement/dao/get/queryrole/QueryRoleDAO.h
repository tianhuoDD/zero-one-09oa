#pragma once
#ifndef _ROLELIST_DAO_
#define _ROLELIST_DAO_
#include "BaseDAO.h"
#include "domain/do/get/queryrole/QueryRoleDO.h"
#include "domain/query/get/queryrole/QueryRoleQuery.h"

class QueryRoleDAO : public BaseDAO {
public:
	// 统计数据条数
	uint64_t count(const QueryRoleQuery::Wrapper& query);
	// 分页查询数据
	list<QueryRoleDO> selectWithPage(const QueryRoleQuery::Wrapper& query);
	// 通过关键字查询数据
	list<QueryRoleDO> selectByWords(const string& words);
};


#endif // !_ROLELIST_DAO_
