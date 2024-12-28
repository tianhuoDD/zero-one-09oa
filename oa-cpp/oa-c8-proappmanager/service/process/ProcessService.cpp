#include "stdafx.h"
#include "ProcessService.h"
#include "dao/process/ProcessDAO.h"
#include <list>
#include "SnowFlake.h"
#include <chrono>

// 查询流程类型及数量
ProcessTypesListVO::Wrapper ProcessService::listTypes(const oatpp::String& appId) {
	// 构建返回对象
	auto lvo = ProcessTypesListVO::createShared();

	// 查询流程类型及数量
	ProcessDAO dao;
	auto result = dao.selectTypes(appId);
	lvo->setTotal(result.size());
	// 将DO转换成VO
	for (auto sub : result) {
		auto vo = ProcessTypesVO::createShared();
		vo->xcategory = sub.getXcategory();
		vo->containNums = sub.getContainNums();
		lvo->addData(vo);
	}
	return lvo;
}

ProcessListPageDTO::Wrapper ProcessService::listProcess(const ProcessListQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = ProcessListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	ProcessDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) return pages;
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ProcessListDO> result = dao.selectProcess(query);
	// 将DO转换成DTO
	for (ProcessListDO sub : result) {
		auto dto = ProcessListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Xid, category, Xcategory, name, Xname, alias, Xalias, description, Xdescription, lastUpdateTime, XlastUpdateTime);
		pages->addData(dto);
	}
	return pages;
}


ProcessInfoDTO::Wrapper ProcessService::queryProcessInfo(const oatpp::String& id) {
	// 构建返回对象
	auto dto = ProcessInfoDTO::createShared();
	// 查询流程详情
	ProcessDAO dao;
	auto result = dao.selectProcessInfoMain(id);
	// 将DO转换成DTO
	// 主表数据
	for (ProcessInfoDO sub : result) {
		dto->id = sub.getXid();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Xname, alias, Xalias, description, Xdescription, creatorPerson, XcreatorPerson, lastUpdatePerson, XlastUpdatePerson, lastUpdateTime, XlastUpdateTime, application, Xapplication, afterBeginScript, XafterBeginScript, afterBeginScriptText, XafterBeginScriptText, afterEndScript, XafterEndScript, afterEndScriptText, XafterEndScriptText, serialTexture, XserialTexture, serialPhase, XserialPhase, expireType, XexpireType, expireDay, XexpireDay, expireHour, XexpireHour, expireWorkTime, XexpireWorkTime, checkDraft, XcheckDraft, startableTerminal, XstartableTerminal, projectionFully, XprojectionFully, routeNameAsOption, XrouteNameAsOption);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, beforeArriveScript, XbeforeArriveScript, beforeArriveScriptText, XbeforeArriveScriptText, afterArriveScript, XafterArriveScript, afterArriveScriptText, XafterArriveScriptText, beforeExecuteScript, XbeforeExecuteScript, beforeExecuteScriptText, XbeforeExecuteScriptText, afterExecuteScript, XafterExecuteScript, afterExecuteScriptText, XafterExecuteScriptText, beforeInquireScript, XbeforeInquireScript, beforeInquireScriptText, XbeforeInquireScriptText, afterInquireScript, XafterInquireScript, afterInquireScriptText, XafterInquireScriptText, edition, Xedition, editionName, XeditionName, editionEnable, XeditionEnable, editionNumber, XeditionNumber, defaultStartMode, XdefaultStartMode, properties, Xproperties, createTime, XcreateTime);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, updateTime, XupdateTime, isNewProcess, XisNewProcess, projectionData, XprojectionData, applicationName, XapplicationName, category, Xcategory, updateTableEnable, XupdateTableEnable, dataTraceFieldType, XdataTraceFieldType);
		break;
	}
	// 处理子表数据
	dto->agentList = queryAgentList(id);
	dto->begin = queryBeginList(id);
	dto->cancelList = queryCancelList(id);
	dto->choiceList = queryChoiceList(id);
	dto->delayList = queryDelayList(id);
	dto->embedList = queryEmbedList(id);
	dto->endList = queryEndList(id);
	dto->invokeList = queryInvokeList(id);
	dto->manualList = queryManualList(id);
	dto->mergerList = queryMergeList(id);
	dto->parallelList = queryParallelList(id);
	dto->controllerList = queryProcessControllerList(id);
	dto->startableGroupList = queryProcessStartableGroupList(id);
	dto->startableIdentityList = queryProcessStartableIdentityList(id);
	dto->startableUnitList = queryProcessStartableUnitList(id);
	dto->publishList = queryPublishList(id);
	dto->routeList = queryRouteList(id);
	dto->serviceList = queryServiceList(id);
	dto->splitList = querySplitList(id);
	return dto;
}



oatpp::List<AgentDTO::Wrapper> ProcessService::queryAgentList(const oatpp::String& process) {
	// 构建返回对象
	auto list = oatpp::List<AgentDTO::Wrapper>::createShared();
	// 查询流程详情
	ProcessDAO dao;
	auto result = dao.selectAgentList(process);
	// 将DO转换成DTO
	for (AgentDO sub : result) {
		auto dto = AgentDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xagentInterruptScript, XagentInterruptScript, xagentInterruptScriptText, XagentInterruptScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xopinionGroup, XopinionGroup, xprocess, Xprocess, xposition, Xposition, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText, xroute, Xroute, xscript, Xscript, xscriptText, XscriptText);
		list->push_back(dto);
	}
	return list;
}

BeginDTO::Wrapper ProcessService::queryBeginList(const oatpp::String& process) {
	ProcessDAO dao;
	auto result = dao.selectBeginList(process);
	for (BeginDO sub : result) {
		auto dto = BeginDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xname, Xname, xopinionGroup, XopinionGroup);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText, xroute, Xroute);
		return dto;
	}
	return BeginDTO::createShared();
}

oatpp::List<CancelDTO::Wrapper> ProcessService::queryCancelList(const oatpp::String& process) {
	auto list = oatpp::List<CancelDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectCancelList(process);
	for (CancelDO sub : result) {
		auto dto = CancelDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xname, Xname, xopinionGroup, XopinionGroup);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText);

		list->push_back(dto);
	}
	return list;
}

oatpp::List<ChoiceDTO::Wrapper> ProcessService::queryChoiceList(const oatpp::String& process) {
	auto list = oatpp::List<ChoiceDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectChoiceList(process);
	for (ChoiceDO sub : result) {
		auto dto = ChoiceDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xname, Xname, xopinionGroup, XopinionGroup);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText);


		list->push_back(dto);
	}
	return list;
}

oatpp::List<DelayDTO::Wrapper> ProcessService::queryDelayList(const oatpp::String& process) {
	auto list = oatpp::List<DelayDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectDelayList(process);
	for (DelayDO sub : result) {
		auto dto = DelayDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdelayDataPath, XdelayDataPath, xdelayMinute, XdelayMinute, xdelayScript, XdelayScript, xdelayScriptText, XdelayScriptText, xdelayTime, XdelayTime, xdelayType, XdelayType, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xextension, Xextension, xform, Xform, xgroup, Xgroup, xname, Xname, xopinionGroup, XopinionGroup, xposition, Xposition, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText, xroute, Xroute, xworkMinute, XworkMinute);


		list->push_back(dto);
	}
	return list;
}

oatpp::List<EmbedDTO::Wrapper> ProcessService::queryEmbedList(const oatpp::String& process) {
	auto list = oatpp::List<EmbedDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectEmbedList(process);
	for (EmbedDO sub : result) {
		auto dto = EmbedDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xembedCreatorType, XembedCreatorType, xextension, Xextension, xform, Xform, xgroup, Xgroup, xinheritAttachment, XinheritAttachment);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xname, Xname, xopinionGroup, XopinionGroup, xposition, Xposition, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText, xroute, Xroute, xtargetApplication, XtargetApplication, xtargetApplicationAlias, XtargetApplicationAlias, xtargetApplicationName, XtargetApplicationName, xtargetAssginDataScript, XtargetAssginDataScript, xtargetAssginDataScriptText, XtargetAssginDataScriptText, xtargetIdentity, XtargetIdentity, xtargetIdentityScript, XtargetIdentityScript, xtargetIdentityScriptText, XtargetIdentityScriptText, xtargetProcess, XtargetProcess, xtargetProcessAlias, XtargetProcessAlias, xtargetProcessName, XtargetProcessName, xtargetTitleScript, XtargetTitleScript, xtargetTitleScriptText, XtargetTitleScriptText, xwaitUntilCompleted, XwaitUntilCompleted);


		list->push_back(dto);
	}
	return list;
}

oatpp::List<EndDTO::Wrapper> ProcessService::queryEndList(const oatpp::String& process) {
	auto list = oatpp::List<EndDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectEndList(process);
	for (EndDO sub : result) {
		auto dto = EndDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xallowRollback, XallowRollback, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xname, Xname);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xposition, Xposition, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<InvokeDTO::Wrapper> ProcessService::queryInvokeList(const oatpp::String& process) {
	auto list = oatpp::List<InvokeDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectInvokeList(process);
	for (InvokeDO sub : result) {
		auto dto = InvokeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xasync, Xasync, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xinternal, Xinternal);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xinvokeMode, XinvokeMode, xjaxrsAddress, XjaxrsAddress, xjaxrsBodyScript, XjaxrsBodyScript, xjaxrsBodyScriptText, XjaxrsBodyScriptText, xjaxrsContentType, XjaxrsContentType, xjaxrsHeadScript, XjaxrsHeadScript, xjaxrsHeadScriptText, XjaxrsHeadScriptText, xjaxrsMethod, XjaxrsMethod, xjaxrsParameterScript, XjaxrsParameterScript, xjaxrsParameterScriptText, XjaxrsParameterScriptText, xjaxrsResponseScript, XjaxrsResponseScript, xjaxrsResponseScriptText, XjaxrsResponseScriptText, xjaxrsWithCipher, XjaxrsWithCipher, xjaxwsAddress, XjaxwsAddress, xjaxwsMethod, XjaxwsMethod, xjaxwsParameterScript, XjaxwsParameterScript, xjaxwsParameterScriptText, XjaxwsParameterScriptText, xjaxwsResponseScript, XjaxwsResponseScript, xjaxwsResponseScriptText, XjaxwsResponseScriptText, xname, Xname, xopinionGroup, XopinionGroup, xposition, Xposition, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xroute, Xroute);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<ManualDTO::Wrapper> ProcessService::queryManualList(const oatpp::String& process) {
	auto list = oatpp::List<ManualDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectManualList(process);
	for (ManualDO sub : result) {
		auto dto = ManualDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowAddSplit, XallowAddSplit, xallowDeleteWork, XallowDeleteWork, xallowPause, XallowPause, xallowPress, XallowPress, xallowRapid, XallowRapid, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xallowReset, XallowReset, xallowRetract, XallowRetract, xallowRollback, XallowRollback, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xmanualAfterTaskScript, XmanualAfterTaskScript, xmanualAfterTaskScriptText, XmanualAfterTaskScriptText, xmanualBeforeTaskScript, XmanualBeforeTaskScript, xmanualBeforeTaskScriptText, XmanualBeforeTaskScriptText, xmanualMergeSameJobActivity, XmanualMergeSameJobActivity, xmanualMode, XmanualMode, xmanualStayScript, XmanualStayScript, xmanualStayScriptText, XmanualStayScriptText, xmanualUncompletedTaskToRead, XmanualUncompletedTaskToRead, xname, Xname, xopinionGroup, XopinionGroup, xposition, Xposition, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xresetCount, XresetCount, xresetRange, XresetRange, xresetRangeScriptText, XresetRangeScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText, xtaskDuty, XtaskDuty);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xtaskExpireHour, XtaskExpireHour, xtaskExpireScript, XtaskExpireScript, xtaskExpireScriptText, XtaskExpireScriptText, xtaskExpireType, XtaskExpireType, xtaskExpireWorkTime, XtaskExpireWorkTime, xtaskScript, XtaskScript, xtaskScriptText, XtaskScriptText);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<MergeDTO::Wrapper> ProcessService::queryMergeList(const oatpp::String& process) {
	auto list = oatpp::List<MergeDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectMergeList(process);
	for (MergeDO sub : result) {
		auto dto = MergeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xname, Xname, xopinionGroup, XopinionGroup);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText, xroute, Xroute);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<ParallelDTO::Wrapper> ProcessService::queryParallelList(const oatpp::String& process) {
	auto list = oatpp::List<ParallelDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectParallelList(process);
	for (ParallelDO sub : result) {
		auto dto = ParallelDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xname, Xname, xopinionGroup, XopinionGroup);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<ProcessControllerDTO::Wrapper> ProcessService::queryProcessControllerList(const oatpp::String& process) {
	auto list = oatpp::List<ProcessControllerDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectProcessControllerList(process);
	for (ProcessControllerDO sub : result) {
		auto dto = ProcessControllerDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, PROCESS_XID, PROCESS_XID, xcontrollerList, XcontrollerList, xorderColumn, XorderColumn);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<ProcessStartableGroupDTO::Wrapper> ProcessService::queryProcessStartableGroupList(const oatpp::String& process) {
	auto list = oatpp::List<ProcessStartableGroupDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectProcessStartableGroupList(process);
	for (ProcessStartableGroupDO sub : result) {
		auto dto = ProcessStartableGroupDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, PROCESS_XID, PROCESS_XID, xstartableGroupList, XstartableGroupList, xorderColumn, XorderColumn);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<ProcessStartableIdentityDTO::Wrapper> ProcessService::queryProcessStartableIdentityList(const oatpp::String& process) {
	auto list = oatpp::List<ProcessStartableIdentityDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectProcessStartableIdentityList(process);
	for (ProcessStartableIdentityDO sub : result) {
		auto dto = ProcessStartableIdentityDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, PROCESS_XID, PROCESS_XID, xstartableIdentityList, XstartableIdentityList, xorderColumn, XorderColumn);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<ProcessStartableUnitDTO::Wrapper> ProcessService::queryProcessStartableUnitList(const oatpp::String& process) {
	auto list = oatpp::List<ProcessStartableUnitDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectProcessStartableUnitList(process);
	for (ProcessStartableUnitDO sub : result) {
		auto dto = ProcessStartableUnitDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, PROCESS_XID, PROCESS_XID, xstartableUnitList, XstartableUnitList, xorderColumn, XorderColumn);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<PublishDTO::Wrapper> ProcessService::queryPublishList(const oatpp::String& process) {
	auto list = oatpp::List<PublishDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectPublishList(process);
	for (PublishDO sub : result) {
		auto dto = PublishDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xauthorDataPathList, XauthorDataPathList, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xcategoryId, XcategoryId, xcategoryIdDataPath, XcategoryIdDataPath, xcategorySelectType, XcategorySelectType, xcmsCreatorIdentity, XcmsCreatorIdentity, xcmsCreatorScript, XcmsCreatorScript, xcmsCreatorScriptText, XcmsCreatorScriptText, xpublishCmsCreatorType, XpublishCmsCreatorType, xdescription, Xdescription);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xinheritAttachment, XinheritAttachment, xname, Xname, xnotifyDataPathList, XnotifyDataPathList, xopinionGroup, XopinionGroup, xpictureDataPathList, XpictureDataPathList, xposition, Xposition, xprocess, Xprocess, xproperties, Xproperties, xpublishTarget, XpublishTarget, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreaderDataPathList, XreaderDataPathList, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText, xroute, Xroute, xtargetAssignDataScript, XtargetAssignDataScript, xtargetAssignDataScriptText, XtargetAssignDataScriptText, xtitleDataPath, XtitleDataPath, xuseProcessForm, XuseProcessForm);
		list->push_back(dto);
	}
	return list;

}

oatpp::List<RouteDTO::Wrapper> ProcessService::queryRouteList(const oatpp::String& process) {
	auto list = oatpp::List<RouteDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectRouteList(process);
	for (RouteDO sub : result) {
		auto dto = RouteDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xactivity, Xactivity, xactivityType, XactivityType, xalias, Xalias, xappendTaskIdentityScript, XappendTaskIdentityScript, xappendTaskIdentityScriptText, XappendTaskIdentityScriptText, xappendTaskIdentityType, XappendTaskIdentityType, xdecisionOpinion, XdecisionOpinion, xdescription, Xdescription, xdisplayNameScript, XdisplayNameScript, xdisplayNameScriptText, XdisplayNameScriptText, xedition, Xedition, xhiddenScript, XhiddenScript, xhiddenScriptText, XhiddenScriptText, xname, Xname, xopinion, Xopinion, xopinionRequired, XopinionRequired, xorderNumber, XorderNumber, xpassExpired, XpassExpired, xpassSameTarget, XpassSameTarget, xposition, Xposition, xprocess, Xprocess, xproperties, Xproperties, xscript, Xscript, xscriptText, XscriptText);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xsole, Xsole, xtrack, Xtrack, xtype, Xtype, xvalidationScript, XvalidationScript, xvalidationScriptText, XvalidationScriptText);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<ServiceDTO::Wrapper> ProcessService::queryServiceList(const oatpp::String& process) {
	auto list = oatpp::List<ServiceDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectServiceList(process);
	for (ServiceDO sub : result) {
		auto dto = ServiceDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xname, Xname, xopinionGroup, XopinionGroup);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText, xroute, Xroute, xscript, Xscript, xscriptText, XscriptText);
		list->push_back(dto);
	}
	return list;
}

oatpp::List<SplitDTO::Wrapper> ProcessService::querySplitList(const oatpp::String& process) {
	auto list = oatpp::List<SplitDTO::Wrapper>::createShared();
	ProcessDAO dao;
	auto result = dao.selectSplitList(process);
	for (SplitDO sub : result) {
		auto dto = SplitDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xid, Xid, xcreateTime, XcreateTime, xsequence, Xsequence, xupdateTime, XupdateTime, xdistributeFactor, XdistributeFactor, xafterArriveScript, XafterArriveScript, xafterArriveScriptText, XafterArriveScriptText, xafterExecuteScript, XafterExecuteScript, xafterExecuteScriptText, XafterExecuteScriptText, xafterInquireScript, XafterInquireScript, xafterInquireScriptText, XafterInquireScriptText, xalias, Xalias, xallowReroute, XallowReroute, xallowRerouteTo, XallowRerouteTo, xbeforeArriveScript, XbeforeArriveScript, xbeforeArriveScriptText, XbeforeArriveScriptText, xbeforeExecuteScript, XbeforeExecuteScript, xbeforeExecuteScriptText, XbeforeExecuteScriptText, xbeforeInquireScript, XbeforeInquireScript, xbeforeInquireScriptText, XbeforeInquireScriptText, xdescription, Xdescription, xdisplayLogScript, XdisplayLogScript, xdisplayLogScriptText, XdisplayLogScriptText, xedition, Xedition, xextension, Xextension, xform, Xform, xgroup, Xgroup, xname, Xname, xopinionGroup, XopinionGroup);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, xprocess, Xprocess, xproperties, Xproperties, xreadDuty, XreadDuty, xreadScript, XreadScript, xreadScriptText, XreadScriptText, xreviewDuty, XreviewDuty, xreviewScript, XreviewScript, xreviewScriptText, XreviewScriptText, xroute, Xroute, xscript, Xscript, xscriptText, XscriptText);
		list->push_back(dto);
	}
	return list;
}


static string getCurrTimeWithMillis() {
	auto now = std::chrono::system_clock::now();
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	time_t now_c = std::chrono::system_clock::to_time_t(now);
	tm* ltm = localtime(&now_c);
	char timeStr[24];
	strftime(timeStr, sizeof(timeStr), "%Y%m%d%H%M%S", ltm);
	snprintf(timeStr + 14, sizeof(timeStr) - 14, "%03d", static_cast<int>(millis.count()));
	return string(timeStr);
}

static string getCurrTime() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	char timeStr[20];
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", ltm);
	return string(timeStr);
}

static string generateId() {
	SnowFlake sf(rand() % 32, rand() % 32);
	uint64_t id;
	int r = rand() % 10;
	for (int i = 0; i < r; i++) {
		sf.nextId();
	}
	id = sf.nextId();
	return to_string(id);
}

static void backupFormVersion(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload, const string& Id) {
	ProcessDO ProcessData;
	ProcessData.setXid(Id);
	ZO_STAR_DOMAIN_DTO_TO_DO(ProcessData, dto, Xid, id, Xalias, alias, Xapplication, application, Xcategory, category, XcheckDraft, checkDraft, XdefaultStartMode, defaultStartMode, Xdescription, description, XlastUpdatePerson, lastUpdatePerson, Xname, name, Xproperties, properties);
	string idStr = generateId();
	ProcessData.setXid(idStr);

	// 获取当前时间，作为创建时间
	string timeStr = getCurrTime();
	ProcessData.setXcreateTime(timeStr);
	ProcessData.setXupdateTime(timeStr);

	// 用创建时间和idStr拼接成序列号
	string serialNumber = getCurrTimeWithMillis() + idStr;
	ProcessData.setXsequence(serialNumber);
	ProcessData.setXcreatorPerson(payload.getUsername());

	// 执行数据添加
	ProcessDAO dao;
	dao.insertProcess(ProcessData);
}


string ProcessService::insertProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 组装DO数据
	ProcessDO ProcessData;
	ZO_STAR_DOMAIN_DTO_TO_DO(ProcessData, dto, Xid, id, Xalias, alias, Xapplication, application, Xcategory, category, XcheckDraft, checkDraft, XdefaultStartMode, defaultStartMode, Xdescription, description, XlastUpdatePerson, lastUpdatePerson, Xname, name, Xproperties, properties);
	ProcessData.setXlastUpdatePerson(payload.getUsername());

	// 执行数据添加
	ProcessDAO dao;
	// 创建数据
	string idStr;
	if (dto->id->empty()) idStr = generateId();
	else idStr = string(dto->id->c_str());
	ProcessData.setXid(idStr);

	// 获取当前时间，作为创建时间
	string timeStr = getCurrTime();
	ProcessData.setXcreateTime(timeStr);
	ProcessData.setXupdateTime(timeStr);
	ProcessData.setXlastUpdateTime(timeStr);

	// 用创建时间和idStr拼接成序列号
	string serialNumber = getCurrTimeWithMillis() + idStr;
	ProcessData.setXsequence(serialNumber);

	// 执行数据添加
	if (dao.insertProcess(ProcessData) == 1) {
		insertProcessBegin(dto, payload);
		insertProcessEnd(dto, payload);
		insertProcessManual(dto, payload);
		insertProcessRoute(dto, payload);
		insertProcessMerge(dto, payload);
		insertProcessInvoke(dto, payload);
		insertProcessEmbed(dto, payload);
		insertProcessPublish(dto, payload);
		insertProcessDelay(dto, payload);
		insertProcessChoice(dto, payload);
		insertProcessService(dto, payload);
		insertProcessSplit(dto, payload);
		return idStr;
	}
	return string("Service failed.");
}

bool ProcessService::updateProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	//backupFormVersion(dto, payload, dto->id.getValue({}));

	ProcessDO ProcessData;
	ZO_STAR_DOMAIN_DTO_TO_DO(ProcessData, dto, Xid, id, Xalias, alias, Xapplication, application, Xcategory, category, XcheckDraft, checkDraft, XdefaultStartMode, defaultStartMode, Xdescription, description, XlastUpdatePerson, lastUpdatePerson, Xname, name, Xproperties, properties);
	ProcessData.setXlastUpdatePerson(payload.getUsername());
	ProcessData.setXlastUpdateTime(getCurrTime());
	ProcessData.setXupdateTime(getCurrTime());

	ProcessDAO dao;

	if (dao.updateProcess(ProcessData) == 1) {
		updateProcessBegin(dto, payload);
		updateProcessEnd(dto, payload);
		updateProcessManual(dto, payload);
		updateProcessRoute(dto, payload);
		updateProcessMerge(dto, payload);
		updateProcessInvoke(dto, payload);
		updateProcessEmbed(dto, payload);
		updateProcessPublish(dto, payload);
		updateProcessDelay(dto, payload);
		updateProcessChoice(dto, payload);
		updateProcessService(dto, payload);
		updateProcessSplit(dto, payload);
		return true;
	}
	return false;
}

bool ProcessService::deleteProcess(const oatpp::String& id) {
	ProcessDAO dao;
	if (dao.deleteProcess(id) == 1) {
		dao.deleteProcessBegin(id);
		dao.deleteProcessEnd(id);
		dao.deleteProcessManual(id);
		dao.deleteProcessRoute(id);
		dao.deleteProcessMerge(id);
		dao.deleteProcessInvoke(id);
		dao.deleteProcessEmbed(id);
		dao.deleteProcessPublish(id);
		dao.deleteProcessDelay(id);
		dao.deleteProcessChoice(id);
		dao.deleteProcessService(id);
		dao.deleteProcessSplit(id);
		return true;
	}
	return false;
}

string ProcessService::insertProcessBegin(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto& item = dto->begin;
	BeginDO beginDO;
	ZO_STAR_DOMAIN_DTO_TO_DO(beginDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
	ZO_STAR_DOMAIN_DTO_TO_DO(beginDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute);

	beginDO.setXcreateTime(getCurrTime());
	beginDO.setXsequence(getCurrTimeWithMillis() + generateId());
	beginDO.setXupdateTime(getCurrTime());

	ProcessDAO dao;
	dao.insertProcessBegin(beginDO);
	return {};
}

string ProcessService::insertProcessEnd(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->endList) {
		EndDO endDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(endDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XallowRollback, xallowRollback, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname);
		ZO_STAR_DOMAIN_DTO_TO_DO(endDO, item, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText);

		endDO.setXcreateTime(getCurrTime());
		endDO.setXsequence(getCurrTimeWithMillis() + generateId());
		endDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessEnd(endDO);
	}
	return {};
}

string ProcessService::insertProcessManual(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->manualList) {
		ManualDO manualDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(manualDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowAddSplit, xallowAddSplit, XallowDeleteWork, xallowDeleteWork, XallowPause, xallowPause, XallowPress, xallowPress, XallowRapid, xallowRapid, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XallowReset, xallowReset, XallowRetract, xallowRetract, XallowRollback, xallowRollback, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription);
		ZO_STAR_DOMAIN_DTO_TO_DO(manualDO, item, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, XmanualAfterTaskScript, xmanualAfterTaskScript, XmanualAfterTaskScriptText, xmanualAfterTaskScriptText, XmanualBeforeTaskScript, xmanualBeforeTaskScript, XmanualBeforeTaskScriptText, xmanualBeforeTaskScriptText, XmanualMergeSameJobActivity, xmanualMergeSameJobActivity, XmanualMode, xmanualMode, XmanualStayScript, xmanualStayScript, XmanualStayScriptText, xmanualStayScriptText, XmanualUncompletedTaskToRead, xmanualUncompletedTaskToRead, Xname, xname, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XresetCount, xresetCount, XresetRange, xresetRange, XresetRangeScriptText, xresetRangeScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, XtaskDuty, xtaskDuty);
		ZO_STAR_DOMAIN_DTO_TO_DO(manualDO, item, XtaskExpireDay, xtaskExpireDay, XtaskExpireHour, xtaskExpireHour, XtaskExpireScript, xtaskExpireScript, XtaskExpireScriptText, xtaskExpireScriptText, XtaskExpireType, xtaskExpireType, XtaskExpireWorkTime, xtaskExpireWorkTime, XtaskScript, xtaskScript, XtaskScriptText, xtaskScriptText);

		manualDO.setXcreateTime(getCurrTime());
		manualDO.setXsequence(getCurrTimeWithMillis() + generateId());
		manualDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessManual(manualDO);
	}
	return {};
}

string ProcessService::insertProcessRoute(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->routeList) {
		RouteDO routeDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(routeDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, Xactivity, xactivity, XactivityType, xactivityType, Xalias, xalias, XappendTaskIdentityScript, xappendTaskIdentityScript, XappendTaskIdentityScriptText, xappendTaskIdentityScriptText, XappendTaskIdentityType, xappendTaskIdentityType, XdecisionOpinion, xdecisionOpinion, Xdescription, xdescription, XdisplayNameScript, xdisplayNameScript, XdisplayNameScriptText, xdisplayNameScriptText, Xedition, xedition, XhiddenScript, xhiddenScript, XhiddenScriptText, xhiddenScriptText, Xname, xname, Xopinion, xopinion, XopinionRequired, xopinionRequired, XorderNumber, xorderNumber, XpassExpired, xpassExpired, XpassSameTarget, xpassSameTarget, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, Xscript, xscript, XscriptText, xscriptText);
		ZO_STAR_DOMAIN_DTO_TO_DO(routeDO, item, XselectConfig, xselectConfig, Xsole, xsole, Xtrack, xtrack, Xtype, xtype, XvalidationScript, xvalidationScript, XvalidationScriptText, xvalidationScriptText);

		routeDO.setXcreateTime(getCurrTime());
		routeDO.setXsequence(getCurrTimeWithMillis() + generateId());
		routeDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessRoute(routeDO);
	}
	return {};
}

string ProcessService::insertProcessMerge(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->mergerList) {
		MergeDO mergeDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(mergeDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
		ZO_STAR_DOMAIN_DTO_TO_DO(mergeDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute);

		mergeDO.setXcreateTime(getCurrTime());
		mergeDO.setXsequence(getCurrTimeWithMillis() + generateId());
		mergeDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessMerge(mergeDO);
	}
	return {};
}

string ProcessService::insertProcessInvoke(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->invokeList) {
		InvokeDO invokeDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(invokeDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, Xasync, xasync, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xinternal, xinternal);
		ZO_STAR_DOMAIN_DTO_TO_DO(invokeDO, item, XinternalProject, xinternalProject, XinvokeMode, xinvokeMode, XjaxrsAddress, xjaxrsAddress, XjaxrsBodyScript, xjaxrsBodyScript, XjaxrsBodyScriptText, xjaxrsBodyScriptText, XjaxrsContentType, xjaxrsContentType, XjaxrsHeadScript, xjaxrsHeadScript, XjaxrsHeadScriptText, xjaxrsHeadScriptText, XjaxrsMethod, xjaxrsMethod, XjaxrsParameterScript, xjaxrsParameterScript, XjaxrsParameterScriptText, xjaxrsParameterScriptText, XjaxrsResponseScript, xjaxrsResponseScript, XjaxrsResponseScriptText, xjaxrsResponseScriptText, XjaxrsWithCipher, xjaxrsWithCipher, XjaxwsAddress, xjaxwsAddress, XjaxwsMethod, xjaxwsMethod, XjaxwsParameterScript, xjaxwsParameterScript, XjaxwsParameterScriptText, xjaxwsParameterScriptText, XjaxwsResponseScript, xjaxwsResponseScript, XjaxwsResponseScriptText, xjaxwsResponseScriptText, Xname, xname, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript);
		ZO_STAR_DOMAIN_DTO_TO_DO(invokeDO, item, XreviewScriptText, xreviewScriptText, Xroute, xroute);

		invokeDO.setXcreateTime(getCurrTime());
		invokeDO.setXsequence(getCurrTimeWithMillis() + generateId());
		invokeDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessInvoke(invokeDO);
	}
	return {};
}

string ProcessService::insertProcessEmbed(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->embedList) {
		EmbedDO embedDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(embedDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, XembedCreatorType, xembedCreatorType, Xextension, xextension, Xform, xform, Xgroup, xgroup, XinheritAttachment, xinheritAttachment);
		ZO_STAR_DOMAIN_DTO_TO_DO(embedDO, item, XinheritData, xinheritData, Xname, xname, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, XtargetApplication, xtargetApplication, XtargetApplicationAlias, xtargetApplicationAlias, XtargetApplicationName, xtargetApplicationName, XtargetAssginDataScript, xtargetAssginDataScript, XtargetAssginDataScriptText, xtargetAssginDataScriptText, XtargetIdentity, xtargetIdentity, XtargetIdentityScript, xtargetIdentityScript, XtargetIdentityScriptText, xtargetIdentityScriptText, XtargetProcess, xtargetProcess, XtargetProcessAlias, xtargetProcessAlias, XtargetProcessName, xtargetProcessName, XtargetTitleScript, xtargetTitleScript, XtargetTitleScriptText, xtargetTitleScriptText, XwaitUntilCompleted, xwaitUntilCompleted);

		embedDO.setXcreateTime(getCurrTime());
		embedDO.setXsequence(getCurrTimeWithMillis() + generateId());
		embedDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessEmbed(embedDO);
	}
	return {};
}

string ProcessService::insertProcessPublish(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->publishList) {
		PublishDO publishDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(publishDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XauthorDataPathList, xauthorDataPathList, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, XcategoryId, xcategoryId, XcategoryIdDataPath, xcategoryIdDataPath, XcategorySelectType, xcategorySelectType, XcmsCreatorIdentity, xcmsCreatorIdentity, XcmsCreatorScript, xcmsCreatorScript, XcmsCreatorScriptText, xcmsCreatorScriptText, XpublishCmsCreatorType, xpublishCmsCreatorType, Xdescription, xdescription);
		ZO_STAR_DOMAIN_DTO_TO_DO(publishDO, item, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, XinheritAttachment, xinheritAttachment, Xname, xname, XnotifyDataPathList, xnotifyDataPathList, XopinionGroup, xopinionGroup, XpictureDataPathList, xpictureDataPathList, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XpublishTarget, xpublishTarget, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreaderDataPathList, xreaderDataPathList, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, XtargetAssignDataScript, xtargetAssignDataScript, XtargetAssignDataScriptText, xtargetAssignDataScriptText, XtitleDataPath, xtitleDataPath, XuseProcessForm, xuseProcessForm);

		publishDO.setXcreateTime(getCurrTime());
		publishDO.setXsequence(getCurrTimeWithMillis() + generateId());
		publishDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessPublish(publishDO);
	}
	return {};
}

string ProcessService::insertProcessDelay(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->delayList) {
		DelayDO delayDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(delayDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, XdelayDataPath, xdelayDataPath, XdelayMinute, xdelayMinute, XdelayScript, xdelayScript, XdelayScriptText, xdelayScriptText, XdelayTime, xdelayTime, XdelayType, xdelayType, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText);
		ZO_STAR_DOMAIN_DTO_TO_DO(delayDO, item, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, XworkMinute, xworkMinute);

		delayDO.setXcreateTime(getCurrTime());
		delayDO.setXsequence(getCurrTimeWithMillis() + generateId());
		delayDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessDelay(delayDO);
	}
	return {};
}

string ProcessService::insertProcessChoice(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->choiceList) {
		ChoiceDO choiceDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(choiceDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
		ZO_STAR_DOMAIN_DTO_TO_DO(choiceDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText);

		choiceDO.setXcreateTime(getCurrTime());
		choiceDO.setXsequence(getCurrTimeWithMillis() + generateId());
		choiceDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessChoice(choiceDO);
	}
	return {};
}

string ProcessService::insertProcessService(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->serviceList) {
		ServiceDO serviceDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(serviceDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
		ZO_STAR_DOMAIN_DTO_TO_DO(serviceDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, Xscript, xscript, XscriptText, xscriptText);

		serviceDO.setXcreateTime(getCurrTime());
		serviceDO.setXsequence(getCurrTimeWithMillis() + generateId());
		serviceDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessService(serviceDO);
	}
	return {};
}

string ProcessService::insertProcessSplit(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->splitList) {
		SplitDO splitDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(splitDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
		ZO_STAR_DOMAIN_DTO_TO_DO(splitDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, Xscript, xscript, XscriptText, xscriptText);

		splitDO.setXcreateTime(getCurrTime());
		splitDO.setXsequence(getCurrTimeWithMillis() + generateId());
		splitDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.insertProcessSplit(splitDO);
	}
	return {};
}
// --------------------UPDATE--------------------
void ProcessService::updateProcessBegin(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto& item = dto->begin;
	BeginDO beginDO;
	ZO_STAR_DOMAIN_DTO_TO_DO(beginDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
	ZO_STAR_DOMAIN_DTO_TO_DO(beginDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute);

	beginDO.setXupdateTime(getCurrTime());

	ProcessDAO dao;
	dao.updateProcessBegin(beginDO);
}

void ProcessService::updateProcessEnd(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->endList) {
		EndDO endDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(endDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XallowRollback, xallowRollback, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname);
		ZO_STAR_DOMAIN_DTO_TO_DO(endDO, item, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText);

		endDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessEnd(endDO);
	}
}

void ProcessService::updateProcessManual(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->manualList) {
		ManualDO manualDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(manualDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowAddSplit, xallowAddSplit, XallowDeleteWork, xallowDeleteWork, XallowPause, xallowPause, XallowPress, xallowPress, XallowRapid, xallowRapid, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XallowReset, xallowReset, XallowRetract, xallowRetract, XallowRollback, xallowRollback, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription);
		ZO_STAR_DOMAIN_DTO_TO_DO(manualDO, item, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, XmanualAfterTaskScript, xmanualAfterTaskScript, XmanualAfterTaskScriptText, xmanualAfterTaskScriptText, XmanualBeforeTaskScript, xmanualBeforeTaskScript, XmanualBeforeTaskScriptText, xmanualBeforeTaskScriptText, XmanualMergeSameJobActivity, xmanualMergeSameJobActivity, XmanualMode, xmanualMode, XmanualStayScript, xmanualStayScript, XmanualStayScriptText, xmanualStayScriptText, XmanualUncompletedTaskToRead, xmanualUncompletedTaskToRead, Xname, xname, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XresetCount, xresetCount, XresetRange, xresetRange, XresetRangeScriptText, xresetRangeScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, XtaskDuty, xtaskDuty);
		ZO_STAR_DOMAIN_DTO_TO_DO(manualDO, item, XtaskExpireDay, xtaskExpireDay, XtaskExpireHour, xtaskExpireHour, XtaskExpireScript, xtaskExpireScript, XtaskExpireScriptText, xtaskExpireScriptText, XtaskExpireType, xtaskExpireType, XtaskExpireWorkTime, xtaskExpireWorkTime, XtaskScript, xtaskScript, XtaskScriptText, xtaskScriptText);

		manualDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessManual(manualDO);
	}
}

void ProcessService::updateProcessRoute(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->routeList) {
		RouteDO routeDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(routeDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, Xactivity, xactivity, XactivityType, xactivityType, Xalias, xalias, XappendTaskIdentityScript, xappendTaskIdentityScript, XappendTaskIdentityScriptText, xappendTaskIdentityScriptText, XappendTaskIdentityType, xappendTaskIdentityType, XdecisionOpinion, xdecisionOpinion, Xdescription, xdescription, XdisplayNameScript, xdisplayNameScript, XdisplayNameScriptText, xdisplayNameScriptText, Xedition, xedition, XhiddenScript, xhiddenScript, XhiddenScriptText, xhiddenScriptText, Xname, xname, Xopinion, xopinion, XopinionRequired, xopinionRequired, XorderNumber, xorderNumber, XpassExpired, xpassExpired, XpassSameTarget, xpassSameTarget, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, Xscript, xscript, XscriptText, xscriptText);
		ZO_STAR_DOMAIN_DTO_TO_DO(routeDO, item, XselectConfig, xselectConfig, Xsole, xsole, Xtrack, xtrack, Xtype, xtype, XvalidationScript, xvalidationScript, XvalidationScriptText, xvalidationScriptText);

		routeDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessRoute(routeDO);
	}
}

void ProcessService::updateProcessMerge(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->mergerList) {
		MergeDO mergeDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(mergeDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
		ZO_STAR_DOMAIN_DTO_TO_DO(mergeDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute);

		mergeDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessMerge(mergeDO);
	}
}

void ProcessService::updateProcessInvoke(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->invokeList) {
		InvokeDO invokeDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(invokeDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, Xasync, xasync, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xinternal, xinternal);
		ZO_STAR_DOMAIN_DTO_TO_DO(invokeDO, item, XinternalProject, xinternalProject, XinvokeMode, xinvokeMode, XjaxrsAddress, xjaxrsAddress, XjaxrsBodyScript, xjaxrsBodyScript, XjaxrsBodyScriptText, xjaxrsBodyScriptText, XjaxrsContentType, xjaxrsContentType, XjaxrsHeadScript, xjaxrsHeadScript, XjaxrsHeadScriptText, xjaxrsHeadScriptText, XjaxrsMethod, xjaxrsMethod, XjaxrsParameterScript, xjaxrsParameterScript, XjaxrsParameterScriptText, xjaxrsParameterScriptText, XjaxrsResponseScript, xjaxrsResponseScript, XjaxrsResponseScriptText, xjaxrsResponseScriptText, XjaxrsWithCipher, xjaxrsWithCipher, XjaxwsAddress, xjaxwsAddress, XjaxwsMethod, xjaxwsMethod, XjaxwsParameterScript, xjaxwsParameterScript, XjaxwsParameterScriptText, xjaxwsParameterScriptText, XjaxwsResponseScript, xjaxwsResponseScript, XjaxwsResponseScriptText, xjaxwsResponseScriptText, Xname, xname, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript);
		ZO_STAR_DOMAIN_DTO_TO_DO(invokeDO, item, XreviewScriptText, xreviewScriptText, Xroute, xroute);

		invokeDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessInvoke(invokeDO);
	}
}

void ProcessService::updateProcessEmbed(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->embedList) {
		EmbedDO embedDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(embedDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, XembedCreatorType, xembedCreatorType, Xextension, xextension, Xform, xform, Xgroup, xgroup, XinheritAttachment, xinheritAttachment);
		ZO_STAR_DOMAIN_DTO_TO_DO(embedDO, item, XinheritData, xinheritData, Xname, xname, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, XtargetApplication, xtargetApplication, XtargetApplicationAlias, xtargetApplicationAlias, XtargetApplicationName, xtargetApplicationName, XtargetAssginDataScript, xtargetAssginDataScript, XtargetAssginDataScriptText, xtargetAssginDataScriptText, XtargetIdentity, xtargetIdentity, XtargetIdentityScript, xtargetIdentityScript, XtargetIdentityScriptText, xtargetIdentityScriptText, XtargetProcess, xtargetProcess, XtargetProcessAlias, xtargetProcessAlias, XtargetProcessName, xtargetProcessName, XtargetTitleScript, xtargetTitleScript, XtargetTitleScriptText, xtargetTitleScriptText, XwaitUntilCompleted, xwaitUntilCompleted);

		embedDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessEmbed(embedDO);
	}
}

void ProcessService::updateProcessPublish(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->publishList) {
		PublishDO publishDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(publishDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XauthorDataPathList, xauthorDataPathList, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, XcategoryId, xcategoryId, XcategoryIdDataPath, xcategoryIdDataPath, XcategorySelectType, xcategorySelectType, XcmsCreatorIdentity, xcmsCreatorIdentity, XcmsCreatorScript, xcmsCreatorScript, XcmsCreatorScriptText, xcmsCreatorScriptText, XpublishCmsCreatorType, xpublishCmsCreatorType, Xdescription, xdescription);
		ZO_STAR_DOMAIN_DTO_TO_DO(publishDO, item, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, XinheritAttachment, xinheritAttachment, Xname, xname, XnotifyDataPathList, xnotifyDataPathList, XopinionGroup, xopinionGroup, XpictureDataPathList, xpictureDataPathList, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XpublishTarget, xpublishTarget, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreaderDataPathList, xreaderDataPathList, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, XtargetAssignDataScript, xtargetAssignDataScript, XtargetAssignDataScriptText, xtargetAssignDataScriptText, XtitleDataPath, xtitleDataPath, XuseProcessForm, xuseProcessForm);

		publishDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessPublish(publishDO);
	}
}

void ProcessService::updateProcessDelay(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->delayList) {
		DelayDO delayDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(delayDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, XdelayDataPath, xdelayDataPath, XdelayMinute, xdelayMinute, XdelayScript, xdelayScript, XdelayScriptText, xdelayScriptText, XdelayTime, xdelayTime, XdelayType, xdelayType, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText);
		ZO_STAR_DOMAIN_DTO_TO_DO(delayDO, item, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, XworkMinute, xworkMinute);

		delayDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessDelay(delayDO);
	}
}

void ProcessService::updateProcessChoice(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->choiceList) {
		ChoiceDO choiceDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(choiceDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
		ZO_STAR_DOMAIN_DTO_TO_DO(choiceDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText);

		choiceDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessChoice(choiceDO);
	}
}

void ProcessService::updateProcessService(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->serviceList) {
		ServiceDO serviceDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(serviceDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
		ZO_STAR_DOMAIN_DTO_TO_DO(serviceDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, Xscript, xscript, XscriptText, xscriptText);

		serviceDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessService(serviceDO);
	}
}

void ProcessService::updateProcessSplit(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	for (auto& item : *dto->splitList) {
		SplitDO splitDO;
		ZO_STAR_DOMAIN_DTO_TO_DO(splitDO, item, Xid, xid, XcreateTime, xcreateTime, Xsequence, xsequence, XupdateTime, xupdateTime, XdistributeFactor, xdistributeFactor, XafterArriveScript, xafterArriveScript, XafterArriveScriptText, xafterArriveScriptText, XafterExecuteScript, xafterExecuteScript, XafterExecuteScriptText, xafterExecuteScriptText, XafterInquireScript, xafterInquireScript, XafterInquireScriptText, xafterInquireScriptText, Xalias, xalias, XallowReroute, xallowReroute, XallowRerouteTo, xallowRerouteTo, XbeforeArriveScript, xbeforeArriveScript, XbeforeArriveScriptText, xbeforeArriveScriptText, XbeforeExecuteScript, xbeforeExecuteScript, XbeforeExecuteScriptText, xbeforeExecuteScriptText, XbeforeInquireScript, xbeforeInquireScript, XbeforeInquireScriptText, xbeforeInquireScriptText, Xdescription, xdescription, XdisplayLogScript, xdisplayLogScript, XdisplayLogScriptText, xdisplayLogScriptText, Xedition, xedition, Xextension, xextension, Xform, xform, Xgroup, xgroup, Xname, xname, XopinionGroup, xopinionGroup);
		ZO_STAR_DOMAIN_DTO_TO_DO(splitDO, item, Xposition, xposition, Xprocess, xprocess, Xproperties, xproperties, XreadDuty, xreadDuty, XreadScript, xreadScript, XreadScriptText, xreadScriptText, XreviewDuty, xreviewDuty, XreviewScript, xreviewScript, XreviewScriptText, xreviewScriptText, Xroute, xroute, Xscript, xscript, XscriptText, xscriptText);

		splitDO.setXupdateTime(getCurrTime());

		ProcessDAO dao;
		dao.updateProcessSplit(splitDO);
	}
}