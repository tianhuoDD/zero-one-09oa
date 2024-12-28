#pragma once
#ifndef _ROUTE_DO_
#define _ROUTE_DO_
#include "../DoInclude.h"

class RouteDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	CC_SYNTHESIZE(string, xactivity, Xactivity);
	CC_SYNTHESIZE(string, xactivityType, XactivityType);
	CC_SYNTHESIZE(string, xalias, Xalias);
	CC_SYNTHESIZE(string, xappendTaskIdentityScript, XappendTaskIdentityScript);
	CC_SYNTHESIZE(string, xappendTaskIdentityScriptText, XappendTaskIdentityScriptText);
	CC_SYNTHESIZE(string, xappendTaskIdentityType, XappendTaskIdentityType);
	CC_SYNTHESIZE(string, xdecisionOpinion, XdecisionOpinion);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xdisplayNameScript, XdisplayNameScript);
	CC_SYNTHESIZE(string, xdisplayNameScriptText, XdisplayNameScriptText);
	CC_SYNTHESIZE(string, xedition, Xedition);
	CC_SYNTHESIZE(string, xhiddenScript, XhiddenScript);
	CC_SYNTHESIZE(string, xhiddenScriptText, XhiddenScriptText);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(string, xopinion, Xopinion);
	CC_SYNTHESIZE(bool, xopinionRequired, XopinionRequired);
	CC_SYNTHESIZE(int, xorderNumber, XorderNumber);
	CC_SYNTHESIZE(bool, xpassExpired, XpassExpired);
	CC_SYNTHESIZE(bool, xpassSameTarget, XpassSameTarget);
	CC_SYNTHESIZE(string, xposition, Xposition);
	CC_SYNTHESIZE(string, xprocess, Xprocess);
	CC_SYNTHESIZE(string, xproperties, Xproperties);
	CC_SYNTHESIZE(string, xscript, Xscript);
	CC_SYNTHESIZE(string, xscriptText, XscriptText);
	CC_SYNTHESIZE(string, xselectConfig, XselectConfig);
	CC_SYNTHESIZE(bool, xsole, Xsole);
	CC_SYNTHESIZE(string, xtrack, Xtrack);
	CC_SYNTHESIZE(string, xtype, Xtype);
	CC_SYNTHESIZE(string, xvalidationScript, XvalidationScript);
	CC_SYNTHESIZE(string, xvalidationScriptText, XvalidationScriptText);
public:
	RouteDO() {
		this->xid = "";
		this->xcreateTime = "";
		this->xsequence = "";
		this->xupdateTime = "";
		this->xdistributeFactor = 0;
		this->xactivity = "";
		this->xactivityType = "";
		this->xalias = "";
		this->xappendTaskIdentityScript = "";
		this->xappendTaskIdentityScriptText = "";
		this->xappendTaskIdentityType = "";
		this->xdecisionOpinion = "";
		this->xdescription = "";
		this->xdisplayNameScript = "";
		this->xdisplayNameScriptText = "";
		this->xedition = "";
		this->xhiddenScript = "";
		this->xhiddenScriptText = "";
		this->xname = "";
		this->xopinion = "";
		this->xopinionRequired = false;
		this->xorderNumber = 0;
		this->xpassExpired = false;
		this->xpassSameTarget = false;
		this->xposition = "";
		this->xprocess = "";
		this->xproperties = "";
		this->xscript = "";
		this->xscriptText = "";
		this->xselectConfig = "";
		this->xsole = false;
		this->xtrack = "";
		this->xtype = "";
		this->xvalidationScript = "";
		this->xvalidationScriptText = "";
		}
};

#endif // !_ROUTE_DO_