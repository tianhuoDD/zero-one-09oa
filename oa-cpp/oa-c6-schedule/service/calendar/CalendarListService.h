#pragma once
#ifndef _CALENDARLISTSERVICE_H_
#define _CALENDARLISTSERVICE_H_

#include "../../domain/dto/calender/CalenderListDTO.h"
#include "../../domain/vo/calender/CalenderListVO.h"

//	Service�㸺�����ݵ���װ
class CalendarListService {
public:
	oatpp::List<CalenderListDTO::Wrapper> queryCalenderList(const string& xsequence);
};
#endif // !_CALENDARLISTSERVICE_H_
