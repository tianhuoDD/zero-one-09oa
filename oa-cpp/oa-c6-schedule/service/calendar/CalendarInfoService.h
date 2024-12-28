#pragma once
#ifndef _CALENDARINFOSERVICE_H_
#define _CALENDARINFOSERVICE_H_

#include "../../domain/dto/calender/CalenderInfoDTO.h"
#include "../../domain/vo/calender/CalenderInfoVO.h"


class CalendarInfoService {
private:

	//	从给定用户序列号中提取出用户名称
	string getName(const string& xdistinguishedname);
	//	组装可见范围和可新建范围数据
	uint64_t packaging();


public:
	CalenderInfoDTO::Wrapper queryCalendarInfo(const string& cal_xid);
};


#endif // !_CALENDARINFOSERVICE_H_
