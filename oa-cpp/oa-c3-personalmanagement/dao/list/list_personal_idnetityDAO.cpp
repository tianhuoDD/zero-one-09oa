#include "stdafx.h"
#include "list_personal_identityDAO.h"
#include "list_personal_identityMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->xid) { \
	sql << " AND `xid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xid.getValue("")); \
} \
if (query->xname) { \
	sql << " AND `xname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xname.getValue("")); \
} 


uint64_t list_personal_identityDAO::count(const list_personal_identityQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_identity";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);

	
}

std::list<org_identityDO> list_personal_identityDAO::selectWithPage(const list_personal_identityQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xname,xunitName,xunique,xdistinguishedName,xmajor FROM org_identity";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	list_personal_identityMapper mapper;
	string sqlStr = sql.str();
	return  sqlSession->executeQuery<org_identityDO, list_personal_identityMapper>(sqlStr, mapper, params);

}

//std::list<org_identityDO> list_personal_identityDAO::selectByName(const string& name)
//{
//	string sql = "SELECT xname,xunitName,xunique,xdistinguishedName,xmajor FROM org_identity WHERE `xunique` LIKE CONCAT('%','%')";
//	list_personal_identityMapper mapper;
//	return sqlSession->executeQuery<org_identityDO, list_personal_identityMapper>(sql, mapper, "%s", name);
//}