#pragma once
#ifndef _FORMTEMPLATE_MAPPER_
#define _FORMTEMPLATE_MAPPER_
#include "Mapper.h"
#include "../../domain/do/formTemplateBuiltDO.h"

class FormTemplateBuiltMapper : public Mapper<formTemplateBuiltDO>
{
public:
	formTemplateBuiltDO mapper(ResultSet* resultSet) const override
	{
		formTemplateBuiltDO data;
		data.setId(resultSet->getString("xid"));
		data.setCreateTime(resultSet->getString("xcreateTime"));
		data.setSequence(resultSet->getString("xsequence"));
		data.setUpdateTime(resultSet->getString("xupdateTime"));
		data.setDistributeFactor(resultSet->getString("xdistributeFactor"));
		data.setAlias(resultSet->getString("xalias"));
		data.setCategory(resultSet->getString("xcategory"));
		data.setData(resultSet->getString("xdata"));
		data.setDescription(resultSet->getString("xdescription"));
		data.setIcon(resultSet->getString("xicon"));
		data.setMobileData(resultSet->getString("xmobileData"));
		data.setName(resultSet->getString("xname"));
		data.setOutline(resultSet->getString("xoutline"));
		return data;
	}
};

class FormTemplateCategoryMapper : public Mapper<formTemplateBuiltDO>
{
public:
	formTemplateBuiltDO mapper(ResultSet* resultSet) const override
	{
		formTemplateBuiltDO data;
		data.setCategory(resultSet->getString("xcategory"));
		data.setNum(resultSet->getInt("xnum"));

		return data;
	}
};
#endif