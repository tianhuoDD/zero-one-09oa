#pragma once
#ifndef _CALEVENTCONTROLLER_H_
#define _CALEVENTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "oatpp-swagger/Types.hpp"
#include "domain/GlobalInclude.h"
#include "domain/query/cal/CalEventQuery.h"
#include "domain/query/cal/CalEventsQuery.h"
#include "domain/vo/cal/CalEventVO.h"
#include "domain/vo/cal/CalEventsVO.h"
#include "domain/vo/cal/CalEventJsonVO.h"
using namespace oatpp;
// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)

//��־����������ʾ��־�����ӿڵ�ʹ��
class CalEventController :public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(CalEventController);

public:
	//�����ѯ�ճ��б�����
	ENDPOINT_INFO(queryCalEvents) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.event.xqueryEvents"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		//�����������������ճ�
		API_DEF_ADD_RSP_JSON_WRAPPER(CalAllEventsJsonVO);

		//����������ѯ��������
		//��������
		API_DEF_ADD_QUERY_PARAMS(String, "calendarId", ZH_WORDS_GETTER("calender.event.xcalendarId"), "66666666666",true);
		//����
		API_DEF_ADD_QUERY_PARAMS(String, "queryDate", ZH_WORDS_GETTER("calender.event.xqueryDate"), "2024-10", true);
	}
	//�����ѯ�ճ��б�ӿ�
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/schedule/query-eventlist-by-dateAndCalendar", queryCalEvents, CalEventsQuery, execQueryCalEventsByCalendar(query));

	/*
	// 3.2 �����ѯ�ӿڴ���
	ENDPOINT(API_M_GET, "/schedule-event/query-by-dateAndCalendar", queryCalEvents, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(queryCalEvents, CalEventsQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryCalEventsByCalendar(queryCalEvents, authObject->getPayload()));
	}
	*/

	//�����ѯ��־��������
	ENDPOINT_INFO(queryCalEvent) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("calender.event.xqueryEvent"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CalEventJsonVO);
		//����������ѯ��������
		//��ѯ��־id
		API_DEF_ADD_QUERY_PARAMS(String, "calEventId", ZH_WORDS_GETTER("calender.event.xid"), "88888888888",true);
	}
	//�����ѯ��־����ӿ�
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/schedule/query-eventinfo-by-eventId", queryCalEvent, CalEventQuery, execQueryCalEventByCalEventId(query));
private:
	//
	CalAllEventsJsonVO::Wrapper execQueryCalEventsByCalendar(const CalEventsQuery::Wrapper& calEventsQuery);

	//CalEventsPageJsonVO::Wrapper executeQueryCalEvents(const CalEventsQuery::Wrapper& calEventsQuery);


	CalEventJsonVO::Wrapper execQueryCalEventByCalEventId(const CalEventQuery::Wrapper& calEventQuery);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_CALEVENTCONTROLLER_H_
