#pragma once
#ifndef _ADDROLE_SERVICE_
#define _ADDROLE_SERVICE_

#include <list>
#include "domain/vo/put/Addrole/AddroleVO.h"
#include "domain/dto/rolemanagement/RoleManagementDTO/put/addrole/AddroleDTO.h"

class AddroleService
{
public:
	// Ôö¼Ó½ÇÉ«
	uint64_t addRole(const AddroleDTO::Wrapper& dto);
};

#endif // !_ADDROLE_SERVICE_
