#include "stdafx.h"
#include "QueryRoleDAO.h"
#include "QueryRoleMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->key) { \
	sql << " AND `xname` LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->key.getValue("")); \
} 

uint64_t QueryRoleDAO::count(const QueryRoleQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_role";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<OrgRoleDO> QueryRoleDAO::selectWithPage(const QueryRoleQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xid,xname,xunique FROM org_role";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	QueryRoleMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<OrgRoleDO, QueryRoleMapper>(sqlStr, mapper, params);
}