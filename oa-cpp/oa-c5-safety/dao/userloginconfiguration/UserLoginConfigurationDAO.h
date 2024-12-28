#pragma once

#ifndef _USERLOGINCONFIGURATION_DAO_
#define _USERLOGINCONFIGURATION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/userloginconfiguration/UserLoginConfigurationDO.h"
#include "../../domain/dto/userloginconfiguration/UserLoginConfigurationDTO.h"

/**
 * 获取和保存登录配置的数据库操作实现
 */
class UserLoginConfigurationDAO : public BaseDAO
{
public:
	//获取登陆配置、保存登陆配置
	//查询,插入，修改，删除

	// 通过用户名查询用户配置
	list<UserLoginConfigurationDO> selectByUserName(const string& username);

	// 插入数据，新建用户时可能用到
	uint64_t insert(const UserLoginConfigurationDO& iObj);
	
	// 保存登陆配置
	int update(const UserLoginConfigurationDO& uObj);
	
	// 通过用户名删除数据
	int deleteByUserName(string name);
};
#endif // !_USERLOGINCONFIGURATION_DAO_