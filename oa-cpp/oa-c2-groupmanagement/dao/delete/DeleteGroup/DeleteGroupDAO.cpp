#include "DeleteGroupDAO.h"



int DeleteGroupDAO::deleteById(string groupId)
{
	//����yi��ʾɾ���ɹ�
	string sql = "DELETE FROM org_group WHERE xid = ?";
	return sqlSession->executeUpdate(sql, "%s", groupId);
}
