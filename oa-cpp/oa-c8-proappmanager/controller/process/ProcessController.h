#pragma once
#ifndef _PROCESS_CONTROLLER_
#define _PROCESS_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/process/ProcessTypesVO.h"
#include "domain/query/process/ProcessListQuery.h"
#include "domain/dto/process/ProcessListDTO.h"
#include "domain/vo/process/ProcessListVO.h"
#include "domain/dto/process/ProcessInfoDTO.h"
#include "domain/dto/process/ProcessSettingDTO.h"
#include "domain/vo/process/ProcessSettingVO.h"
#include "domain/vo/process/ProcessInfoVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ProcessController : public oatpp::web::server::api::ApiController {
	// �������������
	API_ACCESS_DECLARE(ProcessController);
public: // ����ӿ�

	//��ȡ�ӿ���Ϣ
	ENDPOINT_INFO(addProcessInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.setting.get.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessInfoJsonVO);
	}
	//�����ӿ�
	ENDPOINT(API_M_POST, "/process-app-manager/process/add", addProcessInfo, BODY_DTO(ProcessInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(AddProcess(dto, authObject->getPayload()));
	}


	ENDPOINT_INFO(modifyProcessInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.setting.put.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessInfoJsonVO);
	}
	//�޸Ľӿ�
	ENDPOINT(API_M_PUT, "/process-app-manager/process/modify", modifyProcessInfo, BODY_DTO(ProcessInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(ModifyProcess(dto, authObject->getPayload()));
	}


	ENDPOINT_INFO(deleteProcessInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process.setting.delete.summary"));
		// ����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessInfoJsonVO);
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("process-configuration.process-info.field.application"), "", true);
	}
	//ɾ���ӿ�
	ENDPOINT(API_M_DEL, "/process-app-manager/process/delete/{id}", deleteProcessInfo, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(DeleteProcess(id));
	}



	// ��ȡ������������
	ENDPOINT_INFO(queryProcessTypes) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process-configuration.process-types.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessTypesListJsonVO);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/process/query-types", queryProcessTypes, QUERY(String, appId), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryProcessTypes(appId));
	}

	// ��ȡ�����б�
	ENDPOINT_INFO(queryProcessList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process-configuration.process-list.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessListPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		String fieldPrefix = "process-configuration.process-list.field.";
		API_DEF_ADD_QUERY_PARAMS(String, "application", ZH_WORDS_GETTER(String(fieldPrefix + "application")), "application", true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER(String(fieldPrefix + "name")), "name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "alias", ZH_WORDS_GETTER(String(fieldPrefix + "alias")), "alias", false);
		API_DEF_ADD_QUERY_PARAMS(String, "category", ZH_WORDS_GETTER(String(fieldPrefix + "category")), "category", false);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/process/query-list", queryProcessList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(processListQuery, ProcessListQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryProcessList(processListQuery, authObject->getPayload()));
	}

	// ��ȡ��������
	ENDPOINT_INFO(queryProcessInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("process-configuration.process-info.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ProcessInfoJsonVO);
		// ����������ѯ��������
		String fieldPrefix = "process-configuration.process-info.field.";
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER(String(fieldPrefix + "id")), "id", true);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/process/query-info", queryProcessInfo, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execQueryProcessInfo(id));
	}


private: // ����ӿ�ִ�к���
	// ��ȡ������������
	ProcessTypesListJsonVO::Wrapper execQueryProcessTypes(const String& appId);
	// ��ȡ�����б�
	ProcessListPageJsonVO::Wrapper execQueryProcessList(const ProcessListQuery::Wrapper& query, const PayloadDTO& payload);
	// ��ȡ��������
	ProcessInfoJsonVO::Wrapper execQueryProcessInfo(const String& id);


	// ִ�д���
	StringJsonVO::Wrapper AddProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	StringJsonVO::Wrapper ModifyProcess(const ProcessInfoDTO::Wrapper& dto, const PayloadDTO& payload);

	StringJsonVO::Wrapper DeleteProcess(const String id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_PROCESS_CONTROLLER_
