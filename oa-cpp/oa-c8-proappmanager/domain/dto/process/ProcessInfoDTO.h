#pragma once
#ifndef _PROCESSINFO_DTO_
#define _PROCESSINFO_DTO_
#include "../../GlobalInclude.h"
#include "AgentDTO.h"
#include "BeginDTO.h"
#include "CancelDTO.h"
#include "ChoiceDTO.h"
#include "DelayDTO.h"
#include "EmbedDTO.h"
#include "EndDTO.h"
#include "InvokeDTO.h"
#include "ManualDTO.h"
#include "MergeDTO.h"
#include "RouteDTO.h"
#include "ParallelDTO.h"
#include "PublishDTO.h"
#include "ServiceDTO.h"
#include "SplitDTO.h"
#include "ProcessControllerDTO.h"
#include "ProcessStartableGroupDTO.h"
#include "ProcessStartableIdentityDTO.h"
#include "ProcessStartableUnitDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 流程列表传输对象
 */
class ProcessInfoDTO : public oatpp::DTO {
	DTO_INIT(ProcessInfoDTO, DTO);
	// 唯一标识
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("process-configuration.process-info.field.id"));
	//agent-list: // 代理列表
	API_DTO_FIELD_DEFAULT(List<AgentDTO::Wrapper>, agentList, ZH_WORDS_GETTER("process-configuration.process-info.field.agent-list"));
	//begin : // 开始
	API_DTO_FIELD_DEFAULT(BeginDTO::Wrapper, begin, ZH_WORDS_GETTER("process-configuration.process-info.field.begin"));
	//cancel-list : // 取消列表
	API_DTO_FIELD_DEFAULT(List<CancelDTO::Wrapper>, cancelList, ZH_WORDS_GETTER("process-configuration.process-info.field.cancel-list"));
	//choice-list : // 选择列表
	API_DTO_FIELD_DEFAULT(List<ChoiceDTO::Wrapper>, choiceList, ZH_WORDS_GETTER("process-configuration.process-info.field.choice-list"));
	//delay-list : // 延迟列表
	API_DTO_FIELD_DEFAULT(List<DelayDTO::Wrapper>, delayList, ZH_WORDS_GETTER("process-configuration.process-info.field.delay-list"));
	//embed-list : // 嵌入列表
	API_DTO_FIELD_DEFAULT(List<EmbedDTO::Wrapper>, embedList, ZH_WORDS_GETTER("process-configuration.process-info.field.embed-list"));
	//end-list : // 结束列表
	API_DTO_FIELD_DEFAULT(List<EndDTO::Wrapper>, endList, ZH_WORDS_GETTER("process-configuration.process-info.field.end-list"));
	//invoke-list : // 调用列表
	API_DTO_FIELD_DEFAULT(List<InvokeDTO::Wrapper>, invokeList, ZH_WORDS_GETTER("process-configuration.process-info.field.invoke-list"));
	//manual-list : // 手册列表
	API_DTO_FIELD_DEFAULT(List<ManualDTO::Wrapper>, manualList, ZH_WORDS_GETTER("process-configuration.process-info.field.manual-list"));
	//merger-list : // 合并列表
	API_DTO_FIELD_DEFAULT(List<MergeDTO::Wrapper>, mergerList, ZH_WORDS_GETTER("process-configuration.process-info.field.merger-list"));
	//route-list : // 路由列表
	API_DTO_FIELD_DEFAULT(List<RouteDTO::Wrapper>, routeList, ZH_WORDS_GETTER("process-configuration.process-info.field.route-list"));
	//parallel-list : // 平行列表
	API_DTO_FIELD_DEFAULT(List<ParallelDTO::Wrapper>, parallelList, ZH_WORDS_GETTER("process-configuration.process-info.field.parallel-list"));
	//publish-list : // 发布列表
	API_DTO_FIELD_DEFAULT(List<PublishDTO::Wrapper>, publishList, ZH_WORDS_GETTER("process-configuration.process-info.field.publish-list"));
	//service-list : // 服务列表
	API_DTO_FIELD_DEFAULT(List<ServiceDTO::Wrapper>, serviceList, ZH_WORDS_GETTER("process-configuration.process-info.field.service-list"));
	//split-list : // 拆分列表
	API_DTO_FIELD_DEFAULT(List<SplitDTO::Wrapper>, splitList, ZH_WORDS_GETTER("process-configuration.process-info.field.split-list"));
	//name : // 流程名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("process-configuration.process-info.field.name"));
	//alias : // 别名
	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("process-configuration.process-info.field.alias"));
	//description : // 描述
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("process-configuration.process-info.field.description"));
	//creator-person : // 创建人
	API_DTO_FIELD_DEFAULT(String, creatorPerson, ZH_WORDS_GETTER("process-configuration.process-info.field.creator-person"));
	//last-update-person : // 最后修改人
	API_DTO_FIELD_DEFAULT(String, lastUpdatePerson, ZH_WORDS_GETTER("process-configuration.process-info.field.last-update-person"));
	//last-update-time : // 最后修改日期
	API_DTO_FIELD_DEFAULT(String, lastUpdateTime, ZH_WORDS_GETTER("process-configuration.process-info.field.last-update-time"));
	//application : // 应用
	API_DTO_FIELD_DEFAULT(String, application, ZH_WORDS_GETTER("process-configuration.process-info.field.application"));
	//controller-list : // 控制列表
	API_DTO_FIELD_DEFAULT(List<ProcessControllerDTO::Wrapper>, controllerList, ZH_WORDS_GETTER("process-configuration.process-info.field.controller-list"));
	//after-begin-script : // 开始后脚本
	API_DTO_FIELD_DEFAULT(String, afterBeginScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-begin-script"));
	//after-begin-script-text : // 开始后脚本文本
	API_DTO_FIELD_DEFAULT(String, afterBeginScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-begin-script-text"));
	//after-end-script : // 结束后脚本
	API_DTO_FIELD_DEFAULT(String, afterEndScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-end-script"));
	//after-end-script-text : // 结束后脚本文本
	API_DTO_FIELD_DEFAULT(String, afterEndScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-end-script-text"));
	//startable-identity-list : // 可启动的身份列表
	API_DTO_FIELD_DEFAULT(List<ProcessStartableIdentityDTO::Wrapper>, startableIdentityList, ZH_WORDS_GETTER("process-configuration.process-info.field.startable-identity-list"));
	//startable-unit-list : // 可启动的单位列表
	API_DTO_FIELD_DEFAULT(List<ProcessStartableUnitDTO::Wrapper>, startableUnitList, ZH_WORDS_GETTER("process-configuration.process-info.field.startable-unit-list"));
	//startable-group-list : // 可启动的组列表
	API_DTO_FIELD_DEFAULT(List<ProcessStartableGroupDTO::Wrapper>, startableGroupList, ZH_WORDS_GETTER("process-configuration.process-info.field.startable-group-list"));
	//serial-texture : // 串行纹理
	API_DTO_FIELD_DEFAULT(String, serialTexture, ZH_WORDS_GETTER("process-configuration.process-info.field.serial-texture"));
	//serial-phase : // 串行阶段
	API_DTO_FIELD_DEFAULT(String, serialPhase, ZH_WORDS_GETTER("process-configuration.process-info.field.serial-phase"));
	//expire-type : // 到期类型
	API_DTO_FIELD_DEFAULT(String, expireType, ZH_WORDS_GETTER("process-configuration.process-info.field.expire-type"));
	//expire-day : // 到期天数
	API_DTO_FIELD_DEFAULT(UInt64, expireDay, ZH_WORDS_GETTER("process-configuration.process-info.field.expire-day"));
	//expire-hour : // 到期时数
	API_DTO_FIELD_DEFAULT(UInt64, expireHour, ZH_WORDS_GETTER("process-configuration.process-info.field.expire-hour"));
	//expire-work-time : // 过期工时
	API_DTO_FIELD_DEFAULT(Boolean, expireWorkTime, ZH_WORDS_GETTER("process-configuration.process-info.field.expire-work-time"));
	//check-draft : // 检查草稿
	API_DTO_FIELD_DEFAULT(Boolean, checkDraft, ZH_WORDS_GETTER("process-configuration.process-info.field.check-draft"));
	//startable-terminal : // 起始表终端
	API_DTO_FIELD_DEFAULT(String, startableTerminal, ZH_WORDS_GETTER("process-configuration.process-info.field.startable-terminal"));
	//projection-fully : // 完全投影
	API_DTO_FIELD_DEFAULT(Boolean, projectionFully, ZH_WORDS_GETTER("process-configuration.process-info.field.projection-fully"));
	//route-name-as-option : // 使用路由名称作为缺省意见
	API_DTO_FIELD_DEFAULT(Boolean, routeNameAsOption, ZH_WORDS_GETTER("process-configuration.process-info.field.route-name-as-option"));
	//before-arrive-script : // 到达前脚本
	API_DTO_FIELD_DEFAULT(String, beforeArriveScript, ZH_WORDS_GETTER("process-configuration.process-info.field.before-arrive-script"));
	//before-arrive-script-text : // 到达前脚本文本
	API_DTO_FIELD_DEFAULT(String, beforeArriveScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.before-arrive-script-text"));
	//after-arrive-script : // 到达后脚本
	API_DTO_FIELD_DEFAULT(String, afterArriveScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-arrive-script"));
	//after-arrive-script-text : // 到达后脚本文本
	API_DTO_FIELD_DEFAULT(String, afterArriveScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-arrive-script-text"));
	//before-execute-script : // 执行前脚本
	API_DTO_FIELD_DEFAULT(String, beforeExecuteScript, ZH_WORDS_GETTER("process-configuration.process-info.field.before-execute-script"));
	//before-execute-script-text : // 执行前脚本文本
	API_DTO_FIELD_DEFAULT(String, beforeExecuteScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.before-execute-script-text"));
	//after-execute-script : // 执行后脚本
	API_DTO_FIELD_DEFAULT(String, afterExecuteScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-execute-script"));
	//after-execute-script-text : // 执行后脚本文本
	API_DTO_FIELD_DEFAULT(String, afterExecuteScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-execute-script-text"));
	//before-inquire-script : // 询问前脚本
	API_DTO_FIELD_DEFAULT(String, beforeInquireScript, ZH_WORDS_GETTER("process-configuration.process-info.field.before-inquire-script"));
	//before-inquire-script-text : // 询问前脚本文本
	API_DTO_FIELD_DEFAULT(String, beforeInquireScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.before-inquire-script-text"));
	//after-inquire-script : // 询问后脚本
	API_DTO_FIELD_DEFAULT(String, afterInquireScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-inquire-script"));
	//after-inquire-script-text : // 询问后脚本文本
	API_DTO_FIELD_DEFAULT(String, afterInquireScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-inquire-script-text"));
	//edition : // 版号
	API_DTO_FIELD_DEFAULT(String, edition, ZH_WORDS_GETTER("process-configuration.process-info.field.edition"));
	//edition-name : // 编辑名称
	API_DTO_FIELD_DEFAULT(String, editionName, ZH_WORDS_GETTER("process-configuration.process-info.field.edition-name"));
	//edition-enable : // 启用编辑
	API_DTO_FIELD_DEFAULT(Boolean, editionEnable, ZH_WORDS_GETTER("process-configuration.process-info.field.edition-enable"));
	//edition-number : // 编辑次数
	API_DTO_FIELD_DEFAULT(Float64, editionNumber, ZH_WORDS_GETTER("process-configuration.process-info.field.edition-number"));
	//default-start-mode : // 默认启动类型
	API_DTO_FIELD_DEFAULT(String, defaultStartMode, ZH_WORDS_GETTER("process-configuration.process-info.field.default-start-mode"));
	//properties : // 属性
	API_DTO_FIELD_DEFAULT(String, properties, ZH_WORDS_GETTER("process-configuration.process-info.field.properties"));
	//create-time : // 创建时间
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("process-configuration.process-info.field.create-time"));
	//update-time : // 更新时间
	API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("process-configuration.process-info.field.update-time"));
	//is-new-process : // 是新流程
	API_DTO_FIELD_DEFAULT(String, isNewProcess, ZH_WORDS_GETTER("process-configuration.process-info.field.is-new-process"));
	//projection-data :// 投影数据
	API_DTO_FIELD_DEFAULT(String, projectionData, ZH_WORDS_GETTER("process-configuration.process-info.field.projection-data"));
	//application-name : // 应用名称
	API_DTO_FIELD_DEFAULT(String, applicationName, ZH_WORDS_GETTER("process-configuration.process-info.field.application-name"));
	//category : // 所属分类
	API_DTO_FIELD_DEFAULT(String, category, ZH_WORDS_GETTER("process-configuration.process-info.field.category"));
	//update-table-enable : // 启用更新表
	API_DTO_FIELD_DEFAULT(String, updateTableEnable, ZH_WORDS_GETTER("process-configuration.process-info.field.update-table-enable"));
	//data-trace-field-type : // 数据跟踪字段类型
	API_DTO_FIELD_DEFAULT(String, dataTraceFieldType, ZH_WORDS_GETTER("process-configuration.process-info.field.data-trace-field-type"));
};

/**
 * 流程列表分页传输对象
 */
//class ProcessInfoPageDTO : public PageDTO<ProcessInfoDTO::Wrapper> {
//	DTO_INIT(ProcessInfoPageDTO, PageDTO<ProcessInfoDTO::Wrapper>);
//};

#include OATPP_CODEGEN_END(DTO)



#endif // !_PROCESSINFO_DTO_
