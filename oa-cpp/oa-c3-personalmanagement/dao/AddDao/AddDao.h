#pragma once
#ifndef _ADDDAO_
#define _ADDDAO_
#include"../../domain/do/org_personDo/org_personDO.h"
#include "BaseDAO.h"

/**
 * 示例表数据库操作实现
 */
class AddDao : public BaseDAO
{
public:
	 
	// 插入数据
	uint64_t insert(const org_personDO& iObj);
 
};
#endif  