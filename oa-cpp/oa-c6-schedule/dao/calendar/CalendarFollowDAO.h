#pragma once
#ifndef _CALENDARFOLLOW_DAO_
#define _CALENDARFOLLOW_DAO_
#include "BaseDAO.h"
#include "../../domain/do/calendar/cal_calendar_followersDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class CalendarFollowDAO : public BaseDAO
{
public:
	// ��������
	int insert(const cal_calendar_followersDO& iObj);
	// ͨ��IDɾ������
	int deleteByIdAndName(const cal_calendar_followersDO& iObj);
};
#endif // !_CALENDARFOLLOW_DAO_