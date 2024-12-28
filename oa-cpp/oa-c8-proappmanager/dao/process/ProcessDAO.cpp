#include "stdafx.h"
#include <map>
#include "SqlSession.h"
#include "ProcessDAO.h"
#include "ProcessTypesMapper.h"
#include "ProcessListMapper.h"
#include "ProcessInfoMapper.h"
#include "AgentMapper.h"
#include "BeginMapper.h"
#include "CancelMapper.h"
#include "ChoiceMapper.h"
#include "DelayMapper.h"
#include "EmbedMapper.h"
#include "EndMapper.h"
#include "InvokeMapper.h"
#include "ManualMapper.h"
#include "MergeMapper.h"
#include "ParallelMapper.h"
#include "ProcessControllerMapper.h"
#include "ProcessStartableGroupMapper.h"
#include "ProcessStartableIdentityMapper.h"
#include "ProcessStartableUnitMapper.h"
#include "PublishMapper.h"
#include "RouteMapper.h"
#include "ServiceMapper.h"
#include "SplitMapper.h"

// 查询流程类型
#define PROCESSTYPES_TERAM_PARSE(xapplication, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (xapplication) { \
	sql << " AND xapplication=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, xapplication); \
}

list<ProcessTypesDO> ProcessDAO::selectTypes(const oatpp::String& appId) {
	stringstream sql;
	sql << "SELECT xcategory, COUNT(*) FROM pp_e_process WHERE xapplication = ? GROUP BY xcategory";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, appId);
	string sqlStr = sql.str();
	ProcessTypesMapper mapper;
	return sqlSession->executeQuery<ProcessTypesDO, ProcessTypesMapper>(sqlStr, mapper, params);
}

// 查询流程列表
#define PROCESSLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->category != "A") { \
	sql << " AND xcategory=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->category.getValue("")); \
} \
if (query->name != "A") { \
	sql << " AND xname LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->alias != "A") { \
	sql << " AND xalias LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->alias.getValue("")); \
} \
if (query->application != "79bcf960-3a92-4b54-83e7-b99d2298a82d") { \
	sql << " AND xapplication=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->application.getValue("")); \
}

uint64_t ProcessDAO::count(const ProcessListQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM pp_e_process";
	PROCESSLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ProcessListDO> ProcessDAO::selectProcess(const ProcessListQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT xid,xcategory,xname,xalias,xdescription,xlastUpdateTime FROM pp_e_process";
	PROCESSLIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ProcessListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ProcessListDO, ProcessListMapper>(sqlStr, mapper, params);
}

// 查询流程详情
#define PROCESSINFO_TERAM_PARSE(id, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (id) { \
	sql << " AND xid=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, id); \
}

#define PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (xprocess) { \
	sql << " AND xprocess=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, xprocess); \
}

#define PROCESSINFO_TERAM_PARSE_SUB_PROCESS(xprocess, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (xprocess) { \
	sql << " AND PROCESS_XID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, xprocess); \
}

list<ProcessInfoDO> ProcessDAO::selectProcessInfoMain(const oatpp::String& id) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_process";
	PROCESSINFO_TERAM_PARSE(id, sql);
	string sqlStr = sql.str();
	ProcessInfoMapper mapper;
	return sqlSession->executeQuery<ProcessInfoDO, ProcessInfoMapper>(sqlStr, mapper, params);
}

list<AgentDO> ProcessDAO::selectAgentList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_agent";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	AgentMapper mapper;
	return sqlSession->executeQuery<AgentDO, AgentMapper>(sqlStr, mapper, params);
}

list<BeginDO> ProcessDAO::selectBeginList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_begin";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	BeginMapper mapper;
	return sqlSession->executeQuery<BeginDO, BeginMapper>(sqlStr, mapper, params);
}

list<CancelDO> ProcessDAO::selectCancelList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_cancel";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	CancelMapper mapper;
	return sqlSession->executeQuery<CancelDO, CancelMapper>(sqlStr, mapper, params);
}

list<ChoiceDO> ProcessDAO::selectChoiceList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_choice";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	ChoiceMapper mapper;
	return sqlSession->executeQuery<ChoiceDO, ChoiceMapper>(sqlStr, mapper, params);
}

list<DelayDO> ProcessDAO::selectDelayList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_delay";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	DelayMapper mapper;
	return sqlSession->executeQuery<DelayDO, DelayMapper>(sqlStr, mapper, params);
}

list<EmbedDO> ProcessDAO::selectEmbedList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_embed";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	EmbedMapper mapper;
	return sqlSession->executeQuery<EmbedDO, EmbedMapper>(sqlStr, mapper, params);
}

list<EndDO> ProcessDAO::selectEndList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_end";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	EndMapper mapper;
	return sqlSession->executeQuery<EndDO, EndMapper>(sqlStr, mapper, params);
}

list<InvokeDO> ProcessDAO::selectInvokeList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_invoke";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	InvokeMapper mapper;
	return sqlSession->executeQuery<InvokeDO, InvokeMapper>(sqlStr, mapper, params);
}

list<ManualDO> ProcessDAO::selectManualList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_manual";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	ManualMapper mapper;
	return sqlSession->executeQuery<ManualDO, ManualMapper>(sqlStr, mapper, params);
}

list<MergeDO> ProcessDAO::selectMergeList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_merge";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	MergeMapper mapper;
	return sqlSession->executeQuery<MergeDO, MergeMapper>(sqlStr, mapper, params);
}

list<ParallelDO> ProcessDAO::selectParallelList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_parallel";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	ParallelMapper mapper;
	return sqlSession->executeQuery<ParallelDO, ParallelMapper>(sqlStr, mapper, params);
}

list<ProcessControllerDO> ProcessDAO::selectProcessControllerList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_process_controllerlist";
	PROCESSINFO_TERAM_PARSE_SUB_PROCESS(xprocess, sql);
	string sqlStr = sql.str();
	ProcessControllerMapper mapper;
	return sqlSession->executeQuery<ProcessControllerDO, ProcessControllerMapper>(sqlStr, mapper, params);
}

list<ProcessStartableGroupDO> ProcessDAO::selectProcessStartableGroupList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_process_startablegrouplist";
	PROCESSINFO_TERAM_PARSE_SUB_PROCESS(xprocess, sql);
	string sqlStr = sql.str();
	ProcessStartableGroupMapper mapper;
	return sqlSession->executeQuery<ProcessStartableGroupDO, ProcessStartableGroupMapper>(sqlStr, mapper, params);
}

list<ProcessStartableIdentityDO> ProcessDAO::selectProcessStartableIdentityList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_process_startableidentitylist";
	PROCESSINFO_TERAM_PARSE_SUB_PROCESS(xprocess, sql);
	string sqlStr = sql.str();
	ProcessStartableIdentityMapper mapper;
	return sqlSession->executeQuery<ProcessStartableIdentityDO, ProcessStartableIdentityMapper>(sqlStr, mapper, params);
}

list<ProcessStartableUnitDO> ProcessDAO::selectProcessStartableUnitList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_process_startableunitlist";
	PROCESSINFO_TERAM_PARSE_SUB_PROCESS(xprocess, sql);
	string sqlStr = sql.str();
	ProcessStartableUnitMapper mapper;
	return sqlSession->executeQuery<ProcessStartableUnitDO, ProcessStartableUnitMapper>(sqlStr, mapper, params);
}

list<PublishDO> ProcessDAO::selectPublishList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_publish";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	PublishMapper mapper;
	return sqlSession->executeQuery<PublishDO, PublishMapper>(sqlStr, mapper, params);
}

list<RouteDO> ProcessDAO::selectRouteList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_route";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	RouteMapper mapper;
	return sqlSession->executeQuery<RouteDO, RouteMapper>(sqlStr, mapper, params);
}

list<ServiceDO> ProcessDAO::selectServiceList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_service";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	ServiceMapper mapper;
	return sqlSession->executeQuery<ServiceDO, ServiceMapper>(sqlStr, mapper, params);
}

list<SplitDO> ProcessDAO::selectSplitList(const oatpp::String& xprocess) {
	stringstream sql;
	sql << "SELECT * FROM pp_e_split";
	PROCESSINFO_TERAM_PARSE_SUB(xprocess, sql);
	string sqlStr = sql.str();
	SplitMapper mapper;
	return sqlSession->executeQuery<SplitDO, SplitMapper>(sqlStr, mapper, params);
}


//pp_e_process
uint64_t ProcessDAO::insertProcess(const ProcessDO& data) {
	string sql = "INSERT INTO `pp_e_process` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterBeginScript`, `xafterBeginScriptText`, `xafterEndScript`, `xafterEndScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xapplication`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xcategory`, `xcheckDraft`, `xcreatorPerson`, `xdefaultStartMode`, `xdescription`, `xedition`, `xeditionDes`, `xeditionEnable`, `xeditionName`, `xeditionNumber`, `xexpireDay`, `xexpireHour`, `xexpireType`, `xexpireWorkTime`, `xicon`, `xlastUpdatePerson`, `xlastUpdateTime`, `xname`, `xprojection`, `xprojectionFully`, `xproperties`, `xrouteNameAsOpinion`, `xserialActivity`, `xserialPhase`, `xserialTexture`, `xstartableTerminal`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%s%s%b%s%d%i%i%s%b%s%s%dt%s%s%b%s%b%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterBeginScript(), data.getXafterBeginScriptText(), data.getXafterEndScript(), data.getXafterEndScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXapplication(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXcategory(), data.getXcheckDraft(), data.getXcreatorPerson(), data.getXdefaultStartMode(), data.getXdescription(), data.getXedition(), data.getXeditionDes(), data.getXeditionEnable(), data.getXeditionName(), data.getXeditionNumber(), data.getXexpireDay(), data.getXexpireHour(), data.getXexpireType(), data.getXexpireWorkTime(), data.getXicon(), data.getXlastUpdatePerson(), data.getXlastUpdateTime(), data.getXname(), data.getXprojection(), data.getXprojectionFully(), data.getXproperties(), data.getXrouteNameAsOpinion(), data.getXserialActivity(), data.getXserialPhase(), data.getXserialTexture(), data.getXstartableTerminal());
}


int ProcessDAO::updateProcess(const ProcessDO& data) {
	string sql = "UPDATE `pp_e_process` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterBeginScript`=?, `xafterBeginScriptText`=?, `xafterEndScript`=?, `xafterEndScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xcategory`=?, `xcheckDraft`=?, `xdefaultStartMode`=?, `xdescription`=?, `xedition`=?, `xeditionDes`=?, `xeditionEnable`=?, `xeditionName`=?, `xeditionNumber`=?, `xexpireDay`=?, `xexpireHour`=?, `xexpireType`=?, `xexpireWorkTime`=?, `xicon`=?, `xlastUpdatePerson`=?, `xlastUpdateTime`=?, `xname`=?, `xprojection`=?, `xprojectionFully`=?, `xproperties`=?, `xrouteNameAsOpinion`=?, `xserialActivity`=?, `xserialPhase`=?, `xserialTexture`=?, `xstartableTerminal`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%s%b%s%d%i%i%s%b%s%s%dt%s%s%b%s%b%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterBeginScript(), data.getXafterBeginScriptText(), data.getXafterEndScript(), data.getXafterEndScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXcategory(), data.getXcheckDraft(), data.getXdefaultStartMode(), data.getXdescription(), data.getXedition(), data.getXeditionDes(), data.getXeditionEnable(), data.getXeditionName(), data.getXeditionNumber(), data.getXexpireDay(), data.getXexpireHour(), data.getXexpireType(), data.getXexpireWorkTime(), data.getXicon(), data.getXlastUpdatePerson(), data.getXlastUpdateTime(), data.getXname(), data.getXprojection(), data.getXprojectionFully(), data.getXproperties(), data.getXrouteNameAsOpinion(), data.getXserialActivity(), data.getXserialPhase(), data.getXserialTexture(), data.getXstartableTerminal(), data.getXid());
}


int ProcessDAO::deleteProcess(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_process` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_begin
uint64_t ProcessDAO::insertProcessBegin(const BeginDO& data) {
	string sql = "INSERT INTO `pp_e_begin` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`, `xroute`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute());
}


int ProcessDAO::updateProcessBegin(const BeginDO& data) {
	string sql = "UPDATE `pp_e_begin` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=?, `xroute`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXid());
}


int ProcessDAO::deleteProcessBegin(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_begin` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_end
uint64_t ProcessDAO::insertProcessEnd(const EndDO& data) {
	string sql = "INSERT INTO `pp_e_end` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xallowRollback`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXallowRollback(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText());
}


int ProcessDAO::updateProcessEnd(const EndDO& data) {
	string sql = "UPDATE `pp_e_end` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xallowRollback`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXallowRollback(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXid());
}


int ProcessDAO::deleteProcessEnd(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_end` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_manual
uint64_t ProcessDAO::insertProcessManual(const ManualDO& data) {
	string sql = "INSERT INTO `pp_e_manual` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowAddSplit`, `xallowDeleteWork`, `xallowPause`, `xallowPress`, `xallowRapid`, `xallowReroute`, `xallowRerouteTo`, `xallowReset`, `xallowRetract`, `xallowRollback`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xmanualAfterTaskScript`, `xmanualAfterTaskScriptText`, `xmanualBeforeTaskScript`, `xmanualBeforeTaskScriptText`, `xmanualMergeSameJobActivity`, `xmanualMode`, `xmanualStayScript`, `xmanualStayScriptText`, `xmanualUncompletedTaskToRead`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xresetCount`, `xresetRange`, `xresetRangeScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`, `xtaskDuty`, `xtaskExpireDay`, `xtaskExpireHour`, `xtaskExpireScript`, `xtaskExpireScriptText`, `xtaskExpireType`, `xtaskExpireWorkTime`, `xtaskScript`, `xtaskScriptText`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%b%b%b%b%b%b%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%b%s%s%s%s%s%s%s%s%i%s%s%s%s%s%s%i%i%s%s%s%b%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowAddSplit(), data.getXallowDeleteWork(), data.getXallowPause(), data.getXallowPress(), data.getXallowRapid(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXallowReset(), data.getXallowRetract(), data.getXallowRollback(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXmanualAfterTaskScript(), data.getXmanualAfterTaskScriptText(), data.getXmanualBeforeTaskScript(), data.getXmanualBeforeTaskScriptText(), data.getXmanualMergeSameJobActivity(), data.getXmanualMode(), data.getXmanualStayScript(), data.getXmanualStayScriptText(), data.getXmanualUncompletedTaskToRead(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXresetCount(), data.getXresetRange(), data.getXresetRangeScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXtaskDuty(), data.getXtaskExpireDay(), data.getXtaskExpireHour(), data.getXtaskExpireScript(), data.getXtaskExpireScriptText(), data.getXtaskExpireType(), data.getXtaskExpireWorkTime(), data.getXtaskScript(), data.getXtaskScriptText());
}


int ProcessDAO::updateProcessManual(const ManualDO& data) {
	string sql = "UPDATE `pp_e_manual` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowAddSplit`=?, `xallowDeleteWork`=?, `xallowPause`=?, `xallowPress`=?, `xallowRapid`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xallowReset`=?, `xallowRetract`=?, `xallowRollback`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xmanualAfterTaskScript`=?, `xmanualAfterTaskScriptText`=?, `xmanualBeforeTaskScript`=?, `xmanualBeforeTaskScriptText`=?, `xmanualMergeSameJobActivity`=?, `xmanualMode`=?, `xmanualStayScript`=?, `xmanualStayScriptText`=?, `xmanualUncompletedTaskToRead`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xresetCount`=?, `xresetRange`=?, `xresetRangeScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=?, `xtaskDuty`=?, `xtaskExpireDay`=?, `xtaskExpireHour`=?, `xtaskExpireScript`=?, `xtaskExpireScriptText`=?, `xtaskExpireType`=?, `xtaskExpireWorkTime`=?, `xtaskScript`=?, `xtaskScriptText`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%b%b%b%b%b%b%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%b%s%s%s%s%s%s%s%s%i%s%s%s%s%s%s%i%i%s%s%s%b%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowAddSplit(), data.getXallowDeleteWork(), data.getXallowPause(), data.getXallowPress(), data.getXallowRapid(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXallowReset(), data.getXallowRetract(), data.getXallowRollback(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXmanualAfterTaskScript(), data.getXmanualAfterTaskScriptText(), data.getXmanualBeforeTaskScript(), data.getXmanualBeforeTaskScriptText(), data.getXmanualMergeSameJobActivity(), data.getXmanualMode(), data.getXmanualStayScript(), data.getXmanualStayScriptText(), data.getXmanualUncompletedTaskToRead(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXresetCount(), data.getXresetRange(), data.getXresetRangeScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXtaskDuty(), data.getXtaskExpireDay(), data.getXtaskExpireHour(), data.getXtaskExpireScript(), data.getXtaskExpireScriptText(), data.getXtaskExpireType(), data.getXtaskExpireWorkTime(), data.getXtaskScript(), data.getXtaskScriptText(), data.getXid());
}


int ProcessDAO::deleteProcessManual(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_manual` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_route
uint64_t ProcessDAO::insertProcessRoute(const RouteDO& data) {
	string sql = "INSERT INTO `pp_e_route` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xactivity`, `xactivityType`, `xalias`, `xappendTaskIdentityScript`, `xappendTaskIdentityScriptText`, `xappendTaskIdentityType`, `xdecisionOpinion`, `xdescription`, `xdisplayNameScript`, `xdisplayNameScriptText`, `xedition`, `xhiddenScript`, `xhiddenScriptText`, `xname`, `xopinion`, `xopinionRequired`, `xorderNumber`, `xpassExpired`, `xpassSameTarget`, `xposition`, `xprocess`, `xproperties`, `xscript`, `xscriptText`, `xselectConfig`, `xsole`, `xtrack`, `xtype`, `xvalidationScript`, `xvalidationScriptText`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%i%b%b%s%s%s%s%s%s%b%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXactivity(), data.getXactivityType(), data.getXalias(), data.getXappendTaskIdentityScript(), data.getXappendTaskIdentityScriptText(), data.getXappendTaskIdentityType(), data.getXdecisionOpinion(), data.getXdescription(), data.getXdisplayNameScript(), data.getXdisplayNameScriptText(), data.getXedition(), data.getXhiddenScript(), data.getXhiddenScriptText(), data.getXname(), data.getXopinion(), data.getXopinionRequired(), data.getXorderNumber(), data.getXpassExpired(), data.getXpassSameTarget(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXscript(), data.getXscriptText(), data.getXselectConfig(), data.getXsole(), data.getXtrack(), data.getXtype(), data.getXvalidationScript(), data.getXvalidationScriptText());
}


int ProcessDAO::updateProcessRoute(const RouteDO& data) {
	string sql = "UPDATE `pp_e_route` SET `xupdateTime`=?, `xdistributeFactor`=?, `xactivity`=?, `xactivityType`=?, `xalias`=?, `xappendTaskIdentityScript`=?, `xappendTaskIdentityScriptText`=?, `xappendTaskIdentityType`=?, `xdecisionOpinion`=?, `xdescription`=?, `xdisplayNameScript`=?, `xdisplayNameScriptText`=?, `xedition`=?, `xhiddenScript`=?, `xhiddenScriptText`=?, `xname`=?, `xopinion`=?, `xopinionRequired`=?, `xorderNumber`=?, `xpassExpired`=?, `xpassSameTarget`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xscript`=?, `xscriptText`=?, `xselectConfig`=?, `xsole`=?, `xtrack`=?, `xtype`=?, `xvalidationScript`=?, `xvalidationScriptText`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%i%b%b%s%s%s%s%s%s%b%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXactivity(), data.getXactivityType(), data.getXalias(), data.getXappendTaskIdentityScript(), data.getXappendTaskIdentityScriptText(), data.getXappendTaskIdentityType(), data.getXdecisionOpinion(), data.getXdescription(), data.getXdisplayNameScript(), data.getXdisplayNameScriptText(), data.getXedition(), data.getXhiddenScript(), data.getXhiddenScriptText(), data.getXname(), data.getXopinion(), data.getXopinionRequired(), data.getXorderNumber(), data.getXpassExpired(), data.getXpassSameTarget(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXscript(), data.getXscriptText(), data.getXselectConfig(), data.getXsole(), data.getXtrack(), data.getXtype(), data.getXvalidationScript(), data.getXvalidationScriptText(), data.getXid());
}


int ProcessDAO::deleteProcessRoute(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_route` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}
//-------------------------------------------------------------
//pp_e_merge
uint64_t ProcessDAO::insertProcessMerge(const MergeDO& data) {
	string sql = "INSERT INTO `pp_e_merge` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`, `xroute`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute());
}


int ProcessDAO::updateProcessMerge(const MergeDO& data) {
	string sql = "UPDATE `pp_e_merge` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=?, `xroute`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXid());
}


int ProcessDAO::deleteProcessMerge(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_merge` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_parallel
uint64_t ProcessDAO::insertProcessParallel(const ParallelDO& data) {
	string sql = "INSERT INTO `pp_e_parallel` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText());
}


int ProcessDAO::updateProcessParallel(const ParallelDO& data) {
	string sql = "UPDATE `pp_e_parallel` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXid());
}


int ProcessDAO::deleteProcessParallel(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_parallel` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_invoke
uint64_t ProcessDAO::insertProcessInvoke(const InvokeDO& data) {
	string sql = "INSERT INTO `pp_e_invoke` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xasync`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xinternal`, `xinternalProject`, `xinvokeMode`, `xjaxrsAddress`, `xjaxrsBodyScript`, `xjaxrsBodyScriptText`, `xjaxrsContentType`, `xjaxrsHeadScript`, `xjaxrsHeadScriptText`, `xjaxrsMethod`, `xjaxrsParameterScript`, `xjaxrsParameterScriptText`, `xjaxrsResponseScript`, `xjaxrsResponseScriptText`, `xjaxrsWithCipher`, `xjaxwsAddress`, `xjaxwsMethod`, `xjaxwsParameterScript`, `xjaxwsParameterScriptText`, `xjaxwsResponseScript`, `xjaxwsResponseScriptText`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`, `xroute`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXasync(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXinternal(), data.getXinternalProject(), data.getXinvokeMode(), data.getXjaxrsAddress(), data.getXjaxrsBodyScript(), data.getXjaxrsBodyScriptText(), data.getXjaxrsContentType(), data.getXjaxrsHeadScript(), data.getXjaxrsHeadScriptText(), data.getXjaxrsMethod(), data.getXjaxrsParameterScript(), data.getXjaxrsParameterScriptText(), data.getXjaxrsResponseScript(), data.getXjaxrsResponseScriptText(), data.getXjaxrsWithCipher(), data.getXjaxwsAddress(), data.getXjaxwsMethod(), data.getXjaxwsParameterScript(), data.getXjaxwsParameterScriptText(), data.getXjaxwsResponseScript(), data.getXjaxwsResponseScriptText(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute());
	return 1;
}


int ProcessDAO::updateProcessInvoke(const InvokeDO& data) {
	string sql = "UPDATE `pp_e_invoke` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xasync`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xinternal`=?, `xinternalProject`=?, `xinvokeMode`=?, `xjaxrsAddress`=?, `xjaxrsBodyScript`=?, `xjaxrsBodyScriptText`=?, `xjaxrsContentType`=?, `xjaxrsHeadScript`=?, `xjaxrsHeadScriptText`=?, `xjaxrsMethod`=?, `xjaxrsParameterScript`=?, `xjaxrsParameterScriptText`=?, `xjaxrsResponseScript`=?, `xjaxrsResponseScriptText`=?, `xjaxrsWithCipher`=?, `xjaxwsAddress`=?, `xjaxwsMethod`=?, `xjaxwsParameterScript`=?, `xjaxwsParameterScriptText`=?, `xjaxwsResponseScript`=?, `xjaxwsResponseScriptText`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=?, `xroute`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXasync(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXinternal(), data.getXinternalProject(), data.getXinvokeMode(), data.getXjaxrsAddress(), data.getXjaxrsBodyScript(), data.getXjaxrsBodyScriptText(), data.getXjaxrsContentType(), data.getXjaxrsHeadScript(), data.getXjaxrsHeadScriptText(), data.getXjaxrsMethod(), data.getXjaxrsParameterScript(), data.getXjaxrsParameterScriptText(), data.getXjaxrsResponseScript(), data.getXjaxrsResponseScriptText(), data.getXjaxrsWithCipher(), data.getXjaxwsAddress(), data.getXjaxwsMethod(), data.getXjaxwsParameterScript(), data.getXjaxwsParameterScriptText(), data.getXjaxwsResponseScript(), data.getXjaxwsResponseScriptText(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXid());
}


int ProcessDAO::deleteProcessInvoke(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_invoke` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_embed
uint64_t ProcessDAO::insertProcessEmbed(const EmbedDO& data) {
	string sql = "INSERT INTO `pp_e_embed` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xembedCreatorType`, `xextension`, `xform`, `xgroup`, `xinheritAttachment`, `xinheritData`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`, `xroute`, `xtargetApplication`, `xtargetApplicationAlias`, `xtargetApplicationName`, `xtargetAssginDataScript`, `xtargetAssginDataScriptText`, `xtargetIdentity`, `xtargetIdentityScript`, `xtargetIdentityScriptText`, `xtargetProcess`, `xtargetProcessAlias`, `xtargetProcessName`, `xtargetTitleScript`, `xtargetTitleScriptText`, `xwaitUntilCompleted`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXembedCreatorType(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXinheritAttachment(), data.getXinheritData(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXtargetApplication(), data.getXtargetApplicationAlias(), data.getXtargetApplicationName(), data.getXtargetAssginDataScript(), data.getXtargetAssginDataScriptText(), data.getXtargetIdentity(), data.getXtargetIdentityScript(), data.getXtargetIdentityScriptText(), data.getXtargetProcess(), data.getXtargetProcessAlias(), data.getXtargetProcessName(), data.getXtargetTitleScript(), data.getXtargetTitleScriptText(), data.getXwaitUntilCompleted());
}


int ProcessDAO::updateProcessEmbed(const EmbedDO& data) {
	string sql = "UPDATE `pp_e_embed` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xembedCreatorType`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xinheritAttachment`=?, `xinheritData`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=?, `xroute`=?, `xtargetApplication`=?, `xtargetApplicationAlias`=?, `xtargetApplicationName`=?, `xtargetAssginDataScript`=?, `xtargetAssginDataScriptText`=?, `xtargetIdentity`=?, `xtargetIdentityScript`=?, `xtargetIdentityScriptText`=?, `xtargetProcess`=?, `xtargetProcessAlias`=?, `xtargetProcessName`=?, `xtargetTitleScript`=?, `xtargetTitleScriptText`=?, `xwaitUntilCompleted`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXembedCreatorType(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXinheritAttachment(), data.getXinheritData(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXtargetApplication(), data.getXtargetApplicationAlias(), data.getXtargetApplicationName(), data.getXtargetAssginDataScript(), data.getXtargetAssginDataScriptText(), data.getXtargetIdentity(), data.getXtargetIdentityScript(), data.getXtargetIdentityScriptText(), data.getXtargetProcess(), data.getXtargetProcessAlias(), data.getXtargetProcessName(), data.getXtargetTitleScript(), data.getXtargetTitleScriptText(), data.getXwaitUntilCompleted(), data.getXid());
}


int ProcessDAO::deleteProcessEmbed(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_embed` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_publish
uint64_t ProcessDAO::insertProcessPublish(const PublishDO& data) {
	string sql = "INSERT INTO `pp_e_publish` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xauthorDataPathList`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xcategoryId`, `xcategoryIdDataPath`, `xcategorySelectType`, `xcmsCreatorIdentity`, `xcmsCreatorScript`, `xcmsCreatorScriptText`, `xpublishCmsCreatorType`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xinheritAttachment`, `xname`, `xnotifyDataPathList`, `xopinionGroup`, `xpictureDataPathList`, `xposition`, `xprocess`, `xproperties`, `xpublishTarget`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreaderDataPathList`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`, `xroute`, `xtargetAssignDataScript`, `xtargetAssignDataScriptText`, `xtitleDataPath`, `xuseProcessForm`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXauthorDataPathList(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXcategoryId(), data.getXcategoryIdDataPath(), data.getXcategorySelectType(), data.getXcmsCreatorIdentity(), data.getXcmsCreatorScript(), data.getXcmsCreatorScriptText(), data.getXpublishCmsCreatorType(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXinheritAttachment(), data.getXname(), data.getXnotifyDataPathList(), data.getXopinionGroup(), data.getXpictureDataPathList(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXpublishTarget(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreaderDataPathList(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXtargetAssignDataScript(), data.getXtargetAssignDataScriptText(), data.getXtitleDataPath(), data.getXuseProcessForm());
}


int ProcessDAO::updateProcessPublish(const PublishDO& data) {
	string sql = "UPDATE `pp_e_publish` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xauthorDataPathList`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xcategoryId`=?, `xcategoryIdDataPath`=?, `xcategorySelectType`=?, `xcmsCreatorIdentity`=?, `xcmsCreatorScript`=?, `xcmsCreatorScriptText`=?, `xpublishCmsCreatorType`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xinheritAttachment`=?, `xname`=?, `xnotifyDataPathList`=?, `xopinionGroup`=?, `xpictureDataPathList`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xpublishTarget`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreaderDataPathList`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=?, `xroute`=?, `xtargetAssignDataScript`=?, `xtargetAssignDataScriptText`=?, `xtitleDataPath`=?, `xuseProcessForm`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXauthorDataPathList(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXcategoryId(), data.getXcategoryIdDataPath(), data.getXcategorySelectType(), data.getXcmsCreatorIdentity(), data.getXcmsCreatorScript(), data.getXcmsCreatorScriptText(), data.getXpublishCmsCreatorType(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXinheritAttachment(), data.getXname(), data.getXnotifyDataPathList(), data.getXopinionGroup(), data.getXpictureDataPathList(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXpublishTarget(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreaderDataPathList(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXtargetAssignDataScript(), data.getXtargetAssignDataScriptText(), data.getXtitleDataPath(), data.getXuseProcessForm(), data.getXid());
}


int ProcessDAO::deleteProcessPublish(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_publish` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_delay
uint64_t ProcessDAO::insertProcessDelay(const DelayDO& data) {
	string sql = "INSERT INTO `pp_e_delay` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdelayDataPath`, `xdelayMinute`, `xdelayScript`, `xdelayScriptText`, `xdelayTime`, `xdelayType`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`, `xroute`, `xworkMinute`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%i%s%s%dt%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdelayDataPath(), data.getXdelayMinute(), data.getXdelayScript(), data.getXdelayScriptText(), data.getXdelayTime(), data.getXdelayType(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXworkMinute());
}


int ProcessDAO::updateProcessDelay(const DelayDO& data) {
	string sql = "UPDATE `pp_e_delay` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdelayDataPath`=?, `xdelayMinute`=?, `xdelayScript`=?, `xdelayScriptText`=?, `xdelayTime`=?, `xdelayType`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=?, `xroute`=?, `xworkMinute`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%i%s%s%dt%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%b%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdelayDataPath(), data.getXdelayMinute(), data.getXdelayScript(), data.getXdelayScriptText(), data.getXdelayTime(), data.getXdelayType(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXworkMinute(), data.getXid());
}


int ProcessDAO::deleteProcessDelay(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_delay` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_choice
uint64_t ProcessDAO::insertProcessChoice(const ChoiceDO& data) {
	string sql = "INSERT INTO `pp_e_choice` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText());
}


int ProcessDAO::updateProcessChoice(const ChoiceDO& data) {
	string sql = "UPDATE `pp_e_choice` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXid());
}


int ProcessDAO::deleteProcessChoice(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_choice` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_service
uint64_t ProcessDAO::insertProcessService(const ServiceDO& data) {
	string sql = "INSERT INTO `pp_e_service` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`, `xroute`, `xscript`, `xscriptText`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXscript(), data.getXscriptText());
}


int ProcessDAO::updateProcessService(const ServiceDO& data) {
	string sql = "UPDATE `pp_e_service` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=?, `xroute`=?, `xscript`=?, `xscriptText`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXscript(), data.getXscriptText(), data.getXid());
}


int ProcessDAO::deleteProcessService(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_service` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}

//pp_e_split
uint64_t ProcessDAO::insertProcessSplit(const SplitDO& data) {
	string sql = "INSERT INTO `pp_e_split` (`xid`, `xcreateTime`, `xsequence`, `xupdateTime`, `xdistributeFactor`, `xafterArriveScript`, `xafterArriveScriptText`, `xafterExecuteScript`, `xafterExecuteScriptText`, `xafterInquireScript`, `xafterInquireScriptText`, `xalias`, `xallowReroute`, `xallowRerouteTo`, `xbeforeArriveScript`, `xbeforeArriveScriptText`, `xbeforeExecuteScript`, `xbeforeExecuteScriptText`, `xbeforeInquireScript`, `xbeforeInquireScriptText`, `xdescription`, `xdisplayLogScript`, `xdisplayLogScriptText`, `xedition`, `xextension`, `xform`, `xgroup`, `xname`, `xopinionGroup`, `xposition`, `xprocess`, `xproperties`, `xreadDuty`, `xreadScript`, `xreadScriptText`, `xreviewDuty`, `xreviewScript`, `xreviewScriptText`, `xroute`, `xscript`, `xscriptText`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%dt%s%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXid(), data.getXcreateTime(), data.getXsequence(), data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXscript(), data.getXscriptText());
}


int ProcessDAO::updateProcessSplit(const SplitDO& data) {
	string sql = "UPDATE `pp_e_split` SET `xupdateTime`=?, `xdistributeFactor`=?, `xafterArriveScript`=?, `xafterArriveScriptText`=?, `xafterExecuteScript`=?, `xafterExecuteScriptText`=?, `xafterInquireScript`=?, `xafterInquireScriptText`=?, `xalias`=?, `xallowReroute`=?, `xallowRerouteTo`=?, `xbeforeArriveScript`=?, `xbeforeArriveScriptText`=?, `xbeforeExecuteScript`=?, `xbeforeExecuteScriptText`=?, `xbeforeInquireScript`=?, `xbeforeInquireScriptText`=?, `xdescription`=?, `xdisplayLogScript`=?, `xdisplayLogScriptText`=?, `xedition`=?, `xextension`=?, `xform`=?, `xgroup`=?, `xname`=?, `xopinionGroup`=?, `xposition`=?, `xprocess`=?, `xproperties`=?, `xreadDuty`=?, `xreadScript`=?, `xreadScriptText`=?, `xreviewDuty`=?, `xreviewScript`=?, `xreviewScriptText`=?, `xroute`=?, `xscript`=?, `xscriptText`=? WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%dt%i%s%s%s%s%s%s%s%b%b%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", data.getXupdateTime(), data.getXdistributeFactor(), data.getXafterArriveScript(), data.getXafterArriveScriptText(), data.getXafterExecuteScript(), data.getXafterExecuteScriptText(), data.getXafterInquireScript(), data.getXafterInquireScriptText(), data.getXalias(), data.getXallowReroute(), data.getXallowRerouteTo(), data.getXbeforeArriveScript(), data.getXbeforeArriveScriptText(), data.getXbeforeExecuteScript(), data.getXbeforeExecuteScriptText(), data.getXbeforeInquireScript(), data.getXbeforeInquireScriptText(), data.getXdescription(), data.getXdisplayLogScript(), data.getXdisplayLogScriptText(), data.getXedition(), data.getXextension(), data.getXform(), data.getXgroup(), data.getXname(), data.getXopinionGroup(), data.getXposition(), data.getXprocess(), data.getXproperties(), data.getXreadDuty(), data.getXreadScript(), data.getXreadScriptText(), data.getXreviewDuty(), data.getXreviewScript(), data.getXreviewScriptText(), data.getXroute(), data.getXscript(), data.getXscriptText(), data.getXid());
}


int ProcessDAO::deleteProcessSplit(const oatpp::String& id) {
	string sql = "DELETE FROM `pp_e_split` WHERE `xprocess`=?";
	return sqlSession->executeUpdate(sql, "%s", string(id->c_str()));
}