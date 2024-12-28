#pragma once

#ifndef _EVENT_SERVICE_
#define _EVENT_SERVICE_
#include "../../dao/event/EventDAO.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/schedule/ScheduleInfoVO.h"
#include "domain/dto/schedule/ScheduleInfoDTO.h"


class EventService
{
private:

	void assembleDoData(cal_eventDO& data, const ScheduleInfoDTO::Wrapper& dto);
	//ÿ���ظ�����
	vector<std::string> generateDailySchedule(const string& startDate, const string& endDate);
	//ÿ���ظ�����
	vector<std::string> generateWeeklySchedule(const string& startDate, const string& endDate, const string& rule);
	//ÿ���ظ�����
	vector<std::string> generateMonthlySchedule(const string& startDate, const string& endDate);
	//ÿ����ظ�����
	vector<std::string> generateYearlySchedule(const string& startDateStr, const string& endDateStr);
	//��������
	string adjustDateTime(const std::string& dateStr, const std::string& offsetStr);
	
	//list<std::string>  
	// ������������
	bool saveOtherEventData(const ScheduleInfoDTO::Wrapper& dto, cal_eventDO& data, EventDAO& dao);
	// ������������repm
	bool saveOtherRepmEventData(const ScheduleInfoDTO::Wrapper& dto, cal_eventDO& data, EventDAO& dao);

public:
	
	// ����event����(���ε���)
	bool saveEventData(const ScheduleInfoDTO::Wrapper& dto, const string& username);
	// ����Eevnt����(��ѯ����)
	bool saveEventData(cal_event_repmDO data, const string& startDate, const string& endDate, const string& repeatRule);

	// �޸�����
	bool updateEventData(const ScheduleInfoDTO::Wrapper& dto, const string& username);

	// ɾ��event������
	bool removeEventData(const ScheduleDelDTO::Wrapper& dto);
	


};

#endif // !_EVENT_SERVICE_

