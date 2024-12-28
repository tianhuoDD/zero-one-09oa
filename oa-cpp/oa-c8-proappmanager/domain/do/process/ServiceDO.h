#pragma once
#ifndef _SERVICE_DO_
#define _SERVICE_DO_
#include "../DoInclude.h"

class ServiceDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	CC_SYNTHESIZE(string, xafterArriveScript, XafterArriveScript);
	CC_SYNTHESIZE(string, xafterArriveScriptText, XafterArriveScriptText);
	CC_SYNTHESIZE(string, xafterExecuteScript, XafterExecuteScript);
	CC_SYNTHESIZE(string, xafterExecuteScriptText, XafterExecuteScriptText);
	CC_SYNTHESIZE(string, xafterInquireScript, XafterInquireScript);
	CC_SYNTHESIZE(string, xafterInquireScriptText, XafterInquireScriptText);
	CC_SYNTHESIZE(string, xalias, Xalias);
	CC_SYNTHESIZE(bool, xallowReroute, XallowReroute);
	CC_SYNTHESIZE(bool, xallowRerouteTo, XallowRerouteTo);
	CC_SYNTHESIZE(string, xbeforeArriveScript, XbeforeArriveScript);
	CC_SYNTHESIZE(string, xbeforeArriveScriptText, XbeforeArriveScriptText);
	CC_SYNTHESIZE(string, xbeforeExecuteScript, XbeforeExecuteScript);
	CC_SYNTHESIZE(string, xbeforeExecuteScriptText, XbeforeExecuteScriptText);
	CC_SYNTHESIZE(string, xbeforeInquireScript, XbeforeInquireScript);
	CC_SYNTHESIZE(string, xbeforeInquireScriptText, XbeforeInquireScriptText);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xdisplayLogScript, XdisplayLogScript);
	CC_SYNTHESIZE(string, xdisplayLogScriptText, XdisplayLogScriptText);
	CC_SYNTHESIZE(string, xedition, Xedition);
	CC_SYNTHESIZE(string, xextension, Xextension);
	CC_SYNTHESIZE(string, xform, Xform);
	CC_SYNTHESIZE(string, xgroup, Xgroup);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(string, xopinionGroup, XopinionGroup);
	CC_SYNTHESIZE(string, xposition, Xposition);
	CC_SYNTHESIZE(string, xprocess, Xprocess);
	CC_SYNTHESIZE(string, xproperties, Xproperties);
	CC_SYNTHESIZE(string, xreadDuty, XreadDuty);
	CC_SYNTHESIZE(string, xreadScript, XreadScript);
	CC_SYNTHESIZE(string, xreadScriptText, XreadScriptText);
	CC_SYNTHESIZE(string, xreviewDuty, XreviewDuty);
	CC_SYNTHESIZE(string, xreviewScript, XreviewScript);
	CC_SYNTHESIZE(string, xreviewScriptText, XreviewScriptText);
	CC_SYNTHESIZE(string, xroute, Xroute);
	CC_SYNTHESIZE(string, xscript, Xscript);
	CC_SYNTHESIZE(string, xscriptText, XscriptText);
public:
	ServiceDO() {
		this->xid = "";
		this->xcreateTime = "";
		this->xsequence = "";
		this->xupdateTime = "";
		this->xdistributeFactor = 0;
		this->xafterArriveScript = "";
		this->xafterArriveScriptText = "";
		this->xafterExecuteScript = "";
		this->xafterExecuteScriptText = "";
		this->xafterInquireScript = "";
		this->xafterInquireScriptText = "";
		this->xalias = "";
		this->xallowReroute = false;
		this->xallowRerouteTo = false;
		this->xbeforeArriveScript = "";
		this->xbeforeArriveScriptText = "";
		this->xbeforeExecuteScript = "";
		this->xbeforeExecuteScriptText = "";
		this->xbeforeInquireScript = "";
		this->xbeforeInquireScriptText = "";
		this->xdescription = "";
		this->xdisplayLogScript = "";
		this->xdisplayLogScriptText = "";
		this->xedition = "";
		this->xextension = "";
		this->xform = "";
		this->xgroup = "";
		this->xname = "";
		this->xopinionGroup = "";
		this->xposition = "";
		this->xprocess = "";
		this->xproperties = "";
		this->xreadDuty = "";
		this->xreadScript = "";
		this->xreadScriptText = "";
		this->xreviewDuty = "";
		this->xreviewScript = "";
		this->xreviewScriptText = "";
		this->xroute = "";
		this->xscript = "";
		this->xscriptText = "";
		}
};

#endif // !_SERVICE_DO_