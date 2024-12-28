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
	//每日重复插入
	vector<std::string> generateDailySchedule(const string& startDate, const string& endDate);
	//每周重复插入
	vector<std::string> generateWeeklySchedule(const string& startDate, const string& endDate, const string& rule);
	//每月重复插入
	vector<std::string> generateMonthlySchedule(const string& startDate, const string& endDate);
	//每年从重复插入
	vector<std::string> generateYearlySchedule(const string& startDateStr, const string& endDateStr);
	//计算日期
	string adjustDateTime(const std::string& dateStr, const std::string& offsetStr);
	
	//list<std::string>  
	// 插入其他数据
	bool saveOtherEventData(const ScheduleInfoDTO::Wrapper& dto, cal_eventDO& data, EventDAO& dao);
	// 插入其他数据repm
	bool saveOtherRepmEventData(const ScheduleInfoDTO::Wrapper& dto, cal_eventDO& data, EventDAO& dao);

public:
	
	// 插入event数据(初次调用)
	bool saveEventData(const ScheduleInfoDTO::Wrapper& dto, const string& username);
	// 插入Eevnt数据(查询调用)
	bool saveEventData(cal_event_repmDO data, const string& startDate, const string& endDate, const string& repeatRule);

	// 修改数据
	bool updateEventData(const ScheduleInfoDTO::Wrapper& dto, const string& username);

	// 删除event表数据
	bool removeEventData(const ScheduleDelDTO::Wrapper& dto);
	


};

#endif // !_EVENT_SERVICE_

