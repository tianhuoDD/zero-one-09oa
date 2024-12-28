#include "stdafx.h"
#include "AddmenuDAO.h"
#include "AddmenuMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->role_id) { \
	sql << " AND `role_id`=?"; \
	SQLPARAMS_PUSH(params, "ull", std::uint64_t, query->role_id.getValue(0)); \
} \
if (query->permissions) { \
	sql << " AND permissions=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->Menulist.getValue("")); \
}\

uint64_t AddmenuDAO::insert(const Org_role_menulistDO& iObj)
{
	string sql = "INSERT INTO `org_role_menulist` (`role_id`, `menulist`) VALUES (?, ?)";
	return sqlSession->executeInsert(sql, "%s%s", iObj.getrole_Id(),iObj.getMenulist());
}
uint64_t AddmenuDAO::selectbypermissions(const Org_role_menulistDO& iObj)
{
	string sql = "SELECT COUNT(*) FROM `org_menu` WHERE `menu_name` = ?";
	return sqlSession->executeQueryNumerical(sql, "%s", iObj.getMenulist());
}
uint64_t AddmenuDAO::selectisexist(const Org_role_menulistDO& iObj)
{
	string sql = "SELECT COUNT(*) FROM `org_role_menulist` WHERE `role_id` = ? AND `menulist` = ?";
	return sqlSession->executeQueryNumerical(sql, "%s%s", iObj.getrole_Id(), iObj.getMenulist());
}
uint64_t AddmenuDAO::selectbyrole_id(const Org_role_menulistDO& iObj)
{
	string sql = "SELECT COUNT(*) FROM `org_role_personlist` WHERE `ROLE_XID` = ?";
	return sqlSession->executeQueryNumerical(sql, "%s", iObj.getrole_Id());

}