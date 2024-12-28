#include "stdafx.h"
#include "DataListDAO.h"
#include "DataListMapper.h" // 假设您有一个映射器类，用于映射查询结果
#include <sstream>

// 定义条件解析宏，减少重复代码
#define DATALIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (query->appid) { \
    sql << " AND xapplication=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, query->appid.getValue("")); \
} 

uint64_t DataListDAO::count(const DataListQuery::Wrapper & query) {
    stringstream sql;
    sql << "SELECT COUNT(*) FROM pp_e_applicationdict";  
    DATALIST_TERAM_PARSE(query, sql);
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);  // 返回满足条件的记录数
}

std::list<DataListDO> DataListDAO::selectWithPage(const DataListQuery::Wrapper & query) {
    stringstream sql;
    sql << "SELECT xid, xapplication, xname, xalias, xdescription, xcreateTime, xupdateTime FROM pp_e_applicationdict";  
    DATALIST_TERAM_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    DataListMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<DataListDO, DataListMapper>(sqlStr, mapper, params);
}
