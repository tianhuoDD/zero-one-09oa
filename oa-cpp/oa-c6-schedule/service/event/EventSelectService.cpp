#include "stdafx.h"
#include "EventSelectService.h"
#include "dao/event/EventSelectDAO.h"
#include "domain/do/event/cal_eventDO.h"
#include "domain/do/event/cal_event_repmDO.h"


//前置函数，完成重复日程新增检查
//目的：将传来的所属日历的所有重复日程，按重复规则新增查询当前月
//实际操作：1、cal_event_repm表查到所属日历，重复日期早于查询年月的记录
//          2、按重复规则，生成一条条新日程，新日程的所有信息照旧，唯独日程开始时间和结束时间改变
//          3、将所有新增日程插入cal_event表，完成
//          4、此时返回合法日程，将会顺便返回新增的合法日程

//仅完成重复新增功能
void EventSelectService::RecurrenceAddByDate(const CalEventsQuery::Wrapper& query)
{
	EventSelectDAO dao;

//实际操作：1、cal_event_repm表查到所属日历，重复日期早于查询年月的记录
	//cout << "准备查表" << endl;
	list<cal_event_repmDO> repms = dao.selectAllRepm(query);
	//cout << "查到表了" << endl;
	//cout << repms.size() << endl;
	for (cal_event_repmDO doo : repms) {
		//查cal_event_repm_createdmonthlist表检测此重复日程的月数据是否已经生成

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
		cout << "准备插入" << endl;
		while (1);
		*/
		
		if (dao.TheIdIsCreated(doo, query->queryDate.getValue("")))
		{
			//cout << "正在插入" << endl;
			dao.AddRepeatEventIntoTable(doo,query->queryDate.getValue("")+"-01 00:00:00");
			//插入完成后，往cal_event_repm_createdmonthlist表里插入对应月的数据，避免重复插入
			dao.AddRepmCreatedMonthlist(doo.getxId(), query->queryDate.getValue(""));
		}
	}
}


//查询日程列表
CalAllEventsVO::Wrapper EventSelectService::getListEventRows(const CalEventsQuery::Wrapper& query)
{
	auto event_rows = CalAllEventsVO::createShared();
	EventSelectDAO dao;
	//cout << "准备新增" << endl;
	RecurrenceAddByDate(query);
	//cout << "退出新增函数" << endl;
	//统计日志条数
	uint64_t count = dao.countEvent(query);
	if (count <= 0) return event_rows;
	//获取do
	std::list<cal_eventDO> rows = dao.selectAllEvent(query);
	//将do转为需要的eventsvo
	for (cal_eventDO temp: rows) {
		auto vo = CalEventsVO::createShared();
		//转换do为vo
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


//查询日程列表
/*
list<CalEventsVO::Wrapper> EventService::getListEventRows(const CalEventsQuery::Wrapper& query)
{
	list<CalEventsVO::Wrapper> event_rows;
	EventSelectDAO dao;
	//获取do
	std::list<cal_eventDO> rows = dao.selectAllEvent(query);
	//将do转为需要的eventsvo
	for (cal_eventDO temp : rows) {
		auto vo = CalEventsVO::createShared();
		//转换do为vo
		ZO_STAR_DOMAIN_DO_TO_DTO(vo, temp, calEventId, xId, calEventTitle, xTitle, calStartTime, xStartTime, calEndTime, xEndTime, color, xColor, location, xLocationName, isAllDayEvent, xIsAllDayEvent);

		event_rows.push_back(vo);
	}
	return event_rows;
}
*/
//查询日程详情
//CalEventVO::Wrapper getDetaileEvent(const CalEventQuery::Wrapper& query)
//{
	//auto one_event = CalEventVO::createShared();

//}
