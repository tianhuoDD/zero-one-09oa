#pragma once
#ifndef _ROLERESOURCELISTMAPPER_H_
#define _ROLERESOURCELISTMAPPER_H_

#include "Mapper.h"
#include "domain/do/get/roleresource/RoleResourceDO.h"


class RoleResourceListMapper :public Mapper<RoleResourceDO>
{
public:
	RoleResourceDO mapper(ResultSet* resultSet) const override
	{

		RoleResourceDO data;
		data.setId(resultSet->getString(1));
		data.setText(resultSet->getString(2));
		data.setIs_button(resultSet->getUInt(3));
		data.setMenu_type(resultSet->getUInt(4));
		data.setParentId(resultSet->getString(5));
		return data;
	}
};

#endif
