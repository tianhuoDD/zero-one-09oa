#pragma once

#ifndef _SHEETMAPPER_H_
#define _SHEETMAPPER_H_

#include "Mapper.h"
#include "domain/do/personexport/excel/SheetDO.h"

class Sheet1Mapper : public Mapper<Sheet1DO>
{
public:
	Sheet1DO mapper(ResultSet* resultSet) const override
	{
		Sheet1DO data;
		data.setOrg_name(resultSet->getString(1));
		data.setOrg_uqcode(resultSet->getString(2));
		data.setOrg_typename(resultSet->getString(3));
		data.setOrg_porgcode(resultSet->getString(4));
		data.setOrg_description(resultSet->getString(5));
		data.setOrg_sortorder(resultSet->getString(6));

		return data;
	}
};

class Sheet2Mapper : public Mapper<Sheet2DO>
{
public:
	Sheet2DO mapper(ResultSet* resultSet) const override
	{
		Sheet2DO data;
		data.setPerson_name(resultSet->getString(1));
		data.setPerson_uqcode(resultSet->getString(2));
		data.setPerson_mobilenumber(resultSet->getString(3));
		data.setPerson_id(resultSet->getString(4));
		data.setPerson_officephone(resultSet->getString(5));
		data.setPerson_gender(resultSet->getString(6));
		data.setPerson_email(resultSet->getString(7));
		return data;
	}
};

class Sheet3Mapper : public Mapper<Sheet3DO>
{
public:
	Sheet3DO mapper(ResultSet* resultSet) const override
	{
		Sheet3DO data;
		data.setPerson_uqcode(resultSet->getString(1));
		data.setOrg_uqcode(resultSet->getString(2));
		data.setOrg_identity(resultSet->getString(3));
		
		bool xmajor = resultSet->getBoolean(4);
		if (xmajor)	data.setPrimary("true");
		else        data.setPrimary("false");

		return data;
	}
};

class Sheet4Mapper : public Mapper<Sheet4DO>
{
public:
	Sheet4DO mapper(ResultSet* resultSet) const override
	{
		Sheet4DO data;
		data.setPosition_name(resultSet->getString(1));
		data.setPosition_org_ucode(resultSet->getString(2));
		data.setPosition_code(resultSet->getString(3));
		data.setPosition_description(resultSet->getString(4));
		data.setPosition_person_ucode(resultSet->getString(5));
		data.setPerson_and_org_ucode_in_position(resultSet->getString(6));

		return data;
	}
};

class Sheet5Mapper : public Mapper<Sheet5DO>
{
public:
	Sheet5DO mapper(ResultSet* resultSet) const override
	{
		Sheet5DO data;
		data.setGroup_name(resultSet->getString(1));
		data.setGroup_code(resultSet->getString(2));
		data.setPerson_uqcode(resultSet->getString(3));
		data.setOrg_identity(resultSet->getString(4));
		data.setOrg_uqcode(resultSet->getString(5));
		data.setSubgroup_code(resultSet->getString(6));
		data.setGroup_description(resultSet->getString(7));

		return data;
	}
};
#endif