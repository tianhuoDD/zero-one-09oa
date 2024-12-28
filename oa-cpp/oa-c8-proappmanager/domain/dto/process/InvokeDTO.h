#pragma once
#ifndef _INVOKE_DTO_
#define _INVOKE_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class InvokeDTO : public oatpp::DTO {
	DTO_INIT(InvokeDTO, DTO);
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
	API_DTO_FIELD_DEFAULT(Boolean, xasync, "xasync");
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
	API_DTO_FIELD_DEFAULT(Boolean, xinternal, "xinternal");
	API_DTO_FIELD_DEFAULT(String, xinternalProject, "xinternalProject");
	API_DTO_FIELD_DEFAULT(String, xinvokeMode, "xinvokeMode");
	API_DTO_FIELD_DEFAULT(String, xjaxrsAddress, "xjaxrsAddress");
	API_DTO_FIELD_DEFAULT(String, xjaxrsBodyScript, "xjaxrsBodyScript");
	API_DTO_FIELD_DEFAULT(String, xjaxrsBodyScriptText, "xjaxrsBodyScriptText");
	API_DTO_FIELD_DEFAULT(String, xjaxrsContentType, "xjaxrsContentType");
	API_DTO_FIELD_DEFAULT(String, xjaxrsHeadScript, "xjaxrsHeadScript");
	API_DTO_FIELD_DEFAULT(String, xjaxrsHeadScriptText, "xjaxrsHeadScriptText");
	API_DTO_FIELD_DEFAULT(String, xjaxrsMethod, "xjaxrsMethod");
	API_DTO_FIELD_DEFAULT(String, xjaxrsParameterScript, "xjaxrsParameterScript");
	API_DTO_FIELD_DEFAULT(String, xjaxrsParameterScriptText, "xjaxrsParameterScriptText");
	API_DTO_FIELD_DEFAULT(String, xjaxrsResponseScript, "xjaxrsResponseScript");
	API_DTO_FIELD_DEFAULT(String, xjaxrsResponseScriptText, "xjaxrsResponseScriptText");
	API_DTO_FIELD_DEFAULT(Boolean, xjaxrsWithCipher, "xjaxrsWithCipher");
	API_DTO_FIELD_DEFAULT(String, xjaxwsAddress, "xjaxwsAddress");
	API_DTO_FIELD_DEFAULT(String, xjaxwsMethod, "xjaxwsMethod");
	API_DTO_FIELD_DEFAULT(String, xjaxwsParameterScript, "xjaxwsParameterScript");
	API_DTO_FIELD_DEFAULT(String, xjaxwsParameterScriptText, "xjaxwsParameterScriptText");
	API_DTO_FIELD_DEFAULT(String, xjaxwsResponseScript, "xjaxwsResponseScript");
	API_DTO_FIELD_DEFAULT(String, xjaxwsResponseScriptText, "xjaxwsResponseScriptText");
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
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_INVOKE_DTO_