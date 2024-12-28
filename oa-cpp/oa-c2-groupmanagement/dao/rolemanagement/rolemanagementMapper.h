#pragma once

#ifndef _rolemanagement_MAPPER_
#define _rolemanagement_MAPPER_

#include "Mapper.h"
#include "../../domain/do/get/OrgGroupGrouplist/OrgGroupGrouplistDO.h"
#include "../../domain/do/get/OrgGroupUnitlist/OrgGroupUnitlistDO.h"

/**
 * ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class GetGroupMembersMapper : public Mapper<OrgGroupGrouplistDO>
{
public:
	OrgGroupGrouplistDO mapper(ResultSet* resultSet) const override
	{
		OrgGroupGrouplistDO data;
		data.setName(resultSet->getString(1));
		data.setAllname(resultSet->getString(2));
		return data;
	}
};

class GetOrganizationMembersMapper : public Mapper<OrgGroupUnitlistDO>
{
public:
	OrgGroupUnitlistDO mapper(ResultSet* resultSet) const override
	{
		OrgGroupUnitlistDO data;
		data.setName(resultSet->getString(1));
		data.setXunitList(resultSet->getString(2));
		return data;
	}
};

#endif 