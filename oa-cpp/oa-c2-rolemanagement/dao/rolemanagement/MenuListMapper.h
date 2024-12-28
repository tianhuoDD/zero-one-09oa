#pragma once
#ifndef _MENULISTMAPPER_H_
#define _MENULISTMAPPER_H_

#include "Mapper.h"
#include "domain/do/get/roleresource/OrgResRoleMenuDO.h"

class MenuListMapper :public Mapper<oatpp::String>
{
public:
	oatpp::String mapper(ResultSet* resultSet) const override
	{

		oatpp::String data = resultSet->getString(1).c_str();
		return data;
	}
};



#endif // !_GROUPLISTMAPPER_H_
