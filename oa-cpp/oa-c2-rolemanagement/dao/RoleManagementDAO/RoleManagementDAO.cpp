
#include "stdafx.h"

#include"RoleManagementDAO.h"
#include"RoleManagementMapper.h"

#include <sstream>


//É¾³ý½ÇÉ«ÐÅÏ¢
int DelRoleDAO::deleteById(string id)
{
	//tring sql = "INSERT INTO `org_role` (`xname`, `xunique`, `xsequence`) VALUES (?, ?, ?)";
	//return sqlSession->executeInsert(sql, "%s%s%s", iObj.getName(), iObj.getKey(), iObj.getRefer());
	string sql = "DELETE FROM `org_role` WHERE `xunique`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
