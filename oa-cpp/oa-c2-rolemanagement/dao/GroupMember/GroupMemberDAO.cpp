#include "stdafx.h"

#include"GroupMamberMapper.h"
#include <sstream>
#include "GroupMemberDAO.h"

//定义条件解析宏，减少重复代码
#define GROUP_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE"; \
if (query->groupname) { \
	sql << "`groupname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->groupname.getValue("")); \
} \
if (query->groupnameA) { \
	sql << " AND groupnameA=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->groupnameA.getValue("")); \
} \
if (query->groupdes) { \
	sql << " AND groupdes=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->groupdes.getValue("")); \
}
uint64_t GroupMemberDAO::count(const GroupMemberQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM groupmember";
	GROUP_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<GroupMemberDO> GroupMemberDAO::selectWithPage(const GroupMemberQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT groupname,groupnameA,groupdes FROM groupname";
	GROUP_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GroupMemberMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GroupMemberDO,GroupMemberMapper>(sqlStr, mapper, params);
}
