#pragma once
#ifndef _MANUAL_DTO_
#define _MANUAL_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ManualDTO : public oatpp::DTO {
	DTO_INIT(ManualDTO, DTO);
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
	API_DTO_FIELD_DEFAULT(Boolean, xallowAddSplit, "xallowAddSplit");
	API_DTO_FIELD_DEFAULT(Boolean, xallowDeleteWork, "xallowDeleteWork");
	API_DTO_FIELD_DEFAULT(Boolean, xallowPause, "xallowPause");
	API_DTO_FIELD_DEFAULT(Boolean, xallowPress, "xallowPress");
	API_DTO_FIELD_DEFAULT(Boolean, xallowRapid, "xallowRapid");
	API_DTO_FIELD_DEFAULT(Boolean, xallowReroute, "xallowReroute");
	API_DTO_FIELD_DEFAULT(Boolean, xallowRerouteTo, "xallowRerouteTo");
	API_DTO_FIELD_DEFAULT(Boolean, xallowReset, "xallowReset");
	API_DTO_FIELD_DEFAULT(Boolean, xallowRetract, "xallowRetract");
	API_DTO_FIELD_DEFAULT(Boolean, xallowRollback, "xallowRollback");
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
	API_DTO_FIELD_DEFAULT(String, xextension, "xextension");
	API_DTO_FIELD_DEFAULT(String, xform, "xform");
	API_DTO_FIELD_DEFAULT(String, xgroup, "xgroup");
	API_DTO_FIELD_DEFAULT(String, xmanualAfterTaskScript, "xmanualAfterTaskScript");
	API_DTO_FIELD_DEFAULT(String, xmanualAfterTaskScriptText, "xmanualAfterTaskScriptText");
	API_DTO_FIELD_DEFAULT(String, xmanualBeforeTaskScript, "xmanualBeforeTaskScript");
	API_DTO_FIELD_DEFAULT(String, xmanualBeforeTaskScriptText, "xmanualBeforeTaskScriptText");
	API_DTO_FIELD_DEFAULT(Boolean, xmanualMergeSameJobActivity, "xmanualMergeSameJobActivity");
	API_DTO_FIELD_DEFAULT(String, xmanualMode, "xmanualMode");
	API_DTO_FIELD_DEFAULT(String, xmanualStayScript, "xmanualStayScript");
	API_DTO_FIELD_DEFAULT(String, xmanualStayScriptText, "xmanualStayScriptText");
	API_DTO_FIELD_DEFAULT(Boolean, xmanualUncompletedTaskToRead, "xmanualUncompletedTaskToRead");
	API_DTO_FIELD_DEFAULT(String, xname, "xname");
	API_DTO_FIELD_DEFAULT(String, xopinionGroup, "xopinionGroup");
	API_DTO_FIELD_DEFAULT(String, xposition, "xposition");
	API_DTO_FIELD_DEFAULT(String, xprocess, "xprocess");
	API_DTO_FIELD_DEFAULT(String, xproperties, "xproperties");
	API_DTO_FIELD_DEFAULT(String, xreadDuty, "xreadDuty");
	API_DTO_FIELD_DEFAULT(String, xreadScript, "xreadScript");
	API_DTO_FIELD_DEFAULT(String, xreadScriptText, "xreadScriptText");
	API_DTO_FIELD_DEFAULT(UInt64, xresetCount, "xresetCount");
	API_DTO_FIELD_DEFAULT(String, xresetRange, "xresetRange");
	API_DTO_FIELD_DEFAULT(String, xresetRangeScriptText, "xresetRangeScriptText");
	API_DTO_FIELD_DEFAULT(String, xreviewDuty, "xreviewDuty");
	API_DTO_FIELD_DEFAULT(String, xreviewScript, "xreviewScript");
	API_DTO_FIELD_DEFAULT(String, xreviewScriptText, "xreviewScriptText");
	API_DTO_FIELD_DEFAULT(String, xtaskDuty, "xtaskDuty");
	API_DTO_FIELD_DEFAULT(UInt64, xtaskExpireDay, "xtaskExpireDay");
	API_DTO_FIELD_DEFAULT(UInt64, xtaskExpireHour, "xtaskExpireHour");
	API_DTO_FIELD_DEFAULT(String, xtaskExpireScript, "xtaskExpireScript");
	API_DTO_FIELD_DEFAULT(String, xtaskExpireScriptText, "xtaskExpireScriptText");
	API_DTO_FIELD_DEFAULT(String, xtaskExpireType, "xtaskExpireType");
	API_DTO_FIELD_DEFAULT(Boolean, xtaskExpireWorkTime, "xtaskExpireWorkTime");
	API_DTO_FIELD_DEFAULT(String, xtaskScript, "xtaskScript");
	API_DTO_FIELD_DEFAULT(String, xtaskScriptText, "xtaskScriptText");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MANUAL_DTO_