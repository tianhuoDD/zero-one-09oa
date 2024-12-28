

#include "stdafx.h"
#include "GetRoleDAO.h"
#include"GetRoleMapper.h"
#include <sstream>

std::list<GetRoleDO> GetRoleDAO::selectById(const string &id) // �޸ķ������Ͳ���
{
    string sql = "SELECT `xname`, `xunique`, `xdescription`,`xdistinguishedName`,`xcreateTime`,`xupdateTime` FROM org_role WHERE `xunique` = ?"; // ���� ID ��ѯ
    GetRoleMapper mapper;
    return sqlSession->executeQuery<GetRoleDO, GetRoleMapper>(sql, mapper, "%s", id); // ʹ�� ID ��Ϊ����
}
