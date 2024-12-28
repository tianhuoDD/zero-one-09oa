#pragma once
#ifndef _DELAY_MAPPER_
#define _DELAY_MAPPER_
#include "Mapper.h"
#include "domain/do/process/DelayDO.h"


class DelayMapper : public Mapper<DelayDO> {
public:
	DelayDO mapper(ResultSet* resultSet) const override {
		DelayDO data;
		data.setXid(resultSet->getString("xid"));
		data.setXcreateTime(resultSet->getString("xcreateTime"));
		data.setXsequence(resultSet->getString("xsequence"));
		data.setXupdateTime(resultSet->getString("xupdateTime"));
		data.setXdistributeFactor(resultSet->getInt("xdistributeFactor"));
		data.setXafterArriveScript(resultSet->getString("xafterArriveScript"));
		data.setXafterArriveScriptText(resultSet->getString("xafterArriveScriptText"));
		data.setXafterExecuteScript(resultSet->getString("xafterExecuteScript"));
		data.setXafterExecuteScriptText(resultSet->getString("xafterExecuteScriptText"));
		data.setXafterInquireScript(resultSet->getString("xafterInquireScript"));
		data.setXafterInquireScriptText(resultSet->getString("xafterInquireScriptText"));
		data.setXalias(resultSet->getString("xalias"));
		data.setXallowReroute(resultSet->getBoolean("xallowReroute"));
		data.setXallowRerouteTo(resultSet->getBoolean("xallowRerouteTo"));
		data.setXbeforeArriveScript(resultSet->getString("xbeforeArriveScript"));
		data.setXbeforeArriveScriptText(resultSet->getString("xbeforeArriveScriptText"));
		data.setXbeforeExecuteScript(resultSet->getString("xbeforeExecuteScript"));
		data.setXbeforeExecuteScriptText(resultSet->getString("xbeforeExecuteScriptText"));
		data.setXbeforeInquireScript(resultSet->getString("xbeforeInquireScript"));
		data.setXbeforeInquireScriptText(resultSet->getString("xbeforeInquireScriptText"));
		data.setXdelayDataPath(resultSet->getString("xdelayDataPath"));
		data.setXdelayMinute(resultSet->getInt("xdelayMinute"));
		data.setXdelayScript(resultSet->getString("xdelayScript"));
		data.setXdelayScriptText(resultSet->getString("xdelayScriptText"));
		data.setXdelayTime(resultSet->getString("xdelayTime"));
		data.setXdelayType(resultSet->getString("xdelayType"));
		data.setXdescription(resultSet->getString("xdescription"));
		data.setXdisplayLogScript(resultSet->getString("xdisplayLogScript"));
		data.setXdisplayLogScriptText(resultSet->getString("xdisplayLogScriptText"));
		data.setXedition(resultSet->getString("xedition"));
		data.setXextension(resultSet->getString("xextension"));
		data.setXform(resultSet->getString("xform"));
		data.setXgroup(resultSet->getString("xgroup"));
		data.setXname(resultSet->getString("xname"));
		data.setXopinionGroup(resultSet->getString("xopinionGroup"));
		data.setXposition(resultSet->getString("xposition"));
		data.setXprocess(resultSet->getString("xprocess"));
		data.setXproperties(resultSet->getString("xproperties"));
		data.setXreadDuty(resultSet->getString("xreadDuty"));
		data.setXreadScript(resultSet->getString("xreadScript"));
		data.setXreadScriptText(resultSet->getString("xreadScriptText"));
		data.setXreviewDuty(resultSet->getString("xreviewDuty"));
		data.setXreviewScript(resultSet->getString("xreviewScript"));
		data.setXreviewScriptText(resultSet->getString("xreviewScriptText"));
		data.setXroute(resultSet->getString("xroute"));
		data.setXworkMinute(resultSet->getBoolean("xworkMinute"));
		return data;
	}
};

#endif // !_DELAY_MAPPER_