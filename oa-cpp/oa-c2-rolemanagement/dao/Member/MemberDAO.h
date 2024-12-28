#pragma once
#ifndef _Member_DAO_
#define _Member_DAO_
#include "BaseDAO.h"
#include "domain/do/Member/MemberDo.h"
#include "../../domain/query/Member/MemberQuery.h"

/**
 * 示例表数据库操作实现
 */
class MemberDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const MemberDo& iObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_Member_DAO_
