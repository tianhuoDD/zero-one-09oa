#pragma once
#ifndef _EVENT_SELECT_SERVICE_H_
#define _EVENT_SELECT_SERVICE_H_

#include <list>
#include "domain/vo/cal/CalEventsVO.h"
#include "domain/vo/cal/CalEventVO.h"
#include "domain/query/cal/CalEventQuery.h"
#include "domain/query/cal/CalEventsQuery.h"

class EventSelectService {
public:
	//�����Ϸ��ظ��ճ�
	void RecurrenceAddByDate(const CalEventsQuery::Wrapper& query);
	//��ѯ�ճ��б�
	CalAllEventsVO::Wrapper getListEventRows(const CalEventsQuery::Wrapper& query);
	//list<CalEventsVO::Wrapper> getListEventRows(const CalEventsQuery::Wrapper& query);
	//��ѯ�ճ�����
	CalEventVO::Wrapper getDetaileEvent(const CalEventQuery::Wrapper& query);
};
#endif // !_EVENTSERVICE_H_
