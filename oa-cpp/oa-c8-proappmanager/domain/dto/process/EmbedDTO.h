#pragma once
#ifndef _EMBED_DTO_
#define _EMBED_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EmbedDTO : public oatpp::DTO {
	DTO_INIT(EmbedDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, xid, "xid");
	API_DTO_FIELD_DEFAULT(String, xcreateTime, "xcreateTime");
	API_DTO_FIELD_DEFAULT(String, xsequence, "xsequence");
	API_DTO_FIELD_DEFAULT(String, xupdateTime, "xupdateTime");
	API_DTO_FIELD_DEFAULT(UInt64, xdistributeFactor, "xdistributeFactor");
	API_DTO_FIELD_DEFAULT(String, xafterArriveScript, "xafterArriveScript");
	API_DTO_FIELD_DEFAULT(String, xafterArriveScriptText, "xafterArriveScriptText");
	API_DTO_FIELD_DEFAULT(String, xafterExecuteScript, "xafterExecuteScript");
	API_DTO_FIELD_DEFAULT(String, xafterExecuteScriptText, "xafterExecuteScriptText");
	API_DTO_FIELD_DEFAULT(String, xafterInquireScript, "xafterInquireScript");
	API_DTO_FIELD_DEFAULT(String, xafterInquireScriptText, "xafterInquireScriptText");
	API_DTO_FIELD_DEFAULT(String, xalias, "xalias");
	API_DTO_FIELD_DEFAULT(Boolean, xallowReroute, "xallowReroute");
	API_DTO_FIELD_DEFAULT(Boolean, xallowRerouteTo, "xallowRerouteTo");
	API_DTO_FIELD_DEFAULT(String, xbeforeArriveScript, "xbeforeArriveScript");
	API_DTO_FIELD_DEFAULT(String, xbeforeArriveScriptText, "xbeforeArriveScriptText");
	API_DTO_FIELD_DEFAULT(String, xbeforeExecuteScript, "xbeforeExecuteScript");
	API_DTO_FIELD_DEFAULT(String, xbeforeExecuteScriptText, "xbeforeExecuteScriptText");
	API_DTO_FIELD_DEFAULT(String, xbeforeInquireScript, "xbeforeInquireScript");
	API_DTO_FIELD_DEFAULT(String, xbeforeInquireScriptText, "xbeforeInquireScriptText");
	API_DTO_FIELD_DEFAULT(String, xdescription, "xdescription");
	API_DTO_FIELD_DEFAULT(String, xdisplayLogScript, "xdisplayLogScript");
	API_DTO_FIELD_DEFAULT(String, xdisplayLogScriptText, "xdisplayLogScriptText");
	API_DTO_FIELD_DEFAULT(String, xedition, "xedition");
	API_DTO_FIELD_DEFAULT(String, xembedCreatorType, "xembedCreatorType");
	API_DTO_FIELD_DEFAULT(String, xextension, "xextension");
	API_DTO_FIELD_DEFAULT(String, xform, "xform");
	API_DTO_FIELD_DEFAULT(String, xgroup, "xgroup");
	API_DTO_FIELD_DEFAULT(Boolean, xinheritAttachment, "xinheritAttachment");
	API_DTO_FIELD_DEFAULT(Boolean, xinheritData, "xinheritData");
	API_DTO_FIELD_DEFAULT(String, xname, "xname");
	API_DTO_FIELD_DEFAULT(String, xopinionGroup, "xopinionGroup");
	API_DTO_FIELD_DEFAULT(String, xposition, "xposition");
	API_DTO_FIELD_DEFAULT(String, xprocess, "xprocess");
	API_DTO_FIELD_DEFAULT(String, xproperties, "xproperties");
	API_DTO_FIELD_DEFAULT(String, xreadDuty, "xreadDuty");
	API_DTO_FIELD_DEFAULT(String, xreadScript, "xreadScript");
	API_DTO_FIELD_DEFAULT(String, xreadScriptText, "xreadScriptText");
	API_DTO_FIELD_DEFAULT(String, xreviewDuty, "xreviewDuty");
	API_DTO_FIELD_DEFAULT(String, xreviewScript, "xreviewScript");
	API_DTO_FIELD_DEFAULT(String, xreviewScriptText, "xreviewScriptText");
	API_DTO_FIELD_DEFAULT(String, xroute, "xroute");
	API_DTO_FIELD_DEFAULT(String, xtargetApplication, "xtargetApplication");
	API_DTO_FIELD_DEFAULT(String, xtargetApplicationAlias, "xtargetApplicationAlias");
	API_DTO_FIELD_DEFAULT(String, xtargetApplicationName, "xtargetApplicationName");
	API_DTO_FIELD_DEFAULT(String, xtargetAssginDataScript, "xtargetAssginDataScript");
	API_DTO_FIELD_DEFAULT(String, xtargetAssginDataScriptText, "xtargetAssginDataScriptText");
	API_DTO_FIELD_DEFAULT(String, xtargetIdentity, "xtargetIdentity");
	API_DTO_FIELD_DEFAULT(String, xtargetIdentityScript, "xtargetIdentityScript");
	API_DTO_FIELD_DEFAULT(String, xtargetIdentityScriptText, "xtargetIdentityScriptText");
	API_DTO_FIELD_DEFAULT(String, xtargetProcess, "xtargetProcess");
	API_DTO_FIELD_DEFAULT(String, xtargetProcessAlias, "xtargetProcessAlias");
	API_DTO_FIELD_DEFAULT(String, xtargetProcessName, "xtargetProcessName");
	API_DTO_FIELD_DEFAULT(String, xtargetTitleScript, "xtargetTitleScript");
	API_DTO_FIELD_DEFAULT(String, xtargetTitleScriptText, "xtargetTitleScriptText");
	API_DTO_FIELD_DEFAULT(Boolean, xwaitUntilCompleted, "xwaitUntilCompleted");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EMBED_DTO_