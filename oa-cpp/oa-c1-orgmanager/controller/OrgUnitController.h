#pragma once
#ifndef _ORGUNIT_CONTROLLER_
#define _ORGUNIT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/OrgUnitQuery.h"
#include "domain/dto/OrgUnitDTO.h"
#include "domain/vo/OrgUnitVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class OrgUnitController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(OrgUnitController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryOrgInfo) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("org.unit.query"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(OrgUnitJsonVO);
		// �����ҳ��ѯ��������
		//API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "unit_xname", ZH_WORDS_GETTER("org.unit.unit_name"), "01daxue", false);
		
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c1-org/orgmanagment/queryOrgInfo", queryOrgInfo, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(userQuery, OrgUnitQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySample(userQuery, authObject->getPayload()));
	}

	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("org.unit.update"), modifyOrgInfo, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/c1-org/orgmanagment/modifyOrgInfo", modifyOrgInfo, BODY_DTO(OrgUnitDTO::Wrapper, dto), execModifySample(dto));

	// 3.3 ��ʾ��ҳ��ѯ����
	OrgUnitJsonVO::Wrapper execQuerySample(const OrgUnitQuery::Wrapper& query, const PayloadDTO& payload);
	
	// 3.3 ��ʾ�޸�����
	StringJsonVO::Wrapper execModifySample(const OrgUnitDTO::Wrapper& dto);
};






// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ORGUNIT_CONTROLLER_
