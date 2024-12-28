#pragma once
#ifndef _DATAList_DAO_
#define _DATAList_DAO_
#include "BaseDAO.h"
#include "domain/do/data/DataListDO.h"
#include "domain/query/data/DataListQuery.h"

/**
 * 示例表数据库操作实现
 */
class DataListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const DataListQuery::Wrapper& query);
	// 分页查询数据
	list<DataListDO> selectWithPage(const DataListQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_