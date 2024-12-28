#include "stdafx.h"
#include "UserLoginConfigurationDAO.h"
#include "UserLoginConfigurationMapper.h"
#include"../../domain/do/userloginconfiguration/UserLoginConfigurationDO.h"
#include <sstream>


//通过用户名查询
list<UserLoginConfigurationDO> UserLoginConfigurationDAO::selectByUserName(const string& username)
{
	//string sql = "SELECT id,name,sex,age FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
	/*SampleMapper mapper;
	return sqlSession->executeQuery<SampleDO, SampleMapper>(sql, mapper, "%s", name);*/

	string sql = "SELECT id,username,password,lastlogintime,emailaddress,mobilephone,loginattempts,permission,ipaddress FROM user_login_configuration WHERE `username` = `?`";
	UserLoginConfigurationMapper mapper;
	return sqlSession->executeQuery<UserLoginConfigurationDO, UserLoginConfigurationMapper>(sql, mapper, "%s", username);

	//return sqlSession->executeUpdate(sql, "%s%s%i%ull", uObj.getName(), uObj.getSex(), uObj.getAge(), uObj.getId());
}

//插入新的数据
uint64_t UserLoginConfigurationDAO::insert(const UserLoginConfigurationDO& iObj)
{
	string sql = "INSERT INTO `user_login_configuration` (`id`, `username`, `password`,`lastlogintime`,`emailaddress`,`mobilephone`,`loginattempts`,`permission`,`ipaddress`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%i%s%s%s", iObj.getId(), iObj.getUserName(), iObj.getPassword(), iObj.getLastLoginTime(), iObj.getEmailAddress(), iObj.getMobilePhone(), iObj.getLoginAttempts(), iObj.getPermission(),iObj.getIpAddress());

}

//更新，保存数据
int UserLoginConfigurationDAO::update(const UserLoginConfigurationDO& iObj)
{
	string sql = "UPDATE `user_login_configuration` SET `id`=?, `password`=?, `lastlogintime`=?，`emailaddress`=?, `mobilephone`=?, `loginattempts`=?,`permission`=?,`ipaddress`=? WHERE `username`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%i%s%s%s", iObj.getId(), iObj.getPassword(), iObj.getLastLoginTime(), iObj.getEmailAddress(), iObj.getMobilePhone(), iObj.getLoginAttempts(), iObj.getPermission(), iObj.getIpAddress());
}

//删除数据
int UserLoginConfigurationDAO::deleteByUserName(string username)
{
	string sql = "DELETE FROM `user_login_configuration` WHERE `username`=?";
	return sqlSession->executeUpdate(sql, "%ull", username);
}