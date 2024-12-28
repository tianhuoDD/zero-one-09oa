#pragma once
#ifndef _PUBLISH_MAPPER_
#define _PUBLISH_MAPPER_
#include "Mapper.h"
#include "domain/do/process/PublishDO.h"


class PublishMapper : public Mapper<PublishDO> {
public:
	PublishDO mapper(ResultSet* resultSet) const override {
		PublishDO data;
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
		data.setXauthorDataPathList(resultSet->getString("xauthorDataPathList"));
		data.setXbeforeArriveScript(resultSet->getString("xbeforeArriveScript"));
		data.setXbeforeArriveScriptText(resultSet->getString("xbeforeArriveScriptText"));
		data.setXbeforeExecuteScript(resultSet->getString("xbeforeExecuteScript"));
		data.setXbeforeExecuteScriptText(resultSet->getString("xbeforeExecuteScriptText"));
		data.setXbeforeInquireScript(resultSet->getString("xbeforeInquireScript"));
		data.setXbeforeInquireScriptText(resultSet->getString("xbeforeInquireScriptText"));
		data.setXcategoryId(resultSet->getString("xcategoryId"));
		data.setXcategoryIdDataPath(resultSet->getString("xcategoryIdDataPath"));
		data.setXcategorySelectType(resultSet->getString("xcategorySelectType"));
		data.setXcmsCreatorIdentity(resultSet->getString("xcmsCreatorIdentity"));
		data.setXcmsCreatorScript(resultSet->getString("xcmsCreatorScript"));
		data.setXcmsCreatorScriptText(resultSet->getString("xcmsCreatorScriptText"));
		data.setXpublishCmsCreatorType(resultSet->getString("xpublishCmsCreatorType"));
		data.setXdescription(resultSet->getString("xdescription"));
		data.setXdisplayLogScript(resultSet->getString("xdisplayLogScript"));
		data.setXdisplayLogScriptText(resultSet->getString("xdisplayLogScriptText"));
		data.setXedition(resultSet->getString("xedition"));
		data.setXextension(resultSet->getString("xextension"));
		data.setXform(resultSet->getString("xform"));
		data.setXgroup(resultSet->getString("xgroup"));
		data.setXinheritAttachment(resultSet->getBoolean("xinheritAttachment"));
		data.setXname(resultSet->getString("xname"));
		data.setXnotifyDataPathList(resultSet->getString("xnotifyDataPathList"));
		data.setXopinionGroup(resultSet->getString("xopinionGroup"));
		data.setXpictureDataPathList(resultSet->getString("xpictureDataPathList"));
		data.setXposition(resultSet->getString("xposition"));
		data.setXprocess(resultSet->getString("xprocess"));
		data.setXproperties(resultSet->getString("xproperties"));
		data.setXpublishTarget(resultSet->getString("xpublishTarget"));
		data.setXreadDuty(resultSet->getString("xreadDuty"));
		data.setXreadScript(resultSet->getString("xreadScript"));
		data.setXreadScriptText(resultSet->getString("xreadScriptText"));
		data.setXreaderDataPathList(resultSet->getString("xreaderDataPathList"));
		data.setXreviewDuty(resultSet->getString("xreviewDuty"));
		data.setXreviewScript(resultSet->getString("xreviewScript"));
		data.setXreviewScriptText(resultSet->getString("xreviewScriptText"));
		data.setXroute(resultSet->getString("xroute"));
		data.setXtargetAssignDataScript(resultSet->getString("xtargetAssignDataScript"));
		data.setXtargetAssignDataScriptText(resultSet->getString("xtargetAssignDataScriptText"));
		data.setXtitleDataPath(resultSet->getString("xtitleDataPath"));
		data.setXuseProcessForm(resultSet->getBoolean("xuseProcessForm"));
		return data;
	}
};

#endif // !_PUBLISH_MAPPER_