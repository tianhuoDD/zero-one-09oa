#include "stdafx.h"
#include "EventSelectService.h"
#include "dao/event/EventSelectDAO.h"
#include "domain/do/event/cal_eventDO.h"
#include "domain/do/event/cal_event_repmDO.h"


//ǰ�ú���������ظ��ճ��������
//Ŀ�ģ������������������������ظ��ճ̣����ظ�����������ѯ��ǰ��
//ʵ�ʲ�����1��cal_event_repm��鵽�����������ظ��������ڲ�ѯ���µļ�¼
//          2�����ظ���������һ�������ճ̣����ճ̵�������Ϣ�վɣ�Ψ���ճ̿�ʼʱ��ͽ���ʱ��ı�
//          3�������������ճ̲���cal_event�����
//          4����ʱ���غϷ��ճ̣�����˳�㷵�������ĺϷ��ճ�

//������ظ���������
void EventSelectService::RecurrenceAddByDate(const CalEventsQuery::Wrapper& query)
{
	EventSelectDAO dao;

//ʵ�ʲ�����1��cal_event_repm��鵽�����������ظ��������ڲ�ѯ���µļ�¼
	//cout << "׼�����" << endl;
	list<cal_event_repmDO> repms = dao.selectAllRepm(query);
	//cout << "�鵽����" << endl;
	//cout << repms.size() << endl;
	for (cal_event_repmDO doo : repms) {
		//��cal_event_repm_createdmonthlist������ظ��ճ̵��������Ƿ��Ѿ�����

		/*cout << "-------------------------" << endl;
		cout << doo.getxId() << endl;
		cout << doo.getxAlarm() << endl;
		cout << doo.getxCreateTime() << endl;
		cout << doo.getxSequence() << endl;
		cout << doo.getxUpdateTime() << endl;
		cout << doo.getxDistributeFactor() << endl;
		cout << doo.getxAlarm() << endl;
		cout << doo.getxAlarmTime() << endl;
		cout << doo.getxCalendarId() << endl;
		cout << doo.getxColor() << endl;
		cout << doo.getxComment() << endl;
		cout << doo.getxCommentId() << endl;
		cout << doo.getxCreatePerson() << endl;
		cout << doo.getxDaysOfDuration() << endl;
		cout << doo.getxEndTime() << endl;
		cout << doo.getxEventType() << endl;
		cout << doo.getxIsAllDayEvent() << endl;
		cout << doo.getxIsPublic() << endl;
		cout << doo.getxLocationName() << endl;
		cout << doo.getxLongitude() << endl;
		cout << doo.getxRecurrenceStartTime() << endl;
		cout << doo.getxRecurrenceRule() << endl;
		cout << doo.getxSource() << endl;
		cout << doo.getxStartTime() << endl;
		cout << doo.getxTitle() << endl;
		cout << doo.getxUpdatePerson() << endl;
		cout << doo.getxValarmTime_config() << endl;
		cout << doo.getxValarm_Summary() << endl;
		cout << doo.getxValarm_description() << endl;
		cout << doo.getxValarm_mailto() << endl;
		cout << "׼������" << endl;
		while (1);
		*/
		
		if (dao.TheIdIsCreated(doo, query->queryDate.getValue("")))
		{
			//cout << "���ڲ���" << endl;
			dao.AddRepeatEventIntoTable(doo,query->queryDate.getValue("")+"-01 00:00:00");
			//������ɺ���cal_event_repm_createdmonthlist��������Ӧ�µ����ݣ������ظ�����
			dao.AddRepmCreatedMonthlist(doo.getxId(), query->queryDate.getValue(""));
		}
	}
}


//��ѯ�ճ��б�
CalAllEventsVO::Wrapper EventSelectService::getListEventRows(const CalEventsQuery::Wrapper& query)
{
	auto event_rows = CalAllEventsVO::createShared();
	EventSelectDAO dao;
	//cout << "׼������" << endl;
	RecurrenceAddByDate(query);
	//cout << "�˳���������" << endl;
	//ͳ����־����
	uint64_t count = dao.countEvent(query);
	if (count <= 0) return event_rows;
	//��ȡdo
	std::list<cal_eventDO> rows = dao.selectAllEvent(query);
	//��doתΪ��Ҫ��eventsvo
	for (cal_eventDO temp: rows) {
		auto vo = CalEventsVO::createShared();
		//ת��doΪvo
		ZO_STAR_DOMAIN_DO_TO_DTO(vo, temp, calEventId, xId, calEventTitle, xTitle, calStartTime, xStartTime, calEndTime, xEndTime, color, xColor, location, xLocationName, isAllDayEvent, xIsAllDayEvent);
		
		event_rows->addData(vo);
	}
	event_rows->total = count;
	return event_rows;
}

CalEventVO::Wrapper EventSelectService::getDetaileEvent(const CalEventQuery::Wrapper& query)
{
	auto one_event = CalEventVO::createShared();
	EventSelectDAO dao;
	auto result = dao.selectOneEvent(query);
	for (cal_eventDO temp : result) {

		ZO_STAR_DOMAIN_DO_TO_DTO(one_event, temp, calendarId, xCalendarId, calEventTitle, xTitle, calStartTime, xStartTime, calEndTime, xEndTime, color, xColor, comment, xComment, location, xLocationName, recurrenceRule, xRecurrenceRule, isAllDayEvent, xIsAllDayEvent);

	}
	return one_event;
}


//��ѯ�ճ��б�
/*
list<CalEventsVO::Wrapper> EventService::getListEventRows(const CalEventsQuery::Wrapper& query)
{
	list<CalEventsVO::Wrapper> event_rows;
	EventSelectDAO dao;
	//��ȡdo
	std::list<cal_eventDO> rows = dao.selectAllEvent(query);
	//��doתΪ��Ҫ��eventsvo
	for (cal_eventDO temp : rows) {
		auto vo = CalEventsVO::createShared();
		//ת��doΪvo
		ZO_STAR_DOMAIN_DO_TO_DTO(vo, temp, calEventId, xId, calEventTitle, xTitle, calStartTime, xStartTime, calEndTime, xEndTime, color, xColor, location, xLocationName, isAllDayEvent, xIsAllDayEvent);

		event_rows.push_back(vo);
	}
	return event_rows;
}
*/
//��ѯ�ճ�����
//CalEventVO::Wrapper getDetaileEvent(const CalEventQuery::Wrapper& query)
//{
	//auto one_event = CalEventVO::createShared();

//}
