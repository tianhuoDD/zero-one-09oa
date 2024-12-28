#pragma once

#ifndef _USERLOGINCONFIGURATION_SERVICE_
#define _USERLOGINCONFIGURATION_SERVICE_
#include <list>
#include "domain/vo/userloginconfiguration/userloginconfigurationVO.h"
#include "domain/dto/userloginconfiguration/UserLoginConfigurationDTO.h"
#include"domain/vo/BaseJsonVO.h"

/**
 * 用户配置服务实现
 */
class UserLoginConfigurationService
{
public:

	// 查询用户配置
	UserLoginConfigurationDTO::Wrapper listAll(const String& username);
	
	// 保存数据
	uint64_t saveData(const UserLoginConfigurationDTO::Wrapper& dto);

	// 修改数据
	bool updateData(const UserLoginConfigurationDTO::Wrapper& dto);
	
	// 通过ID删除数据
	bool removeData(string username);
};

#endif // !_SAMPLE_SERVICE_

