#pragma once
#ifndef _CALENDARSPACE_CONTROLLER_
#define _CALENDARSPACE_CONTROLLER_

#include "domain/vo/calendar/CalendarSpaceVO.h"
#include "domain/query/calendar/CalendarSpaceQuery.h"
#include "domain/dto/calendar/CalendarSpaceDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class CalendarSpaceController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(CalendarSpaceController);
	// 3 ����ӿ�
public:
	// 3.1 �����ѯ�ӿ�����
	ENDPOINT_INFO(queryCalendarSpace) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.get.space"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CalendarSpacePageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
	}

	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/scehdule/calendar-space-query", queryCalendarSpace, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
			API_HANDLER_QUERY_PARAM(query, CalendarSpaceQuery, queryParams);
			API_HANDLER_RESP_VO(execQueryCalendarSpace(query, authObject->getPayload()));
	}
private:
	// 3.3 ��ѯ�����㳡�Ĺ�������
	CalendarSpacePageJsonVO::Wrapper execQueryCalendarSpace(const CalendarSpaceQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _CALENDARSPACE_CONTROLLER_