#pragma once
#ifndef _ADDROLE_DAO_
#define _ADDROLE_DAO_

#include "BaseDAO.h"
#include "domain/do/rolemanagement/RoleManagementDO/put/addrole/AddroleDO.h"

class AddroleDAO : public BaseDAO {
public:
	// 插入数据
	uint64_t insert(const AddroleDO& iObj);
	// 查询数据
	uint64_t count(const AddroleDO& iObj);
};

#endif // !_ADDROLE_DAO_