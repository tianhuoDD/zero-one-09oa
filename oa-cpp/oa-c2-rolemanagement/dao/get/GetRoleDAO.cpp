

#include "stdafx.h"
#include "GetRoleDAO.h"
#include"GetRoleMapper.h"
#include <sstream>

std::list<GetRoleDO> GetRoleDAO::selectById(const string &id) // 修改方法名和参数
{
    string sql = "SELECT `xname`, `xunique`, `xdescription`,`xdistinguishedName`,`xcreateTime`,`xupdateTime` FROM org_role WHERE `xunique` = ?"; // 根据 ID 查询
    GetRoleMapper mapper;
    return sqlSession->executeQuery<GetRoleDO, GetRoleMapper>(sql, mapper, "%s", id); // 使用 ID 作为参数
}
