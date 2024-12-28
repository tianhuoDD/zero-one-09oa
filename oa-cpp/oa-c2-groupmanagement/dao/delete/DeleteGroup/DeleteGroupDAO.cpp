#include "DeleteGroupDAO.h"



int DeleteGroupDAO::deleteById(string groupId)
{
	//返回yi表示删除成功
	string sql = "DELETE FROM org_group WHERE xid = ?";
	return sqlSession->executeUpdate(sql, "%s", groupId);
}
