#pragma once
#ifndef _CALENDARFOLLOW_SERVICE_
#define _CALENDARFOLLOW_SERVICE_
#include "domain/dto/calendar/CalendarFollowDTO.h"

/**
 * ��֪����ô�ͳ��ֵķ���ʵ��
 */
class CalendarFollowService
{
public:
	int addFollow(const CalendarFollowDTO::Wrapper& dto);
	int removeFollow(const CalendarFollowDTO::Wrapper& dto);
};

#endif // !_CALENDARSPACE_SERVICE_