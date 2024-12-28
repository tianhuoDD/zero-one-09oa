#pragma once
#ifndef _ADDMENU_MAPPER_
#define _ADDMENU_MAPPER_

#include "../../../../lib-mysql/include/Mapper.h"
//#include "../../domain/do/sample/SampleDO.h"
#include "../../../domain/do/Function-permissions/Org_role_menulistDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class AddmenuMapper : public Mapper<Org_role_menulistDO>
{
public:
	Org_role_menulistDO mapper(ResultSet* resultSet) const override
	{
		Org_role_menulistDO data;
		data.setrole_Id(resultSet->getString(1));
		data.setMenulist(resultSet->getString(2));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_