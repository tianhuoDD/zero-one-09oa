 #pragma once
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/gets-person-lists/PersonlistVO.h"
#include "domain/query/gets-person-lists/Personlistquery.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PersonlistController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PersonlistController);
	// 3 ����ӿ�
public:
	// ��ȡ������Ϣ�ӿ�
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryPersonlist) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("person.setting.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(PersonlistPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����״̬�Ĳ�ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xstatus", ZH_WORDS_GETTER("person.setting.get.field.xstatus"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "input", ZH_WORDS_GETTER("person.setting.get.field.input"), "", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "personal-management/gets-person-lists", queryPersonlist, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, PersonlistQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(executeQueryPersonList(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	PersonlistPageJsonVO::Wrapper executeQueryPersonList(const PersonlistQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_