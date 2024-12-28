#pragma once
#ifndef _ROLEGROUPLISTMAPPER_H_
#define _ROLEGROUPLISTMAPPER_H_

#include "Mapper.h"
#include "domain/do/del/rolegrouplist/OrgRoleGroupListDO.h"

class RoleGroupListMapper :public Mapper<oatpp::String>
{
public:
	oatpp::String mapper(ResultSet* resultSet) const override
	{
		
		oatpp::String data = resultSet->getString(1).c_str();
		return data;
	}
};



#endif // !_GROUPLISTMAPPER_H_
