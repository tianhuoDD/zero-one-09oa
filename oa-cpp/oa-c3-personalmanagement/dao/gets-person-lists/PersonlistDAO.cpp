#include "stdafx.h"
#include "PersonlistDAO.h"
#include "PersonlistMapper.h"
#include <sstream>

// 定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->xstatus) { \
    sql << " AND xstatus=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->xstatus.getValue("")); \
}

// 定义模糊查询宏
#define SAMPLE_FUZZY_PARSE(query, sql) \
    sql << " AND ("; \
    sql << "xname LIKE CONCAT('%',?,'%') OR "; \
    sql << "xid LIKE CONCAT('%',?,'%') OR "; \
    sql << "xmobile LIKE CONCAT('%',?,'%') OR "; \
    sql << "xpinyin LIKE CONCAT('%',?,'%') OR "; \
    sql << "xpinyinInitial LIKE CONCAT('%',?,'%')"; \
    sql << ")"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->input.getValue("")); \
    SQLPARAMS_PUSH(params, "s", std::string, query->input.getValue("")); \
    SQLPARAMS_PUSH(params, "s", std::string, query->input.getValue("")); \
    SQLPARAMS_PUSH(params, "s", std::string, query->input.getValue("")); \
    SQLPARAMS_PUSH(params, "s", std::string, query->input.getValue(""));

uint64_t PersonlistDAO::count(const PersonlistQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT COUNT(*) FROM org_person";
    SAMPLE_TERAM_PARSE(query, sql);
    SAMPLE_FUZZY_PARSE(query, sql);
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<org_personDO> PersonlistDAO::selectWithPage(const PersonlistQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT xname, xmobile, xicon, xid, xunique FROM org_person";
    SAMPLE_TERAM_PARSE(query, sql);
    SAMPLE_FUZZY_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    PersonlistMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<org_personDO, PersonlistMapper>(sqlStr, mapper, params);
}
