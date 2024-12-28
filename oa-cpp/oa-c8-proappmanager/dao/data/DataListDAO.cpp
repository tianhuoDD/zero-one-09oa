#include "stdafx.h"
#include "DataListDAO.h"
#include "DataListMapper.h" // ��������һ��ӳ�����࣬����ӳ���ѯ���
#include <sstream>

// �������������꣬�����ظ�����
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
    return sqlSession->executeQueryNumerical(sqlStr, params);  // �������������ļ�¼��
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
