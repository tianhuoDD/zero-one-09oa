#pragma once

#ifndef _APPNDICT_CONTROLLER_
#define _APPNDICT_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/appndict/AppndictQuery.h"
#include "domain/dto/appndict/AppndictDTO.h"
#include "domain/vo/appndict/AppndictVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����������
 */
class AppndictController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AppndictController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAppndict) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("appndict.query.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AppndictJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/appndict", queryAppndict, QUERIES(QueryParams, queryParams)) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(appndictQuery, AppndictQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryOne(appndictQuery));
	}
private:
	AppndictJsonVO::Wrapper execQueryOne(const AppndictQuery::Wrapper& query);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _APPNDICT_CONTROLLER_