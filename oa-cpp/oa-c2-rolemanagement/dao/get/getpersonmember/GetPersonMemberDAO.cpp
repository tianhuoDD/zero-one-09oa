#include "stdafx.h"
#include "GetPersonMemberDAO.h"
#include "GetPersonMemberMapper.h"
#include <sstream>
//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->ROLE_XID) { \
	sql << " AND ROLE_XID=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->ROLE_XID.getValue("")); \
} 

uint64_t GetPersonMemberDAO::count(const GetPersonMemberQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM org_role_grouplist";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	std::cout << sqlStr << std::endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<GetPersonMemberDO> GetPersonMemberDAO::selectWithPage(const GetPersonMemberQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT xgroupList FROM org_role_grouplist";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetPersonMemberMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GetPersonMemberDO, GetPersonMemberMapper>(sqlStr, mapper, params);
}

list<GetPersonMemberDTO> GetPersonMemberDAO::selectGroupMemberWithPage(const list<GetPersonMemberDO>& list)
{
	// ���� SQL ��ѯ���
	std::string sql = "SELECT xdescription, xname, xdistinguishedName,xid FROM org_group WHERE xid IN (";
	// ��������ռλ�������� (?, ?, ?)
	std::ostringstream placeholders;
	for (auto it = list.begin(); it != list.end(); ++it) {
		if (it != list.begin()) {
			placeholders << ", ";
		}
		placeholders << "?";
	}
	sql += placeholders.str() + ")";

	// ���ò�ѯ����
	SqlParams params;
	for (const auto& menuId : list) {
		SQLPARAMS_PUSH(params, "s", std::string, menuId.getXgroupList());
	}

	// ִ�в�ѯ
	GetMembersMapper mapper;
	return sqlSession->executeQuery<GetPersonMemberDTO, GetMembersMapper>(sql, mapper, params);

}
