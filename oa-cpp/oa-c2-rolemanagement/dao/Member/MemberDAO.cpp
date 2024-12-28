#include"stdafx.h"
#include"dao/Member/MemberDAO.h"

uint64_t MemberDAO::insert(const MemberDo& iObj)
{
	string sql = "INSERT INTO member (id) VALUES(?)";
	return sqlSession->executeUpdate(sql, "%ull", iObj.getId());
}

int MemberDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM member WHERE id=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}
