#include "stdafx.h"
#include "AcReDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(meetingId, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (!meetingId.empty()) { \
	sql << " AND `MEETING_XID`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, meetingId); \
}

uint64_t AcReDAO::countAccept(const string & meetingId)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM mt_meeting_acceptpersonlist";
	SAMPLE_TERAM_PARSE(meetingId, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t AcReDAO::countRefuse(const string& meetingId)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM mt_meeting_rejectpersonlist";
	SAMPLE_TERAM_PARSE(meetingId, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

uint64_t AcReDAO::insertAccept(const string& meetingId, const string& userId)
{
	int cnt = countAccept(meetingId);

	string sql = "INSERT INTO `mt_meeting_acceptpersonlist` (`MEETING_XID`, `xacceptPersonList`, `xorderColumn`) VALUES (?, ?, ?)";
	
	return sqlSession->executeInsert(sql, "%s%s%i", meetingId, userId, cnt);
}

uint64_t AcReDAO::insertRefuse(const string& meetingId, const string& userId)
{
	int cnt = countRefuse(meetingId);
	
	string sql = "INSERT INTO `mt_meeting_rejectpersonlist` (`MEETING_XID`, `xrejectPersonList`, `xorderColumn`) VALUES (?, ?, ?)";

	return sqlSession->executeInsert(sql, "%s%s%i", meetingId, userId, cnt);
}