#pragma once
#ifndef _ROUTE_DTO_
#define _ROUTE_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RouteDTO : public oatpp::DTO {
	DTO_INIT(RouteDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, xid, "xid");
	API_DTO_FIELD_DEFAULT(String, xcreateTime, "xcreateTime");
	API_DTO_FIELD_DEFAULT(String, xsequence, "xsequence");
	API_DTO_FIELD_DEFAULT(String, xupdateTime, "xupdateTime");
	API_DTO_FIELD_DEFAULT(UInt64, xdistributeFactor, "xdistributeFactor");
	API_DTO_FIELD_DEFAULT(String, xactivity, "xactivity");
	API_DTO_FIELD_DEFAULT(String, xactivityType, "xactivityType");
	API_DTO_FIELD_DEFAULT(String, xalias, "xalias");
	API_DTO_FIELD_DEFAULT(String, xappendTaskIdentityScript, "xappendTaskIdentityScript");
	API_DTO_FIELD_DEFAULT(String, xappendTaskIdentityScriptText, "xappendTaskIdentityScriptText");
	API_DTO_FIELD_DEFAULT(String, xappendTaskIdentityType, "xappendTaskIdentityType");
	API_DTO_FIELD_DEFAULT(String, xdecisionOpinion, "xdecisionOpinion");
	API_DTO_FIELD_DEFAULT(String, xdescription, "xdescription");
	API_DTO_FIELD_DEFAULT(String, xdisplayNameScript, "xdisplayNameScript");
	API_DTO_FIELD_DEFAULT(String, xdisplayNameScriptText, "xdisplayNameScriptText");
	API_DTO_FIELD_DEFAULT(String, xedition, "xedition");
	API_DTO_FIELD_DEFAULT(String, xhiddenScript, "xhiddenScript");
	API_DTO_FIELD_DEFAULT(String, xhiddenScriptText, "xhiddenScriptText");
	API_DTO_FIELD_DEFAULT(String, xname, "xname");
	API_DTO_FIELD_DEFAULT(String, xopinion, "xopinion");
	API_DTO_FIELD_DEFAULT(Boolean, xopinionRequired, "xopinionRequired");
	API_DTO_FIELD_DEFAULT(UInt64, xorderNumber, "xorderNumber");
	API_DTO_FIELD_DEFAULT(Boolean, xpassExpired, "xpassExpired");
	API_DTO_FIELD_DEFAULT(Boolean, xpassSameTarget, "xpassSameTarget");
	API_DTO_FIELD_DEFAULT(String, xposition, "xposition");
	API_DTO_FIELD_DEFAULT(String, xprocess, "xprocess");
	API_DTO_FIELD_DEFAULT(String, xproperties, "xproperties");
	API_DTO_FIELD_DEFAULT(String, xscript, "xscript");
	API_DTO_FIELD_DEFAULT(String, xscriptText, "xscriptText");
	API_DTO_FIELD_DEFAULT(String, xselectConfig, "xselectConfig");
	API_DTO_FIELD_DEFAULT(Boolean, xsole, "xsole");
	API_DTO_FIELD_DEFAULT(String, xtrack, "xtrack");
	API_DTO_FIELD_DEFAULT(String, xtype, "xtype");
	API_DTO_FIELD_DEFAULT(String, xvalidationScript, "xvalidationScript");
	API_DTO_FIELD_DEFAULT(String, xvalidationScriptText, "xvalidationScriptText");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ROUTE_DTO_