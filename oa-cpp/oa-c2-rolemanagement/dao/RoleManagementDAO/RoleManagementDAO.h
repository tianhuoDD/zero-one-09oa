#pragma once
#ifndef _DELROLE_DAO_
#define _DELROLE_DAO_
#include"BaseDAO.h"
#include "domain/dto/get/GetroleDTO.h"


/**
 * 示例表数据库操作实现
 */
class DelRoleDAO : public BaseDAO
{
public:

	// 通过ID删除数据
	int deleteById(string id);
};

#endif // !_DELROLE_DAO_
