#include "stdafx.h"
#include "modify_menulist_fpService.h"
#include "dao/modify/modify_menulist_function_permissionsDAO.h"
#include "../../domain/do/modify/org_menulistDO.h"

bool modify_menulist_fpService::updateData(const modify_menulist_fpDTO::Wrapper& dto)
{
	// 组装DO数据
	org_menulistDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Role_id, role_id, MenuList, menuList,XorderColumn,xorderColumn);
	// 执行数据修改
	modify_menulist_function_permissionsDAO dao;
	return dao.update(data) == 1;
}
