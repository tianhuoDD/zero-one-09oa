#pragma once

#ifndef _LIST_PERSONAL_IDENTITYCONTROLLER_
#define _LIST_PERSONAL_IDENTITYCONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/query/list/list_personal_identityQuery.h"
#include "../../domain/vo/list/list_personal_identityJsonVO.h"
#include "../../domain/dto/list/list_personal_identityDTO.h"




#include OATPP_CODEGEN_BEGIN(ApiController)

class list_personal_identityController : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(list_personal_identityController);
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(query_list_personal_identity) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.get.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ 
		API_DEF_ADD_RSP_JSON_WRAPPER(listPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "xid", ZH_WORDS_GETTER("sample.field.xid"), "221c0b2a-09d5-4820-8ac8-33f5747881bf", false);
		API_DEF_ADD_QUERY_PARAMS(String, "xname", ZH_WORDS_GETTER("sample.field.xname"), "jack", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "personal-management/list-personal-identity", query_list_personal_identity, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		//��������Ȩ���� 
		//API_HANDLER_AUTH_PARAME()
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, list_personal_identityQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerylist_personal_identity(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 ��ʾ��ҳ��ѯ����
	listPageJsonVO::Wrapper execQuerylist_personal_identity(const list_personal_identityQuery::Wrapper& query, const PayloadDTO& payload);
};


#endif // !_LIST_PERSONAL_IDENTITYCONTROLLER_
