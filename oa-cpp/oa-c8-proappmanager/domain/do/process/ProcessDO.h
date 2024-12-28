#pragma once
#ifndef _PROCESS_DO_
#define _PROCESS_DO_
#include "../DoInclude.h"


class ProcessDO {	// 表pp_e_process
	// 唯一标识
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	CC_SYNTHESIZE(string, xsequence, Xsequence);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(int, xdistributeFactor, XdistributeFactor);
	CC_SYNTHESIZE(string, xafterArriveScript, XafterArriveScript);
	CC_SYNTHESIZE(string, xafterArriveScriptText, XafterArriveScriptText);
	CC_SYNTHESIZE(string, xafterBeginScript, XafterBeginScript);
	CC_SYNTHESIZE(string, xafterBeginScriptText, XafterBeginScriptText);
	CC_SYNTHESIZE(string, xafterEndScript, XafterEndScript);
	CC_SYNTHESIZE(string, xafterEndScriptText, XafterEndScriptText);
	CC_SYNTHESIZE(string, xafterExecuteScript, XafterExecuteScript);
	CC_SYNTHESIZE(string, xafterExecuteScriptText, XafterExecuteScriptText);
	CC_SYNTHESIZE(string, xafterInquireScript, XafterInquireScript);
	CC_SYNTHESIZE(string, xafterInquireScriptText, XafterInquireScriptText);
	CC_SYNTHESIZE(string, xalias, Xalias);
	CC_SYNTHESIZE(string, xapplication, Xapplication);
	CC_SYNTHESIZE(string, xbeforeArriveScript, XbeforeArriveScript);
	CC_SYNTHESIZE(string, xbeforeArriveScriptText, XbeforeArriveScriptText);
	CC_SYNTHESIZE(string, xbeforeExecuteScript, XbeforeExecuteScript);
	CC_SYNTHESIZE(string, xbeforeExecuteScriptText, XbeforeExecuteScriptText);
	CC_SYNTHESIZE(string, xbeforeInquireScript, XbeforeInquireScript);
	CC_SYNTHESIZE(string, xbeforeInquireScriptText, XbeforeInquireScriptText);
	CC_SYNTHESIZE(string, xcategory, Xcategory);
	CC_SYNTHESIZE(bool, xcheckDraft, XcheckDraft);
	CC_SYNTHESIZE(string, xcreatorPerson, XcreatorPerson);
	CC_SYNTHESIZE(string, xdefaultStartMode, XdefaultStartMode);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xedition, Xedition);
	CC_SYNTHESIZE(string, xeditionDes, XeditionDes);
	CC_SYNTHESIZE(bool, xeditionEnable, XeditionEnable);
	CC_SYNTHESIZE(string, xeditionName, XeditionName);
	CC_SYNTHESIZE(double, xeditionNumber, XeditionNumber);
	CC_SYNTHESIZE(int, xexpireDay, XexpireDay);
	CC_SYNTHESIZE(int, xexpireHour, XexpireHour);
	CC_SYNTHESIZE(string, xexpireType, XexpireType);
	CC_SYNTHESIZE(bool, xexpireWorkTime, XexpireWorkTime);
	CC_SYNTHESIZE(string, xicon, Xicon);
	CC_SYNTHESIZE(string, xlastUpdatePerson, XlastUpdatePerson);
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(string, xprojection, Xprojection);
	CC_SYNTHESIZE(bool, xprojectionFully, XprojectionFully);
	CC_SYNTHESIZE(string, xproperties, Xproperties);
	CC_SYNTHESIZE(bool, xrouteNameAsOpinion, XrouteNameAsOpinion);
	CC_SYNTHESIZE(string, xserialActivity, XserialActivity);
	CC_SYNTHESIZE(string, xserialPhase, XserialPhase);
	CC_SYNTHESIZE(string, xserialTexture, XserialTexture);
	CC_SYNTHESIZE(string, xstartableTerminal, XstartableTerminal);
public:
	ProcessDO() {
		this->xid = "";
		this->xcreateTime = "";
		this->xsequence = "";
		this->xupdateTime = "";
		this->xdistributeFactor = 0;
		this->xafterArriveScript = "";
		this->xafterArriveScriptText = "";
		this->xafterBeginScript = "";
		this->xafterBeginScriptText = "";
		this->xafterEndScript = "";
		this->xafterEndScriptText = "";
		this->xafterExecuteScript = "";
		this->xafterExecuteScriptText = "";
		this->xafterInquireScript = "";
		this->xafterInquireScriptText = "";
		this->xalias = "";
		this->xapplication = "";
		this->xbeforeArriveScript = "";
		this->xbeforeArriveScriptText = "";
		this->xbeforeExecuteScript = "";
		this->xbeforeExecuteScriptText = "";
		this->xbeforeInquireScript = "";
		this->xbeforeInquireScriptText = "";
		this->xcategory = "";
		this->xcheckDraft = false;
		this->xcreatorPerson = "";
		this->xdefaultStartMode = "";
		this->xdescription = "";
		this->xedition = "";
		this->xeditionDes = "";
		this->xeditionEnable = false;
		this->xeditionName = "";
		this->xeditionNumber = 0;
		this->xexpireDay = 0;
		this->xexpireHour = 0;
		this->xexpireType = "";
		this->xexpireWorkTime = false;
		this->xicon = "";
		this->xlastUpdatePerson = "";
		this->xlastUpdateTime = "";
		this->xname = "";
		this->xprojection = "";
		this->xprojectionFully = false;
		this->xproperties = "";
		this->xrouteNameAsOpinion = false;
		this->xserialActivity = "";
		this->xserialPhase = "";
		this->xserialTexture = "";
		this->xstartableTerminal = "";
	}	
};

#endif // !_PROCESS_DO_
