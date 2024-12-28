#include "RoleManagementDAO.h"
#include"OrgRolePersonListMapper.h"

uint64_t RoleManagementDAO::count(const PersonListQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT COUNT(*) FROM org_role AS r\
			JOIN org_role_personlist AS rp ON r.xid = rp.ROLE_XID";

    SqlParams params; sql << " WHERE 1=1";
    if (query->xunique) {
        sql << " AND r.xunique=?";
        params.emplace_back(SqlParam("s", std::make_shared<std::string>(query->xunique.getValue(""))));
    }

    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}
//ÓÐ¶àÉÙ¸ö
uint64_t RoleManagementDAO::roleUnique(const string& xunique)
{
    stringstream sql;
    sql << "SELECT COUNT(*) FROM org_role AS r";

    SqlParams params; sql << " WHERE 1=1";
    if (!xunique.empty()) {
        sql << " AND r.xunique=?";
        params.emplace_back(SqlParam("s", std::make_shared<std::string>(xunique)));
    }
    string sqlStr = sql.str();
    return sqlSession->executeQueryNumerical(sqlStr, params);
}

int RoleManagementDAO::update(const OrgRoleDO& uObj)
{
    string sql = "UPDATE `org_role` SET `xname`=?,`xupdateTime`=?, `xunique`=?, `xdescription`=? ,`xdistinguishedName`=? WHERE `xunique`=?";
    return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", uObj.getXName(), uObj.getXUpdateTime(), uObj.getXUnique(), uObj.getXDescription(), uObj.getXDistinguishedName(), uObj.getLastXUnique());
}

list<OrgRolePersonListDO> RoleManagementDAO::selectWithPage(const PersonListQuery::Wrapper& query)
{
    stringstream sql;
    sql << "SELECT p.xname,p.xemployee,p.xmobile,p.xmail,p.xid \
			FROM org_role_personlist AS rp \
			JOIN org_person AS p ON rp.xpersonlist = p.xid \
			JOIN org_role AS r ON rp.ROLE_XID = r.xid";
    SqlParams params;
    sql << " WHERE 1=1";
    if (query->xunique) {
        sql << " and r.xunique=?";
        SQLPARAMS_PUSH(params, "s", std::string, query->xunique.getValue(""));
    }
    sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
    OrgRolePersonListMapper mapper;
    string sqlStr = sql.str();
    return sqlSession->executeQuery<OrgRolePersonListDO, OrgRolePersonListMapper>(sqlStr, mapper, params);
}



uint64_t RoleManagementDAO::insertToOrgRoleGroupList(const std::list<OrgRoleGroupListDO>& listIobj)
{
    if (listIobj.empty())
    {
        return 0;
    }
	string sql = "INSERT INTO `org_role_grouplist` (`ROLE_XID`, `xgroupList`, `xorderColumn`) VALUES ";
    std::ostringstream placeholders;
    for (auto it = listIobj.begin(); it != listIobj.end(); ++it)
    {
        if (it != listIobj.begin())
        {
            placeholders << ",";
        }
        placeholders << "(?,?,?)";
    }
    sql += placeholders.str();
    SqlParams params;
    for (const auto& roleGroup : listIobj) {
        SQLPARAMS_PUSH(params, "s", std::string, roleGroup.getROLE_XID());
        SQLPARAMS_PUSH(params, "s", std::string, roleGroup.getXgroupList());
        SQLPARAMS_PUSH(params, "i", uint64_t, roleGroup.getXorderColumn());
    }
    return sqlSession->executeUpdate(sql, params);
}

uint64_t RoleManagementDAO::updateOrgRoleGroupList(const string roleId, list<oatpp::String>& dataGroupList, std::list<OrgRoleGroupListDO>& listData)
{
    uint64_t count = 0;
    uint64_t maxOrderColumn = 0;
    sqlSession->beginTransaction();
    count += insertToOrgRoleGroupList(listData);

    for (const auto item : dataGroupList)
    {
        maxOrderColumn = selectMaxXordercolumn(roleId, "org_role_grouplist", "ROLE_XID");
        count += deleteOrgRoleGroupList(roleId, item.getValue({}), maxOrderColumn);
    }
    if (count == 0)
    {
        sqlSession->rollbackTransaction();
    }
    sqlSession->commitTransaction();
    return count;
}
/*
   uint64_t count = 0;
    uint64_t maxOrderColumn = 0;
    sqlSession->beginTransaction();
    count += insertToOrgResRoleMenu(listData);

    for (const auto item : dataMenuList)
    {
        maxOrderColumn = selectMaxXordercolumn(roleId, "org_role_menulist", "role_id");
        string sql = "SELECT xorderColumn FROM `org_role_menulist` WHERE role_id = ? AND menuList = ?";
        uint64_t columnId = sqlSession->executeQueryNumerical(sql, "%s%s", roleId, item.getValue({}));
        if (!(columnId == maxOrderColumn))
        {
            sql = "UPDATE `org_role_menulist` SET xorderColumn = ? WHERE role_id = ? AND xorderColumn = ? ";
            sqlSession->executeUpdate(sql, "%i%s%i", columnId, roleId, maxOrderColumn);
        }
        sql = "DELETE FROM `org_role_menulist` WHERE role_id = ? AND menuList = ?";
        count += sqlSession->executeUpdate(sql, "%s%s", roleId, item.getValue({}));
    }
    if (count == 0)
    {
        sqlSession->rollbackTransaction();
    }
    sqlSession->commitTransaction();
    return count;
*/



uint64_t RoleManagementDAO::deleteOrgRoleGroupList(const string roleId, const string groupId,const uint64_t maxColumn)
{
	string sql = "SELECT xorderColumn FROM `org_role_grouplist` WHERE ROLE_XID = ? AND xgroupList = ?";
	uint64_t columnId = sqlSession->executeQueryNumerical(sql, "%s%s", roleId, groupId);
	if (!(columnId == maxColumn))
	{
		sql = "UPDATE `org_role_grouplist` SET xorderColumn = ? WHERE ROLE_XID = ? AND xorderColumn = ? ";
		sqlSession->executeUpdate(sql, "%i%s%i", columnId, roleId, maxColumn);
	}
	sql = "DELETE FROM `org_role_grouplist` WHERE ROLE_XID = ? AND xgroupList = ?";
	return sqlSession->executeUpdate(sql, "%s%s", roleId, groupId);
}

uint64_t RoleManagementDAO::deleteOrgRoleGroupListOperation(const string roleId, const std::list<oatpp::String>& groupList)
{
    uint64_t maxOrderColumn = 0;
    uint64_t count = 0;
    sqlSession->beginTransaction();
    for (const auto item : groupList)
    {
        maxOrderColumn = selectMaxXordercolumn(roleId, "org_role_grouplist", "ROLE_XID");
        count += deleteOrgRoleGroupList(roleId, item, maxOrderColumn);
    }
    if (count == 0)
    {
        sqlSession->rollbackTransaction();
    }
    sqlSession->commitTransaction();
    return count;
}

std::list<oatpp::String> RoleManagementDAO::selectGroupList(const string roleId)
{
	string sql = "SELECT xgroupList FROM org_role_menulist WHERE ROLE_XID = ?";
	RoleGroupListMapper mapper;
	return sqlSession->executeQuery<oatpp::String,RoleGroupListMapper>(sql, mapper, "%s", roleId);

}

std::list<oatpp::String> RoleManagementDAO::selectMenuList(const string roleId)
{
	string sql = "SELECT menuList FROM org_role_menulist WHERE role_id = ?";
	MenuListMapper mapper;
	return sqlSession->executeQuery<oatpp::String, MenuListMapper>(sql, mapper, "%s", roleId);
}

//std::list<RoleResourceDO> RoleManagementDAO::selectRoleResource(const std::list<string> menuList)
//{
//	string sql = "SELECT menu_id,menu_name,is_button,menu_type,parent_id";
//	RoleResourceListMapper mapper;
//	return sqlSession->executeQuery<RoleResourceDO, RoleResourceListMapper>(sql, mapper, );
//}

std::list<RoleResourceDO> RoleManagementDAO::selectRoleResource(const std::list<oatpp::String>& menuList) {
    // 检查 menuList 是否为空
    if (menuList.empty()) {
        // 如果为空，则返回一个空的结果列表
        return {};
    }
    // 构建 SQL 查询语句
    std::string sql = "SELECT menu_id, menu_name, is_button, menu_type, parent_id FROM org_menu WHERE menu_id IN (";
    // 构建参数占位符，例如 (?, ?, ?)
    std::ostringstream placeholders;
    for (auto it = menuList.begin(); it != menuList.end(); ++it) {
        if (it != menuList.begin()) {
            placeholders << ", ";
        }
        placeholders << "?";
    }
    sql += placeholders.str() + ")";

    // 设置查询参数
    SqlParams params;
    for (const auto& menuId : menuList) {
        SQLPARAMS_PUSH(params, "s", std::string, menuId.getValue({}));
    }

    // 执行查询
    RoleResourceListMapper mapper;
    return sqlSession->executeQuery<RoleResourceDO, RoleResourceListMapper>(sql, mapper, params);
}

uint64_t RoleManagementDAO::insertToOrgResRoleMenu(const std::list<OrgResRoleMenuDO>& listIobj)
{
    if (listIobj.empty())
    {
        return 0;
    }
    string sql = "INSERT INTO `org_role_menulist` (`role_id`, `menuList`, `xorderColumn`) VALUES ";
    std::ostringstream placeholders;
    for (auto it = listIobj.begin();it != listIobj.end();++it)
    {
        if (it != listIobj.begin())
        {
            placeholders << ",";
        }
        placeholders << "(?,?,?)";
    }
    sql += placeholders.str();

    SqlParams params;
    for (const auto& menu : listIobj) {
        SQLPARAMS_PUSH(params, "s", std::string, menu.getRole_id());
        SQLPARAMS_PUSH(params, "s", std::string, menu.getMenuList());
        SQLPARAMS_PUSH(params, "i", uint64_t, menu.getXorderColumn());  
    }

    return sqlSession->executeUpdate(sql, params);
    //return sqlSession->executeUpdate(sql, "%s%s%i", iobj.getRole_id(), iobj.getMenuList(), iobj.getXorderColumn());
}

uint64_t RoleManagementDAO::deleteOrgResRoleMenu(const string roleId, list<oatpp::String>& dataMenuList, std::list<OrgResRoleMenuDO>& listData)
{
    uint64_t count = 0;
    uint64_t maxOrderColumn = 0;
    sqlSession->beginTransaction();
    count += insertToOrgResRoleMenu(listData);

    for (const auto item : dataMenuList)
    {
        std::cout << item.getValue({}) << std::endl;
        maxOrderColumn = selectMaxXordercolumn(roleId, "org_role_menulist", "role_id");
        string sql = "SELECT xorderColumn FROM `org_role_menulist` WHERE role_id = ? AND menuList = ?";
        uint64_t columnId = sqlSession->executeQueryNumerical(sql, "%s%s", roleId, item.getValue({}));
        if (!(columnId == maxOrderColumn))
        {
            sql = "UPDATE `org_role_menulist` SET xorderColumn = ? WHERE role_id = ? AND xorderColumn = ? ";
            sqlSession->executeUpdate(sql, "%i%s%i", columnId, roleId, maxOrderColumn);
        }
        sql = "DELETE FROM `org_role_menulist` WHERE role_id = ? AND menuList = ?";
        count += sqlSession->executeUpdate(sql, "%s%s", roleId, item.getValue({}));
    }
    if (count == 0)
    {
        sqlSession->rollbackTransaction();
    }
    sqlSession->commitTransaction();
    return count;
}


uint64_t RoleManagementDAO::selectMaxXordercolumn(const string roleId,const string dataTableName,const string field)
{
	stringstream sql;
    sql << "SELECT MAX(xorderColumn) FROM `";
    sql << dataTableName;
    sql << "` WHERE ";
    sql << field;
    sql << " = '";
	sql << roleId << "\'";
	string sqlStr = sql.str();
	//std::cout << sqlStr << std::endl;
	return sqlSession->executeQueryNumerical(sqlStr);
}

//int RoleManagementDAO::update(const OrgRoleDO& uObj)
//{
//    //不完善，还有很多和他们关联的数据，拼音什么的,可以考虑判断一下某个值是否有变化之类的？
//    string sql = "UPDATE `sample` SET `xname`=?, `xunique`=?, `xdescription`=? WHERE `xunique`=?";
//    return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getXName(), uObj.getXUnique(), uObj.getXDescription(), uObj.getXUnique());
//}