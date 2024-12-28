#include "stdafx.h"
#include "Attrib_modify_DAO.h"
#include "Attrib_modify_Mapper.h"
#include <sstream>
#include "oatpp/core/utils/String.hpp"
#include "../../lib-common/include/SnowFlake.h"

//定义条件解析宏，减少重复代码  
#define ATTRIB_TERAM_PARSE(iObj, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (iObj.getXid().size()) { \
	sql << " AND xunique=? "; \
	SQLPARAMS_PUSH(params, "s", string, iObj.getXid()); \
}\
if (iObj.getXdistinguishedName_pre().size()) { \
	sql << " AND xdistinguishedName=? "; \
	SQLPARAMS_PUSH(params, "s", string, iObj.getXdistinguishedName_pre()); \
}\

//对数据库进行操作
uint64_t Attrib_modify_DAO::select(const Attrib_modify_DO& iObj)
{
	stringstream sql;
	sql << "SELECT xunique FROM org_unitattribute";
	ATTRIB_TERAM_PARSE(iObj, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//更改这个id的数据
int Attrib_modify_DAO::update(const Attrib_modify_DO& uObj)
{
	string sql = "UPDATE `org_unitattribute` SET `xdistributeFactor`=? ,`xdescription`=? ,`xdistinguishedName`=? WHERE `xunique`=? AND `xdistinguishedName`=? ";
	return sqlSession->executeUpdate(sql, "%i%s%s%s%s", uObj.getXdistributeFactor(), uObj.getXdescription(), uObj.getXdistinguishedName_last(), uObj.getXid(), uObj.getXdistinguishedName_pre());
}
