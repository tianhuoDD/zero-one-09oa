#include "stdafx.h"
#include "AdminPwdDAO.h"
#include "AdminPwdMapper.h"
#include "domain/do/password/admin/AdminPwdDO.h"
#include <sstream>


//通过xid查询返回
list<AdminPwdDO> AdminPwdDAO::selectByXId(const string& xid)
{
	string sql = "SELECT xid,xoldpassword,xnewpassword,xconfirmpassword,xchangePasswordTime,xpasswordExpiredTime FROM safety_password WHERE `xid` = `?`";
	AdminPwdMapper mapper;
	return sqlSession->executeQuery<AdminPwdDO, AdminPwdMapper>(sql, mapper, "%s", xid);
}

//插入新的数据
uint64_t AdminPwdDAO::insert(const AdminPwdDO& iObj)
{
	string sql = "INSERT INTO `safety_password` (`xid`, `xoldpassword`, `xnewpassword`,`xnewpassword`,`xnewpassword`,`xnewpassword`) VALUES (?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s", iObj.getId(), iObj.getOldPassword(), iObj.getNewPassword(), iObj.getConfirmPassword(), iObj.getChangePasswordTime(), iObj.getPasswordExpiredTime());

}

//更新，保存数据
int AdminPwdDAO::update(const AdminPwdDO& iObj)
{
	string sql = "UPDATE `safety_password` SET  `xoldpassword`=?, `xnewpassword`=?，`xnewpassword`=?, `xnewpassword`=?, `xnewpassword`=?` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s", iObj.getId(), iObj.getOldPassword(), iObj.getNewPassword(), iObj.getConfirmPassword(), iObj.getPasswordExpiredTime());
}

//删除数据
int AdminPwdDAO::deleteByXId(string xid)
{
	string sql = "DELETE FROM `safety_password` WHERE `xid`=?";
	return sqlSession->executeUpdate(sql, "%ull", xid);
}