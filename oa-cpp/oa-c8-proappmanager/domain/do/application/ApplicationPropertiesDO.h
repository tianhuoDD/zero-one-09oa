#pragma once
#ifndef _APPLICATIONPROPERTIES_DO_
#define _APPLICATIONPROPERTIES_DO_

#include "../DoInclude.h"

class ApplicationPropertiesDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xicon, Xicon);
	CC_SYNTHESIZE(string, xalias, Xalias);
	CC_SYNTHESIZE(string, xapplicationCategory, XapplicationCategory);
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	CC_SYNTHESIZE(string, xcreatorPerson, XcreatorPerson);
	CC_SYNTHESIZE(string, xdefaultForm, XdefaultForm);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xlastUpdatePerson, XlastUpdatePerson);
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(string, xproperties, Xproperties);
public:
	ApplicationPropertiesDO() {
		this->xid = "";
		this->xalias = "";
		this->xapplicationCategory = "";
		this->xcreateTime = "";
		this->xcreatorPerson = "";
		this->xdefaultForm = "";
		this->xdescription = "";
		this->xlastUpdatePerson = "";
		this->xlastUpdateTime = "";
		this->xname = "";
		this->xupdateTime = "";
		this->xproperties = "";
	}
};

class AvailableGroupListDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	CC_SYNTHESIZE(string, xavailableGroupList, XavailableGroupList);
public:
	AvailableGroupListDO() {
		this->xid = "";
		this->xorderColumn = 0;
		this->xavailableGroupList = "";
	}
};

class AvailableIdentityListDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	CC_SYNTHESIZE(string, xavailableIdentityList, XavailableIdentityList);
public:
	AvailableIdentityListDO() {
		this->xid = "";
		this->xorderColumn = 0;
		this->xavailableIdentityList = "";
	}
};

class AvailableUnitListDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	CC_SYNTHESIZE(string, xavailableUnitList, XavailableUnitList);
public:
	AvailableUnitListDO() {
		this->xid = "";
		this->xorderColumn = 0;
		this->xavailableUnitList = "";
	}
};

class ControllerListDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(int, xorderColumn, XorderColumn);
	CC_SYNTHESIZE(string, xcontrollerList, XcontrollerList);
public:
	ControllerListDO() {
		this->xid = "";
		this->xorderColumn = 0;
		this->xcontrollerList = "";
	}
};



#endif // !_APPLICATIONPROPERTIES_DO_
