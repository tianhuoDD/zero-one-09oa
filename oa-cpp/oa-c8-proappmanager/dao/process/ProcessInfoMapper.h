#pragma once
#ifndef _PROCESSINFO_MAPPER_
#define _PROCESSINFO_MAPPER_

#include "Mapper.h"
#include "domain/do/process/ProcessInfoDO.h"

/**
 * 流程详情数据库实体映射类
 */
class ProcessInfoMapper : public Mapper<ProcessInfoDO> {
public:
	ProcessInfoDO mapper(ResultSet* resultSet) const override {
		ProcessInfoDO data;
		data.setXid(resultSet->getString("xid"));
		//data.setXagentList(resultSet->getString("xagentList"));
		//data.setXbegin(resultSet->getString("xbegin"));
		/*data.setXcancelList(resultSet->getString("xcancelList"));
		data.setXchoiceList(resultSet->getString("xchoiceList"));
		data.setXdelayList(resultSet->getString("xdelayList"));
		data.setXembedList(resultSet->getString("xembedList"));
		data.setXendList(resultSet->getString("xendList"));
		data.setXinvokeList(resultSet->getString("xinvokeList"));
		data.setXmanualList(resultSet->getString("xmanualList"));
		data.setXmergerList(resultSet->getString("xmergerList"));
		data.setXrouteList(resultSet->getString("xrouteList"));
		data.setXparallelList(resultSet->getString("xparallelList"));
		data.setXpublishList(resultSet->getString("xpublishList"));
		data.setXserviceList(resultSet->getString("xserviceList"));
		data.setXsplitList(resultSet->getString("xsplitList"));*/
		data.setXname(resultSet->getString("xname"));
		data.setXalias(resultSet->getString("xalias"));
		data.setXdescription(resultSet->getString("xdescription"));
		data.setXcreatorPerson(resultSet->getString("xcreatorPerson"));
		data.setXlastUpdatePerson(resultSet->getString("xlastUpdatePerson"));
		data.setXlastUpdateTime(resultSet->getString("xlastUpdateTime"));
		data.setXapplication(resultSet->getString("xapplication"));
		//data.setXcontrollerList(resultSet->getString("xcontrollerList"));
		data.setXafterBeginScript(resultSet->getString("xafterBeginScript"));
		data.setXafterBeginScriptText(resultSet->getString("xafterBeginScriptText"));
		data.setXafterEndScript(resultSet->getString("xafterEndScript"));
		data.setXafterEndScriptText(resultSet->getString("xafterEndScriptText"));
		//data.setXstartableIdentityList(resultSet->getString("xstartableIdentityList"));
		//data.setXstartableUnitList(resultSet->getString("xstartableUnitList"));
		//data.setXstartableGroupList(resultSet->getString("xstartableGroupList"));
		data.setXserialTexture(resultSet->getString("xserialTexture"));
		data.setXserialPhase(resultSet->getString("xserialPhase"));
		data.setXexpireType(resultSet->getString("xexpireType"));
		data.setXexpireDay(resultSet->getInt("xexpireDay"));
		data.setXexpireHour(resultSet->getInt("xexpireHour"));
		data.setXexpireWorkTime(resultSet->getBoolean("xexpireWorkTime"));
		data.setXcheckDraft(resultSet->getBoolean("xcheckDraft"));
		data.setXstartableTerminal(resultSet->getString("xstartableTerminal"));
		data.setXprojectionFully(resultSet->getBoolean("xprojectionFully"));
		data.setXrouteNameAsOption(resultSet->getBoolean("xrouteNameAsOpinion"));
		data.setXbeforeArriveScript(resultSet->getString("xbeforeArriveScript"));
		data.setXbeforeArriveScriptText(resultSet->getString("xbeforeArriveScriptText"));
		data.setXafterArriveScript(resultSet->getString("xafterArriveScript"));
		data.setXafterArriveScriptText(resultSet->getString("xafterArriveScriptText"));
		data.setXbeforeExecuteScript(resultSet->getString("xbeforeExecuteScript"));
		data.setXbeforeExecuteScriptText(resultSet->getString("xbeforeExecuteScriptText"));
		data.setXafterExecuteScript(resultSet->getString("xafterExecuteScript"));
		data.setXafterExecuteScriptText(resultSet->getString("xafterExecuteScriptText"));
		data.setXbeforeInquireScript(resultSet->getString("xbeforeInquireScript"));
		data.setXbeforeInquireScriptText(resultSet->getString("xbeforeInquireScriptText"));
		data.setXafterInquireScript(resultSet->getString("xafterInquireScript"));
		data.setXafterInquireScriptText(resultSet->getString("xafterInquireScriptText"));
		data.setXedition(resultSet->getString("xedition"));
		data.setXeditionName(resultSet->getString("xeditionName"));
		data.setXeditionEnable(resultSet->getBoolean("xeditionEnable"));
		data.setXeditionNumber(resultSet->getDouble("xeditionNumber"));
		data.setXdefaultStartMode(resultSet->getString("xdefaultStartMode"));
		data.setXproperties(resultSet->getString("xproperties"));
		data.setXcreateTime(resultSet->getString("xcreateTime"));
		data.setXupdateTime(resultSet->getString("xupdateTime"));
		//data.setXisNewProcess(resultSet->getString("xisNewProcess"));
		//data.setXprojectionData(resultSet->getString("xprojectionData"));
		//data.setXapplicationName(resultSet->getString("xapplicationName"));
		data.setXcategory(resultSet->getString("xcategory"));
		//data.setXupdateTableEnable(resultSet->getString("xupdateTableEnable"));
		//data.setXdataTraceFieldType(resultSet->getString("xdataTraceFieldType"));
		return data;
	}
};

#endif // !_PROCESSINFO_MAPPER_