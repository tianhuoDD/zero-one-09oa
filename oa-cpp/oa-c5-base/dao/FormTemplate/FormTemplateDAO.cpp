#include "stdafx.h"
#include "FormTemplateDAO.h"
#include "FormTemplateMapper.h"
#include <sstream>

#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->templateName) { \
	sql << " AND `templateName`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->templateName.getValue("")); \
} \
if (query->category) { \
	sql << " AND category=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->category.getValue("")); \
}


uint64_t FormTemlplateDAO::count(const FormTemplateQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sys_templateform";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<formTemplateBuiltDO> FormTemlplateDAO::selectWithPage(const FormTemplateQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT xid, xcreateTime, xsequence, xupdateTime, xdistributeFactor, xalias, xcategory, xdata, xdescription, xicon, xmobileData, xname, xoutline FROM sys_templateform";
    SAMPLE_TERAM_PARSE(query, sql);
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    FormTemplateBuiltMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<formTemplateBuiltDO, FormTemplateBuiltMapper>(sqlStr, mapper, params);
}
