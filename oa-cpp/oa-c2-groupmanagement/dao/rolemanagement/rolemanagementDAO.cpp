
#include "stdafx.h"
#include "rolemanagementDAO.h"
#include "rolemanagementMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define rolemanagement_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->groupxid) { \
	sql << " AND `groupxid`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->groupxid.getValue("")); \
} \
if (query->pageSize) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->pageSize.getValue(0)); \
}

uint64_t rolemanagementDAO::countG(const GetGroupMembersQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_group_grouplist";
	rolemanagement_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 获取群组成员
std::list<OrgGroupGrouplistDO> rolemanagementDAO::selectWithPage(const GetGroupMembersQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT org_group.xname,org_group.xdistinguishedName FROM org_group_grouplist LEFT JOIN org_group ON org_group_grouplist.GROUP_XID = org_group.xid";
	rolemanagement_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetGroupMembersMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<OrgGroupGrouplistDO, GetGroupMembersMapper>(sqlStr, mapper, params);
}

uint64_t rolemanagementDAO::countO(const GetOrganizationMembersQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_group_unitlist";
	rolemanagement_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

//获取组织成员
std::list<OrgGroupUnitlistDO> rolemanagementDAO::selectWithPage(const GetOrganizationMembersQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT org_group.xname,org_group_unitlist.xunitList FROM org_group_unitlist LEFT JOIN org_group ON org_group_unitlist.GROUP_XID = org_group.xid";
	rolemanagement_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetOrganizationMembersMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<OrgGroupUnitlistDO, GetOrganizationMembersMapper>(sqlStr, mapper, params);
}

// 增加身份成员
uint64_t rolemanagementDAO::insert(const OrgGroupIdentitylistDO& iObj)
{
	string sql = "INSERT INTO `org_group_identitylist` (`GROUP_XID`, `xidentityList`) VALUES ( ?,?)";
	return sqlSession->executeUpdate(sql, "%s%s", iObj.getGroupxid(), iObj.getXidentityList());
}


// 通过groupxid删除身份成员
int rolemanagementDAO::deleteById(string groupxid)
{
	string sql = "DELETE FROM `org_group_identitylist` WHERE `GROUP_XID`=? AND `xidentityList`=?";
	return sqlSession->executeUpdate(sql, "%s%s", groupxid);
}


