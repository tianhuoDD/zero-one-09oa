#pragma once

#ifndef _ADMINPWDDAO_H_
#define _ADMINPWDDAO_H_
#include "BaseDAO.h"

#include "domain/do/password/admin/AdminPwdDO.h"
#include "domain/dto/password/admin/AdminPwdDTO.h"

/**
 * 获取和保存登录配置的数据库操作实现
 */
class AdminPwdDAO : public BaseDAO
{
public:
	//获取登陆配置、保存登陆配置
	//查询,插入，修改，删除

	// 通过用户名查询用户配置
	list<AdminPwdDO> selectByXId(const string& xid);

	// 插入数据，新建用户时可能用到
	uint64_t insert(const AdminPwdDO& iObj);

	// 保存登陆配置
	int update(const AdminPwdDO& uObj);

	// 通过用户名删除数据
	int deleteByXId(string xid);
};
#endif // !_ADMINPWD_DAO_