#pragma once
#ifndef _MODIFY_MENULIST_FUCTION_PERMISSIONSMAPPER_
#define _MODIFY_MENULIST_FUCTION_PERMISSIONSMAPPER_

#include "Mapper.h"

#include "../../domain/do/modify/org_menulistDO.h"

class modify_menulist_fuction_permissionsMapper : public Mapper<org_menulistDO>
{
public:
	org_menulistDO mapper(ResultSet* resultSet) const override
	{
		org_menulistDO data;
		data.setRole_id(resultSet->getString("1"));
		data.setMenuList(resultSet->getString("2"));
		data.setXorderColumn(resultSet->getInt(-1));

		return data;
	}
};












#endif // !_MODIFY_MENULIST_FUCTION_PERMISSIONSMAPPER_
