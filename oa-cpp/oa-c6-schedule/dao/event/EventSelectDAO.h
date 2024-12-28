#pragma once
#ifndef _EVENTSELECTDAO_H_
#define _EVENTSELECTDAO_H_

#include<list>
#include "BaseDAO.h"
#include "domain/query/cal/CalEventsQuery.h"
#include "domain/query/cal/CalEventQuery.h"
#include "domain/do/event/cal_eventDO.h"
#include "domain/do/event/cal_event_repmDO.h"
#include "../lib-common/include/SnowFlake.h"
#include "domain/do/event/cal_event_repm_createdmonthlistDO.h"
#include <iomanip>
#include <chrono>
#include <sstream>

class EventSelectDAO:public BaseDAO {
public:
	//����жϴ��·��Ƿ�����
	bool TheIdIsCreated(const cal_event_repmDO& doo, string querydate);

	//����������ɵ��·�����
	int AddRepmCreatedMonthlist(const string& repeatId, const string& monthdate);

	list<cal_event_repmDO> selectAllRepm(const CalEventsQuery::Wrapper& query);

	int AddRepeatEventIntoTable(const cal_event_repmDO &doo,string month_start);

	uint64_t countEvent(const CalEventsQuery::Wrapper& query);
	std::list<cal_eventDO> selectAllEvent(const CalEventsQuery::Wrapper& query);
	list<cal_eventDO> selectOneEvent(const CalEventQuery::Wrapper& query);

	int insertToCal_event(const cal_eventDO& cedo);
};

#endif // !_EVENTSELECTDAO_H_
