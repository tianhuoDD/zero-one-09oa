/*
 @Author: LemonFlavoredSoda
 @Date: 2024年 10月 24日 星期四 09:11:54 CST
*/
#include "stdafx.h"
#include "IDmemberDAO.h"
#include "IDmemberMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->xname) { \
	sql << " AND `xname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xname.getValue("")); \
} \
if (query->xunitLevelName) { \
	sql << " AND xunitLevelName=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xunitLevelName.getValue("")); \
} 

uint64_t IDmemberDAO::count(const IDmemberQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_identity INNER JOIN org_group_identitylist ON xidentityList=xid";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
	//return {};
}

std::list<IDmemberDO> IDmemberDAO::selectWithPage(const IDmemberQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT A.xname xname,A.xunitLevelName xunitLevelName FROM org_identity A INNER JOIN org_group_identitylist B ON B.xidentityList=A.xid";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	IDmemberMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<IDmemberDO, IDmemberMapper>(sqlStr, mapper, params);
	//return {};
}

//std::list<SampleDO> SampleDAO::selectByName(const string& name)
//{
//	string sql = "SELECT id,name,sex,age FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
//	SampleMapper mapper;
//	return sqlSession->executeQuery<SampleDO, SampleMapper>(sql, mapper, "%s", name);
//}