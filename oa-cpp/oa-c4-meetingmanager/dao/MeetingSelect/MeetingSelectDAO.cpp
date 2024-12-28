#include "stdafx.h"
#include "MeetingSelectDAO.h"
#include "MeetingSelectMapper.h"
#include <sstream>

// �������������꣬�����ظ�����
#define MEETING_QUERY_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->id) { \
    sql << " AND `xid`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->applicant) { \
    sql << " AND `xapplicant`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->applicant.getValue("")); \
} \
if (query->time) { \
    sql << " AND `xstartTime`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->time.getValue("")); \
} \
if (query->title) { \
    sql << " AND `xsummary` =?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->title.getValue("")); \
} \
if (query->meetingRoom) { \
    sql << " AND `xroom`=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->meetingRoom.getValue("")); \
} \
//if (query->status) { \
//    sql << " AND 'xconfirmStatus'=?"; \
//    SQLPARAMS_PUSH(params, "s", std::string, query->status.getValue("")); \
//} \
//if (query->type) { \
//    sql << " AND xtype=?"; \
//    SQLPARAMS_PUSH(params, "i", std::uint64_t, query->type.getValue(0)); \
//} 
//if (query->month) { \
//    sql << " AND DATE_FORMAT(xstartTime, '%Y-%m') = ?"; \
//    SQLPARAMS_PUSH(params, "s", std::string, query->month.getValue("")); \
//}

/**
 * ͳ�Ʒ��ϲ�ѯ�����Ļ����¼��
 */
uint64_t MeetingSelectDAO::count(const MeetingSelectQuery::Wrapper& query)
{
    std::stringstream sql;
    sql << "SELECT COUNT(*) FROM `mt_meeting`";
    MEETING_QUERY_PARSE(query, sql);
    std::string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

/**
 * ���ݷ�ҳ������ѯ�����¼
 */
std::list<MeetingSelectDO> MeetingSelectDAO::selectWithPage(const MeetingSelectQuery::Wrapper& query)
{
    std::stringstream sql; 
    sql << "SELECT `xid`, `xapplicant`, `xstartTime`, `xsummary`, `xroom`  FROM `mt_meeting`";
    MEETING_QUERY_PARSE(query, sql);
    sql << " LIMIT " << ((query->page.getValue(1) - 1) * query->pageSize.getValue(10)) << ", " << query->pageSize.getValue(10);

    MeetingSelectMapper mapper;
    std::string sqlStr = sql.str();
    return sqlSession->executeQuery<MeetingSelectDO, MeetingSelectMapper>(sqlStr, mapper, params);
}

/**
 * ���ݻ�������ѯ�����¼
 */
std::list<MeetingSelectDO> MeetingSelectDAO::selectByTitle(const std::string& title)
{
    std::string sql = "SELECT `xid`, `xapplicant`, `xstartTime` ,`xroom` FROM `mt_meeting` WHERE `xsummary` LIKE CONCAT('%',?,'%')";

    MeetingSelectMapper mapper;
    return sqlSession->executeQuery<MeetingSelectDO, MeetingSelectMapper>(sql, mapper, "%s", title);
}

///**
// * �����µĻ����¼
// */
//uint64_t MeetingSelectDAO::insert(const MeetingSelectDO& iObj)
//{
//    std::string sql = "INSERT INTO mt_meeting (xapplicant, xstartTime,xroom, xconfirmStatus, xtype) VALUES (?, ?, ?, ?, ?)";
//
//    return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%i", iObj.getApplicant(), iObj.getTime(), iObj.getTitle(), iObj.getMeetingRoom(), iObj.getStatuS(), iObj.getType());
//}

///**
// * ���»����¼
// */
//int MeetingSelectDAO::update(const MeetingSelectDO& uObj)
//{
//    std::string sql = "UPDATE mt_meeting SET xapplicant=?, xstartTime=?,xstartTime, xroom=?, xconfirmStatus=?, xtype=? WHERE xid=?";
//
//    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%i%ull", uObj.getApplicant(), uObj.getTime(), uObj.getTitle(), uObj.getMeetingRoom(), uObj.getStatuS(), uObj.getType(), uObj.getId());
//}

///**
// * ����IDɾ�������¼
// */
//int MeetingSelectDAO::deleteById(uint64_t id)
//{
//    std::string sql = "DELETE FROM mt_meeting WHERE xid=?";
//
//    return sqlSession->executeUpdate(sql, "%ull", id);
//}
