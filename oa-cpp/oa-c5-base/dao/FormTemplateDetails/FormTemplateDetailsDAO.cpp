#include "stdafx.h"
#include "FormTemplateDetailsDAO.h"
#include "FormTemplateDetailsMapper.h"
#include "../../domain/query/FormTemplateQuery.h"
#include <sstream>


list<formTemplateBuiltDO> FormTemplateDetailsDAO::selectInfoById(const char* xid)
{
	stringstream sql;
	sql << "SELECT xid, xcreateTime, xsequence, xupdateTime, xdistributeFactor, xalias, xcategory, xdata, xdescription, xicon, xmobileData, xname, xoutline FROM sys_templateform WHERE `xid` = ?";
	FormTemplateBuiltMapper mapper;
	std::string std_str(xid);
	return sqlSession->executeQuery<formTemplateBuiltDO, FormTemplateBuiltMapper>(sql.str(), mapper, "%s", std_str);
}

list<formTemplateBuiltDO> FormTemplateDetailsDAO::selectcategoryAndnumByApp(const char* xid)
{
	stringstream sql;
	sql << "SELECT xcategory,COUNT(*) AS xnum FROM sys_templateform WHERE `xid` = ? GROUP BY xcategory";
	FormTemplateCategoryMapper mapper;
	std::string std_str(xid);
	return sqlSession->executeQuery<formTemplateBuiltDO, FormTemplateCategoryMapper>(sql.str(), mapper, "%s", std_str);
}
