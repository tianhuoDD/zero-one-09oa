#pragma once
#ifndef _ROLEINFOMAPPER_H_
#define _ROLEINFOMAPPER_H_

#include "Mapper.h"
#include "domain/do/OrgManagement/PersonalManagement/org_roleDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class RoleInfoMapper : public Mapper<org_roleDO>
{
public:
	org_roleDO mapper(ResultSet* resultSet) const override
	{
		org_roleDO data;
		data.setXname(resultSet->getString(1));
		data.setXdistinguishedName(resultSet->getString(2));
		data.setXdescription(resultSet->getString(3));
		return data;
	}
};

#endif // _ROLEINFOMAPPER_H_