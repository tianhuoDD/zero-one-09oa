#include "stdafx.h"
#include "EventSelectDAO.h"
#include "EventSelectMapper.h"
#include<sstream>


//为time_point型日期往后加一个月
std::chrono::system_clock::time_point addMonths(std::chrono::system_clock::time_point tp, int months);

//为time_point型日期往后加一年
std::chrono::system_clock::time_point addYears(std::chrono::system_clock::time_point tp, int years);

//定义解析until类型为可进行日期计算的数据类型time_point
std::chrono::system_clock::time_point parseUntil(const std::string& until);

//定义解析datetime类型为可进行日期计算的数据类型time_point
std::chrono::system_clock::time_point parseDatetime(const std::string& datetime);

//将time_point转为字符串
std::string timePointToString(const std::chrono::system_clock::time_point& timePoint);

//将time_point转为字符串
std::string convertDateTime(const std::string& dateTimeStr);

//获取当前时间
std::string getCurrentTimeString();

//以上为相关时间处理函数声明
//--------------------------------------------------------------
//--------------------------------------------------------------




//定义条件解析宏，减少重复代码
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


//查cal_event_repm_createdmonthlist表判断此月份是否插入过
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

	//cout << "Recurrence Rule: " << re_rule << endl; // 输出原始字符串
	string frequency;
	string until = "NULL"; // 默认值
	stringstream ss(re_rule);
	string token;
	while (getline(ss, token, ';'))
	{
		size_t pos = token.find('=');
		if (pos != string::npos) { // 确保找到了 '='
			string key = token.substr(0, pos);
			string value = token.substr(pos + 1);

			// 去掉键值对两端的空格
			key.erase(0, key.find_first_not_of(" ")); // 从前去除空格
			key.erase(key.find_last_not_of(" ") + 1); // 从后去除空格
			value.erase(0, value.find_first_not_of(" ")); // 从前去除空格
			value.erase(value.find_last_not_of(" ") + 1); // 从后去除空格

			// 输出调试信息
			//cout << "Key: '" << key << "', Value: '" << value << "'" << endl;

			if (key == "FREQ") {
				frequency = value;
			}
			else if (key == "UNTIL") {
				until = value;
			}
		}
		else {
			cout << "No '=' found in token: '" << token << "'" << endl; // 输出没有找到 '=' 的情况
		}
	}

	// 输出结果检查
	//cout << "Frequency: " << frequency << endl;
	//cout << "Until: " << until << endl;

	//根据查询的月份，插入属于此月份的符合规则的日程
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
	//cout << "将要执行插入命令" << endl;
	if (frequency == "DAILY") {
		try {
			// 循环加一天，从 untilTime 开始
			while (recurrence_time <= data_month_end) {
				if (recurrence_time >= data_month_start&& (until=="NULL" || (until != "NULL" && recurrence_time <= untilTime))) {
					// 在这里插入数据到数据库
					
					//组装出新的cal_eventDO
					cal_eventDO cedo;
					//获取日历id
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
			// 循环加一天，从 untilTime 开始
			while (recurrence_time <= data_month_end) {
				if (recurrence_time >= data_month_start && (until == "NULL" || (until != "NULL" && recurrence_time <= untilTime))) {
					// 在这里插入数据到数据库

					//组装出新的cal_eventDO
					cal_eventDO cedo;
					//获取日历id
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
			//cout << "正在进行每个月的增加" << endl;
			// 循环加一个月，从 untilTime 开始
			while (recurrence_time <= data_month_end) {
				if (recurrence_time >= data_month_start && (until == "NULL" || (until != "NULL" && recurrence_time <= untilTime))) {
					// 在这里插入数据到数据库

					//组装出新的cal_eventDO
					cal_eventDO cedo;
					//获取日历id
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
			//cout << "结束每个月的增加" << endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else if (frequency == "YEARLY") {
		try {
			//cout << "正在进行每年的增加" << endl;
			// 循环加一年，从 untilTime 开始
			while (recurrence_time <= data_month_end) {
				if (recurrence_time >= data_month_start && (until == "NULL" || (until != "NULL" && recurrence_time <= untilTime))) {
					// 在这里插入数据到数据库

					//组装出新的cal_eventDO
					cal_eventDO cedo;
					//获取日历id
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
			//cout << "结束每年的增加" << endl;
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


//插入cal_event表
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
//以下为处理时间相关函数定义

//为time_point型日期往后加一个月
std::chrono::system_clock::time_point addMonths(std::chrono::system_clock::time_point tp, int months) {
	std::time_t time = std::chrono::system_clock::to_time_t(tp);
	std::tm* tm = std::localtime(&time);

	// 加上月份
	tm->tm_mon += months;

	// 规范化时间，处理溢出
	std::mktime(tm);

	return std::chrono::system_clock::from_time_t(std::mktime(tm));
}

//为time_point型日期往后加一年
std::chrono::system_clock::time_point addYears(std::chrono::system_clock::time_point tp, int years) {
	std::time_t time = std::chrono::system_clock::to_time_t(tp);
	std::tm* tm = std::localtime(&time);

	// 加上年份
	tm->tm_year += years;

	// 规范化时间，处理溢出
	std::mktime(tm);

	return std::chrono::system_clock::from_time_t(std::mktime(tm));
}

//定义解析until类型为可进行日期计算的数据类型time_point
std::chrono::system_clock::time_point parseUntil(const std::string& until) {
	std::tm tm = {};
	std::istringstream ss(until);

	// 尝试解析完整的格式
	ss >> std::get_time(&tm, "%Y%m%dT%H%M%SZ");
	if (ss.fail()) {
		// 如果失败，重置并尝试解析没有时间部分的格式
		ss.clear();
		ss.str(until); // 重新设置字符串流
		ss >> std::get_time(&tm, "%Y%m%d");
		if (ss.fail()) {
			throw std::runtime_error("Failed to parse until date");
		}
		tm.tm_hour = 0; // 设置时间为午夜
		tm.tm_min = 0;
		tm.tm_sec = 0;
	}

	// 将 tm 转换为 time_t
	std::time_t time = std::mktime(&tm);

	// 转换为 system_clock::time_point
	return std::chrono::system_clock::from_time_t(time);
}

//定义解析datetime类型为可进行日期计算的数据类型time_point

std::chrono::system_clock::time_point parseDatetime(const std::string& datetime) {
	std::tm tm = {};
	std::istringstream ss(datetime);
	ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
	if (ss.fail()) {
		throw std::runtime_error("Failed to parse datetime");
	}
	std::time_t time = std::mktime(&tm);
	//cout << "解析成功" << endl;
	return std::chrono::system_clock::from_time_t(time);
}

//将time_point转为字符串
std::string timePointToString(const std::chrono::system_clock::time_point& timePoint) {
	// 将 time_point 转换为 time_t
	std::time_t timeT = std::chrono::system_clock::to_time_t(timePoint);
	// 将 time_t 转换为 tm 结构
	std::tm* tmPtr = std::localtime(&timeT);

	// 使用 stringstream 格式化时间
	std::ostringstream oss;
	oss << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S");
	return oss.str(); // 返回字符串
}

//将time_point转为字符串
std::string convertDateTime(const std::string& dateTimeStr) {
	// 确保输入字符串格式为 "YYYY-MM-DD HH:MM:SS"
	if (dateTimeStr.size() != 19 || dateTimeStr[4] != '-' || dateTimeStr[7] != '-' || dateTimeStr[10] != ' ' || dateTimeStr[13] != ':' || dateTimeStr[16] != ':') {
		throw std::invalid_argument("Invalid dateTime format");
	}

	std::string result;

	// 提取年、月、日、时、分、秒
	result += dateTimeStr.substr(0, 4); // 年
	result += dateTimeStr.substr(5, 2); // 月
	result += dateTimeStr.substr(8, 2); // 日
	result += dateTimeStr.substr(11, 2); // 时
	result += dateTimeStr.substr(14, 2); // 分

	return result;
}

//获取当前时间
std::string getCurrentTimeString() {
	// 获取当前时间点
	auto now = std::chrono::system_clock::now();
	// 将当前时间点转换为 time_t
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	// 将 time_t 转换为 tm 结构
	std::tm* now_tm = std::localtime(&now_time_t);

	// 使用 stringstream 格式化当前时间
	std::ostringstream oss;
	oss << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S");
	return oss.str(); // 返回字符串
}