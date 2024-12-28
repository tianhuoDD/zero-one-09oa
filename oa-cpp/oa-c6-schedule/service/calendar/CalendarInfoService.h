#pragma once
#ifndef _CALENDARINFOSERVICE_H_
#define _CALENDARINFOSERVICE_H_

#include "../../domain/dto/calender/CalenderInfoDTO.h"
#include "../../domain/vo/calender/CalenderInfoVO.h"


class CalendarInfoService {
private:

	//	�Ӹ����û����к�����ȡ���û�����
	string getName(const string& xdistinguishedname);
	//	��װ�ɼ���Χ�Ϳ��½���Χ����
	uint64_t packaging();


public:
	CalenderInfoDTO::Wrapper queryCalendarInfo(const string& cal_xid);
};


#endif // !_CALENDARINFOSERVICE_H_
