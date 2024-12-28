#include "stdafx.h"
#include "RoleInfoDAO.h"
#include "RoleInfoMapper.h"
#include <sstream>
uint64_t RoleInfoDAO::count(const RoleInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_role_personlist WHERE ";
	SqlParams params;
	if (query->xid) {
			sql << "`xpersonList`=?"; 
			SQLPARAMS_PUSH(params, "s", std::string, query->xid.getValue(""));
	}
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<org_roleDO> RoleInfoDAO::selectWithPage(const RoleInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xname,xdistinguishedName,xdescription FROM org_role_personlist,org_role ";
	sql<<"WHERE org_role_personlist.ROLE_XID=org_role.xid";
	SqlParams params;
	if (query->xid) {
			sql << " AND `xpersonList`=?"; 
			SQLPARAMS_PUSH(params, "s", std::string, query->xid.getValue(""));
	}
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	RoleInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<org_roleDO, RoleInfoMapper>(sqlStr, mapper, params);
}

