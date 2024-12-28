#pragma once
#ifndef _PROCESSINFO_DO_
#define _PROCESSINFO_DO_

#include "../DoInclude.h"

/**
 * 流程详情数据库实体类
 */
class ProcessInfoDO {
	CC_SYNTHESIZE(string, xid, Xid);
	CC_SYNTHESIZE(string, xagentList, XagentList);
	CC_SYNTHESIZE(string, xbegin, Xbegin);
	CC_SYNTHESIZE(string, xcancelList, XcancelList);
	CC_SYNTHESIZE(string, xchoiceList, XchoiceList);
	CC_SYNTHESIZE(string, xdelayList, XdelayList);
	CC_SYNTHESIZE(string, xembedList, XembedList);
	CC_SYNTHESIZE(string, xendList, XendList);
	CC_SYNTHESIZE(string, xinvokeList, XinvokeList);
	CC_SYNTHESIZE(string, xmanualList, XmanualList);
	CC_SYNTHESIZE(string, xmergerList, XmergerList);
	CC_SYNTHESIZE(string, xrouteList, XrouteList);
	CC_SYNTHESIZE(string, xparallelList, XparallelList);
	CC_SYNTHESIZE(string, xpublishList, XpublishList);
	CC_SYNTHESIZE(string, xserviceList, XserviceList);
	CC_SYNTHESIZE(string, xsplitList, XsplitList);
	CC_SYNTHESIZE(string, xname, Xname);
	CC_SYNTHESIZE(string, xalias, Xalias);
	CC_SYNTHESIZE(string, xdescription, Xdescription);
	CC_SYNTHESIZE(string, xcreatorPerson, XcreatorPerson);
	CC_SYNTHESIZE(string, xlastUpdatePerson, XlastUpdatePerson);
	CC_SYNTHESIZE(string, xlastUpdateTime, XlastUpdateTime);
	CC_SYNTHESIZE(string, xapplication, Xapplication);
	CC_SYNTHESIZE(string, xcontrollerList, XcontrollerList);
	CC_SYNTHESIZE(string, xafterBeginScript, XafterBeginScript);
	CC_SYNTHESIZE(string, xafterBeginScriptText, XafterBeginScriptText);
	CC_SYNTHESIZE(string, xafterEndScript, XafterEndScript);
	CC_SYNTHESIZE(string, xafterEndScriptText, XafterEndScriptText);
	CC_SYNTHESIZE(string, xstartableIdentityList, XstartableIdentityList);
	CC_SYNTHESIZE(string, xstartableUnitList, XstartableUnitList);
	CC_SYNTHESIZE(string, xstartableGroupList, XstartableGroupList);
	CC_SYNTHESIZE(string, xserialTexture, XserialTexture);
	CC_SYNTHESIZE(string, xserialPhase, XserialPhase);
	CC_SYNTHESIZE(string, xexpireType, XexpireType);
	CC_SYNTHESIZE(int, xexpireDay, XexpireDay);
	CC_SYNTHESIZE(int, xexpireHour, XexpireHour);
	CC_SYNTHESIZE(bool, xexpireWorkTime, XexpireWorkTime);
	CC_SYNTHESIZE(bool, xcheckDraft, XcheckDraft);
	CC_SYNTHESIZE(string, xstartableTerminal, XstartableTerminal);
	CC_SYNTHESIZE(bool, xprojectionFully, XprojectionFully);
	CC_SYNTHESIZE(bool, xrouteNameAsOption, XrouteNameAsOption);
	CC_SYNTHESIZE(string, xbeforeArriveScript, XbeforeArriveScript);
	CC_SYNTHESIZE(string, xbeforeArriveScriptText, XbeforeArriveScriptText);
	CC_SYNTHESIZE(string, xafterArriveScript, XafterArriveScript);
	CC_SYNTHESIZE(string, xafterArriveScriptText, XafterArriveScriptText);
	CC_SYNTHESIZE(string, xbeforeExecuteScript, XbeforeExecuteScript);
	CC_SYNTHESIZE(string, xbeforeExecuteScriptText, XbeforeExecuteScriptText);
	CC_SYNTHESIZE(string, xafterExecuteScript, XafterExecuteScript);
	CC_SYNTHESIZE(string, xafterExecuteScriptText, XafterExecuteScriptText);
	CC_SYNTHESIZE(string, xbeforeInquireScript, XbeforeInquireScript);
	CC_SYNTHESIZE(string, xbeforeInquireScriptText, XbeforeInquireScriptText);
	CC_SYNTHESIZE(string, xafterInquireScript, XafterInquireScript);
	CC_SYNTHESIZE(string, xafterInquireScriptText, XafterInquireScriptText);
	CC_SYNTHESIZE(string, xedition, Xedition);
	CC_SYNTHESIZE(string, xeditionName, XeditionName);
	CC_SYNTHESIZE(bool, xeditionEnable, XeditionEnable);
	CC_SYNTHESIZE(double, xeditionNumber, XeditionNumber);
	CC_SYNTHESIZE(string, xdefaultStartMode, XdefaultStartMode);
	CC_SYNTHESIZE(string, xproperties, Xproperties);
	CC_SYNTHESIZE(string, xcreateTime, XcreateTime);
	CC_SYNTHESIZE(string, xupdateTime, XupdateTime);
	CC_SYNTHESIZE(string, xisNewProcess, XisNewProcess);
	CC_SYNTHESIZE(string, xprojectionData, XprojectionData);
	CC_SYNTHESIZE(string, xapplicationName, XapplicationName);
	CC_SYNTHESIZE(string, xcategory, Xcategory);
	CC_SYNTHESIZE(string, xupdateTableEnable, XupdateTableEnable);
	CC_SYNTHESIZE(string, xdataTraceFieldType, XdataTraceFieldType);
public:
	ProcessInfoDO() {
		this->xid = "";
		this->xagentList = "";
		this->xbegin = "";
		this->xcancelList = "";
		this->xchoiceList = "";
		this->xdelayList = "";
		this->xembedList = "";
		this->xendList = "";
		this->xinvokeList = "";
		this->xmanualList = "";
		this->xmergerList = "";
		this->xrouteList = "";
		this->xparallelList = "";
		this->xpublishList = "";
		this->xserviceList = "";
		this->xsplitList = "";
		this->xname = "";
		this->xalias = "";
		this->xdescription = "";
		this->xcreatorPerson = "";
		this->xlastUpdatePerson = "";
		this->xlastUpdateTime = "";
		this->xapplication = "";
		this->xcontrollerList = "";
		this->xafterBeginScript = "";
		this->xafterBeginScriptText = "";
		this->xafterEndScript = "";
		this->xafterEndScriptText = "";
		this->xstartableIdentityList = "";
		this->xstartableUnitList = "";
		this->xstartableGroupList = "";
		this->xserialTexture = "";
		this->xserialPhase = "";
		this->xexpireType = "";
		this->xexpireDay = 0;
		this->xexpireHour = 0;
		this->xexpireWorkTime = false;
		this->xcheckDraft = false;
		this->xstartableTerminal = "";
		this->xprojectionFully = false;
		this->xrouteNameAsOption = false;
		this->xbeforeArriveScript = "";
		this->xbeforeArriveScriptText = "";
		this->xafterArriveScript = "";
		this->xafterArriveScriptText = "";
		this->xbeforeExecuteScript = "";
		this->xbeforeExecuteScriptText = "";
		this->xafterExecuteScript = "";
		this->xafterExecuteScriptText = "";
		this->xbeforeInquireScript = "";
		this->xbeforeInquireScriptText = "";
		this->xafterInquireScript = "";
		this->xafterInquireScriptText = "";
		this->xedition = "";
		this->xeditionName = "";
		this->xeditionEnable = false;
		this->xeditionNumber = 0;
		this->xdefaultStartMode = "";
		this->xproperties = "";
		this->xcreateTime = "";
		this->xupdateTime = "";
		this->xisNewProcess = "";
		this->xprojectionData = "";
		this->xapplicationName = "";
		this->xcategory = "";
		this->xupdateTableEnable = "";
		this->xdataTraceFieldType = "";
	}


};

#endif // !_PROCESSINFO_DO_
