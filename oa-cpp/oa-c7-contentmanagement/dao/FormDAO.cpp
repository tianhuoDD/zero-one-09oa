#include "stdafx.h"
#include "FormDAO.h"
#include "FormMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->xname) { \
	sql << " AND `xname`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->xname.getValue("")); \
} \

list<FormDO> FormDAO::selectByAppId(const FormQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xid, xupateTime, xalias, xdescription FROM `cms_form` WHERE `xappId`=?";
	SqlParams params;
	SQLPARAMS_PUSH(params, "s", std::string, query->xappId.getValue(""));

	FormMapper mapper;

	string sqlStr = sql.str();
	//std::cout << sqlStr << std::endl;
	return sqlSession->executeQuery<FormDO, FormMapper>(sqlStr, mapper, params);

	return list<FormDO>();
}