#pragma once
#ifndef _CALENDARINFODAO_H_
#define _CALENDARINFODAO_H_

#include "BaseDAO.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendar_viewablegrouplistDO.h"
#include "../../domain/do/calendar/cal_calendar_viewableunitlistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishablegrouplistDO.h"
#include "../../domain/do/calendar/cal_calendar_publishableunitlistDO.h"
#include "../../domain/do/calendar/cal_calendar_manageablepersonlistDO.h"

class CalendarInfoDAO : public BaseDAO {
private:
	//	ͨ������ID��ѯ��Χ��ģ��
	template<class T>
	list<T> execSelect(const string& table, const string& find_name, const string& cal_xid);

public:
	//	ͨ������ID��ѯ����������Ϣ
	list<cal_calendarDO> selectCalendarInfoById(const string& cal_xid);
	//	ͨ������ID��ѯ���������˵ķ�Χ
	list<cal_calendar_manageablepersonlistDO> selectManageablePersonById(const string& cal_xid);
	//	ͨ������ID��ѯ�����ɼ��˵ķ�Χ
	list<cal_calendar_viewablepersonlistDO> selectViewablePersonById(const string& cal_xid);
	//	ͨ������ID��ѯ�����ɼ�Ⱥ��ķ�Χ
	list<cal_calendar_viewablegrouplistDO> selectViewableGroupById(const string& cal_xid);
	//	ͨ������ID��ѯ�����ɼ���֯�ķ�Χ
	list<cal_calendar_viewableunitlistDO> selectViewableUnitById(const string& cal_xid);
	//	ͨ������ID��ѯ�������½��˵ķ�Χ
	list<cal_calendar_publishablepersonlistDO> selectPublishablePersonById(const string& cal_xid);
	//	ͨ������ID��ѯ�������½�Ⱥ��ķ�Χ
	list<cal_calendar_publishablegrouplistDO> selectPublishableGroupById(const string& cal_xid);
	//	ͨ������ID��ѯ�������½���֯�ķ�Χ
	list<cal_calendar_publishableunitlistDO> selectPublishableUnitById(const string& cal_xid);

};

#endif // !_CALENDARINFODAO_H_
