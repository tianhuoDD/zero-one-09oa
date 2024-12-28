#pragma once
#ifndef _DELETEDAO_
#define _DELETEDAO_
#include"../../domain/do/org_personDo/org_personDO.h"
#include "BaseDAO.h"

/**
 * 示例表数据库操作实现
 */
class DeleteDao : public BaseDAO
{
public:
	 
	// 通过ID删除数据
	int deleteById(string id);
 
};
#endif  