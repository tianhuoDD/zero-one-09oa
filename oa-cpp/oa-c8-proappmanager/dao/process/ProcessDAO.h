#pragma once
#ifndef _PROCESS_DAO_
#define _PROCESS_DAO_

#include "BaseDAO.h"
#include <list>
#include <map>
#include "domain/query/process/ProcessListQuery.h"
#include "domain/do/process/ProcessTypesDO.h"
#include "domain/do/process/ProcessListDO.h"
#include "domain/do/process/ProcessInfoDO.h"
#include "domain/do/process/AgentDO.h"
#include "domain/do/process/BeginDO.h"
#include "domain/do/process/CancelDO.h"
#include "domain/do/process/ChoiceDO.h"
#include "domain/do/process/DelayDO.h"
#include "domain/do/process/EmbedDO.h"
#include "domain/do/process/EndDO.h"
#include "domain/do/process/InvokeDO.h"
#include "domain/do/process/ManualDO.h"
#include "domain/do/process/MergeDO.h"
#include "domain/do/process/ParallelDO.h"
#include "domain/do/process/ProcessControllerDO.h"
#include "domain/do/process/ProcessStartableGroupDO.h"
#include "domain/do/process/ProcessStartableIdentityDO.h"
#include "domain/do/process/ProcessStartableUnitDO.h"
#include "domain/do/process/PublishDO.h"
#include "domain/do/process/RouteDO.h"
#include "domain/do/process/ServiceDO.h"
#include "domain/do/process/SplitDO.h"
#include "domain/do/process/ProcessDO.h"


/**
 * 流程DAO
 */
class ProcessDAO : public BaseDAO {
public:
	// 查询流程类型及数量
	list<ProcessTypesDO> selectTypes(const oatpp::String& appId);
	// 统计数据总数
	uint64_t count(const ProcessListQuery::Wrapper& query);
	// 分页查询所有列表
	list<ProcessListDO> selectProcess(const ProcessListQuery::Wrapper& query);
	// 查询流程详情
	list<ProcessInfoDO> selectProcessInfoMain(const oatpp::String& id);
	// 查询详情相关函数
	list<AgentDO> selectAgentList(const oatpp::String& xprocess);
	list<BeginDO> selectBeginList(const oatpp::String& xprocess);
	list<CancelDO> selectCancelList(const oatpp::String& xprocess);
	list<ChoiceDO> selectChoiceList(const oatpp::String& xprocess);
	list<DelayDO> selectDelayList(const oatpp::String& xprocess);
	list<EmbedDO> selectEmbedList(const oatpp::String& xprocess);
	list<EndDO> selectEndList(const oatpp::String& xprocess);
	list<InvokeDO> selectInvokeList(const oatpp::String& xprocess);
	list<ManualDO> selectManualList(const oatpp::String& xprocess);
	list<MergeDO> selectMergeList(const oatpp::String& xprocess);
	list<ParallelDO> selectParallelList(const oatpp::String& xprocess);
	list<ProcessControllerDO> selectProcessControllerList(const oatpp::String& xprocess);
	list<ProcessStartableGroupDO> selectProcessStartableGroupList(const oatpp::String& xprocess);
	list<ProcessStartableIdentityDO> selectProcessStartableIdentityList(const oatpp::String& xprocess);
	list<ProcessStartableUnitDO> selectProcessStartableUnitList(const oatpp::String& xprocess);
	list<PublishDO> selectPublishList(const oatpp::String& xprocess);
	list<RouteDO> selectRouteList(const oatpp::String& xprocess);
	list<ServiceDO> selectServiceList(const oatpp::String& xprocess);
	list<SplitDO> selectSplitList(const oatpp::String& xprocess);

	//pp_e_process
	uint64_t insertProcess(const ProcessDO& data);

	int updateProcess(const ProcessDO& data);

	int deleteProcess(const oatpp::String& id);

	//pp_e_begin
	uint64_t insertProcessBegin(const BeginDO& data);

	int updateProcessBegin(const BeginDO& data);

	int deleteProcessBegin(const oatpp::String& id);

	//pp_e_end
	uint64_t insertProcessEnd(const EndDO& data);

	int updateProcessEnd(const EndDO& data);

	int deleteProcessEnd(const oatpp::String& id);

	//pp_e_manual
	uint64_t insertProcessManual(const ManualDO& data);

	int updateProcessManual(const ManualDO& data);

	int deleteProcessManual(const oatpp::String& id);

	//pp_e_route
	uint64_t insertProcessRoute(const RouteDO& data);

	int updateProcessRoute(const RouteDO& data);

	int deleteProcessRoute(const oatpp::String& id);

	//pp_e_merge
	uint64_t insertProcessMerge(const MergeDO& data);

	int updateProcessMerge(const MergeDO& data);

	int deleteProcessMerge(const oatpp::String& id);

	//pp_e_parallel
	uint64_t insertProcessParallel(const ParallelDO& data);

	int updateProcessParallel(const ParallelDO& data);

	int deleteProcessParallel(const oatpp::String& id);

	//pp_e_invoke
	uint64_t insertProcessInvoke(const InvokeDO& data);

	int updateProcessInvoke(const InvokeDO& data);

	int deleteProcessInvoke(const oatpp::String& id);

	//pp_e_embed
	uint64_t insertProcessEmbed(const EmbedDO& data);

	int updateProcessEmbed(const EmbedDO& data);

	int deleteProcessEmbed(const oatpp::String& id);

	//pp_e_publish
	uint64_t insertProcessPublish(const PublishDO& data);

	int updateProcessPublish(const PublishDO& data);

	int deleteProcessPublish(const oatpp::String& id);

	//pp_e_delay
	uint64_t insertProcessDelay(const DelayDO& data);

	int updateProcessDelay(const DelayDO& data);

	int deleteProcessDelay(const oatpp::String& id);

	//pp_e_choice
	uint64_t insertProcessChoice(const ChoiceDO& data);

	int updateProcessChoice(const ChoiceDO& data);

	int deleteProcessChoice(const oatpp::String& id);

	//pp_e_service
	uint64_t insertProcessService(const ServiceDO& data);

	int updateProcessService(const ServiceDO& data);

	int deleteProcessService(const oatpp::String& id);

	//pp_e_split
	uint64_t insertProcessSplit(const SplitDO& data);

	int updateProcessSplit(const SplitDO& data);

	int deleteProcessSplit(const oatpp::String& id);
};

#endif // !_PROCESS_DAO_
