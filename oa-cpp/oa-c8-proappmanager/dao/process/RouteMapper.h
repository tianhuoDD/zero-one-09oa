#pragma once
#ifndef _ROUTE_MAPPER_
#define _ROUTE_MAPPER_
#include "Mapper.h"
#include "domain/do/process/RouteDO.h"


class RouteMapper : public Mapper<RouteDO> {
public:
	RouteDO mapper(ResultSet* resultSet) const override {
		RouteDO data;
		data.setXid(resultSet->getString("xid"));
		data.setXcreateTime(resultSet->getString("xcreateTime"));
		data.setXsequence(resultSet->getString("xsequence"));
		data.setXupdateTime(resultSet->getString("xupdateTime"));
		data.setXdistributeFactor(resultSet->getInt("xdistributeFactor"));
		data.setXactivity(resultSet->getString("xactivity"));
		data.setXactivityType(resultSet->getString("xactivityType"));
		data.setXalias(resultSet->getString("xalias"));
		data.setXappendTaskIdentityScript(resultSet->getString("xappendTaskIdentityScript"));
		data.setXappendTaskIdentityScriptText(resultSet->getString("xappendTaskIdentityScriptText"));
		data.setXappendTaskIdentityType(resultSet->getString("xappendTaskIdentityType"));
		data.setXdecisionOpinion(resultSet->getString("xdecisionOpinion"));
		data.setXdescription(resultSet->getString("xdescription"));
		data.setXdisplayNameScript(resultSet->getString("xdisplayNameScript"));
		data.setXdisplayNameScriptText(resultSet->getString("xdisplayNameScriptText"));
		data.setXedition(resultSet->getString("xedition"));
		data.setXhiddenScript(resultSet->getString("xhiddenScript"));
		data.setXhiddenScriptText(resultSet->getString("xhiddenScriptText"));
		data.setXname(resultSet->getString("xname"));
		data.setXopinion(resultSet->getString("xopinion"));
		data.setXopinionRequired(resultSet->getBoolean("xopinionRequired"));
		data.setXorderNumber(resultSet->getInt("xorderNumber"));
		data.setXpassExpired(resultSet->getBoolean("xpassExpired"));
		data.setXpassSameTarget(resultSet->getBoolean("xpassSameTarget"));
		data.setXposition(resultSet->getString("xposition"));
		data.setXprocess(resultSet->getString("xprocess"));
		data.setXproperties(resultSet->getString("xproperties"));
		data.setXscript(resultSet->getString("xscript"));
		data.setXscriptText(resultSet->getString("xscriptText"));
		data.setXselectConfig(resultSet->getString("xselectConfig"));
		data.setXsole(resultSet->getBoolean("xsole"));
		data.setXtrack(resultSet->getString("xtrack"));
		data.setXtype(resultSet->getString("xtype"));
		data.setXvalidationScript(resultSet->getString("xvalidationScript"));
		data.setXvalidationScriptText(resultSet->getString("xvalidationScriptText"));
		return data;
	}
};

#endif // !_ROUTE_MAPPER_