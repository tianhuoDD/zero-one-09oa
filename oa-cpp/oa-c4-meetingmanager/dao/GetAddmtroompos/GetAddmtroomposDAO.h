#pragma once

#ifndef _GETADDMTROOMPOS_DAO_
#define _GETADDMTROOMPOS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/GetAddmtroompos/GetAddmtroomposDO.h"
#include "../../domain/query/getmtroompos/GetmtroomposQuery.h"

/**
 * 示数据库操作实现
 */
class GetAddmtroomposDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const GetmtroomposQuery::Wrapper& query);
	// 分页查询数据
	list<GetAddmtroomposDO> selectWithPage(const GetmtroomposQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const GetAddmtroomposDO& iObj);
	// 修改数据
	//int update(const GetAddmtroomposDO& uObj);
};
#endif // !_GETADDMTROOMPOS_DAO_
