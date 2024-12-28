#include "stdafx.h"
#include "EventService.h"
#include "../../dao/event/EventDAO.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include "../../../lib-common/include/SnowFlake.h"
#include <list>

static bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int daysInMonth(int year, int month) {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 4: case 6: case 9: case 11: return 30;
	case 2: return isLeapYear(year) ? 29 : 28;
	default: return 0; // ������·�
	}
}
//����repm_monthlist��ʼ�Ĳ���
static int getPreviousAndNextMonth(const string& currentMonthStr, cal_eventDO& data, EventDAO& dao) {

	istringstream ss(currentMonthStr);
	int year, month;
	char delimiter;
	ss >> year >> delimiter >> month;

	// ������һ����
	int prevYear = year;
	int prevMonth = month - 1;
	if (prevMonth < 1) {
		prevMonth = 12;
		prevYear--;
	}

	// ������һ����
	int nextYear = year;
	int nextMonth = month + 1;
	if (nextMonth > 12) {
		nextMonth = 1;
		nextYear++;
	}

	int flag = 1;
	std::ostringstream oss;
	// ������һ����
	oss << std::setw(4) << std::setfill('0') << prevYear << "-"
		<< std::setw(2) << std::setfill('0') << prevMonth;
	flag &= dao.insertRepmMonthlistEvent(data, oss.str(), 0);

	oss.str("");
	// ���������
	oss << std::setw(4) << std::setfill('0') << year << "-"
		<< std::setw(2) << std::setfill('0') << month;
	flag &= dao.insertRepmMonthlistEvent(data, oss.str(), 2);
	
	oss.str("");
	// ������һ����
	oss << std::setw(4) << std::setfill('0') << nextYear << "-"
		<< std::setw(2) << std::setfill('0') << nextMonth;
	flag &= dao.insertRepmMonthlistEvent(data, oss.str(), 1);

	return flag;

}

static string checkEndOfMonth(const string& start, const string& end) {
	istringstream startStream(start);
	istringstream endStream(end);

	std::tm startTm = {}, endTm = {};
	startStream >> std::get_time(&startTm, "%Y-%m-%d");
	endStream >> std::get_time(&endTm, "%Y-%m-%d");

	// ��ȡ�������ڵ��·ݺ����
	int endYear = endTm.tm_year + 1900;
	int endMonth = endTm.tm_mon + 1;

	// ��ȡ��ĩ����

	istringstream ss(start);
	std::tm tm = {};
	ss >> std::get_time(&tm, "%Y-%m-%d");

	// ��ȡ�¸��µĵ�һ��
	tm.tm_mon += 1;
	tm.tm_mday = 1;
	std::mktime(&tm);

	// ����Ϊ�ϸ������һ��
	tm.tm_mday = 0;
	std::mktime(&tm);

	ostringstream result;
	result << std::put_time(&tm, "%Y-%m-%d");

	string endOfMonth = result.str();

	// �ж��Ƿ��ڿ�ʼ�ͽ���֮��
	if ((startTm.tm_year < endTm.tm_year) ||
		(startTm.tm_year == endTm.tm_year && startTm.tm_mon < endTm.tm_mon) ||
		(startTm.tm_year == endTm.tm_year && startTm.tm_mon == endTm.tm_mon && startTm.tm_mday <= endTm.tm_mday)) {

		if (endOfMonth >= start && endOfMonth <= end) {
			return endOfMonth;
		}
	}

	return end;
}

vector<std::string> EventService::generateDailySchedule(const string& startDate, const string& endDate) {
	vector<string> schedule;

	// ������ʼ����
	tm start_tm = {};
	istringstream ss_start(startDate);
	ss_start >> get_time(&start_tm, "%Y-%m-%d");
	// ������������
	tm end_tm = {};
	istringstream ss_end(endDate);
	ss_end >> get_time(&end_tm, "%Y-%m-%d");


	auto start = chrono::system_clock::from_time_t(mktime(&start_tm));
	auto end = chrono::system_clock::from_time_t(mktime(&end_tm));

	for (auto day = start ; day <= end; day += chrono::hours(24)) {
		time_t day_time_t = chrono::system_clock::to_time_t(day);
		tm* day_tm = std::localtime(&day_time_t);
		char buffer[11];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d", day_tm);
		schedule.push_back(buffer);
	}

	return schedule;
}

vector<std::string> EventService::generateWeeklySchedule(const string& startDate, const string& endDate,const string& rule) {
	std::vector<std::string> dates;

	// ��������
	std::string daysPart = rule.substr(rule.find("BYDAY=") + 6);
	daysPart = daysPart.substr(0, daysPart.find(';'));

	// ����ʼ���ڽ���Ϊstd::tm
	std::tm start_tm = {};
	std::istringstream ss(startDate);
	ss >> std::get_time(&start_tm, "%Y-%m-%d");
	std::tm end_tm = {};
	ss.clear();
	ss.str(endDate);
	ss >> std::get_time(&end_tm, "%Y-%m-%d");

	// ��ȡ���ڼ�
	std::vector<int> daysOfWeek;
	std::istringstream daysStream(daysPart);
	std::string day;
	while (std::getline(daysStream, day, ',')) {
		if (day == "MO") daysOfWeek.push_back(1);
		else if (day == "TU") daysOfWeek.push_back(2);
		else if (day == "WE") daysOfWeek.push_back(3);
		else if (day == "TH") daysOfWeek.push_back(4);
		else if (day == "FR") daysOfWeek.push_back(5);
		else if (day == "SA") daysOfWeek.push_back(6);
		else if (day == "SU") daysOfWeek.push_back(0);
	}

	// ת����ʼ����Ϊʱ���
	std::time_t start_time = std::mktime(&start_tm);
	std::time_t end_time = std::mktime(&end_tm);


	for (int dayOfWeek : daysOfWeek) {
		std::tm tmp_tm = start_tm;
		// �ҵ���ʼ����֮��ĵ�һ�����ϵ����ڼ�
		while (tmp_tm.tm_wday != dayOfWeek) {
			tmp_tm.tm_mday++;
			std::mktime(&tmp_tm);
		}

		// ���ҵ������ڿ�ʼ����ճ�
		while (std::mktime(&tmp_tm) <= end_time) {
			std::ostringstream dateStream;
			dateStream << std::put_time(&tmp_tm, "%Y-%m-%d");
			dates.push_back(dateStream.str());
			tmp_tm.tm_mday += 7;
			std::mktime(&tmp_tm);
		}
	}

	return dates;
}

vector<std::string> EventService::generateMonthlySchedule(const string& startDate, const string& endDate) {

	vector<std::string> schedule;

	// ������ʼ����
	tm tm = {};
	istringstream ss(startDate);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	auto start = chrono::system_clock::from_time_t(std::mktime(&tm));

	// ������������
	ss.clear();
	tm = {};
	ss.str(endDate);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	auto end = chrono::system_clock::from_time_t(std::mktime(&tm));

	// �����ճ̣����ǵ�ÿ���µ�����
	auto current = start;

	while (current <= end) {
		time_t day_time_t = chrono::system_clock::to_time_t(current);
		std::tm* day_tm = std::localtime(&day_time_t);
		char buffer[11];
		std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", day_tm);
		schedule.push_back(buffer);

		// ����һ����
		int year = day_tm->tm_year + 1900;
		int month = day_tm->tm_mon + 1; // ��ǰ�·ݣ�1-12��

		// ������һ���·�
		month += 1;
		if (month > 12) {
			month = 1; // �������12�£����1
			year += 1;
		}

		// ������һ���·ݵ�����
		int daysInNextMonth;
		daysInNextMonth = daysInMonth(year, month);

		// ������һ������
		tm.tm_year = year - 1900; // �趨���
		tm.tm_mon = month - 1; // �趨�·ݣ�0-11��
		tm.tm_mday = std::min(day_tm->tm_mday, daysInNextMonth); // �������ڣ�ȷ����������һ���µ��������

		current = std::chrono::system_clock::from_time_t(std::mktime(&tm));
	}

	return schedule;
}

vector<std::string> EventService::generateYearlySchedule(const string& startDateStr, const string& endDateStr) {

	tm startDate = {};
	istringstream ss(startDateStr);
	ss >> std::get_time(&startDate, "%Y-%m-%d");

	tm endDate = {};
	istringstream ssEnd(endDateStr);
	ssEnd >> std::get_time(&endDate, "%Y-%m-%d");

	std::vector<std::string> schedule;
	while (true) {

		ostringstream oss;
		oss << std::put_time(&startDate, "%Y-%m-%d");
		schedule.push_back(oss.str());

		startDate.tm_year += 1;

		if (std::mktime(&startDate) > std::mktime(&endDate)) {
			break;
		}
	}

	return schedule;
}

string EventService::adjustDateTime(const std::string& dateStr, const std::string& offsetStr) {
	// �ָ����ں�ʱ��
	std::string datePart = dateStr.substr(0, 10); // "2024-10-27"
	std::string timeStr = dateStr.substr(11, 8); // "04:00:00"

	// ��������
	int year, month, day;
	std::sscanf(datePart.c_str(), "%d-%d-%d", &year, &month, &day);

	// ��ʱ��ֽ�ΪСʱ�����ӡ���
	int hours, minutes, seconds;
	char colon;
	std::istringstream timeStream(timeStr);
	timeStream >> hours >> colon >> minutes >> colon >> seconds;

	// ����ƫ����
	int offsetHours, offsetMinutes, offsetSeconds, placeholding;
	std::istringstream offsetStream(offsetStr);
	offsetStream >> placeholding >> colon >> offsetHours >> colon >> offsetMinutes >> colon >> offsetSeconds;

	// �����µ�ʱ��
	minutes += offsetMinutes;
	hours += offsetHours;

	// ������Ӻ�Сʱ�����
	if (minutes < 0) {
		minutes += 60;
		hours--;
	}
	if (hours < 0) {
		hours += 24;
		day--; // ��Ҫ��������
	}

	// �������ڵ����
	while (day <= 0) {
		month--;
		if (month <= 0) {
			month = 12;
			year--;
		}
		day += daysInMonth(year, month);
	}

	while (day > daysInMonth(year, month)) {
		day -= daysInMonth(year, month);
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}

	// ��ʽ���µ����ں�ʱ��
	std::ostringstream newDateStream;
	newDateStream << std::setw(4) << std::setfill('0') << year << "-"
		<< std::setw(2) << std::setfill('0') << month << "-"
		<< std::setw(2) << std::setfill('0') << day << " "
		<< std::setw(2) << std::setfill('0') << hours << ":"
		<< std::setw(2) << std::setfill('0') << minutes << ":"
		<< std::setw(2) << std::setfill('0') << seconds;

	return newDateStream.str();
}

void EventService::assembleDoData(cal_eventDO& data, const ScheduleInfoDTO::Wrapper& dto)
{

	//data.setxDistributeFactor(NULL);
	
	//data.setxEventType("CAL_EVENT");
	//data.setxIsPublic(0); //XXX:Ĭ��
	//data.setxLatitude(nullptr);
	//data.setxLongitude(nullptr);
	//data.setxRecurrenceExc(nullptr);

	//data.setxUpdatePerson("xadmin"); 
	//data.setxCreatePerson("xadmin");
	//data.setxSource("PERSONAL");
	//setxTargetType("PERSON");
	EventDAO otherTableData;   //����������������

	list<cal_calendarDO> tag = otherTableData.selectCalenderByXid(data.getxCalendarId());
	auto it = tag.begin();
	cout << "... during assemble" << " ..." << endl;
	data.setxSource(it->getxSource());
	cout << data.getxSource() << " ";
	data.setxTargetType(it->getxTarget());
	cout << data.getxTargetType() << " ";
	data.setxIsPublic(it->getxIsPublic());
	cout << data.getxIsPublic() << endl;

	/*list<cal_calendar_manageablepersonlistDO> manager = otherTableData.selectCalenderManeByXid(data.getxCalendarId());
	auto it2 = manager.begin();
	data.setxCreatePerson(it2->getFiled());*/
	cout << data.getxCreatePerson();

	data.setxUpdatePerson(data.getxCreatePerson());

	string result = data.getxCreateTime() + data.getxId();
	// �Ƴ�����ʱ���е��ַ�
	result.erase(16, 1); 
	result.erase(13, 1); 
	result.erase(10, 1); 
	result.erase(7, 1); 
	result.erase(4, 1); 

	cout << result << endl;


	data.setxSequence(result);

	data.setxUpdateTime(SimpleDateTimeFormat::format());
	//data.setxDistributeFactor(NULL);
	//data.setxAlarm(0);
	// TODO:����ʱ���
	string time = adjustDateTime(data.getxStartTime(), data.getxValarmTime_config());
	data.setxAlarmTime(time);

	data.setxDaysOfDuration(0);
	if (data.getxIsAllDayEvent() == 1) {
		string newDateStr = data.getxStartTime().substr(0, 11) + "23:59:59";
		data.setxEndTime(newDateStr); 
	}

	data.setxRepeatMasterId("");

}
/*
void EventService::assembleDoOtherData(cal_eventDO data, const ScheduleInfoDTO::Wrapper& dto)
{
	EventDAO dao;
	string tmp;
	//TODO:ͨ������id��ȡ������
	tmp = dao.otherOption(data, "xcreatePerson");
	data.setxCreatePerson(tmp);
	//TODO:ͨ������id��ȡ��Ϣ
	tmp = dao.otherOption(data, "xsource");
	data.setxSource(tmp);
	//TODO:ͨ������id��ȡ��Ϣ
	tmp = dao.otherOption(data, "xTargetType");
	data.setxTargetType(tmp);
}
*/

bool EventService::saveOtherEventData(const ScheduleInfoDTO::Wrapper& dto, cal_eventDO& data, EventDAO& dao)
{
	int flag = 1;
	int orderColum = dto->manegerList->size() - 1;
	cout << "... during saveOthereventData ..." << endl;
	cout << dto->manegerList->size() <<  " " << orderColum << endl;
	for (const auto& name : *dto->manegerList) {

		cout << (string)name << endl;
		flag &= dao.insertOtherEvent(data, name, orderColum--);
	}
	return flag;
}

bool EventService::saveOtherRepmEventData(const ScheduleInfoDTO::Wrapper& dto, cal_eventDO& data, EventDAO& dao)
{
	int flag = 1;
	int orderColum = dto->manegerList->size() - 1;
	cout << "... during saveOther-Remp-EventData ..." << endl;
	cout << dto->manegerList->size() << " " << orderColum << endl;

	flag &= dao.insertRepmevent(data); //�����ظ��ճ�

	flag &= getPreviousAndNextMonth(data.getxStartTime(), data, dao);//����monthlist��

	for (const auto& name : *dto->manegerList) {

		cout << (string)name << endl;
		flag &= dao.insertOtherRepmEvent(data, name, orderColum--);
	}
	return flag;
}

// ��������
bool EventService::saveEventData(const ScheduleInfoDTO::Wrapper& dto, const string& username)
{
	// ��װDO����
	cal_eventDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, xId, xid, xCalendarId, xcalendarId, xTitle, xtitle, xStartTime, xstartTime, xEndTime, xendTime,
		xLocationName, xlocationName, xIsAllDayEvent, xisAllDayEvent, xAlarm, xalarm, xValarmTime_config, xvalarmTime_config,
		xRepeat, xrepeat, xRecurrenceRule, xrecurrenceRule, xRepeatUnitDate, xrepeatUnitDate, xColor, xcolor, xComment, xcomment)

		cout << "... alarm: " << data.getxAlarm() << " ..." << endl;

	//��װ��������
	data.setxCreateTime(SimpleDateTimeFormat::format());
	cout << "... before assemble : " << username << " ..." << endl;
	data.setxCreatePerson(username);
	assembleDoData(data, dto);
	SnowFlake sf(0, 0);
	data.setxId(to_string(sf.nextId()));

	// ִ���������
	EventDAO dao;

	
	int flag = 1;
	if (data.getxRepeat() == "NO") { // ���ظ�
	
		flag = dao.insertEvent(data);  //�����ճ�
		flag &= saveOtherEventData(dto, data, dao);
	}
	else if (data.getxRepeat() == "1") { //ÿ���ظ�

		SnowFlake sf(0, 0);
		data.setxRepeatMasterId(to_string(sf.nextId()));
		
		//flag = dao.insertEvent(data);  //�����ճ�
		//flag &= saveOtherEventData(dto, data, dao);

		flag &= saveOtherRepmEventData(dto, data, dao);

		//TODO:��ȡ��ʼ���ں��ظ���������
		//�жϿ�ʼ�·��Ƿ�С���ظ������·�

		//XXX:�ⲿ�ֿ����ûص�����ʵ��
		string endTime = checkEndOfMonth(data.getxStartTime().substr(0, 10), data.getxRepeatUnitDate());

		auto schedule = generateDailySchedule(data.getxStartTime().substr(0,10), endTime);
		cout << "... event cnt : " << schedule.size() << " ..." << endl;
		
		for (auto& date : schedule) {
			string tmpStartTime;
			string tmpEndTime;
			string tmpAlarmTime;
			tmpStartTime = date + data.getxStartTime().substr(10, 9);
			tmpEndTime = date + data.getxEndTime().substr(10, 9);
			tmpAlarmTime = date + data.getxAlarmTime().substr(10, 9);
			data.setxStartTime(tmpStartTime);
			data.setxEndTime(tmpEndTime);
			data.setxAlarmTime(tmpAlarmTime);
			SnowFlake sf(0, 0);
			data.setxId(to_string(sf.nextId()));
			flag &= dao.insertEvent(data);
			flag &= saveOtherEventData(dto, data, dao);
		}
	}
	else if (data.getxRepeat() == "2") {  //ÿ���ظ�

		SnowFlake sf(0, 0);
		data.setxRepeatMasterId(to_string(sf.nextId()));


		flag &= saveOtherRepmEventData(dto, data, dao); //�����ظ�����

		string endTime = checkEndOfMonth(data.getxStartTime().substr(0, 10), data.getxRepeatUnitDate());

		cout << "... weekly startTime and endTime : " << data.getxStartTime().substr(0, 10) << " " << endTime << " ..." << endl;
 
		auto schedule = generateWeeklySchedule(data.getxStartTime().substr(0, 10), endTime,
							data.getxRecurrenceRule());

		cout << "... weekly schedule size : " << schedule.size() << " ..." << endl;

		for (const auto& date : schedule) {
			string tmpStartTime;
			string tmpEndTime;
			string tmpAlarmTime;
			cout << date << endl;
			tmpStartTime = date + data.getxStartTime().substr(10, 9);
			tmpEndTime = date + data.getxEndTime().substr(10, 9);
			tmpAlarmTime = date + data.getxAlarmTime().substr(10, 9);
			cout << tmpEndTime << "   " << tmpStartTime << endl;
			data.setxStartTime(tmpStartTime);
			data.setxEndTime(tmpEndTime);
			data.setxAlarmTime(tmpAlarmTime);
			SnowFlake sf(0, 0);
			data.setxId(to_string(sf.nextId()));
			flag &= dao.insertEvent(data);
			flag &= saveOtherEventData(dto, data, dao);
		}
	}
	else if (data.getxRepeat() == "3") {
		SnowFlake sf(0, 0);
		data.setxRepeatMasterId(to_string(sf.nextId()));

		flag &= saveOtherRepmEventData(dto, data, dao); //�����ظ�����

		string endTime = checkEndOfMonth(data.getxStartTime().substr(0, 10), data.getxRepeatUnitDate());

		auto schedule = generateMonthlySchedule(data.getxStartTime().substr(0, 10), endTime);

		for (const auto& date : schedule) {
			string tmpStartTime;
			string tmpEndTime;
			string tmpAlarmTime;
			cout << date << endl;
			tmpStartTime = date + data.getxStartTime().substr(10, 9);
			tmpEndTime = date + data.getxEndTime().substr(10, 9);
			tmpAlarmTime = date + data.getxAlarmTime().substr(10, 9);
			cout << tmpEndTime << "   " << tmpStartTime << endl;
			data.setxStartTime(tmpStartTime);
			data.setxEndTime(tmpEndTime);
			data.setxAlarmTime(tmpAlarmTime);
			SnowFlake sf(0, 0);
			data.setxId(to_string(sf.nextId()));
			flag &= dao.insertEvent(data);
			flag &= saveOtherEventData(dto, data, dao);
		}

	}
	else if (data.getxRepeat() == "4") {
		SnowFlake sf(0, 0);
		data.setxRepeatMasterId(to_string(sf.nextId()));

		flag &= saveOtherRepmEventData(dto, data, dao); //�����ظ�����

		string endTime = checkEndOfMonth(data.getxStartTime().substr(0, 10), data.getxRepeatUnitDate());

		auto schedule = generateYearlySchedule(data.getxStartTime().substr(0, 10), endTime);

		for (const auto& date : schedule) {
			string tmpStartTime;
			string tmpEndTime;
			string tmpAlarmTime;
			cout << date << endl;
			tmpStartTime = date + data.getxStartTime().substr(10, 9);
			tmpEndTime = date + data.getxEndTime().substr(10, 9);
			tmpAlarmTime = date + data.getxAlarmTime().substr(10, 9);
			cout << tmpEndTime << "   " << tmpStartTime << endl;
			data.setxStartTime(tmpStartTime);
			data.setxEndTime(tmpEndTime);
			data.setxAlarmTime(tmpAlarmTime);
			SnowFlake sf(0, 0);
			data.setxId(to_string(sf.nextId()));
			flag &= dao.insertEvent(data);
			flag &= saveOtherEventData(dto, data, dao);
		}

	}


	return flag;
}

bool EventService::saveEventData(cal_event_repmDO repmData, const string& startDate, const string& endDate, const string& repeatRule)
{
	cout << "... during querySave :" << repeatRule << " -- " << startDate << " -- " << endDate << " ..." << endl;
	int flag = 1;
	EventDAO dao;
	cal_eventDO data;
	data.setxCreateTime(repmData.getxCreateTime()); data.setxSequence(repmData.getxSequence());
	data.setxUpdateTime(repmData.getxUpdateTime()); data.setxDistributeFactor(repmData.getxDistributeFactor());
	data.setxAlarm(repmData.getxAlarm()); data.setxAlarmTime(repmData.getxAlarmTime());
	data.setxCalendarId(repmData.getxCalendarId()); data.setxColor(repmData.getxColor());
	data.setxComment(repmData.getxComment()); 
	data.setxCommentId(repmData.getxCommentId()); data.setxCreatePerson(repmData.getxCreatePerson());
	data.setxDaysOfDuration(repmData.getxDaysOfDuration()); data.setxEndTime(repmData.getxEndTime());
	data.setxEventType(repmData.getxEventType()); data.setxIsAllDayEvent(repmData.getxIsAllDayEvent());
	data.setxIsPublic(repmData.getxIsPublic()); data.setxLatitude(repmData.getxLatitude());
	data.setxLocationName(repmData.getxLocationName()); data.setxLongitude(repmData.getxLongitude());
	data.setxRecurrenceExc(repmData.getxRecurrenceExc()); data.setxRecurrenceRule(repmData.getxRecurrenceRule());
	data.setxSource(repmData.getxSource()); data.setxStartTime(repmData.getxStartTime());
	data.setxTargetType(repmData.getxTargetType()); data.setxTitle(repmData.getxTitle());
	data.setxUpdatePerson(repmData.getxUpdatePerson()); data.setxValarmTime_config(repmData.getxValarmTime_config());
	data.setxValarm_Summary(repmData.getxValarm_Summary()); data.setxValarm_description(repmData.getxValarm_description());
	data.setxValarm_mailto(repmData.getxValarm_mailto()); data.setxRecurrenceRule(repmData.getxRecurrenceRule());
	data.setxRecurrenceExc(repmData.getxRecurrenceExc()); data.setxRecurrenceRule(repmData.getxRecurrenceRule());

	data.setxAlarmAlready(0); 
	data.setxBundle(0);
	data.setxRepeatMasterId(repmData.getxId());

	
 	
	if (repeatRule == "DAILY") {

		auto schedule = generateDailySchedule(startDate, endDate);
		cout << "... event cnt : " << schedule.size() << " ..." << endl;

		for (auto& date : schedule) {
			string tmpStartTime;
			string tmpEndTime;
			tmpStartTime = date + data.getxStartTime().substr(10, 9);
			tmpEndTime = date + data.getxEndTime().substr(10, 9);
			data.setxStartTime(tmpStartTime);
			data.setxEndTime(tmpEndTime);
			SnowFlake sf(0, 0);
			data.setxId(to_string(sf.nextId()));
			flag &= dao.insertEvent(data);
			//TODO:��ȡ�������б�
			//flag &= saveOtherEventData(dto, data, dao);
		}
	}
	else if (repeatRule == "WEEKLY") {

		auto schedule = generateWeeklySchedule(startDate, endDate, data.getxRecurrenceRule());

		for (const auto& date : schedule) {
			string tmpStartTime;
			string tmpEndTime;
			cout << date << endl;
			tmpStartTime = date + data.getxStartTime().substr(10, 9);
			tmpEndTime = date + data.getxEndTime().substr(10, 9);
			cout << tmpEndTime << "   " << tmpStartTime << endl;
			data.setxStartTime(tmpStartTime);
			data.setxEndTime(tmpEndTime);
			SnowFlake sf(0, 0);
			data.setxId(to_string(sf.nextId()));
			flag &= dao.insertEvent(data);
			//flag &= saveOtherEventData(dto, data, dao);
		}
	}
	else if (repeatRule == "MONTHLY") {
		auto schedule = generateMonthlySchedule(startDate, endDate);

		for (const auto& date : schedule) {
			string tmpStartTime;
			string tmpEndTime;
			cout << date << endl;
			tmpStartTime = date + data.getxStartTime().substr(10, 9);
			tmpEndTime = date + data.getxEndTime().substr(10, 9);
			cout << tmpEndTime << "   " << tmpStartTime << endl;
			data.setxStartTime(tmpStartTime);
			data.setxEndTime(tmpEndTime);
			SnowFlake sf(0, 0);
			data.setxId(to_string(sf.nextId()));
			flag &= dao.insertEvent(data);
			//flag &= saveOtherEventData(dto, data, dao);
		}
	}
	else if (repeatRule == "YEARLY") {
		auto schedule = generateYearlySchedule(startDate, endDate);

		for (const auto& date : schedule) {
			string tmpStartTime;
			string tmpEndTime;
			cout << date << endl;
			tmpStartTime = date + data.getxStartTime().substr(10, 9);
			tmpEndTime = date + data.getxEndTime().substr(10, 9);
			cout << tmpEndTime << "   " << tmpStartTime << endl;
			data.setxStartTime(tmpStartTime);
			data.setxEndTime(tmpEndTime);
			SnowFlake sf(0, 0);
			data.setxId(to_string(sf.nextId()));
			flag &= dao.insertEvent(data);
			//flag &= saveOtherEventData(dto, data, dao);
		}
	}

	return false;
}

// �޸�����
bool EventService::updateEventData(const ScheduleInfoDTO::Wrapper& dto, const string& username)
{
	// ��װDO����
	cal_eventDO data;
	
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, xId, xid, xCalendarId, xcalendarId, xTitle, xtitle, xStartTime, xstartTime, xEndTime, xendTime,
		xLocationName, xlocationName, xIsAllDayEvent, xisAllDayEvent, xAlarm, xalarm, xValarmTime_config, xvalarmTime_config,
		xRepeat, xrepeat, xRecurrenceRule, xrecurrenceRule, xRepeatUnitDate, xrepeatUnitDate, xColor, xcolor, xComment, xcomment)

		//��װ��������
		assembleDoData(data, dto);
	data.setxAlarmAlready(data.getxAlarmAlready());


	// ִ���������
	EventDAO dao;
	int flag = 1;

	if (dto->updateMenuOption == "1") {     //�޸ĵ���

		flag &= dao.updateEvnet(data);

	}
	else if (dto->updateMenuOption == "2") {  //����޸�ȫ�� ��ɾ�������

		if(dto->xrepmId == "")
			flag &= dao.deleteEventByXid(dto->xid);
		else {
			flag &= dao.deleteEventByRepmXid(dto->xrepmId);
			flag &= dao.deleteEventByFindXid(dto->xrepmId);
		}


		flag &= EventService::saveEventData(dto, username);  

	}

	return flag;
}


// ͨ��IDɾ������
bool EventService::removeEventData(const ScheduleDelDTO::Wrapper& dto) {

	EventDAO dao;
	int flag = 1;
	cout << "... xid: " << (string)dto->xidList->front() << " ..." << endl;
	if(dto->updateMenuOption == "1")  //ɾ����ǰ
		for(auto xid : *dto->xidList)
			flag &= dao.deleteEventByXid(xid);   
	else if(dto->updateMenuOption == "2") { //ɾ������

		//flag &= dao.deleteEventByFindRepmXid(dto->xidList->front());

		if (dto->xrepmId != "") {
			flag &= dao.deleteEventByRepmXid((string)dto->xrepmId);
			flag &= dao.deleteEventByFindXid((string)dto->xrepmId);
		}
		else {
			for (auto xid : *dto->xidList)
				flag &= dao.deleteEventByXid(xid);
		}
	}
	
	return flag;
}

