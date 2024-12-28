#pragma once

#ifndef _SortByPinYin_Controller_
#define _SortByPinYin_Controller_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/Sort/SortByPinYinQuery.h"
#include "domain/dto/Sort/SortByPinYinDTO.h"
#include "domain/vo/Sort/SortByPinYinVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class SortByPinYinController : public oatpp::web::server::api::ApiController
{
	// 2 ����������������
	API_ACCESS_DECLARE(SortByPinYinController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(querySortByPinYin) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sort.sort_res"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(SortByPinYinPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������

	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/c1-org/querySortByPinYin", querySortByPinYin, QUERIES(QueryParams, Params), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(query, SortByPinYinQuery, Params);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQuerySortByPinYin(query, authObject->getPayload()));
	}


private:
	SortByPinYinPageJsonVO::Wrapper execQuerySortByPinYin(const SortByPinYinQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_