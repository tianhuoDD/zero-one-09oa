#include "stdafx.h"
#include "AddroleDAO.h"
#include "AddroleMapper.h"
#include <sstream>

#define SAMPLE_TERAM_PARSE(unique, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} 

uint64_t AddroleDAO::insert(const AddroleDO& iObj) {

    string sql = "INSERT INTO `org_role` (`xid`,`xcreateTime`,`xsequence`,`xupdateTime`,`xdescription`,`xdistinguishedName`,`xname`,`xorderNumber`,`xpinyin`,`xpinyinInitial`,`xunique`) \
                    VALUES (?,?,?,?,?,?,?,?,?,?,?)";
        
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%s", 
        iObj.getXid(), iObj.getXcreateTime(), iObj.getXsequence(), iObj.getXupdateTime(), iObj.getXdescription(), iObj.getXdistinguishedName(), iObj.getXname(), iObj.getXorderNumber(), iObj.getXpinyin(), iObj.getXpinyinInitial(), iObj.getXunique());
}

uint64_t AddroleDAO::count(const AddroleDO& iObj) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_role";
	SqlParams params;
	sql << " WHERE `xunique` = ?";
	SQLPARAMS_PUSH(params, "s", std::string, iObj.getXunique());
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}