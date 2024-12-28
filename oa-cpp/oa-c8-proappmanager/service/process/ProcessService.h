#pragma once
#ifndef _PROCESS_SERVICE_
#define _PROCESS_SERVICE_

#include "domain/vo/process/ProcessTypesVO.h"
#include "domain/dto/process/ProcessListDTO.h"
#include "domain/do/process/ProcessListDO.h"
#include "domain/query/process/ProcessListQuery.h"
#include "domain/dto/process/ProcessInfoDTO.h"
#include "domain/vo/process/ProcessInfoVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/process/AgentDTO.h"
#include "domain/dto/process/BeginDTO.h"
#include "domain/dto/process/CancelDTO.h"
#include "domain/dto/process/ChoiceDTO.h"
#include "domain/dto/process/DelayDTO.h"
#include "domain/dto/process/EmbedDTO.h"
#include "domain/dto/process/EndDTO.h"
#include "domain/dto/process/InvokeDTO.h"
#include "domain/dto/process/ManualDTO.h"
#include "domain/dto/process/MergeDTO.h"
#include "domain/dto/process/ParallelDTO.h"
#include "domain/dto/process/ProcessControllerDTO.h"
#include "domain/dto/process/ProcessStartableGroupDTO.h"
#include "domain/dto/process/ProcessStartableIdentityDTO.h"
#include "domain/dto/process/ProcessStartableUnitDTO.h"
#include "domain/dto/process/PublishDTO.h"
#include "domain/dto/process/RouteDTO.h"
#include "domain/dto/process/ServiceDTO.h"
#include "domain/dto/process/SplitDTO.h"

class ProcessService {
public:
	// 查询流程类型及数量
	ProcessTypesListVO::Wrapper listTypes(const oatpp::String& appId);
	// 分页查询所有列表
	ProcessListPageDTO::Wrapper listProcess(const ProcessListQuery::Wrapper& query);
	// 查询流程详情
	ProcessInfoDTO::Wrapper queryProcessInfo(const oatpp::String& id);
	string insertProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	bool updateProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	bool deleteProcess(const oatpp::String& id);
private:
	oatpp::List<AgentDTO::Wrapper> queryAgentList(const oatpp::String& process);
	BeginDTO::Wrapper queryBeginList(const oatpp::String& process);
	oatpp::List<CancelDTO::Wrapper> queryCancelList(const oatpp::String& process);
	oatpp::List<ChoiceDTO::Wrapper> queryChoiceList(const oatpp::String& process);
	oatpp::List<DelayDTO::Wrapper> queryDelayList(const oatpp::String& process);
	oatpp::List<EmbedDTO::Wrapper> queryEmbedList(const oatpp::String& process);
	oatpp::List<EndDTO::Wrapper> queryEndList(const oatpp::String& process);
	oatpp::List<InvokeDTO::Wrapper> queryInvokeList(const oatpp::String& process);
	oatpp::List<ManualDTO::Wrapper> queryManualList(const oatpp::String& process);
	oatpp::List<MergeDTO::Wrapper> queryMergeList(const oatpp::String& process);
	oatpp::List<ParallelDTO::Wrapper> queryParallelList(const oatpp::String& process);
	oatpp::List<ProcessControllerDTO::Wrapper> queryProcessControllerList(const oatpp::String& process);
	oatpp::List<ProcessStartableGroupDTO::Wrapper> queryProcessStartableGroupList(const oatpp::String& process);
	oatpp::List<ProcessStartableIdentityDTO::Wrapper> queryProcessStartableIdentityList(const oatpp::String& process);
	oatpp::List<ProcessStartableUnitDTO::Wrapper> queryProcessStartableUnitList(const oatpp::String& process);
	oatpp::List<PublishDTO::Wrapper> queryPublishList(const oatpp::String& process);
	oatpp::List<RouteDTO::Wrapper> queryRouteList(const oatpp::String& process);
	oatpp::List<ServiceDTO::Wrapper> queryServiceList(const oatpp::String& process);
	oatpp::List<SplitDTO::Wrapper> querySplitList(const oatpp::String& process);

	string insertProcessBegin(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessEnd(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessManual(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessRoute(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessMerge(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessInvoke(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessEmbed(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessPublish(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessDelay(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessChoice(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessService(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessSplit(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	void updateProcessBegin(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessEnd(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessManual(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessRoute(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessMerge(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessInvoke(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessEmbed(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessPublish(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessDelay(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessChoice(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessService(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	void updateProcessSplit(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	/*string insertProcessAgent(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessCancel(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessParallel(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessControllerlist(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessStartablegrouplist(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessStartableidentitylist(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	string insertProcessStartableunitlist(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);*/
};

#endif // !_PROCESS_SERVICE_
