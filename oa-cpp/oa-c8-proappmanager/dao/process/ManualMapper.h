#pragma once
#ifndef _MANUAL_MAPPER_
#define _MANUAL_MAPPER_
#include "Mapper.h"
#include "domain/do/process/ManualDO.h"


class ManualMapper : public Mapper<ManualDO> {
public:
	ManualDO mapper(ResultSet* resultSet) const override {
		ManualDO data;
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
		data.setXallowAddSplit(resultSet->getBoolean("xallowAddSplit"));
		data.setXallowDeleteWork(resultSet->getBoolean("xallowDeleteWork"));
		data.setXallowPause(resultSet->getBoolean("xallowPause"));
		data.setXallowPress(resultSet->getBoolean("xallowPress"));
		data.setXallowRapid(resultSet->getBoolean("xallowRapid"));
		data.setXallowReroute(resultSet->getBoolean("xallowReroute"));
		data.setXallowRerouteTo(resultSet->getBoolean("xallowRerouteTo"));
		data.setXallowReset(resultSet->getBoolean("xallowReset"));
		data.setXallowRetract(resultSet->getBoolean("xallowRetract"));
		data.setXallowRollback(resultSet->getBoolean("xallowRollback"));
		data.setXbeforeArriveScript(resultSet->getString("xbeforeArriveScript"));
		data.setXbeforeArriveScriptText(resultSet->getString("xbeforeArriveScriptText"));
		data.setXbeforeExecuteScript(resultSet->getString("xbeforeExecuteScript"));
		data.setXbeforeExecuteScriptText(resultSet->getString("xbeforeExecuteScriptText"));
		data.setXbeforeInquireScript(resultSet->getString("xbeforeInquireScript"));
		data.setXbeforeInquireScriptText(resultSet->getString("xbeforeInquireScriptText"));
		data.setXdescription(resultSet->getString("xdescription"));
		data.setXdisplayLogScript(resultSet->getString("xdisplayLogScript"));
		data.setXdisplayLogScriptText(resultSet->getString("xdisplayLogScriptText"));
		data.setXedition(resultSet->getString("xedition"));
		data.setXextension(resultSet->getString("xextension"));
		data.setXform(resultSet->getString("xform"));
		data.setXgroup(resultSet->getString("xgroup"));
		data.setXmanualAfterTaskScript(resultSet->getString("xmanualAfterTaskScript"));
		data.setXmanualAfterTaskScriptText(resultSet->getString("xmanualAfterTaskScriptText"));
		data.setXmanualBeforeTaskScript(resultSet->getString("xmanualBeforeTaskScript"));
		data.setXmanualBeforeTaskScriptText(resultSet->getString("xmanualBeforeTaskScriptText"));
		data.setXmanualMergeSameJobActivity(resultSet->getBoolean("xmanualMergeSameJobActivity"));
		data.setXmanualMode(resultSet->getString("xmanualMode"));
		data.setXmanualStayScript(resultSet->getString("xmanualStayScript"));
		data.setXmanualStayScriptText(resultSet->getString("xmanualStayScriptText"));
		data.setXmanualUncompletedTaskToRead(resultSet->getBoolean("xmanualUncompletedTaskToRead"));
		data.setXname(resultSet->getString("xname"));
		data.setXopinionGroup(resultSet->getString("xopinionGroup"));
		data.setXposition(resultSet->getString("xposition"));
		data.setXprocess(resultSet->getString("xprocess"));
		data.setXproperties(resultSet->getString("xproperties"));
		data.setXreadDuty(resultSet->getString("xreadDuty"));
		data.setXreadScript(resultSet->getString("xreadScript"));
		data.setXreadScriptText(resultSet->getString("xreadScriptText"));
		data.setXresetCount(resultSet->getInt("xresetCount"));
		data.setXresetRange(resultSet->getString("xresetRange"));
		data.setXresetRangeScriptText(resultSet->getString("xresetRangeScriptText"));
		data.setXreviewDuty(resultSet->getString("xreviewDuty"));
		data.setXreviewScript(resultSet->getString("xreviewScript"));
		data.setXreviewScriptText(resultSet->getString("xreviewScriptText"));
		data.setXtaskDuty(resultSet->getString("xtaskDuty"));
		data.setXtaskExpireDay(resultSet->getInt("xtaskExpireDay"));
		data.setXtaskExpireHour(resultSet->getInt("xtaskExpireHour"));
		data.setXtaskExpireScript(resultSet->getString("xtaskExpireScript"));
		data.setXtaskExpireScriptText(resultSet->getString("xtaskExpireScriptText"));
		data.setXtaskExpireType(resultSet->getString("xtaskExpireType"));
		data.setXtaskExpireWorkTime(resultSet->getBoolean("xtaskExpireWorkTime"));
		data.setXtaskScript(resultSet->getString("xtaskScript"));
		data.setXtaskScriptText(resultSet->getString("xtaskScriptText"));
		return data;
	}
};

#endif // !_MANUAL_MAPPER_