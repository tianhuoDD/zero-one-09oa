#pragma once

#ifndef _GROUPLIST_DAO_
#define _GROUPLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/get/GroupListDO.h"
#include "../../domain/query/get/GroupListQuery.h"

/**
 * 示例表数据库操作实现
 */
class GroupListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const GroupListQuery::Wrapper& query);
	// 分页查询数据
	list<GroupListDO> selectWithPage(const GroupListQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const GroupListDO& iObj);
};
#endif // !_SAMPLE_DAO_
