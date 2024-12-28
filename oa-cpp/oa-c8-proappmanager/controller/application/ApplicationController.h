#ifndef _APPLICATIONINFOCONTROLLER_H_
#define _APPLICATIONINFOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/application/ApplicationDTO.h"
#include "domain/dto/application/AddApplicationDTO.h"
#include "domain/dto/application/ApplicationIdDTO.h"
#include "domain/query/application/ApplicationQuery.h"
#include "domain/vo/application/ApplicationPageVO.h"
#include "domain/vo/application/ApplicationIdVO.h"
#include "domain/vo/application/ApplicationTypesVO.h"
#include "domain/vo/application/ApplicationPropertiesVO.h"
#include "domain/dto/application/ApplicationPropertiesDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

class ApplicationController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(ApplicationController);

public: 
	
	//��ҳ��ȡӦ����Ϣ(����+��ҳ)
	ENDPOINT_INFO(queryApplication) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("application.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplicationPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������(�п�)
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("application.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("application.field.name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xalias", ZH_WORDS_GETTER("application.field.alias"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xapplicationCategory", ZH_WORDS_GETTER("application.field.applicationCategory"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/process-app-manager/application/summary", queryApplication, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(applicationQuery, ApplicationQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryApplication(applicationQuery, authObject->getPayload()));
	}

	//�½�Ӧ��
	ENDPOINT_INFO(addApplication) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("application.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplicationIdJsonVO);
	}
	ENDPOINT(API_M_POST, "/process-app-manager/application/add", addApplication, BODY_DTO(AddApplicationDTO::Wrapper, one_application), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddApplication(one_application, authObject->getPayload()));
	}

	 //ɾ������Ӧ������
	ENDPOINT_INFO(removeApplication) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("application.delete.summary"), ApplicationIdJsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/process-app-manager/application/delete/{id}", removeApplication, PATH(String, id), execRemoveApplication(id, authObject->getPayload()));
	
	// ��ȡӦ������
	ENDPOINT_INFO(queryAppTypes) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("application.app-types.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplicationTypesListJsonVO);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/application/query-types", queryAppTypes, API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAppTypes());
	}

	// ��ȡӦ������
	ENDPOINT_INFO(queryAppProperties) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("application.app-properties.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ApplicationPropertiesJsonVO);
		// ��ѯ����:Ӧ��ID
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("application-info.pp_e_application.field.xid"), "83496759-2037-440d-8e4f-27ede60f85bd", true);
	}
	ENDPOINT(API_M_GET, "/process-app-manager/application/query-properties", queryAppProperties, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAppProperties(id, authObject->getPayload()));
	}

	// �޸�Ӧ������
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("application.app-properties.put.summary"), modifyAppProperties, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/process-app-manager/application/modify-properties", modifyAppProperties, BODY_DTO(ApplicationPropertiesDTO::Wrapper, dto), execModifyAppProperties(dto, authObject->getPayload()));

private: // ����ӿ�ִ�к���
	ApplicationPageJsonVO::Wrapper execQueryApplication(const ApplicationQuery::Wrapper& query, const PayloadDTO& payload);
	ApplicationIdJsonVO::Wrapper execAddApplication(const AddApplicationDTO::Wrapper& one_application, const PayloadDTO& payload);
	ApplicationIdJsonVO::Wrapper execRemoveApplication(const String id, const PayloadDTO& payload);
	// ��ȡӦ������
	ApplicationTypesListJsonVO::Wrapper execQueryAppTypes();
	// ��ȡӦ������
	ApplicationPropertiesJsonVO::Wrapper execQueryAppProperties(const String& id, const PayloadDTO& payload);
	// �޸�Ӧ������
	Uint64JsonVO::Wrapper execModifyAppProperties(const ApplicationPropertiesDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_APPLICATIONINFOCONTROLLER_H_