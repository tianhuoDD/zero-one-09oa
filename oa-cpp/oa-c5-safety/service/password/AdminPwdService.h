#pragma once

#ifndef _ADMINPWDSERVICE_H_
#define _ADMINPWDSERVICE_H_
#include <list>
#include "domain/vo/password/admin/AdminPwdVO.h"
#include "domain/dto/password/admin/AdminPwdDTO.h"
#include"domain/vo/BaseJsonVO.h"

/**
 * 用户配置服务实现
 */
class AdminPwdService
{
public:

	// 查询用户配置
	AdminPwdDTO::Wrapper listAll(const String& xid);

	// 保存数据
	uint64_t saveData(const AdminPwdDTO::Wrapper& dto);

	// 修改数据
	bool updateData(const AdminPwdDTO::Wrapper& dto);

	// 通过ID删除数据
	bool removeData(string xid);
};

#endif // !_ADMINPWD_SERVICE_

