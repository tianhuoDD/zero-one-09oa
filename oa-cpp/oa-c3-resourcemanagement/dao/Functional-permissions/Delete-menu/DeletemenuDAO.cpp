#include "stdafx.h"
#include "DeletemenuDAO.h"
#include "DeletemenuMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
}\
if (query->permissions) { \
	sql << " AND permissions=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->permissions.getValue(""); \
}
uint64_t DeletemenuDAO::selectbyall(const Org_role_menulistDO & iOjb)
{
	string sql = "SELECT COUNT(*) FROM `org_role_menulist` WHERE `role_id` = ? AND `menulist` =?";
	return sqlSession->executeQueryNumerical(sql, "%s%s", iOjb.getrole_Id(), iOjb.getMenulist());
}
uint64_t DeletemenuDAO::deleteById(const Org_role_menulistDO&iOjb)
{
	string sql = "DELETE FROM `org_role_menulist` WHERE `role_id`=? AND `menulist`=?";
	return sqlSession->executeUpdate(sql, "%s%s",iOjb.getrole_Id(),iOjb.getMenulist());
}
