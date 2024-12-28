#pragma once
#ifndef _APPLICATIONPROPERTIES_MAPPER_
#define _APPLICATIONPROPERTIES_MAPPER_

#include "Mapper.h"
#include "domain/do/application/ApplicationPropertiesDO.h"

class ApplicationPropertiesMapper : public Mapper<ApplicationPropertiesDO> {
public:
	ApplicationPropertiesDO mapper(ResultSet* res) const override {
		ApplicationPropertiesDO obj;
		obj.setXid(res->getString("xid"));
		obj.setXicon(res->getString("xicon"));
		obj.setXalias(res->getString("xalias"));
		obj.setXapplicationCategory(res->getString("xapplicationCategory"));
		obj.setXcreateTime(res->getString("xcreateTime"));
		obj.setXcreatorPerson(res->getString("xcreatorPerson"));
		obj.setXdescription(res->getString("xdescription"));
		obj.setXlastUpdatePerson(res->getString("xlastUpdatePerson"));
		obj.setXlastUpdateTime(res->getString("xlastUpdateTime"));
		obj.setXname(res->getString("xname"));
		obj.setXupdateTime(res->getString("xupdateTime"));
		obj.setXproperties(res->getString("xproperties"));
		return obj;
	}
};

class AvailableGroupListMapper : public Mapper<AvailableGroupListDO> {
public:
	AvailableGroupListDO mapper(ResultSet* res) const override {
		AvailableGroupListDO obj;
		obj.setXid(res->getString("APPLICATION_XID"));
		obj.setXorderColumn(res->getInt("xorderColumn"));
		obj.setXavailableGroupList(res->getString("xavailableGroupList"));
		return obj;
	}
};

class AvailableIdentityListMapper : public Mapper<AvailableIdentityListDO> {
public:
	AvailableIdentityListDO mapper(ResultSet* res) const override {
		AvailableIdentityListDO obj;
		obj.setXid(res->getString("APPLICATION_XID"));
		obj.setXorderColumn(res->getInt("xorderColumn"));
		obj.setXavailableIdentityList(res->getString("xavailableIdentityList"));
		return obj;
	}
};

class AvailableUnitListMapper : public Mapper<AvailableUnitListDO> {
public:
	AvailableUnitListDO mapper(ResultSet* res) const override {
		AvailableUnitListDO obj;
		obj.setXid(res->getString("APPLICATION_XID"));
		obj.setXorderColumn(res->getInt("xorderColumn"));
		obj.setXavailableUnitList(res->getString("xavailableUnitList"));
		return obj;
	}
};

class ControllerListMapper : public Mapper<ControllerListDO> {
public:
	ControllerListDO mapper(ResultSet* res) const override {
		ControllerListDO obj;
		obj.setXid(res->getString("APPLICATION_XID"));
		obj.setXorderColumn(res->getInt("xorderColumn"));
		obj.setXcontrollerList(res->getString("xcontrollerList"));
		return obj;
	}
};

#endif // !_APPLICATIONPROPERTIES_MAPPER_
