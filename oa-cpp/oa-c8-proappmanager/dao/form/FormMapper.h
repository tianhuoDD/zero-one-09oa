#pragma once
#ifndef _FORM_MAPPER_
#define _FORM_MAPPER_

#include "Mapper.h"
#include "domain/do/form/FormDO.h"

/**
 * 表单列表匹配映射
 */
class FormListMapper : public Mapper<FormDO>
{
public:
	FormDO mapper(ResultSet* resultSet) const override
	{
		FormDO data;
		data.setId(resultSet->getString("xid"));
		data.setName(resultSet->getString("xname"));
		data.setCategory(resultSet->getString("xcategory"));
		data.setCreateTime(resultSet->getString("xcreateTime"));
		data.setUpdateTime(resultSet->getString("xupdateTime"));
		data.setLastUpdatePerson (resultSet->getString("xlastUpdatePerson"));
		data.setLastUpdateTime(resultSet->getString("xlastUpdateTime"));
		data.setAlias(resultSet->getString("xalias"));
		data.setApplication(resultSet->getString("xapplication"));
		data.setDescription(resultSet->getString("xdescription"));
		data.setHasMobile(resultSet->getBoolean("xhasMobile"));
		data.setIcon(resultSet->getString("xicon"));
		
		return data;
	}
};


/**
 * 表单详情字段匹配映射
 */
class FormInfoMapper : public Mapper<FormDO>
{
public:
	FormDO mapper(ResultSet* resultSet) const override
	{
		FormDO data;
		data.setId(resultSet->getString("xid"));
		data.setName(resultSet->getString("xname"));
		data.setCategory(resultSet->getString("xcategory"));
		data.setDescription(resultSet->getString("xdescription"));
		data.setData(resultSet->getString("xdata"));
		data.setCreateTime(resultSet->getString("xcreateTime"));
		data.setUpdateTime(resultSet->getString("xupdateTime"));
		data.setLastUpdatePerson(resultSet->getString("xlastUpdatePerson"));
		data.setLastUpdateTime(resultSet->getString("xlastUpdateTime"));
		data.setAlias(resultSet->getString("xalias"));
		data.setApplication(resultSet->getString("xapplication"));
		data.setProperties(resultSet->getString("xproperties"));
		data.setHasMobile(resultSet->getBoolean("xhasMobile"));
		data.setMobileData(resultSet->getString("xmobileData"));
		data.setIcon(resultSet->getString("xicon"));
		return data;
	}
};

/**
 * 表单类型及其数量匹配映射
 */
class FormCategoryMapper : public Mapper<FormDO>
{
public:
	FormDO mapper(ResultSet* resultSet) const override
	{
		FormDO data;
		data.setCategory(resultSet->getString("xcategory"));
		data.setNum(resultSet->getInt("xnum"));

		return data;
	}
};

#endif // !_FORM_MAPPER_