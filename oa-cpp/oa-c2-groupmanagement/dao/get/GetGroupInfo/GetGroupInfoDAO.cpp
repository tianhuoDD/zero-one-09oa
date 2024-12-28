#include "stdafx.h"
#include "GetGroupInfoDAO.h"
#include "GetGroupInfoMapper.h"
#include <sstream>
#include "../../../domain/do/groupmanagement/OrgGroupDO.h"



//uint64_t GetGroupInfoDAO::count(const GetGroupInfoQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM org_group";
//	
//	SqlParams params;
//	sql << " WHERE 1=1";
//	if (query->name) {
//		sql << " AND `name`=?";
//		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
//	}
//	if (query->id) {
//		sql << " AND id=?";
//		SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));
//	}
//	if (query->description) {
//		sql << " AND description=?";
//		SQLPARAMS_PUSH(params, "s", std::string, query->description.getValue(""));
//		//SQLPARAMS_PUSH(params, "i", int, query->description.getValue(0));
//	}
//
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}

std::list<OrgGroupDO> GetGroupInfoDAO::selectByName(const string& name)
{
	string sql = "SELECT xname, xid, xdescription FROM org_group WHERE xname LIKE CONCAT('%',?,'%')";
	GetGroupInfoMapper mapper;
	return sqlSession->executeQuery<OrgGroupDO, GetGroupInfoMapper>(sql, mapper, "%s", name);
}

std::list<OrgGroupDO> GetGroupInfoDAO::selectById(const string& id)
{
	string sql = "SELECT xname, xid, xdescription FROM org_group WHERE xid = ?";
	GetGroupInfoMapper mapper;
	return sqlSession->executeQuery<OrgGroupDO, GetGroupInfoMapper>(sql, mapper, "%s", id);
}