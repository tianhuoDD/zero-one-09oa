#include "stdafx.h"
#include "EventSelectDAO.h"
#include "EventSelectMapper.h"
#include<sstream>


//Ϊtime_point�����������һ����
std::chrono::system_clock::time_point addMonths(std::chrono::system_clock::time_point tp, int months);

//Ϊtime_point�����������һ��
std::chrono::system_clock::time_point addYears(std::chrono::system_clock::time_point tp, int years);

//�������until����Ϊ�ɽ������ڼ������������time_point
std::chrono::system_clock::time_point parseUntil(const std::string& until);

//�������datetime����Ϊ�ɽ������ڼ������������time_point
std::chrono::system_clock::time_point parseDatetime(const std::string& datetime);

//��time_pointתΪ�ַ���
std::string timePointToString(const std::chrono::system_clock::time_point& timePoint);

//��time_pointתΪ�ַ���
std::string convertDateTime(const std::string& dateTimeStr);

//��ȡ��ǰʱ��
std::string getCurrentTimeString();

//����Ϊ���ʱ�䴦��������
//--------------------------------------------------------------
//--------------------------------------------------------------




//�������������꣬�����ظ�����
#define EVENT_TERAM_PARSE(query,sql)\
SqlParams params;\
sql<<" WHERE 1=1";\
if(query->calendarId){\
	sql<<" AND xcalendarId=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->calendarId.getValue(""));\
}\
if(query->queryDate){\
	sql<<" AND xstartTime LIKE ?";\
	std::string yearmonth=query->queryDate.getValue("")+"-%";\
	SQLPARAMS_PUSH(params,"s",std::string,yearmonth);\
};




int EventSelectDAO::AddRepmCreatedMonthlist(const string & repeatId, const string & monthdate)
{
	cal_event_repm_createdmonthlistDO cercdo;
	cercdo.setXCALENDAR_EVENTREPEATMASTER_XID(repeatId);
	cercdo.setxCreatedMonthList(monthdate);
	cercdo.setxOrderColumn(0);
	stringstream sql;
	sql << "INSERT INTO cal_event_repm_createdmonthlist (CALENDAR_EVENTREPEATMASTER_XID,xcreatedMonthList,xorderColumn) VALUES(?,?,?)";
	string sql_str = sql.str();
	int result = sqlSession->executeUpdate(sql_str, "%s%s%i", cercdo.getXCALENDAR_EVENTREPEATMASTER_XID(), cercdo.getxCreatedMonthList(), cercdo.getxOrderColumn());
	return result;
}

std::list<cal_event_repmDO> EventSelectDAO::selectAllRepm(const CalEventsQuery::Wrapper &query)
{
	stringstream sql;
	string queryDate = query->queryDate.getValue("") + "-28 23:59:59";
	sql << "SELECT xid,xsequence,xdistributeFactor,xalarm,xalarmTime,xcalendarId,xcolor,xcomment,xcommentId,\
xcreatePerson,xdaysOfDuration,xendTime,xeventType,xisAllDayEvent,xisPublic,\
xlocationName,xrecurrenceRule,xrecurrenceStartTime,xsource,xstartTime,\
xtargetType,xtitle,xupdatePerson,xvalarmTime_config,xvalarm_Summary,xcreateTime,xupdateTime FROM ";
	sql<<"cal_event_repm WHERE xcalendarId = ? AND xrecurrenceStartTime < ?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->calendarId.getValue(""));
	SQLPARAMS_PUSH(params, "s", std::string, queryDate);
	string sql_str = sql.str();
	RepmSelectMapper mapper;
	return sqlSession->executeQuery<cal_event_repmDO,RepmSelectMapper>(sql_str,mapper,params);
}


//��cal_event_repm_createdmonthlist���жϴ��·��Ƿ�����
bool EventSelectDAO::TheIdIsCreated(const cal_event_repmDO& doo, string querydate)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM cal_event_repm_createdmonthlist WHERE CALENDAR_EVENTREPEATMASTER_XID=? AND xcreatedMonthList=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, doo.getxId());
	SQLPARAMS_PUSH(params, "s", std::string, querydate);
	string sql_str = sql.str();
	//
	//cout << sql_str << endl;
	int result= sqlSession->executeQueryNumerical(sql_str, params);
	//cout << result << endl;
	return result==0;
}


int EventSelectDAO::AddRepeatEventIntoTable(const cal_event_repmDO& doo,string month_start)
{
	string re_rule = doo.getxRecurrenceRule();

	//cout << "Recurrence Rule: " << re_rule << endl; // ���ԭʼ�ַ���
	string frequency;
	string until = "NULL"; // Ĭ��ֵ
	stringstream ss(re_rule);
	string token;
	while (getline(ss, token, ';'))
	{
		size_t pos = token.find('=');
		if (pos != string::npos) { // ȷ���ҵ��� '='
			string key = token.substr(0, pos);
			string value = token.substr(pos + 1);

			// ȥ����ֵ�����˵Ŀո�
			key.erase(0, key.find_first_not_of(" ")); // ��ǰȥ���ո�
			key.erase(key.find_last_not_of(" ") + 1); // �Ӻ�ȥ���ո�
			value.erase(0, value.find_first_not_of(" ")); // ��ǰȥ���ո�
			value.erase(value.find_last_not_of(" ") + 1); // �Ӻ�ȥ���ո�

			// ���������Ϣ
			//cout << "Key: '" << key << "', Value: '" << value << "'" << endl;

			if (key == "FREQ") {
				frequency = value;
			}
			else if (key == "UNTIL") {
				until = value;
			}
		}
		else {
			cout << "No '=' found in token: '" << token << "'" << endl; // ���û���ҵ� '=' �����
		}
	}

	// ���������
	//cout << "Frequency: " << frequency << endl;
	//cout << "Until: " << until << endl;

	//���ݲ�ѯ���·ݣ��������ڴ��·ݵķ��Ϲ�����ճ�
	auto data_month_start = parseDatetime(month_start);
	auto data_month_end = addMonths(data_month_start,1);
	auto recurrence_time = parseDatetime(doo.getxRecurrenceStartTime());
	auto recurrence_end_time = parseDatetime(doo.getxEndTime());
	std::chrono::system_clock::time_point untilTime;
	if (until != "NULL") {
		untilTime = parseUntil(until);
		string zzz = timePointToString(untilTime);
		//cout << zzz << endl;
	}
	//cout << "��Ҫִ�в�������" << endl;
	if (frequency == "DAILY") {
		try {
			// ѭ����һ�죬�� untilTime ��ʼ
			while (recurrence_time <= data_month_end) {
				if (recurrence_time >= data_month_start&& (until=="NULL" || (until != "NULL" && recurrence_time <= untilTime))) {
					// ������������ݵ����ݿ�
					
					//��װ���µ�cal_eventDO
					cal_eventDO cedo;
					//��ȡ����id
					SnowFlake snowflake(30, 30);
					string xid = to_string(snowflake.nextId());
					cedo.setxId(xid);
					cedo.setxCreateTime(doo.getxCreateTime());
					cedo.setxSequence(convertDateTime(doo.getxUpdateTime())+ xid);
					cedo.setxUpdateTime(doo.getxUpdateTime());
					cedo.setxDistributeFactor(doo.getxDistributeFactor());
					cedo.setxAlarm(doo.getxAlarm());
					cedo.setxAlarmAlready(0);
					//cedo.setxAlarmTime("NULL");
					cedo.setxCalendarId(doo.getxCalendarId());
					cedo.setxColor(doo.getxColor());
					cedo.setxComment(doo.getxComment());
					cedo.setxCommentId(doo.getxCommentId());
					cedo.setxCreatePerson(doo.getxCreatePerson());
					cedo.setxDaysOfDuration(doo.getxDaysOfDuration());
					cedo.setxEndTime(timePointToString(recurrence_end_time));
					cedo.setxEventType(doo.getxEventType());
					cedo.setxIsAllDayEvent(doo.getxIsAllDayEvent());
					cedo.setxIsPublic(doo.getxIsPublic());
					cedo.setxLocationName(doo.getxLocationName());
					cedo.setxLongitude(doo.getxLongitude());
					cedo.setxRecurrenceExc(doo.getxRecurrenceExc());
					cedo.setxRecurrenceRule(doo.getxRecurrenceRule());
					cedo.setxRepeatMasterId(doo.getxId());
					cedo.setxSource(doo.getxSource());
					cedo.setxStartTime(timePointToString(recurrence_time));
					cedo.setxTargetType(doo.getxTargetType());
					cedo.setxTitle(doo.getxTitle());
					cedo.setxUpdatePerson(doo.getxUpdatePerson());
					cedo.setxValarmTime_config(doo.getxValarmTime_config());
					cedo.setxValarm_Summary(doo.getxValarm_Summary());
					cedo.setxValarm_description(doo.getxValarm_description());
					cedo.setxValarm_mailto(doo.getxValarm_mailto());

					//cout << "2" << endl;
					insertToCal_event(cedo);
				}
				recurrence_time += std::chrono::hours(24);
				recurrence_end_time+= std::chrono::hours(24);
			}
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else if (frequency == "WEEKLY") {
		try {
			// ѭ����һ�죬�� untilTime ��ʼ
			while (recurrence_time <= data_month_end) {
				if (recurrence_time >= data_month_start && (until == "NULL" || (until != "NULL" && recurrence_time <= untilTime))) {
					// ������������ݵ����ݿ�

					//��װ���µ�cal_eventDO
					cal_eventDO cedo;
					//��ȡ����id
					SnowFlake snowflake(30, 30);
					string xid = to_string(snowflake.nextId());
					cedo.setxId(xid);
					cedo.setxCreateTime(doo.getxCreateTime());
					cedo.setxSequence(convertDateTime(doo.getxUpdateTime()) + xid);
					cedo.setxUpdateTime(doo.getxUpdateTime());
					cedo.setxDistributeFactor(doo.getxDistributeFactor());
					cedo.setxAlarm(doo.getxAlarm());
					cedo.setxAlarmAlready(0);
					//cedo.setxAlarmTime("NULL");
					cedo.setxCalendarId(doo.getxCalendarId());
					cedo.setxColor(doo.getxColor());
					cedo.setxComment(doo.getxComment());
					cedo.setxCommentId(doo.getxCommentId());
					cedo.setxCreatePerson(doo.getxCreatePerson());
					cedo.setxDaysOfDuration(doo.getxDaysOfDuration());
					cedo.setxEndTime(timePointToString(recurrence_end_time));
					cedo.setxEventType(doo.getxEventType());
					cedo.setxIsAllDayEvent(doo.getxIsAllDayEvent());
					cedo.setxIsPublic(doo.getxIsPublic());
					cedo.setxLocationName(doo.getxLocationName());
					cedo.setxLongitude(doo.getxLongitude());
					cedo.setxRecurrenceExc(doo.getxRecurrenceExc());
					cedo.setxRecurrenceRule(doo.getxRecurrenceRule());
					cedo.setxRepeatMasterId(doo.getxId());
					cedo.setxSource(doo.getxSource());
					cedo.setxStartTime(timePointToString(recurrence_time));
					cedo.setxTargetType(doo.getxTargetType());
					cedo.setxTitle(doo.getxTitle());
					cedo.setxUpdatePerson(doo.getxUpdatePerson());
					cedo.setxValarmTime_config(doo.getxValarmTime_config());
					cedo.setxValarm_Summary(doo.getxValarm_Summary());
					cedo.setxValarm_description(doo.getxValarm_description());
					cedo.setxValarm_mailto(doo.getxValarm_mailto());

					//cout << "2" << endl;
					insertToCal_event(cedo);
				}
				recurrence_time += std::chrono::hours(24*7);
				recurrence_end_time += std::chrono::hours(24*7);
			}
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else if (frequency == "MONTHLY") {
		try {
			//cout << "���ڽ���ÿ���µ�����" << endl;
			// ѭ����һ���£��� untilTime ��ʼ
			while (recurrence_time <= data_month_end) {
				if (recurrence_time >= data_month_start && (until == "NULL" || (until != "NULL" && recurrence_time <= untilTime))) {
					// ������������ݵ����ݿ�

					//��װ���µ�cal_eventDO
					cal_eventDO cedo;
					//��ȡ����id
					SnowFlake snowflake(30, 30);
					string xid = to_string(snowflake.nextId());
					cedo.setxId(xid);
					cedo.setxCreateTime(doo.getxCreateTime());
					cedo.setxSequence(convertDateTime(doo.getxUpdateTime()) + xid);
					cedo.setxUpdateTime(doo.getxUpdateTime());
					cedo.setxDistributeFactor(doo.getxDistributeFactor());
					cedo.setxAlarm(doo.getxAlarm());
					cedo.setxAlarmAlready(0);
					//cedo.setxAlarmTime("NULL");
					cedo.setxCalendarId(doo.getxCalendarId());
					cedo.setxColor(doo.getxColor());
					cedo.setxComment(doo.getxComment());
					cedo.setxCommentId(doo.getxCommentId());
					cedo.setxCreatePerson(doo.getxCreatePerson());
					cedo.setxDaysOfDuration(doo.getxDaysOfDuration());
					cedo.setxEndTime(timePointToString(recurrence_end_time));
					cedo.setxEventType(doo.getxEventType());
					cedo.setxIsAllDayEvent(doo.getxIsAllDayEvent());
					cedo.setxIsPublic(doo.getxIsPublic());
					cedo.setxLocationName(doo.getxLocationName());
					cedo.setxLongitude(doo.getxLongitude());
					cedo.setxRecurrenceExc(doo.getxRecurrenceExc());
					cedo.setxRecurrenceRule(doo.getxRecurrenceRule());
					cedo.setxRepeatMasterId(doo.getxId());
					cedo.setxSource(doo.getxSource());
					cedo.setxStartTime(timePointToString(recurrence_time));
					cedo.setxTargetType(doo.getxTargetType());
					cedo.setxTitle(doo.getxTitle());
					cedo.setxUpdatePerson(doo.getxUpdatePerson());
					cedo.setxValarmTime_config(doo.getxValarmTime_config());
					cedo.setxValarm_Summary(doo.getxValarm_Summary());
					cedo.setxValarm_description(doo.getxValarm_description());
					cedo.setxValarm_mailto(doo.getxValarm_mailto());

					//cout << "1" << endl;
					insertToCal_event(cedo);
					//cout << "6" << endl;
				}
				recurrence_time =addMonths(recurrence_time,1);
				recurrence_end_time = addMonths(recurrence_time, 1);
			}
			//cout << "����ÿ���µ�����" << endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else if (frequency == "YEARLY") {
		try {
			//cout << "���ڽ���ÿ�������" << endl;
			// ѭ����һ�꣬�� untilTime ��ʼ
			while (recurrence_time <= data_month_end) {
				if (recurrence_time >= data_month_start && (until == "NULL" || (until != "NULL" && recurrence_time <= untilTime))) {
					// ������������ݵ����ݿ�

					//��װ���µ�cal_eventDO
					cal_eventDO cedo;
					//��ȡ����id
					SnowFlake snowflake(30, 30);
					string xid = to_string(snowflake.nextId());
					cedo.setxId(xid);
					cedo.setxCreateTime(doo.getxCreateTime());
					cedo.setxSequence(convertDateTime(doo.getxUpdateTime())+ xid);
					cedo.setxUpdateTime(doo.getxUpdateTime());
					cedo.setxDistributeFactor(doo.getxDistributeFactor());
					cedo.setxAlarm(doo.getxAlarm());
					cedo.setxAlarmAlready(0);
					//cedo.setxAlarmTime("NULL");
					cedo.setxCalendarId(doo.getxCalendarId());
					cedo.setxColor(doo.getxColor());
					cedo.setxComment(doo.getxComment());
					cedo.setxCommentId(doo.getxCommentId());
					cedo.setxCreatePerson(doo.getxCreatePerson());
					cedo.setxDaysOfDuration(doo.getxDaysOfDuration());
					cedo.setxEndTime(timePointToString(recurrence_end_time));
					cedo.setxEventType(doo.getxEventType());
					cedo.setxIsAllDayEvent(doo.getxIsAllDayEvent());
					cedo.setxIsPublic(doo.getxIsPublic());
					cedo.setxLocationName(doo.getxLocationName());
					cedo.setxLongitude(doo.getxLongitude());
					cedo.setxRecurrenceExc(doo.getxRecurrenceExc());
					cedo.setxRecurrenceRule(doo.getxRecurrenceRule());
					cedo.setxRepeatMasterId(doo.getxId());
					cedo.setxSource(doo.getxSource());
					cedo.setxStartTime(timePointToString(recurrence_time));
					cedo.setxTargetType(doo.getxTargetType());
					cedo.setxTitle(doo.getxTitle());
					cedo.setxUpdatePerson(doo.getxUpdatePerson());
					cedo.setxValarmTime_config(doo.getxValarmTime_config());
					cedo.setxValarm_Summary(doo.getxValarm_Summary());
					cedo.setxValarm_description(doo.getxValarm_description());
					cedo.setxValarm_mailto(doo.getxValarm_mailto());

					insertToCal_event(cedo);
				}
				recurrence_time = addYears(recurrence_time, 1);
				recurrence_end_time = addYears(recurrence_time, 1);
			}
			//cout << "����ÿ�������" << endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

uint64_t EventSelectDAO::countEvent(const CalEventsQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM cal_event";
	EVENT_TERAM_PARSE(query, sql);
	string sql_str = sql.str();
	//cout << sql_str << endl;
	return sqlSession->executeQueryNumerical(sql_str, params);
}
std::list<cal_eventDO> EventSelectDAO::selectAllEvent(const CalEventsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xid,xtitle,xstartTime,xendTime,xcolor,xlocationName,xisAllDayEvent FROM cal_event";
	EVENT_TERAM_PARSE(query, sql);
	string sql_str = sql.str();
	EventsSelectMapper mapper;
	return sqlSession->executeQuery<cal_eventDO, EventsSelectMapper>(sql_str, mapper, params);
}

list<cal_eventDO> EventSelectDAO::selectOneEvent(const CalEventQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xcalendarId,xtitle,xstartTime,xendTime,xcolor,xcomment,xlocationName,xrecurrenceRule,xisAllDayEvent FROM cal_event WHERE 1=1 AND xid=?";
	SqlParams params;
	if (query->calEventId) {
		SQLPARAMS_PUSH(params, "s", std::string, query->calEventId.getValue(""));
	}
	string sql_str = sql.str();
	EventSelectMapper mapper;
	return sqlSession->executeQuery<cal_eventDO,EventSelectMapper>(sql_str,mapper,params);
}


//����cal_event��
int EventSelectDAO::insertToCal_event(const cal_eventDO& cedo)
{
	stringstream sql;
	sql << "INSERT INTO cal_event (xid,xcreatetime,xsequence,xupdatetime,\
xdistributeFactor,xalarm,xalarmAlready,xcalendarId,\
xcolor,xcomment,xcommentId,xcreatePerson,xdaysOfDuration,xendTime,\
xeventType,xisAllDayEvent,xisPublic,xlocationName,xlongitude,xrecurrenceExc,\
xrecurrenceRule,xrepeatMasterId,xsource,xstartTime,xtargetType,xtitle,\
xupdatePerson,xvalarmTime_config,xvalarm_Summary,xvalarm_description,\
xvalarm_mailto) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	string sql_str = sql.str();
	int result=sqlSession->executeUpdate(sql_str, "%s%s%s%s%i%i%i%s%s%s%s%s%i%s%s%i%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s", \
		cedo.getxId(), cedo.getxCreateTime(), cedo.getxSequence(), cedo.getxUpdateTime(), cedo.getxDistributeFactor(), cedo.getxAlarm(), cedo.getxAlarmAlready(), \
		cedo.getxCalendarId(), cedo.getxColor(), cedo.getxComment(), cedo.getxCommentId(), cedo.getxCreatePerson(), cedo.getxDaysOfDuration(), \
		cedo.getxEndTime(), cedo.getxEventType(), cedo.getxIsAllDayEvent(), cedo.getxIsPublic(), cedo.getxLocationName(), cedo.getxLongitude(), cedo.getxRecurrenceExc(), \
		cedo.getxRecurrenceRule(), cedo.getxRepeatMasterId(), cedo.getxSource(), cedo.getxStartTime(), cedo.getxTargetType(), cedo.getxTitle(), cedo.getxUpdatePerson(), \
		cedo.getxValarmTime_config(), cedo.getxValarm_Summary(), cedo.getxValarm_description(), cedo.getxValarm_mailto());
	return result;
}



//-----------------------------------------------
// ----------------------------------------------
//����Ϊ����ʱ����غ�������

//Ϊtime_point�����������һ����
std::chrono::system_clock::time_point addMonths(std::chrono::system_clock::time_point tp, int months) {
	std::time_t time = std::chrono::system_clock::to_time_t(tp);
	std::tm* tm = std::localtime(&time);

	// �����·�
	tm->tm_mon += months;

	// �淶��ʱ�䣬�������
	std::mktime(tm);

	return std::chrono::system_clock::from_time_t(std::mktime(tm));
}

//Ϊtime_point�����������һ��
std::chrono::system_clock::time_point addYears(std::chrono::system_clock::time_point tp, int years) {
	std::time_t time = std::chrono::system_clock::to_time_t(tp);
	std::tm* tm = std::localtime(&time);

	// �������
	tm->tm_year += years;

	// �淶��ʱ�䣬�������
	std::mktime(tm);

	return std::chrono::system_clock::from_time_t(std::mktime(tm));
}

//�������until����Ϊ�ɽ������ڼ������������time_point
std::chrono::system_clock::time_point parseUntil(const std::string& until) {
	std::tm tm = {};
	std::istringstream ss(until);

	// ���Խ��������ĸ�ʽ
	ss >> std::get_time(&tm, "%Y%m%dT%H%M%SZ");
	if (ss.fail()) {
		// ���ʧ�ܣ����ò����Խ���û��ʱ�䲿�ֵĸ�ʽ
		ss.clear();
		ss.str(until); // ���������ַ�����
		ss >> std::get_time(&tm, "%Y%m%d");
		if (ss.fail()) {
			throw std::runtime_error("Failed to parse until date");
		}
		tm.tm_hour = 0; // ����ʱ��Ϊ��ҹ
		tm.tm_min = 0;
		tm.tm_sec = 0;
	}

	// �� tm ת��Ϊ time_t
	std::time_t time = std::mktime(&tm);

	// ת��Ϊ system_clock::time_point
	return std::chrono::system_clock::from_time_t(time);
}

//�������datetime����Ϊ�ɽ������ڼ������������time_point

std::chrono::system_clock::time_point parseDatetime(const std::string& datetime) {
	std::tm tm = {};
	std::istringstream ss(datetime);
	ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
	if (ss.fail()) {
		throw std::runtime_error("Failed to parse datetime");
	}
	std::time_t time = std::mktime(&tm);
	//cout << "�����ɹ�" << endl;
	return std::chrono::system_clock::from_time_t(time);
}

//��time_pointתΪ�ַ���
std::string timePointToString(const std::chrono::system_clock::time_point& timePoint) {
	// �� time_point ת��Ϊ time_t
	std::time_t timeT = std::chrono::system_clock::to_time_t(timePoint);
	// �� time_t ת��Ϊ tm �ṹ
	std::tm* tmPtr = std::localtime(&timeT);

	// ʹ�� stringstream ��ʽ��ʱ��
	std::ostringstream oss;
	oss << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");
	return oss.str(); // �����ַ���
}

//��time_pointתΪ�ַ���
std::string convertDateTime(const std::string& dateTimeStr) {
	// ȷ�������ַ�����ʽΪ "YYYY-MM-DD HH:MM:SS"
	if (dateTimeStr.size() != 19 || dateTimeStr[4] != '-' || dateTimeStr[7] != '-' || dateTimeStr[10] != ' ' || dateTimeStr[13] != ':' || dateTimeStr[16] != ':') {
		throw std::invalid_argument("Invalid dateTime format");
	}

	std::string result;

	// ��ȡ�ꡢ�¡��ա�ʱ���֡���
	result += dateTimeStr.substr(0, 4); // ��
	result += dateTimeStr.substr(5, 2); // ��
	result += dateTimeStr.substr(8, 2); // ��
	result += dateTimeStr.substr(11, 2); // ʱ
	result += dateTimeStr.substr(14, 2); // ��

	return result;
}

//��ȡ��ǰʱ��
std::string getCurrentTimeString() {
	// ��ȡ��ǰʱ���
	auto now = std::chrono::system_clock::now();
	// ����ǰʱ���ת��Ϊ time_t
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	// �� time_t ת��Ϊ tm �ṹ
	std::tm* now_tm = std::localtime(&now_time_t);

	// ʹ�� stringstream ��ʽ����ǰʱ��
	std::ostringstream oss;
	oss << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S");
	return oss.str(); // �����ַ���
}