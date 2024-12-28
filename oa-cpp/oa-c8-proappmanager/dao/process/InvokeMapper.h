#pragma once
#ifndef _INVOKE_MAPPER_
#define _INVOKE_MAPPER_
#include "Mapper.h"
#include "domain/do/process/InvokeDO.h"


class InvokeMapper : public Mapper<InvokeDO> {
public:
	InvokeDO mapper(ResultSet* resultSet) const override {
		InvokeDO data;
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
		data.setXasync(resultSet->getBoolean("xasync"));
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
		data.setXinternal(resultSet->getBoolean("xinternal"));
		data.setXinternalProject(resultSet->getString("xinternalProject"));
		data.setXinvokeMode(resultSet->getString("xinvokeMode"));
		data.setXjaxrsAddress(resultSet->getString("xjaxrsAddress"));
		data.setXjaxrsBodyScript(resultSet->getString("xjaxrsBodyScript"));
		data.setXjaxrsBodyScriptText(resultSet->getString("xjaxrsBodyScriptText"));
		data.setXjaxrsContentType(resultSet->getString("xjaxrsContentType"));
		data.setXjaxrsHeadScript(resultSet->getString("xjaxrsHeadScript"));
		data.setXjaxrsHeadScriptText(resultSet->getString("xjaxrsHeadScriptText"));
		data.setXjaxrsMethod(resultSet->getString("xjaxrsMethod"));
		data.setXjaxrsParameterScript(resultSet->getString("xjaxrsParameterScript"));
		data.setXjaxrsParameterScriptText(resultSet->getString("xjaxrsParameterScriptText"));
		data.setXjaxrsResponseScript(resultSet->getString("xjaxrsResponseScript"));
		data.setXjaxrsResponseScriptText(resultSet->getString("xjaxrsResponseScriptText"));
		data.setXjaxrsWithCipher(resultSet->getBoolean("xjaxrsWithCipher"));
		data.setXjaxwsAddress(resultSet->getString("xjaxwsAddress"));
		data.setXjaxwsMethod(resultSet->getString("xjaxwsMethod"));
		data.setXjaxwsParameterScript(resultSet->getString("xjaxwsParameterScript"));
		data.setXjaxwsParameterScriptText(resultSet->getString("xjaxwsParameterScriptText"));
		data.setXjaxwsResponseScript(resultSet->getString("xjaxwsResponseScript"));
		data.setXjaxwsResponseScriptText(resultSet->getString("xjaxwsResponseScriptText"));
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
		return data;
	}
};

#endif // !_INVOKE_MAPPER_