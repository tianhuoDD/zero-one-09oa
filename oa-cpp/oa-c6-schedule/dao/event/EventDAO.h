#pragma once
#ifndef _EVENT_DAO_
#define _EVNET_DAO_

#include "BaseDAO.h"
#include "../../domain/do/event/cal_eventDO.h"
#include "../../domain/do/event/cal_event_manageablepersonlistDO.h"
#include "../../domain/do/event/cal_event_participantsDO.h"
#include "../../domain/do/event/cal_event_repmDO.h"
#include "../../domain/do/event/cal_event_repm_createdmonthlistDO.h"
#include "../../domain/do/event/cal_event_repm_manageablepersonlistDO.h"
#include "../../domain/do/event/cal_event_repm_participantsDO.h"
#include "../../domain/do/event/cal_event_repm_viewablepersonlistDO.h"
#include "../../domain/do/event/cal_event_viewablepersonlistDO.h"
#include "../../domain/do/calendar/cal_calendarDO.h"
#include "../../domain/do/calendar/cal_calendar_manageablepersonlistDO.h"


class EventDAO : public BaseDAO
{
private:

	//

public:
	//��ѯ������
	list<cal_calendarDO> selectCalenderByXid(const string& xid);
	//��ѯ���������߱�
	list<cal_calendar_manageablepersonlistDO> selectCalenderManeByXid(const string& xid);
	// ��������
	int insertEvent(const cal_eventDO& iObj);
	// ������������
	int insertOtherEvent(const cal_eventDO& iObj, string preson, int orderColum);
	// ����repm��
	int insertRepmevent(const cal_eventDO& iObj);
	// ����repm����������
	int insertOtherRepmEvent(const cal_eventDO& iObj, string preson, int orderColum);
	// ����repm_monthlist��
	int insertRepmMonthlistEvent(const cal_eventDO& iObj, string date, int orderColum);
	//�޸�����
	int updateEvnet(const cal_eventDO& uObj);
	// ͨ��IDɾ��Evnet����
	int deleteEventByXid(string xid);
	// ͨ��Repeat_idɾ������
	int deleteEventByRepmXid(string xid);
	// ͨ��eventId��ѯrepmId��ɾ������
	int deleteEventByFindRepmXid(string xid);
	// ͨ��repmIdɾ��eventId
	int deleteEventByFindXid(string xid);

};


#endif // !_EVENT_DAO_