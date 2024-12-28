#pragma once
/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 25日 星期五 19:40:34 CST
*/
#ifndef _ADDPERSON_DAO_
#define _ADDPERSON_DAO_
#include "BaseDAO.h"
#include "../../../domain/do/put/OrgGroupPersonlistDO.h"
#include "domain/vo/put/AddPersonVO.h"

/**
 * 示例表数据库操作实现
 */
class AddPersonDAO : public BaseDAO
{
public:
	// 插入数据
	uint64_t insert(const OrgGroupPersonlistDO& iObj);
};
#endif // !_ADDPERSON_DAO_
