#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 23日 星期三 20:45:51 CST
*/
#ifndef _IDMEMBER_DAO_
#define _IDMEMBER_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/get/IDmemberDO.h"
#include "../../../domain/query/get/IDmemberQuery.h"

/**
 * 示例表数据库操作实现
 */
class IDmemberDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const IDmemberQuery::Wrapper& query);
	// 分页查询数据
	list<IDmemberDO> selectWithPage(const IDmemberQuery::Wrapper& query);
	// 通过姓名查询数据
	//list<OrgGroupIdentitylistDO> selectByName(const string& name);

};
#endif // !_IDMEMBER_DAO_
