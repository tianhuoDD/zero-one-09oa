#include "stdafx.h"
#include "GroupDAO.h"
#include "GroupMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->info) { \
	sql << " AND info=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \

//uint64_t SampleDAO::count(const SampleQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM sample";
//	SAMPLE_TERAM_PARSE(query, sql);
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}

int GroupDAO::update(const GroupDO& uObj)
{
	string sql = "UPDATE `groupinfo` SET `name`=?, `info`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%ull", uObj.getName(), uObj.getInfo(), uObj.getId());
}
