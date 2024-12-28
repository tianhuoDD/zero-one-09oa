#pragma once
#ifndef _SEARCHDUTYMAPPER_H_
#define _SEARCHDUTYMAPPER_H_

#include "Mapper.h"
#include "domain/do/OrgManagement/PersonalManagement/org_unitdutyDO.h"
#include "domain/do/OrgManagement/PersonalManagement/org_unitDO.h"
/**
 * 示例表字段匹配映射
 */
class SearchDutyMapper : public Mapper<pair<org_unitdutyDO, org_unitDO>>
{
public:
	pair<org_unitdutyDO, org_unitDO> mapper(ResultSet* resultSet) const override
	{
		pair<org_unitdutyDO, org_unitDO> data;
		data.first.setXname(resultSet->getString(1));
		data.second.setXlevelName(resultSet->getString(2));
		return data;
	}
};

#endif // !_SEARCHDUTYMAPPER_H_