#include "stdafx.h"
#include "modify_menulist_function_permissionsDAO.h"
#include "modify_menulist_function_permissionsMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->role_id) { \
	sql << " AND `role_id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->role_id.getValue("")); \
} \
if (query->menuList) { \
	sql << " AND menuList=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->menuList.getValue("")); \
} \
if (query->xorderColumn) { \
	sql << " AND xorderColumn=?"; \
	SQLPARAMS_PUSH(params, "i", std::int32_t, query->xorderColumn.getValue("")); \
}


int modify_menulist_function_permissionsDAO::update(const org_menulistDO& uObj)
{
	string sql = "UPDATE `org_role_menulist` SET `menuList`=?, `xorderColumn`=? WHERE `role_id`=?";
 
	return sqlSession->executeUpdate(sql, "%s%i%s", uObj.getMenuList(), uObj.getXorderColumn(), uObj.getRole_id());
}
