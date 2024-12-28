
#include "stdafx.h"
#include"DelRoleService.h"
#include"../../dao/RoleManagementDAO/RoleManagementDAO.h"

bool DelRoleService::removeData(std::string id)
{
	DelRoleDAO dao;
	return dao.deleteById(id) == 1;
}
