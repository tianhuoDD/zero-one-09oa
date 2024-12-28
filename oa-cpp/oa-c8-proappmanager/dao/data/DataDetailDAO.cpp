#include "stdafx.h"
#include "DataDetailDAO.h"
#include "DataDetailMapper.h" 
#include "DataDetailSubMapper.h"
#include <sstream>

// �������������꣬�����ظ�����
#define DATADETAIL_TERM_PARSE(dataid, sql) \
SqlParams params; \
sql << " WHERE 1=1"; \
if (dataid!="") { \
    sql << " AND xid=?"; \
    SQLPARAMS_PUSH(params, "s", std::string, dataid); \
}

std::list<DataDetailDO> DataDetailDAO::selectByAppIdAndDataId(const string & dataid) {
    stringstream sql;
    sql << "SELECT xid, xapplication, xname, xalias, xdescription, xcreateTime, xupdateTime FROM pp_e_applicationdict";
    DATADETAIL_TERM_PARSE(dataid, sql);
    string sqlStr = sql.str();
    DataDetailMapper mapper;
    return sqlSession->executeQuery<DataDetailDO, DataDetailMapper>(sqlStr, mapper, params);
}

list<DataDetailSubDO> DataDetailDAO::selectData(const string& dataid) {
	stringstream sql;
	sql << "SELECT xstringLongValue AS fieldStr FROM pp_e_applicationdictitem WHERE xbundle=?";
	SqlParams params;
    SQLPARAMS_PUSH(params, "s", std::string, dataid);
	string sqlStr = sql.str();
    DataDetailSubMapper mapper;
	return sqlSession->executeQuery<DataDetailSubDO, DataDetailSubMapper>(sqlStr, mapper, params);
}
