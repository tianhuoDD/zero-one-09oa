#pragma once
#ifndef _CALENDARSPACE_DAO_
#define _CALENDARSPACE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/calendar/cal_calendar_spaceDO.h"
#include "../../domain/query/calendar/CalendarSpaceQuery.h"

/**
 * ���ݿ����ʵ�������Ҳ�����
 */
class CalendarSpaceDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count();
	// ��ѯ����
	std::list<cal_calendar_spaceDO> queryAll(const CalendarSpaceQuery::Wrapper& query);
};
#endif // !_CALENDARSPACE_DAO_