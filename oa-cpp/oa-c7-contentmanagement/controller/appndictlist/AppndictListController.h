#pragma once

#ifndef _APPNDICTLIST_CONTROLLER_
#define _APPNDICTLIST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/appndictlist/AppndictListQuery.h"
#include "domain/dto/appndictlist/AppndictListDTO.h"
#include "domain/vo/appndictlist/AppndictListVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * �����б������
 */
class AppndictListController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AppndictListController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryAppndictList) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("appndict.query-all.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		//API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AppndictListPageJsonVO);//////
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		//API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sample.field.name"), "li ming", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sex", ZH_WORDS_GETTER("sample.field.sex"), "N", false);
	}
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/appndictlist", queryAppndictList, QUERIES(QueryParams, queryParams)) {////???
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(appndictListQuery, AppndictListQuery, queryParams);/////????
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryAll(appndictListQuery));
	}
private:
	AppndictListPageJsonVO::Wrapper execQueryAll(const AppndictListQuery::Wrapper& query);/////
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _APPNDICTLIST_CONTROLLER_