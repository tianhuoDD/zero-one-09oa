#include"stdafx.h"
#include"dao/put/PersonMember/PersonMemberDAO.h"
#include"dao/put/PersonMember/PersonMemberMapper.h"

std::list<oatpp::String> PersonMemberDAO::selectPersonMemberList(const string roleId)
{
	string sql = "SELECT ROLE_XID FROM org_role_personlist WHERE xpersonList = ?";
	PersonMemberMapper mapper;
	return sqlSession->executeQuery<oatpp::String, PersonMemberMapper>(sql, mapper, "%s", roleId);

}

uint64_t PersonMemberDAO::selectMaxXordercolumn(const string roleId, const string dataTableName, const string field)
{
	stringstream sql;
	sql << "SELECT MAX(xorderColumn) FROM `";
	sql << dataTableName;
	sql << "` WHERE ";
	sql << field;
	sql << " = '";
	sql << roleId << "\'";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr);
}


uint64_t PersonMemberDAO::insertPersonMemberList(const std::list<PersonMemberDO>& listIobj)
{
	if (listIobj.empty())
	{
		return 0;
	}
	string sql = "INSERT INTO `org_role_personlist` (`ROLE_XID`, `xpersonList`, `xorderColumn`) VALUES ";
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
	for (const auto& rolePerson : listIobj) {
		SQLPARAMS_PUSH(params, "s", std::string, rolePerson.getROLE_XID());
		SQLPARAMS_PUSH(params, "s", std::string, rolePerson.getXpersonList());
		SQLPARAMS_PUSH(params, "i", uint64_t, rolePerson.getXorderColumn());
	}
	return sqlSession->executeUpdate(sql, params);
}

uint64_t PersonMemberDAO::deletePersonMemberList(const string roleId, const string personId, const uint64_t maxColumn)
{
	

	string sql = "SELECT xorderColumn FROM `org_role_personlist` WHERE ROLE_XID = ? AND xpersonList = ?";
	uint64_t columnId = sqlSession->executeQueryNumerical(sql, "%s%s", roleId, personId);
	if (!(columnId == maxColumn))
	{
		sql = "UPDATE `org_role_personlist` SET xorderColumn = ? WHERE ROLE_XID = ? AND xorderColumn = ? ";
		sqlSession->executeUpdate(sql, "%i%s%i", columnId, roleId, maxColumn);
	}
	sql = "DELETE FROM `org_role_personlist` WHERE ROLE_XID = ? AND xpersonList = ?";
	return sqlSession->executeUpdate(sql, "%s%s", roleId, personId);
}
uint64_t PersonMemberDAO::updatePersonMemberList(const string role_xid, list<oatpp::String>& dataPersonList, std::list<PersonMemberDO>& listData)
{
	uint64_t count = 0;
	uint64_t maxOrderColumn = 0;
	sqlSession->beginTransaction();
	count += insertPersonMemberList(listData);

	for (const auto item : dataPersonList)
	{
		maxOrderColumn = selectMaxXordercolumn(role_xid, "org_role_personlist", "role_xid");
		count += deletePersonMemberList(role_xid, item.getValue({}), maxOrderColumn);
	}
	std::cout << "count3 = " << count << std::endl;
	if (count == 0)
	{		
		sqlSession->rollbackTransaction();
	}
	sqlSession->commitTransaction();
	return count;
}


uint64_t PersonMemberDAO::deletePersonMemberListOperation(const string role_xid, const std::list<oatpp::String>& xpersonList)
{
	uint64_t maxOrderColumn = 0;
	uint64_t count = 0;
	sqlSession->beginTransaction();
	for (const auto item : xpersonList)
	{
		maxOrderColumn = selectMaxXordercolumn(role_xid, "org_role_personlist", "role_xid");
		count += deletePersonMemberList(role_xid, item, maxOrderColumn);
	}
	if (count == 0)
	{
		sqlSession->rollbackTransaction();
	}
	sqlSession->commitTransaction();
	return count;
}
