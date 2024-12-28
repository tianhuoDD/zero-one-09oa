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
 * �����б������
 */
class ProcessInfoDTO : public oatpp::DTO {
	DTO_INIT(ProcessInfoDTO, DTO);
	// Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("process-configuration.process-info.field.id"));
	//agent-list: // �����б�
	API_DTO_FIELD_DEFAULT(List<AgentDTO::Wrapper>, agentList, ZH_WORDS_GETTER("process-configuration.process-info.field.agent-list"));
	//begin : // ��ʼ
	API_DTO_FIELD_DEFAULT(BeginDTO::Wrapper, begin, ZH_WORDS_GETTER("process-configuration.process-info.field.begin"));
	//cancel-list : // ȡ���б�
	API_DTO_FIELD_DEFAULT(List<CancelDTO::Wrapper>, cancelList, ZH_WORDS_GETTER("process-configuration.process-info.field.cancel-list"));
	//choice-list : // ѡ���б�
	API_DTO_FIELD_DEFAULT(List<ChoiceDTO::Wrapper>, choiceList, ZH_WORDS_GETTER("process-configuration.process-info.field.choice-list"));
	//delay-list : // �ӳ��б�
	API_DTO_FIELD_DEFAULT(List<DelayDTO::Wrapper>, delayList, ZH_WORDS_GETTER("process-configuration.process-info.field.delay-list"));
	//embed-list : // Ƕ���б�
	API_DTO_FIELD_DEFAULT(List<EmbedDTO::Wrapper>, embedList, ZH_WORDS_GETTER("process-configuration.process-info.field.embed-list"));
	//end-list : // �����б�
	API_DTO_FIELD_DEFAULT(List<EndDTO::Wrapper>, endList, ZH_WORDS_GETTER("process-configuration.process-info.field.end-list"));
	//invoke-list : // �����б�
	API_DTO_FIELD_DEFAULT(List<InvokeDTO::Wrapper>, invokeList, ZH_WORDS_GETTER("process-configuration.process-info.field.invoke-list"));
	//manual-list : // �ֲ��б�
	API_DTO_FIELD_DEFAULT(List<ManualDTO::Wrapper>, manualList, ZH_WORDS_GETTER("process-configuration.process-info.field.manual-list"));
	//merger-list : // �ϲ��б�
	API_DTO_FIELD_DEFAULT(List<MergeDTO::Wrapper>, mergerList, ZH_WORDS_GETTER("process-configuration.process-info.field.merger-list"));
	//route-list : // ·���б�
	API_DTO_FIELD_DEFAULT(List<RouteDTO::Wrapper>, routeList, ZH_WORDS_GETTER("process-configuration.process-info.field.route-list"));
	//parallel-list : // ƽ���б�
	API_DTO_FIELD_DEFAULT(List<ParallelDTO::Wrapper>, parallelList, ZH_WORDS_GETTER("process-configuration.process-info.field.parallel-list"));
	//publish-list : // �����б�
	API_DTO_FIELD_DEFAULT(List<PublishDTO::Wrapper>, publishList, ZH_WORDS_GETTER("process-configuration.process-info.field.publish-list"));
	//service-list : // �����б�
	API_DTO_FIELD_DEFAULT(List<ServiceDTO::Wrapper>, serviceList, ZH_WORDS_GETTER("process-configuration.process-info.field.service-list"));
	//split-list : // ����б�
	API_DTO_FIELD_DEFAULT(List<SplitDTO::Wrapper>, splitList, ZH_WORDS_GETTER("process-configuration.process-info.field.split-list"));
	//name : // ��������
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("process-configuration.process-info.field.name"));
	//alias : // ����
	API_DTO_FIELD_DEFAULT(String, alias, ZH_WORDS_GETTER("process-configuration.process-info.field.alias"));
	//description : // ����
	API_DTO_FIELD_DEFAULT(String, description, ZH_WORDS_GETTER("process-configuration.process-info.field.description"));
	//creator-person : // ������
	API_DTO_FIELD_DEFAULT(String, creatorPerson, ZH_WORDS_GETTER("process-configuration.process-info.field.creator-person"));
	//last-update-person : // ����޸���
	API_DTO_FIELD_DEFAULT(String, lastUpdatePerson, ZH_WORDS_GETTER("process-configuration.process-info.field.last-update-person"));
	//last-update-time : // ����޸�����
	API_DTO_FIELD_DEFAULT(String, lastUpdateTime, ZH_WORDS_GETTER("process-configuration.process-info.field.last-update-time"));
	//application : // Ӧ��
	API_DTO_FIELD_DEFAULT(String, application, ZH_WORDS_GETTER("process-configuration.process-info.field.application"));
	//controller-list : // �����б�
	API_DTO_FIELD_DEFAULT(List<ProcessControllerDTO::Wrapper>, controllerList, ZH_WORDS_GETTER("process-configuration.process-info.field.controller-list"));
	//after-begin-script : // ��ʼ��ű�
	API_DTO_FIELD_DEFAULT(String, afterBeginScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-begin-script"));
	//after-begin-script-text : // ��ʼ��ű��ı�
	API_DTO_FIELD_DEFAULT(String, afterBeginScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-begin-script-text"));
	//after-end-script : // ������ű�
	API_DTO_FIELD_DEFAULT(String, afterEndScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-end-script"));
	//after-end-script-text : // ������ű��ı�
	API_DTO_FIELD_DEFAULT(String, afterEndScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-end-script-text"));
	//startable-identity-list : // ������������б�
	API_DTO_FIELD_DEFAULT(List<ProcessStartableIdentityDTO::Wrapper>, startableIdentityList, ZH_WORDS_GETTER("process-configuration.process-info.field.startable-identity-list"));
	//startable-unit-list : // �������ĵ�λ�б�
	API_DTO_FIELD_DEFAULT(List<ProcessStartableUnitDTO::Wrapper>, startableUnitList, ZH_WORDS_GETTER("process-configuration.process-info.field.startable-unit-list"));
	//startable-group-list : // �����������б�
	API_DTO_FIELD_DEFAULT(List<ProcessStartableGroupDTO::Wrapper>, startableGroupList, ZH_WORDS_GETTER("process-configuration.process-info.field.startable-group-list"));
	//serial-texture : // ��������
	API_DTO_FIELD_DEFAULT(String, serialTexture, ZH_WORDS_GETTER("process-configuration.process-info.field.serial-texture"));
	//serial-phase : // ���н׶�
	API_DTO_FIELD_DEFAULT(String, serialPhase, ZH_WORDS_GETTER("process-configuration.process-info.field.serial-phase"));
	//expire-type : // ��������
	API_DTO_FIELD_DEFAULT(String, expireType, ZH_WORDS_GETTER("process-configuration.process-info.field.expire-type"));
	//expire-day : // ��������
	API_DTO_FIELD_DEFAULT(UInt64, expireDay, ZH_WORDS_GETTER("process-configuration.process-info.field.expire-day"));
	//expire-hour : // ����ʱ��
	API_DTO_FIELD_DEFAULT(UInt64, expireHour, ZH_WORDS_GETTER("process-configuration.process-info.field.expire-hour"));
	//expire-work-time : // ���ڹ�ʱ
	API_DTO_FIELD_DEFAULT(Boolean, expireWorkTime, ZH_WORDS_GETTER("process-configuration.process-info.field.expire-work-time"));
	//check-draft : // ���ݸ�
	API_DTO_FIELD_DEFAULT(Boolean, checkDraft, ZH_WORDS_GETTER("process-configuration.process-info.field.check-draft"));
	//startable-terminal : // ��ʼ���ն�
	API_DTO_FIELD_DEFAULT(String, startableTerminal, ZH_WORDS_GETTER("process-configuration.process-info.field.startable-terminal"));
	//projection-fully : // ��ȫͶӰ
	API_DTO_FIELD_DEFAULT(Boolean, projectionFully, ZH_WORDS_GETTER("process-configuration.process-info.field.projection-fully"));
	//route-name-as-option : // ʹ��·��������Ϊȱʡ���
	API_DTO_FIELD_DEFAULT(Boolean, routeNameAsOption, ZH_WORDS_GETTER("process-configuration.process-info.field.route-name-as-option"));
	//before-arrive-script : // ����ǰ�ű�
	API_DTO_FIELD_DEFAULT(String, beforeArriveScript, ZH_WORDS_GETTER("process-configuration.process-info.field.before-arrive-script"));
	//before-arrive-script-text : // ����ǰ�ű��ı�
	API_DTO_FIELD_DEFAULT(String, beforeArriveScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.before-arrive-script-text"));
	//after-arrive-script : // �����ű�
	API_DTO_FIELD_DEFAULT(String, afterArriveScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-arrive-script"));
	//after-arrive-script-text : // �����ű��ı�
	API_DTO_FIELD_DEFAULT(String, afterArriveScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-arrive-script-text"));
	//before-execute-script : // ִ��ǰ�ű�
	API_DTO_FIELD_DEFAULT(String, beforeExecuteScript, ZH_WORDS_GETTER("process-configuration.process-info.field.before-execute-script"));
	//before-execute-script-text : // ִ��ǰ�ű��ı�
	API_DTO_FIELD_DEFAULT(String, beforeExecuteScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.before-execute-script-text"));
	//after-execute-script : // ִ�к�ű�
	API_DTO_FIELD_DEFAULT(String, afterExecuteScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-execute-script"));
	//after-execute-script-text : // ִ�к�ű��ı�
	API_DTO_FIELD_DEFAULT(String, afterExecuteScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-execute-script-text"));
	//before-inquire-script : // ѯ��ǰ�ű�
	API_DTO_FIELD_DEFAULT(String, beforeInquireScript, ZH_WORDS_GETTER("process-configuration.process-info.field.before-inquire-script"));
	//before-inquire-script-text : // ѯ��ǰ�ű��ı�
	API_DTO_FIELD_DEFAULT(String, beforeInquireScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.before-inquire-script-text"));
	//after-inquire-script : // ѯ�ʺ�ű�
	API_DTO_FIELD_DEFAULT(String, afterInquireScript, ZH_WORDS_GETTER("process-configuration.process-info.field.after-inquire-script"));
	//after-inquire-script-text : // ѯ�ʺ�ű��ı�
	API_DTO_FIELD_DEFAULT(String, afterInquireScriptText, ZH_WORDS_GETTER("process-configuration.process-info.field.after-inquire-script-text"));
	//edition : // ���
	API_DTO_FIELD_DEFAULT(String, edition, ZH_WORDS_GETTER("process-configuration.process-info.field.edition"));
	//edition-name : // �༭����
	API_DTO_FIELD_DEFAULT(String, editionName, ZH_WORDS_GETTER("process-configuration.process-info.field.edition-name"));
	//edition-enable : // ���ñ༭
	API_DTO_FIELD_DEFAULT(Boolean, editionEnable, ZH_WORDS_GETTER("process-configuration.process-info.field.edition-enable"));
	//edition-number : // �༭����
	API_DTO_FIELD_DEFAULT(Float64, editionNumber, ZH_WORDS_GETTER("process-configuration.process-info.field.edition-number"));
	//default-start-mode : // Ĭ����������
	API_DTO_FIELD_DEFAULT(String, defaultStartMode, ZH_WORDS_GETTER("process-configuration.process-info.field.default-start-mode"));
	//properties : // ����
	API_DTO_FIELD_DEFAULT(String, properties, ZH_WORDS_GETTER("process-configuration.process-info.field.properties"));
	//create-time : // ����ʱ��
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("process-configuration.process-info.field.create-time"));
	//update-time : // ����ʱ��
	API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("process-configuration.process-info.field.update-time"));
	//is-new-process : // ��������
	API_DTO_FIELD_DEFAULT(String, isNewProcess, ZH_WORDS_GETTER("process-configuration.process-info.field.is-new-process"));
	//projection-data :// ͶӰ����
	API_DTO_FIELD_DEFAULT(String, projectionData, ZH_WORDS_GETTER("process-configuration.process-info.field.projection-data"));
	//application-name : // Ӧ������
	API_DTO_FIELD_DEFAULT(String, applicationName, ZH_WORDS_GETTER("process-configuration.process-info.field.application-name"));
	//category : // ��������
	API_DTO_FIELD_DEFAULT(String, category, ZH_WORDS_GETTER("process-configuration.process-info.field.category"));
	//update-table-enable : // ���ø��±�
	API_DTO_FIELD_DEFAULT(String, updateTableEnable, ZH_WORDS_GETTER("process-configuration.process-info.field.update-table-enable"));
	//data-trace-field-type : // ���ݸ����ֶ�����
	API_DTO_FIELD_DEFAULT(String, dataTraceFieldType, ZH_WORDS_GETTER("process-configuration.process-info.field.data-trace-field-type"));
};

/**
 * �����б��ҳ�������
 */
//class ProcessInfoPageDTO : public PageDTO<ProcessInfoDTO::Wrapper> {
//	DTO_INIT(ProcessInfoPageDTO, PageDTO<ProcessInfoDTO::Wrapper>);
//};

#include OATPP_CODEGEN_END(DTO)



#endif // !_PROCESSINFO_DTO_
