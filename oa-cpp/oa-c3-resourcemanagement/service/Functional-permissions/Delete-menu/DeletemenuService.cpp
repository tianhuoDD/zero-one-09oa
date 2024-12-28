#include "stdafx.h"
#include "DeletemenuService.h"

#include "../../../controller/Functional-permissions/Delete-menu/DeletePermissionsController.h"
#include "../../../dao/Functional-permissions/Delete-menu/DeletemenuDAO.h"
uint64_t DeletemenuService::selectData(const DeletemenuDTO::Wrapper& dto)
{
	DeletemenuDAO dao;
	uint64_t count = 0;
	for (const auto& permission : *dto->permissions)
	{
		Org_role_menulistDO data;
		//对list中的每个元素赋值给data的成员
		data.setrole_Id(dto->role_id);
		data.setMenulist(permission);
		//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, role_Id, role_id, Permissions, permission)
		
		if (dao.selectbyall(data) <= 0)
		{
			count = 0;
			return count;
		}
		count += dao.selectbyall(data);
		

		
	}
	//DeletemenuDO data;
	
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, role_Id, role_id, Permissions, permission)
	//DeletemenuDAO dao;
	//return dao.selectbyall(data);
	return count;
}
uint64_t DeletemenuService::removeData(const DeletemenuDTO::Wrapper& dto)
{
	
	DeletemenuDAO dao;
	uint64_t count = 0;
	for (const auto& permission : *dto->permissions)
	{
		Org_role_menulistDO data;
		data.setrole_Id(dto->role_id);
		data.setMenulist(permission);
		//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, role_Id, role_id, Permissions, permission)

		count += dao.deleteById(data);
	}
	return count;
	//ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,role_Id,role_id,Permissions, permissions)
	
	
}
