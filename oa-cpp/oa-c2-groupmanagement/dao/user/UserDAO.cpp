#include "stdafx.h"
#include "UserDAO.h"
#include "UserMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->phone) { \
	sql << " AND phone=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->phone.getValue("")); \
} \
if (query->mail) { \
	sql << " AND mail=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->mail.getValue("")); \
}

//uint64_t SampleDAO::count(const SampleQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM sample";
//	SAMPLE_TERAM_PARSE(query, sql);
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}

std::list<UserDO> UserDAO::selectWithPage(const UserQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,name,phone,mail FROM user";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	UserMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<UserDO, UserMapper>(sqlStr, mapper, params);
}

//std::list<UserDO> SampleDAO::selectByName(const string& name)
//{
//	string sql = "SELECT id,name,phone,mail FROM user WHERE `name` LIKE CONCAT('%',?,'%')";
//	UserMapper mapper;
//	return sqlSession->executeQuery<UserDO, UserMapper>(sql, mapper, "%s", name);
//}

uint64_t UserDAO::count(const UserQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sample";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}